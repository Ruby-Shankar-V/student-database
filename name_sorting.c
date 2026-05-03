#include "header.h"

extern void name_sorting(SLL *hp){
	if(hp == 0){
		pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
		return;
	}
	
	int i, j, c = count(hp);
	SLL *p1 = hp, *p2, temp;
	for(i = 0; i<c; i++)
	{
		p2 = p1 -> next;
		for(j=0; j<c-i-1; j++){
			if(strcmp(p1 -> name, p2 -> name) > 0){

				temp.rollno = p1 -> rollno;
				strcpy(temp.name, p1 -> name);
				temp.percentage = p1 -> percentage;

				p1 -> rollno = p2 -> rollno;
				strcpy(p1 -> name, p2 -> name);
				p1 -> percentage = p2 -> percentage;

				p2 -> rollno = temp.rollno;
				strcpy(p2 -> name, temp.name);
				p2 -> percentage = temp.percentage;
			}
			p2 = p2 -> next;
		}
		p1 = p1 -> next;
	}
 
	while(hp){
		pf("\t%d\t%s\t\t%0.2f\n", hp -> rollno, hp -> name, hp -> percentage);
		hp = hp -> next;
	}

}
