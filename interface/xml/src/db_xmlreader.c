/*
 * ser_xml_reader.c
 *
 *  Created on: Oct 25, 2011
 *      Author: sander
 */

#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "libxml/xmlreader.h"

#include "db_object.h"
#include "db_err.h"
#include "db_xmlreader.h"

static db_bool xml_initialized = FALSE;

typedef struct db_xmlreader_s {
	xmlDocPtr doc;
	xmlNodePtr root;
}db_xmlreader_s;

/* Open xml memory */
db_xmlreader db_xmlMemoryReaderNew(const char* str, const char* rootElement) {
	xmlDocPtr doc;
	xmlNodePtr root;
	db_xmlreader reader;

	reader = 0;

	if (!xml_initialized) {
		xmlInitParser();
		xml_initialized = TRUE;
	}

	doc = xmlReadMemory(str, strlen(str), "noname.xml", NULL, 0);
	if (doc) {
		root = xmlDocGetRootElement(doc);
		assert(root);

		if (xmlStrcmp(root->name, (const xmlChar*)rootElement)) {
			db_error("incorrect root element '%s' (expected '%s').", root->name, rootElement);
			xmlFreeDoc(doc);
			doc = 0;
		} else {
			reader = malloc(sizeof(db_xmlreader_s));
			reader->doc = doc;
			reader->root = root;
		}
	}

	return reader;
}

/* Open xml file */
db_xmlreader db_xmlreaderNew(const char* file, const char* rootElement) {
	xmlDocPtr doc;
	xmlNodePtr root;
	db_xmlreader reader;

	reader = 0;

	if (!xml_initialized) {
		xmlInitParser();
		xml_initialized = TRUE;
	}

	doc = xmlParseFile(file);
	if (doc) {
		root = xmlDocGetRootElement(doc);
		assert(root);

		if (xmlStrcmp(root->name, (const xmlChar*)rootElement)) {
			db_error("incorrect root element '%s' (expected '%s').", root->name, rootElement);
			xmlFreeDoc(doc);
			doc = 0;
		} else {
			reader = malloc(sizeof(db_xmlreader_s));
			reader->doc = doc;
			reader->root = root;
		}
	}

	return reader;
}

/* Close xml file */
void db_xmlreaderFree(db_xmlreader reader) {
	xmlFreeDoc(reader->doc);
	/*xmlCleanupParser();*/
	free(reader);
}

/* Get name of node */
const char* db_xmlnodeName(db_xmlnode cnode) {
	xmlNodePtr node = (xmlNodePtr)cnode;
	return (const char*)node->name;
}

/* Get namespace of node */
const char* db_xmlnodeNs(db_xmlnode cnode) {
	xmlNodePtr node = (xmlNodePtr)cnode;
	if (node->ns) {
		return (const char*)node->ns->prefix;
	} else {
		return 0;
	}
}

/* Get parent of node */
db_xmlnode db_xmlnodeParent(db_xmlnode cnode) {
	xmlNodePtr node = (xmlNodePtr)cnode;
	if (node->parent) {
		return (db_xmlnode)node->parent;
	} else {
		return 0;
	}
}

/* Get linenumber of node */
short int db_xmlnodeLine(db_xmlnode cnode) {
	xmlNodePtr node = (xmlNodePtr)cnode;
	return node->line;
}

/* Get content of node */
char* db_xmlnodeContent(db_xmlnode cnode) {
	xmlNodePtr node = (xmlNodePtr)cnode;
	return (char*)xmlNodeGetContent(node);
}

/* Get root of doc */
db_xmlnode db_xmlreaderRoot(db_xmlreader reader) {
	return (db_xmlnode)reader->root;
}

/* Find element in node */
db_xmlnode db_xmlnodeFind(db_xmlnode cnode, const char* element) {
	xmlNodePtr p;
	xmlNodePtr node = (xmlNodePtr)cnode;

	p = node->children;
	while(p) {
		if ((p->type == XML_ELEMENT_NODE) && !strcmp((char*)p->name, element)) {
			return (db_xmlnode)p;
		}
		p = p->next;
	}
	return 0;
}

