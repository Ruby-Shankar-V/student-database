#include "header.h"

extern void delete_record_rollno(SLL **hp){
	
	if(*hp == 0){
		pslow("\033[31;1;5m\n\tNo Recourds Found!\033[0m\n", 1000);
		return;
	}
		//show_the_list(*hp);
		int num, i =1, flag = 0;
		pslow("\033[34;1m\tEnter the RollNo You Want to Delete: \033[0m", 1000);
		sf("%d", &num);

		SLL *del = *hp, *prev; 
	while(del){
		if(num == del->rollno){
			flag = 1;
			if(del == *hp)
				*hp = del -> next;
			else
				prev -> next = del -> next;
	
			free(del);
			pslow("\033[32;1;5m\tSuccessfully Record Deleted!\033[0m\n", 1000);
			break;
		}
		prev = del;
		del = del -> next;
	}
	if(!flag){
		pslow("\033[31;1;5m\n\tRollNo Doesn't match with Recourds!\033[0m\n", 1000);	
		return;
	}

	/*SLL *temp = *hp;
	while(temp){
		temp -> rollno = i++;
		temp = temp -> next;
	}*/
		
	show_the_list(*hp);
	save(*hp);
}
