#include "header.h"

extern void delete_all(SLL **hp){
	if(*hp == 0){
		pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
		return;
	}
	SLL *del = *hp;
	int c = 1;
	while(del){
		*hp = del -> next;
		free(del);
		pslow("\033[31;1m", 1000);
		pf("\tRecord %d Successfully Deleted!", c++);
		pslow("\033[0m\n", 1000);
		del = *hp;
	}
	pslow("\033[32;1;5m\tSuccessfully All Records Deleted!\033[0m\n", 1000);
	save(*hp);
}
