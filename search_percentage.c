#include "header.h"

extern void search_percentage(SLL *hp){
	if(hp == 0){
		pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
		return;
	}
		
		float num, c = 0;
		pslow("\033[34;1m\tEnter the Record Percentage(%) You Want to Modify: \033[0m", 1000);
		sf("%f", &num);

	SLL *srch = hp;
	while(srch){
		if(fabs(num - srch->percentage) < 0.0001){
			c++;
			
			pf("\t%d\t%s\t\t%f\n", srch -> rollno, srch -> name, srch -> percentage);

			pslow("\033[34;1m\n\tEnter the New Percentage: \033[0m", 1000);
			sf("%f", &srch -> percentage);

			pslow("\033[32;1;5m\n\tNew Percentage Updated Successfully!\033[0m\n", 1000);
			save(hp);
			return;
			
		}
		srch = srch -> next;
	}

	if(c == 0) 
		pslow("\033[31;1;5m\n\tPercentage Doesn't match with Recourds!\033[0m\n", 1000);
}