/* Load int */
int db_xmlnodeInt(db_xmlnode cnode, int* out) {
	char* str;
	int result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.");

	result = -1;

	str = (char*)xmlNodeGetContent(node);
	if (str) {
		*out = atoi(str);
		result = 0;
	} else {
		db_error("node '%s' has no content (expected integer).", node->name);
	}

	return result;
}

/* Load unsigned int */
int db_xmlnodeUint(db_xmlnode cnode, unsigned int* out) {
	char* str;
	int result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.");

	result = -1;

	str = (char*)xmlNodeGetContent(node);
	if (str) {
		*out = atoi(str);
		result = 0;
	} else {
		db_error("node '%s' has no content (expected integer).", node->name);
	}

	return result;
}

/* Load int */
float db_xmlnodeFloat(db_xmlnode cnode, float* out) {
	char* str;
	float result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.");

	result = -1;

	str = (char*)xmlNodeGetContent(node);
	if (str) {
		*out = (float)atof(str);
		result = 0;
	} else {
		db_error("node '%s' has no content (expected float).", node->name);
	}

	return result;
}

/* Load boolean */
int db_xmlnodeBool(db_xmlnode cnode, unsigned int* out) {
	char* str;
	int result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.");

	result = -1;

	str = (char*)xmlNodeGetContent(node);
	if (str) {
		result = 0;
		if (!strcmp("true", str) || !strcmp("TRUE", str)) {
			*out = 1;
		} else if (!strcmp("false", str) || !strcmp("FALSE", str)){
			*out = 0;
		} else {
			result = -1;
			db_error("invalid boolean value '%s' in node '%s'.", str, node->name);
		}
		free(str);
	} else {
		db_error("node '%s' has no content (expected integer).", node->name);
	}

	return result;
}

/* Load string */
char* db_xmlnodeStr(db_xmlnode cnode) {
	char* str;
	xmlNodePtr node = (xmlNodePtr)cnode;

	str = (char*)xmlNodeGetContent(node);
	if (!str) {
		db_error("node %s has no content (expected string).", node->name);
	}

	return str;
}

/* Load char */
int db_xmlnodeAttrChar(db_xmlnode cnode, const char* attribute, char* out) {
	char* str;
	char result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.", "db_xmlnodeAttrChar: Invalid out parameter.");

	result = -1;

	str = (char*)xmlGetProp(node, (xmlChar*)attribute);
	if (str) {
		*out = *str;
		free(str);
		result = 0;
	} else {
		db_error("char attribute '%s' not found in node '%s'.", attribute, node->name);
	}

	return result;
}

/* Load int from attribute */
int db_xmlnodeAttrInt(db_xmlnode cnode, const char* attribute, int* out) {
	char* str;
	int result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.");

	result = -1;

	str = (char*)xmlGetProp(node, (xmlChar*)attribute);
	if (str) {
		*out = atoi(str);
		free(str);
		result = 0;
	} else {
		db_error("integer attribute '%s' not found in node '%s'.", attribute, node->name);
	}

	return result;
}

/* Load unsigned int from attribute */
int db_xmlnodeAttrUint(db_xmlnode cnode, const char* attribute, unsigned int* out) {
	char* str;
	int result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.");

	result = -1;

	str = (char*)xmlGetProp(node, (xmlChar*)attribute);
	if (str) {
		*out = atoi(str);
		free(str);
		result = 0;
	} else {
		db_error("integer attribute '%s' not found in node '%s'.", attribute, node->name);
	}

	return result;
}

