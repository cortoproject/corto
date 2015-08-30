
#include "corto_install.h"

static cx_bool corto_validProject(void) {
	if (!cx_fileTest("rakefile")) {
		cx_error("corto: need a valid project directory to install (no rakefile found)!");
		goto error;
	}
	return TRUE;
error:
	return FALSE;
}

static void corto_promptPassword(void) {
	cx_pid pid = cx_procrun("sudo", (char*[]){"sudo", "true", NULL});
	cx_procwait(pid, NULL);
}

cx_int16 corto_install(int argc, char *argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);
	cx_bool buildingCorto = FALSE;

	if (!corto_validProject()) {
		goto error;
	}

	/* Write installation script */
	FILE *install = fopen("install.sh", "w");
	if (!install) {
		cx_error("corto: failed to create installation script (check permissions)");
		goto error;
	}

	/* Install build system from source */
	if (cx_fileTest("configure") && cx_fileTest("build")) {
		/* If installing corto itself, install buildsystem */
		fprintf(install, "mkdir -p /usr/lib/corto/%s\n", CORTO_VERSION);
		fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
		fprintf(install, "cp -r ./build /usr/lib/corto/%s\n", CORTO_VERSION);
		fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
		buildingCorto = TRUE;
	}

	/* Set the build target to the global environment */
	fprintf(install, "export CORTO_TARGET=/usr\n");
	fprintf(install, "export CORTO_HOME=/usr\n");
	fprintf(install, "export CORTO_BUILD=/usr/lib/corto/%s/build\n", CORTO_VERSION);
	fprintf(install, "export CORTO_VERSION=%s\n", CORTO_VERSION);
	fprintf(install, "export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin\n");

	/* Build libraries to global environment */
	fprintf(install, "rake silent=true\n");
	fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");

	if (buildingCorto) {
		/* Rename corto */
		fprintf(install, "mv -f /usr/bin/corto /usr/bin/corto.%s\n", CORTO_VERSION);
		fprintf(install, "ln -s /usr/bin/corto.%s /usr/bin/corto\n", CORTO_VERSION);
		fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");

		/* Rename libcorto.so */
		fprintf(install, "mv -f /usr/lib/libcorto.so /usr/lib/libcorto.so.%s\n", CORTO_VERSION);
		fprintf(install, "ln -s /usr/lib/libcorto.so.%s /usr/lib/libcorto.so\n", CORTO_VERSION);
		fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
	}

	fprintf(install, "rake clean 2> /dev/null\n");
	fprintf(install, "rc=$?; if [ $rc != 0 ]; then exit $rc; fi\n");
	fclose(install);

	corto_promptPassword();

	cx_pid pid = cx_procrun("sudo", (char*[]){"sudo", "sh", "install.sh", NULL});
	cx_char progress[] = {'|', '/', '-', '\\'};
	cx_int32 procresult, i = 0;
	cx_int8 rc = 0;
	printf("corto: installing...  ");
	while(!(procresult = cx_proccheck(pid, &rc))) {
		i++;
		printf("\b%c", progress[i % 4]);
		fflush(stdout);
		cx_sleep(0, 200000000);
	}

	if ((procresult != -1) || rc) {
		printf("failed :(\n");
		printf("  A likely cause is an error in the corto code. Try doing a regular corto\n");
		printf("  build first (type 'rake') and see if that works. If the issue persists,\n");
		printf("  please file an issue in our GitHub repository!\n");
	} else {
		cx_rm("install.sh");
		printf("\bdone!\n");
	}

	return 0;
error:
	return -1;
}

cx_int16 corto_uninstall(int argc, char *argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);

	if (!corto_validProject()) {
		goto error;
	}

	/* Write installation script */
	FILE *uninstall = fopen("uninstall.sh", "w");
	if (!uninstall) {
		cx_error("corto: failed to create uninstall script (check permissions)");
		goto error;
	}

	/* Set the build target to the global environment */
	fprintf(uninstall, "export CORTO_TARGET=/usr\n");
	fprintf(uninstall, "export CORTO_HOME=/usr\n");
	fprintf(uninstall, "export CORTO_BUILD=/usr/lib/corto/%s/build\n", CORTO_VERSION);
	fprintf(uninstall, "export CORTO_VERSION=%s\n", CORTO_VERSION);
	fprintf(uninstall, "export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin\n");
	fprintf(uninstall, "rake clobber 2> /dev/null\n");

	/* Also remove from local environment */
	fprintf(uninstall, "export CORTO_TARGET=~/.corto\n");
	fprintf(uninstall, "rake clobber 2> /dev/null\n");

	if (cx_fileTest("configure") && cx_fileTest("build")) {
		fprintf(uninstall, "rm -rf /usr/lib/corto");
		fprintf(uninstall, "rm -rf ~/.corto");
	}

	fclose(uninstall);

	corto_promptPassword();

	cx_pid pid = cx_procrun("sudo", (char*[]){"sudo", "sh", "uninstall.sh", NULL});
	cx_char progress[] = {'|', '/', '-', '\\'};
	cx_int32 i = 0;
	printf("corto: uninstalling...  ");
	while(!cx_proccheck(pid, NULL)) {
		i++;
		printf("\b%c", progress[i % 4]);
		fflush(stdout);
		cx_sleep(0, 200000000);
	}
	cx_rm("uninstall.sh");
	printf("\bdone!\n");

	return 0;
