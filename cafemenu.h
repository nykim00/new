#ifndef CAFEMENU_H
#define CAFEMENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX 100

typedef struct {
	char menuName[20]; // 메뉴의 이름
	int category; // 메뉴의 카테고리 (1.COFFE 2.NON-COFFEE 3.DESERT)
	int price; // 메뉴의 가격
	int popular; // 메뉴가 유명한 정도
	char info[100]; // 메뉴의 부가적인 설명
}CAFE;

void m_sort(); // [list] sort
int m_first_available(); // [create]
int m_count();
void m_create_keyboard(char* m,int c, int pr, int po, char* in);
void m_create_file(char * filename); // [file read] make menu
CAFE* m_search_by_menu(char* m);
void m_update_all(int c, char* m, int price, int pop, char*info, CAFE* p); // 특정 cafes 의 모든 내용을 변경
void m_update_integer(int c,  int change, CAFE* p); // 특정 cafes의 int type의 내용을 변경
void m_update_string(int c, char* change, CAFE* p); // 특정 cafes의 char* type의 내용을 변경
void m_delete_all(); // 전체 struct 삭제
void m_delete_menu(char* m); // 한개의 cafes struct 삭제
char* m_getmenu(CAFE* p); 
char* m_getcategory(CAFE* p); // [read]
int m_getprice(CAFE* p); // [read]
char* m_getpopular(CAFE* p); // [read]
char* m_getinformation(CAFE* p); // [read]
char* m_to_string(CAFE* p); // [list] search
char* m_list_to_category(int cate_, CAFE* p); // [list]
void m_get_all(CAFE* a[]); 
int m_get_all_by_menu(CAFE* a[], char* m);
void m_save(char* filename); // [file write] make .txt file
int m_piece(); // 비어있는 메모리 정리

#endif
