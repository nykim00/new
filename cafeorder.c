#include <stdio.h>

#include "cafeorder.h"

ORDER* orders[MAX_O];
int order_count = 0 ; 

int o_first_available(){
	int i;
	for(i = 0 ; i < MAX_O ; i++)
		if(orders[i] == NULL) return i;
	return -1;
}

int o_count(){
	return order_count;
}

void o_ordering(char* guest, char* menu){

#ifdef DEBUG
	printf("[DEBUG] in odering\n");
#endif

	int index = o_first_available();
	if(index == -1 ){
		printf("SOLD OUT.. sorry see u!\n"); 
		return ;
	}

	orders[index] = (ORDER*)malloc(sizeof(ORDER));
	ORDER* p = orders[index];
	strcpy(p->guest, guest);
	strcpy(p->guestMenu, menu);
	p->clear = 0 ;

#ifdef DEBUG
	printf("[DEBUG] orders[%d] guest nickname : %s complete! \n", order_count, p->guest);
#endif
	order_count++;
}

ORDER* o_search_by_guest(char* n){
	int i;
	for(i = 0 ; i < MAX_O ; i++){
		if(orders[i]!=NULL && strcmp(orders[i]->guest, n)==0)
			return orders[i];
	}

	return NULL;
}


void o_get_all(ORDER* a[]){
	int i, c = 0;

	for(i = 0 ; i < MAX_O; i++){
		if(orders[i]!=NULL){
			a[c]=orders[i];
			c++;
		}
	}
}

char* o_to_string(ORDER* p){
	
	static char str[sizeof(ORDER)];
	sprintf(str, "[%s] %s / %s", p->guest, p->guestMenu, o_getclear(p));
	return str;
}

char* o_getclear(ORDER* p){
	if(p->clear != 0)
		return "COMPLETE :)";

	return "PREPARING :(";
}

void o_update_clear(ORDER* p, int clear_){
	p->clear = clear_;
}
