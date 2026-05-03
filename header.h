#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>   
#include <math.h>
/* ── db_utils.h ── */
#include <sys/stat.h>    /* mkdir, chmod  */
#include <sys/types.h>   /* chown, getuid, getgid */
#include <pwd.h>         /* getpwuid      */
#include <grp.h>         /* getgrgid      */

#define pf printf
#define sf scanf


typedef struct student{
	int rollno;
	char name[20];
	float percentage;
	struct student *next;
}SLL;

extern int c;
extern void get_db_path(char *buf, size_t size);
extern void init_db_dir(void);

void pslow(const char *, int);
void add_new_record(SLL **);
void show_the_list(SLL *);
void save(SLL *);
void delete_record_rollno(SLL **);
void delete_record_name(SLL **);
void delete_all(SLL **);
void reverse_list(SLL *);
int count(SLL *);
int read_file(SLL **);
int read_file_rollno(SLL **);
void search_rollno(SLL *);
void search_name(SLL *);
void search_percentage(SLL *);
void rollno_sorting(SLL *);
void name_sorting(SLL *);
void percentage_sorting(SLL *);

#endif

