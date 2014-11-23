/*
 * pingpong.c
 *
 *  Created on: Jul 24, 2013
 *      Author: sander
 */

#include "PingPong__meta.h"
#include "os_thread.h"
#include "db_loader.h"

int main(int argc, char* argv[]) {
	DB_UNUSED(argc);
	DB_UNUSED(argv);

	db_start();

	db_load("os");
	PingPong_load();

	/* Start dispatcher thread */
	os_thread_start((os_thread)pp_pongDispatcher_o);

	/* Initial ping */
	db_updateFrom(pp_pong_o, pp_ping_o);

	/* Wait until thread has finished */
	os_thread_join((os_thread)pp_pongDispatcher_o);

	db_stop();

	return 0;
}
