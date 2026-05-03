#include "header.h"

extern void delete_record_name(SLL **hp){
	if(*hp == 0){
		pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
		return;
	}
	
	char str[20];
	pslow("\033[34;1m\tEnter the Name: \033[0m\0", 1000);
	sf("%s", str);
	
	SLL *del = *hp, *prev;
	int c = 0;	
	while(del){
		if(strcmp(str, del -> name) == 0){
			c++;
			pf("\t%d\t%s\t\t%f\n", del -> rollno, del -> name, del -> percentage);
		}
		del = del -> next;	
	}

	if(c != 0){
		delete_record_rollno(hp);	
	}
	else
		pslow("\033[31;1;5m\n\tName Doesn't match with Recourds!\033[0m\n", 1000);			
}
