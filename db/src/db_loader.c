/*
 * db_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#include "db_loader.h"
#include "string.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"
#include "db_ll.h"
#include "db_dl.h"
#include "stdlib.h"

void db_onexit(void(*handler)(void*),void*userData);

#include "db_platform.h"

static db_ll fileHandlers = NULL;
static db_ll libraries = NULL;

struct db_fileHandler {
	db_string ext;
	db_loadAction load;
	void* userData;
};

/* Lookup file handler action */
int db_lookupExtWalk(struct db_fileHandler* h, struct db_fileHandler** data) {
	if (!strcmp(h->ext, (*data)->ext)) {
		*data = h;
		return 0;
	}
	return 1;
}

/* Lookup file handler */
static struct db_fileHandler* db_lookupExt(db_string ext) {
	struct db_fileHandler dummy, *dummy_p;

	dummy.ext = ext;
	dummy_p = &dummy;

	/* Walk handlers */
	if (fileHandlers) {
		db_llWalk(fileHandlers, (db_walkAction)db_lookupExtWalk, &dummy_p);
	}

	if (dummy_p == &dummy) {
		dummy_p = NULL;
	}

	return dummy_p;
}

/* Get file extension */
static void db_fileExt(db_char* buffer, db_string file) {
	db_char *ptr, *bptr;
	db_char ch;

	bptr = buffer;

	ptr = file + strlen(file);
	while(ptr >= file) {
		if (*ptr == '.') break;
		ptr--;
	}
	if (ptr >= file) {
		ptr++;
		while((ch = *ptr)) {
			*bptr = ch;
			ptr++;
			bptr++;
		}
	}
	*bptr = '\0';
}

/* Register a filetype */
int db_loaderRegister(db_string ext, db_loadAction handler, void* userData) {
	struct db_fileHandler* h;

	/* Check if extension is already registered */
	if ((h = db_lookupExt(ext))) {
		if (h->load != handler) {
			db_error("db_loaderRegister: extension '%s' is already registered with another loader.", ext);
			goto error;
		}
	} else {
		h = db_malloc(sizeof(struct db_fileHandler));
		h->ext = ext;
		h->load = handler;
		h->userData = userData;

		if (!fileHandlers) {
			fileHandlers = db_llNew();
		}

		db_llAppend(fileHandlers, h);
	}

	return 0;
error:
	return -1;
}

static db_ll filesLoaded = NULL;

/* Load known filetypes */
int db_load(db_string str){
	db_char ext[16];
	struct db_fileHandler* h;
	int result = -1;

	if (!filesLoaded) {
	    filesLoaded = db_llNew();
	} else {
	    db_iter iter;
	    db_string loaded;

	    /* Lookup whether a file is already loaded */
	    iter = db_llIter(filesLoaded);
	    while(db_iterHasNext(&iter)) {
	        loaded = db_iterNext(&iter);
	        if (!strcmp(loaded, str)) {
	            /* File is already loaded! */
	            result = 0;
	            goto loaded;
	        }
	    }
	}

	/* Get extension from filename */
	db_fileExt(ext, str);

	/* Lookup extension */
	h = db_lookupExt(ext);
	if (h) {
		/* Load file */
		result = h->load(str, h->userData);
	} else {
		db_error("file-extension '%s' not supported.", ext);
		goto error;
	}

	if (!result) {
	    db_llInsert(filesLoaded, db_strdup(str));
	}

	return result;
error:
	return -1;
loaded:
    return 0;
}

/* Load library */
int db_libraryLoader(db_string _file, void* udata) {
	db_dl dl;
	db_string filename = NULL, file = NULL;
	int (*proc)(int argc, char* argv[]);

	DB_UNUSED(udata);

	/* Convert scoped name to filename */
	if (strchr(_file, ':')) {
	    db_char ch, *ptr, *bptr;
	    ptr = _file;
	    file = malloc(strlen(_file)+1);
	    filename = file;
	    ptr = _file;
	    bptr = file;
	    while((ch=*ptr)) {
	        switch(ch) {
	        case ':':
	            *bptr = '/';
	            bptr++;
	            ptr++;
	            filename = bptr;
	            break;
	        default:
	            *bptr = ch;
	            bptr++;
	            break;
	        }
	        ptr++;
	    }
	    *bptr = '\0';
	} else {
	    file = db_strdup(_file);
	    filename = file;
	}

	/* Load shared object from HYVE_HOME */
	dl = db_dlOpen(file);
	if (!dl) {
	    int length;
	    db_char path[256];
	    db_char str[256];
	    db_string err;
        db_string hyveHome = getenv("HYVE_HOME");
	    err = db_strdup(db_dlError());
	    length = (db_word)filename - (db_word)file;
        memcpy(path, file, length);
        path[length]='\0';
        if (length) {
            sprintf(str, "%s/bin/%slib%s.so", hyveHome, path, filename);
        } else {
            sprintf(str, "lib%s.so", filename);
        }
	    if (!(dl = db_dlOpen(str))) {
	    	db_error("db_libraryLoader: %s, %s", err, db_dlError());
	        goto error;
	    }
	    db_dealloc(err);
	}

	/* Lookup main function */
	proc = (int(*)(int,char*[]))db_dlProc(dl, "hyvemain");
	if (!proc) {
		db_error("unresolved 'hyvemain' in library '%s'.", file);
		goto error;
	}

	/* Call main */
	if (proc(0, NULL)) {
		db_error("%s: hyvemain failed.", file);
		goto error;
	}

	/* Add library to libraries list */
	if (!libraries) {
		libraries = db_llNew();
	}
	db_llInsert(libraries, dl);

	if (file) {
	    db_dealloc(file);
	}

	return 0;
error:
    if (file) {
        db_dealloc(file);
    }
	return -1;
}

void db_loaderOnExit(void* udata) {
	struct db_fileHandler* h;
	db_dl dl;
	void (*proc)(int code);
	db_iter iter;
	db_string loaded;

	DB_UNUSED(udata);

	/* Free loaded administration */

	if (filesLoaded) {
        iter = db_llIter(filesLoaded);
         while(db_iterHasNext(&iter)) {
             loaded = db_iterNext(&iter);
             db_dealloc(loaded);
         }
         db_llFree(filesLoaded);
	}

	/* Free handlers */
	while((h = db_llTakeFirst(fileHandlers))) {
		db_dealloc(h);
	}
	db_llFree(fileHandlers);

	/* Free libraries */
	if (libraries) {
		while((dl = db_llTakeFirst(libraries))) {
            /* Lookup exit function */
            proc = (void(*)(int))db_dlProc(dl, "exit");
            if (proc) {
                proc(0);
            }
			db_dlClose(dl);
		}
		db_llFree(libraries);
	}
}

/* Register handlers for shared objects */
DB_DLL_CONSTRUCT {
	/* Register exit-handler */
	db_onexit(db_loaderOnExit, NULL);

	/* Register library-binding */
	db_loaderRegister("", db_libraryLoader, NULL);
	db_loaderRegister("so", db_libraryLoader, NULL);
	db_loaderRegister("dll", db_libraryLoader, NULL);
}





