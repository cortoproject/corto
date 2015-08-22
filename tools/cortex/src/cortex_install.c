
#include "cortex_install.h"

cx_int16 cortex_install(int argc, char *argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);
	cx_id cmd;

	cx_setenv("CORTEX_TARGET", "/usr");

	if (cx_fileTest("configure")) {
		/* If installing cortex itself, install buildsystem */
		printf("cortex: installing buildsystem\n");
		system ("mkdir -p /usr/lib/cortex");
		system ("cp -r ./build /usr/lib/cortex/");
	}

	printf("cortex: clearing local files\n");
	sprintf(cmd, "rm -rf ~/.cortex/%s", CORTEX_VERSION);
	system(cmd);

	printf("cortex: installing binaries\n");
	system("rake silent=true");

	if (cx_fileTest("configure")) {
		/* Rename cortex */
		sprintf(cmd, "mv /usr/bin/cortex /usr/bin/cortex.%s", CORTEX_VERSION);
		system(cmd);
		sprintf(cmd, "ln -s /usr/bin/cortex.%s /usr/bin/cortex", CORTEX_VERSION);
		system(cmd);

		/* Rename libcortex.so */
		sprintf(cmd, "mv /usr/lib/libcortex.so /usr/lib/libcortex.so.%s", CORTEX_VERSION);
		system(cmd);
		sprintf(cmd, "ln -s /usr/lib/libcortex.so.%s /usr/lib/libcortex.so", CORTEX_VERSION);
		system(cmd);
	}

	printf("cortex: cleaning up\n");
	system("rake clean &> /dev/null");

	printf("cortex: done!\n");

	return 0;
}

cx_int16 cortex_uninstall(int argc, char *argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);

	cx_setenv("CORTEX_TARGET", "/usr");

	printf("cortex: uninstalling\n");
	system("rake clobber &> /dev/null");

	if (cx_fileTest("configure")) {
		/* If installing cortex itself, install buildsystem */
		printf("cortex: removing buildsystem\n");
		system("rm -rf /usr/lib/cortex");
	}

	printf("cortex: done!\n");

	return 0;
}

