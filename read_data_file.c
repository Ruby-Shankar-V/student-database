#include "header.h"

extern int read_file(SLL **hp){
	char path[512];

	get_db_path(path, sizeof(path));  /* ~/.dbase/student.dat */

	FILE *fp = fopen(path, "r");
	if(fp == NULL){
		/* First run — no file yet, that's fine */
		return 0;
	}

	SLL *new = NULL;

	while(1){
		new = malloc(sizeof(SLL));
		if(new == NULL){
			pf("\033[31;1m\n\tError: Memory allocation failed!\033[0m\n");
			fclose(fp);
			return -1;
		}

		if(fscanf(fp, "%d %49s %f",
			&new->rollno,
			new->name,
			&new->percentage) != 3){
			free(new);
			break;
		}

		new->next = NULL;

		/* Append to end of linked list */
		if(*hp == NULL){
			*hp = new;
		} else {
			SLL *last = *hp;
			while(last->next)
				last = last->next;
			last->next = new;
		}
	}

	fclose(fp);
	return 1;
}