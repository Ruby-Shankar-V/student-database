#include "header.h"

extern int count(SLL *hp){
	SLL *t = hp;	
	int c = 0;
	while(t){
		c++;
		t = t -> next;
	}
	return c;
}
