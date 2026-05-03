#include "header.h"

extern void show_the_list(SLL *hp){
		pslow("\033[36;1m\n\tStudents Record List\033[0m\n", 1000);
	if(hp == 0){
		if(read_file(&hp));
		else{
			pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
			return;
		}
	}
	while(hp){
		pf("\t%d\t%s\t\t\t%0.2f\n", hp -> rollno, hp -> name, hp -> percentage);
		hp = hp -> next;
	}
}
