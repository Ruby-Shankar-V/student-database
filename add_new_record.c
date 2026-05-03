#include "header.h"

extern void add_new_record(SLL **hp)
{
	int rn = 1,  i;
	SLL *new = malloc(sizeof(SLL));
	SLL *last, *temp;

	pslow("\033[34;1m\tEnter the Student Name & Percentage: \033[0m", 1000);
	sf("%s%f", new -> name, &new -> percentage);

	new -> next = 0;
	if(*hp == 0){
		new -> rollno = 1;
		*hp = new;
		save(*hp);
		return;
	}

	//finding largest rollno
	last = *hp;
	while(last){
		if(last -> rollno > rn) 
			rn = last ->rollno;
		last = last -> next;		
	}

	for(i = 1; i<=rn; i++){
		int c = 0;
		temp = *hp;
		
		while(temp){
			if (i == temp -> rollno){
				c = 1;
			break;
			}
			temp = temp -> next;
		}

		if(c==0){
			new -> rollno = i;
			last = *hp;
			while(last -> next)
				last = last -> next;

			last -> next = new;
			save(*hp);
			return;
		}
	}

	new -> rollno = rn +1;
	last = *hp;
	while(last -> next)
		last = last -> next;

	last -> next = new;
	save(*hp);
}	
