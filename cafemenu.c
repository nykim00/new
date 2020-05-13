#include <stdio.h>

#include "cafemenu.h"

CAFE* cafes[MAX];
int menu_count = 0;
int piece_count = 0; 
int m_first_available(){
	int i;
	for(i = 0; i < MAX; i++)
		if(cafes[i] == NULL) return i;
	return -1;
}

int m_count(){
	return menu_count;
}

void m_create_file(char* filename){
#ifdef DEBUG 
	printf("[DEBUG] Load File\n");
#endif

	FILE* fp = fopen(filename,"rw");
	if(fp == NULL) {
		printf("\n[ERROR] Do Not search file name \"%s\"\n", filename);
		return ;
	}

	while(1){
		
		char menu[20];
		fscanf(fp, "%s", menu);
		if(feof(fp)) break;

		if(m_search_by_menu(menu)!=NULL){
#ifdef DEBUG
			printf("[DEBUG] duplicate menu name\n");
#endif
			break;
		}
		else if(m_search_by_menu(menu)==NULL){
			int index = m_first_available();
			if(index == -1) return ;

			cafes[index] = (CAFE*)malloc(sizeof(CAFE));
			CAFE* p = cafes[index];

			strcpy(p->menuName, menu);
			fscanf(fp, "%d", &p->category);
			fscanf(fp, "%d", &p->price);
			fscanf(fp, "%d", &p->popular);
			fscanf(fp, "%[^\n]s", p->info);
			menu_count++;
			piece_count++;
#ifdef DEBUG
			printf("[DEBUG] index[%d] %d / %s / %d / %d / %s \n", index, p->category, p->menuName, p->price, p->popular, p->info);
#endif
		}
	}
	fclose(fp);
	printf("\nComplete read %s.txt file!\n", filename );
}

void m_create_keyboard(char* m,int c, int pr, int po, char* in){
#ifdef DEBUG
	printf("[DEBUG] in create keyboard\n");
#endif

	int index = m_first_available();
	if(index == -1) return;

	cafes[index]= (CAFE*)malloc(sizeof(CAFE));
	CAFE* p = cafes[index];
	strcpy(p->menuName, m);
	p->category = c;
	p->price = pr;
	p->popular = po;
	strcpy(p->info, in);
#ifdef DEBUG
	printf("[DEBUG] cafes[%d] menu : %s complete! \n", menu_count, p->menuName);
#endif
	menu_count++;
	piece_count++;
}

CAFE* m_search_by_menu(char* m){
	int i;

	for(i = 0; i < MAX; i++){
		if(cafes[i]!=NULL && strcmp(cafes[i]->menuName , m)==0 )
			return cafes[i];
	}
	
	return NULL;
}

void m_delete_all(){
#ifdef DEBUG
	printf("[DEBUG] in m_delete_all fuction\n");
#endif
	int i;
	int count = m_count();
	for(i = 0 ; i < count ; i ++){
		cafes[i]=NULL;
	}
	menu_count=0;
}

void m_delete_menu(char* m){

	CAFE* p  = m_search_by_menu(m);

	int i, index;
	int count = m_count();

	for(i = 0; i <= count ; i ++){
		if(cafes[i] == p){
			index = i;
			break;
		}
	}
	cafes[index]=NULL;
	menu_count--;
}

void m_update_all(int c, char* m, int price, int pop, char* info, CAFE* p){
#ifdef DEBUG 
	printf("[DEBUG] in m_update_all start update\n");
#endif

	p->category = c;
	strcpy(p->menuName, m);
	p->price = price;
	p->popular = pop;
	strcpy(p->info, info);

#ifdef DEBUG
	printf("[DEBUG] complete update\n");
#endif
	return;
}

void m_update_integer(int c, int change, CAFE* p){
#ifdef DEBUG
	printf("[DEBUG] in m_update_integer start update\n");
#endif

	switch(c){
		case 2:
			p->category = change;
			break;
		case 4:
			p->price = change;
			break;
		case 5:
			p->popular = change;
			break;
		default :
			break;
	}

	return;
}

void m_update_string(int c, char* change, CAFE* p){
#ifdef DEBUG
	printf("[DEBUG] in m_update_string start update\n");
#endif

	switch(c){
		case 3:
		strcpy(p->menuName,change);
			break;
		case 6:
			strcpy(p->info, change);
			break;
		default :
			break;
	}
	return;
}

