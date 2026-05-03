#include "header.h"

extern void save(SLL *hp){
	SLL *temp = hp;
	char path[512];

	get_db_path(path, sizeof(path));  /* ~/.dbase/student.dat */

	FILE *fp = fopen(path, "w");
	if(fp == NULL){
		pf("\033[31;1;5m\n\tError: Could not open file for saving!\033[0m\n");
		pf("\033[33;1m\tPath: %s\033[0m\n", path);
		return;
	}

	while(temp){
		fprintf(fp, "%d %s %.2f\n",
			temp->rollno,
			temp->name,
			temp->percentage);
		temp = temp->next;
	}

	fclose(fp);

	/* Lock the file: owner = root, permissions = 440
	 * (root can read/write via program, user can only read,
	 *  deletion requires sudo)                              */
	chown(path, 0, getgid());   /* root owns it             */
	chmod(path, 0440);          /* r--r----- root:usergroup */

	pslow("\033[32;1;5m\n\tRecords Saved Successfully!\033[0m\n", 1000);
	pf("\033[33;1m\tSaved to: %s\033[0m\n", path);
}