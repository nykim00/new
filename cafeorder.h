#ifndef CAFEORDER_H
#define CAFEORDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>                     
#include <malloc.h>  

#define MAX_O 10

typedef struct{
	char guest[20];
	char guestMenu[20];
	int clear;
}ORDER;

int o_first_available(); // 추가할 수 있는 가장 빠른orders 포인터 찾기
int	o_count(); // 주문개수 count
void o_ordering(char* guest, char* menu); // 손님의 주문 list 추가
ORDER* o_search_by_guest(char* n); // 손님의 별명의 포인터 값을 찾아줌
void o_get_all(ORDER* a[]); // 주문이 들어온 내역을 확인
char* o_to_string(ORDER* p); // 주문된 내역을 string으로 변경시켜줌 
char* o_getclear(ORDER* p); // 손님의 주문 완료 여부 반환
void o_update_clear(ORDER* p, int clear); // 손님의 주문 완성여부 수정

#endif
