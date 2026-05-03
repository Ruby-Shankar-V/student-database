#include "header.h"

extern void reverse_list(SLL *hp){
			pslow("\033[36;1m\n\tStudents Record List\033[0m\n", 1000);
	if(hp == 0){
		pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
		return;
	}
	int i, j, c = count(hp);
	SLL *t = NULL;
	for(i = 0; i<c; i++){
		t = hp;
		for(j=0; j<c-i-1; j++)
			t = t -> next;
		pslow("\033[37;1m", 1000);
		pf("\t%d\t%s\t\t%0.2f", t -> rollno, t -> name, t -> percentage);
		pslow("\033[0m\n", 1000);
	}
	save(hp);
}
