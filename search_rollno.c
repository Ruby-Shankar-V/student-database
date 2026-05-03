#include "header.h"

extern void search_rollno(SLL *hp){
	if(hp == 0){
		pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
		return;
	}
		
		int num, c = 0;
		pslow("\033[34;1m\tEnter the RollNo You Want to Modify: \033[0m", 1000);
		sf("%d", &num);

	SLL *srch = hp;
	while(srch){
		if(num == srch -> rollno){
			c++;
			
			pf("\t%d\t%s\t\t%f\n", srch -> rollno, srch -> name, srch -> percentage);

			pslow("\033[34;1m\n\tEnter the New Roll No: \033[0m", 1000);
			sf("%d", &srch -> rollno);

			pslow("\033[32;1;5m\n\tNew Roll No Updated Successfully!\033[0m\n", 1000);
			save(hp);
			return;
			
		}
		srch = srch -> next;
	}

	if(c == 0) 
		pslow("\033[31;1;5m\n\tRollNo Doesn't match with Recourds!\033[0m\n", 1000);
}