char* m_getmenu(CAFE* p){
	printf("name menu : %s\n", p->menuName);
	return p->menuName;
}

char* m_getcategory(CAFE* p){
	if(p->category == 1)
		return "[COFFEE]\t";
	else if(p->category == 2)
		return "[NON-COFFEE]";
	else if(p->category == 3)
		return "[DESERT]\t";
	return NULL;
}

int m_getprice(CAFE* p){
	return p->price;
}

char* m_getpopular(CAFE* p){
	if(p->popular == 1)
		return "♡ ";
	else if(p->popular == 2)
		return "♡♡ ";
	return "♡♡♡ ";
}

char* m_getinformation(CAFE* p){
	return p->info;
}

char* m_to_string(CAFE* p){
	static char str[80];
	sprintf(str,"%s %s  / %d /  %s", m_getcategory(p), p->menuName, p->price, m_getpopular(p));
	return str;
}

void m_get_all(CAFE* a[]){
	int i, c=0;
	for(i = 0; i < MAX ; i++){
		if(cafes[i]!=NULL){
			a[c]=cafes[i];
			c++;
		}
	}
}

char* m_list_to_category(int cate_, CAFE* p){
	switch(cate_){
		case 1 :
			if(p->category == 1 ) return m_to_string(p);
			break;
		case 2 :
			if(p->category == 2 ) return m_to_string(p);
			break;
		case 3 :
			if(p->category == 3 ) return m_to_string(p);
	}

	return NULL;
}

void m_sort(){
#ifdef DEBUG
	printf("[DEBUG] in sort(bubble)\n");
#endif

	int i, j;
	CAFE* tmp;
	for(i = 0; i < menu_count - 1 ; i++){
		for(j = 0; j < menu_count - i - 1 ; j++ ){
			if((cafes[j]->category) >  cafes[j+1]->category){
				tmp = cafes[j+1];
				cafes[j+1]=cafes[j];
				cafes[j] = tmp;
			}
		}
	}
}

int m_get_all_by_menu(CAFE* a[], char* m){
#ifdef DEBUG
	printf("[DEBUG] in m_get_all_by_menu\n");
#endif

	int i, c=0;
	for(i=0; i<menu_count; i++){
		if(cafes[i]!=NULL && strstr(cafes[i]->menuName, m)){
			a[c]=cafes[i];
			c++;
		}
	}
	return c;
}

void m_save(char* filename){
	int size = m_count();
	FILE* sfp = fopen(filename, "wt");
	
	fprintf(sfp, "category / Menu Name / price / popular level / infortmation \n\n");
#ifdef DEBUG
	printf("[DEBUG] in m_save and fprintf works normally\n");
#endif

	for(int i = 0 ; i < size ;i++){
		CAFE* p = cafes[i];
		fprintf(sfp, "%s ", m_getcategory(p));
		fprintf(sfp, "%s ", p->menuName);
		fprintf(sfp, "%d ", p->price);
		fprintf(sfp, "%s ", m_getpopular(p));
		fprintf(sfp, "%s\n", p->info);
#ifdef DEBUG
		printf("[DEBUG] cafes[%d] save\n",i);
#endif
	}

	fclose(sfp);
#ifdef DEBUG
	printf("[DEBUG] all complete\n");
#endif
}

int m_piece(){
	int i, j;
	int index = -1;
	
	for(i = 0 ; i < piece_count; i++){
		if(i == piece_count - 1 && cafes[i] == NULL){
			free(cafes[i]);
			piece_count--;
			return 1;
		}
		else if(cafes[i] == NULL){
			index = i;
			break ;
		}
	}
	
	
	int a = 1;
	
#ifdef DEBUG 
	printf("change\n");
#endif

	for(j = index+1 ; j < piece_count ; j++){
		if(j == piece_count - 1 && cafes[j] == NULL){
			a++;
			break;
		}
		else if(cafes[j]==NULL){
			a++;
			continue;
		}
		else{
			cafes[j-a]=cafes[j];
		}
	}

#ifdef DEBUG
	printf("free\n");
#endif

	for(i = 0 ; i < a; i++){
		piece_count--;
		cafes[piece_count] = NULL ;
		free(cafes[piece_count]);
	}

	
	return a;
}