error:
	return -1;
}

cx_int16 corto_locate(int argc, char* argv[]) {
	cx_string location;

	if (argc <= 1) {
		printf("corto: please provide a package name\n");
		goto error;
	}

	location = cx_locate(argv[1]);

	if (location) {
		printf("corto: '%s' => '%s'\n", argv[1], location);
	} else {
		printf("corto: package '%s' not found\n", argv[1]);
		goto error;
	}

	return 0;
error:
	return -1;
}

cx_int16 corto_tar(int argc, char* argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);

	if (!corto_validProject()) {
		goto error;
	}

	/* Write installation script */
	FILE *tar = fopen("tar.sh", "w");
	if (!tar) {
		cx_error("corto: failed to create tar script (check permissions)");
		goto error;
	}

	/* Set the build target to the global environment */
	fprintf(tar, "export CORTO_TARGET=/usr\n");
	fprintf(tar, "export CORTO_HOME=/usr\n");
	fprintf(tar, "export CORTO_BUILD=/usr/lib/corto/%s/build\n", CORTO_VERSION);
	fprintf(tar, "export CORTO_VERSION=%s\n", CORTO_VERSION);
	fprintf(tar, "export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin\n");
	fprintf(tar, "rake collect\n");
	fprintf(tar, "DIR=`pwd`\n");
	fprintf(tar, "cd ~/.corto/pack\n");
	fprintf(tar, "tar -zcf $DIR/corto.tar.gz .\n");
	fprintf(tar, "rm -rf ~/.corto/pack\n");
	fclose(tar);

	corto_promptPassword();

	cx_pid pid = cx_procrun("sudo", (char*[]){"sudo", "sh", "tar.sh", NULL});
	cx_char progress[] = {'|', '/', '-', '\\'};
	cx_int32 i = 0;
	printf("corto: tarring...  ");
	while(!cx_proccheck(pid, NULL)) {
		i++;
		printf("\b%c", progress[i % 4]);
		fflush(stdout);
		cx_sleep(0, 200000000);
	}
	cx_rm("tar.sh");
	printf("\bdone!\n");

	return 0;
error:
	return -1;
}

cx_int16 corto_untar(int argc, char* argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);

	/* Write installation script */
	FILE *tar = fopen("untar.sh", "w");
	if (!tar) {
		cx_error("corto: failed to create tar script (check permissions)");
		goto error;
	}

	/* Set the build target to the global environment */
	fprintf(tar, "export CORTO_TARGET=/usr\n");
	fprintf(tar, "export CORTO_HOME=/usr\n");
	fprintf(tar, "export CORTO_BUILD=/usr/lib/corto/%s/build\n", CORTO_VERSION);
	fprintf(tar, "export CORTO_VERSION=%s\n", CORTO_VERSION);
	fprintf(tar, "export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin\n");
	fprintf(tar, "tar -zxf %s -C /usr\n", argv[1]);
	fclose(tar);

	corto_promptPassword();

	cx_pid pid = cx_procrun("sudo", (char*[]){"sudo", "sh", "untar.sh", NULL});
	cx_char progress[] = {'|', '/', '-', '\\'};
	cx_int32 i = 0;
	printf("corto: untarring...  ");
	while(!cx_proccheck(pid, NULL)) {
		i++;
		printf("\b%c", progress[i % 4]);
		fflush(stdout);
		cx_sleep(0, 200000000);
	}
	cx_rm("untar.sh");
	printf("\bdone!\n");

	return 0;
error:
	return -1;
}

void corto_installHelp(void) {
    printf("Usage: corto install\n");
    printf("\n");
    printf("This command installs your project (component or package) to\n");
    printf("the global environment (/usr). Only run this command when you want to\n");
    printf("make your project available for other users. Run this command from the\n");
    printf("root directory of your project.\n");
    printf("\n");
    printf("Note: installation requires root priviledges.\n");
    printf("\n");
}

void corto_uninstallHelp(void) {
    printf("Usage: corto uninstall\n");
    printf("\n");
    printf("This command removes your project (component or package) from\n");
    printf("the global environment (/usr).\n");
    printf("\n");
    printf("Note that uninstalling requires root priviledges.\n");
    printf("\n");
}

void corto_tarHelp(void) {
    printf("Usage: corto tar\n");
    printf("\n");
    printf("This command packs up your project in a redistributable tar. You\n");
    printf("will need to install your project before calling 'corto tar'.\n");
    printf("To install the tarfile, use 'corto untar'.\n");
    printf("\n");
}

void corto_untarHelp(void) {
    printf("Usage: corto untar\n");
    printf("\n");
    printf("This command installs the contents of a tarfile to the global\n");
    printf("environment (/usr). Be sure to only use tarfiles that are created\n");
    printf("with 'corto tar'.\n");
    printf("\n");
    printf("Note: installation requires root priviledges.\n");
    printf("\n");
}


