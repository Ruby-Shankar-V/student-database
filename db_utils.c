#include "header.h"

/* ─────────────────────────────────────────────────────
 * get_db_path()
 * Builds full path: /home/<user>/.dbase/student.dat
 * and stores it in 'buf' (max 'size' bytes)
 * ───────────────────────────────────────────────────── */
void get_db_path(char *buf, size_t size){
	const char *home = getenv("HOME");
	if(home == NULL) home = "/root";      /* fallback for pure root shell */
	snprintf(buf, size, "%s/.dbase/student.dat", home);
}

/* ─────────────────────────────────────────────────────
 * init_db_dir()
 * Creates ~/.dbase/ directory if it does not exist.
 * Permission 0700 → only owner (user) can enter it.
 * ───────────────────────────────────────────────────── */
void init_db_dir(void){
	const char *home = getenv("HOME");
	if(home == NULL) home = "/root";
	char dir[512];
	snprintf(dir, sizeof(dir), "%s/.dbase", home);
	mkdir(dir, 0700);   /* silently ignored if already exists */
}