/* Load float from attribute */
float db_xmlnodeAttrFloat(db_xmlnode cnode, const char* attribute, float* out) {
	char* str;
	float result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.");

	result = -1;

	str = (char*)xmlGetProp(node, (xmlChar*)attribute);
	if (str) {
		*out = (float)atof(str);
		free(str);
		result = 0;
	} else {
		db_error("float attribute '%s' not found in node '%s'.", attribute, node->name);
	}

	return result;
}
/* Load boolean from attribute */
int db_xmlnodeAttrBool(db_xmlnode cnode, const char* attribute, unsigned int* out) {
	char* str;
	int result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	db_assert(out != 0, "Invalid out parameter.");

	result = -1;

	str = (char*)xmlGetProp(node, (xmlChar*)attribute);
	if (str) {
		result = 0;
		if (!strcmp("true", str) || !strcmp("TRUE", str) || !strcmp("True", str)) {
			*out = 1;
		} else if (!strcmp("false", str) || !strcmp("FALSE", str) || !strcmp("False", str)){
			*out = 0;
		} else {
			result = -1;
			db_error("invalid boolean value '%s' in attribute '%s' of node '%s'.", str, attribute, node->name);
		}
		free(str);
	} else {
		db_error("boolean attribute '%s' not found in node '%s'.", attribute, node->name);
	}

	return result;
}

/* Load string from attribute */
char* db_xmlnodeAttrStr(db_xmlnode cnode, const char* attribute) {
	char* str;
	xmlNodePtr node = (xmlNodePtr)cnode;

	str = (char*)xmlGetProp(node, (xmlChar*)attribute);
	if (!str) {
		db_error("string attribute '%s' not found in node '%s'.", attribute, node->name);
	}

	return str;
}

/* Test for attribute */
int db_xmlnodeAttrTest(db_xmlnode cnode, const char* attribute) {
	char* str;
	int result;
	xmlNodePtr node = (xmlNodePtr)cnode;

	result = 0;
	str = (char*)xmlGetProp(node, (xmlChar*)attribute);
	if (str) {
		result = 1;
		free(str);
	}

	return result;
}

/* Walk attributes */
int db_xmlnodeWalkAttr(db_xmlnode cnode, db_xmlreaderWalkAttrCallback callback, void* userData) {
	xmlNodePtr node = (xmlNodePtr)cnode;
	xmlAttrPtr attr;
	int result;

	result = 1;

	/* Walk attributes on node */
	if (node->properties) {
		attr = node->properties;

		while(result && attr) {
			result = callback((db_string)attr->ns, (db_string)attr->name, (db_string)attr->children->content, userData);
			attr = attr->next;
		}
	}

	return result;
}

/* Walk children */
int db_xmlnodeWalkChildren(db_xmlnode cnode, db_xmlreaderWalkCallback callback, void* userData) {
	xmlNodePtr node = (xmlNodePtr)cnode;
	return db_xmlnodeWalk(node->xmlChildrenNode, callback, userData);
}

/* Walk xml */
int db_xmlnodeWalk(db_xmlnode cnode, db_xmlreaderWalkCallback callback, void* userData) {
	int result = 1;
	xmlNodePtr node = (xmlNodePtr)cnode;

	while(node) {
		if (node->type == XML_ELEMENT_NODE) {
			if (!(result = callback(node, userData))) {
				break;
			}
		}
		node = node->next;
	}

	return result;
}

/* Count children of node */
int db_xmlnodeChildrenCount(db_xmlnode cnode) {
	int n = 0;
	xmlNodePtr child;
	xmlNodePtr node = (xmlNodePtr)cnode;

	child = node->children;
	while(child) {
		if (child->type == XML_ELEMENT_NODE) {
			n++;
		}
		child = child->next;
	}

	return n;
}

db_xmlnode db_xmlnodeGetChild(db_xmlnode cnode, unsigned int childnode) {
	unsigned int n = 0;
	xmlNodePtr child;
	xmlNodePtr node = (xmlNodePtr)cnode;

	child = node->children;
	while(child) {
		if (child->type == XML_ELEMENT_NODE) {
			if (n == childnode) {
				return (db_xmlnode)child;
			}
			n++;
		}
		child = child->next;
	}
	return 0;
}



