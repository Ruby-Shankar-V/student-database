#include "header.h"

extern void search_name(SLL *hp){
	if(hp == 0){
		pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
		return;
	}
		
		int c = 0;
		char str[20];
		pslow("\033[34;1m\tEnter the Record Name You Want to Modify: \033[0m", 1000);
		sf("%s", str);

	SLL *srch = hp;
	while(srch){
		if(strcmp(str, srch -> name) == 0){
			c++;
			
			pf("\t%d\t%s\t\t%f\n", srch -> rollno, srch -> name, srch -> percentage);

			pslow("\033[34;1m\n\tEnter the New Name: \033[0m", 1000);
			sf("%s", srch -> name);

			pslow("\033[32;1;5m\n\tNew Name Updated Successfully!\033[0m\n", 1000);
			save(hp);
			return;
			
		}
		srch = srch -> next;
	}

	if(c == 0) 
		pslow("\033[31;1;5m\n\tName Doesn't match with Recourds!\033[0m\n", 1000);
}
