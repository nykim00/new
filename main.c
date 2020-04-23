#include "cafemenu.h"
#include "cafeorder.h"

void Manager();
void Guest();
void create(); // create
void read(); // read
void update();
void delete();
void list_all(); //read
void list_category(); //read
void search_menu(); //read
void list_sort(); //read
void save();
void piece();
void order_check();
void order_update();
void order_guest();

int main(){
	int person;
	while(1){
		printf("Manager(1) / Guest(2) / quit(0) > ");
		scanf("%d", &person);

		if(person == 1 ) Manager();
		else if(person == 2) Guest();
		else 
			return 0;
	}
}

void Manager(){
	int kiosk;
	while(1){
		printf("\n*********************************************************************************************************\n");
		printf("KIOSK MENU[MANAGER] : 1.Create 2.Read(menu, information) 3.Update 4.Delete 5.List(all) 6.List(category)\n");
		printf("7.Search(menu) 8.Sort 9.Save 10.Piece Sort 11.Order Check 12.Order Update 0.quit");
		printf("\n*********************************************************************************************************\n");
		printf("\nEnter menu num > ");
		scanf("%d", &kiosk);

		switch(kiosk){
			case 1:
				create();
				break;
			case 2:
				read();
				break;
			case 3:
				update();
				break;
			case 4:
				delete();
				break;
			case 5:
				list_all();
				break;
			case 6:
				list_category();
				break;
			case 7:
				search_menu();
				break;
			case 8:
				list_sort();
				break;
			case 9:
				save();
				break;
			case 10:
				piece();
				break;
			case 11:
				order_check();
				break;
			case 12:
				order_update();
				break;
			default :
				return ;
		}
	}
}

void Guest(){
	int kiosk;

	while(1){
		printf("\n****************************************************************************************************\n");
		printf("\nKIOSK MENU[GUEST] : 1.Read(menu, informatiom) 2.List(all) 3.List(category) 4.Search(menu) 5.Order 0. quit\n");
		printf("\n****************************************************************************************************\n");
		printf("\nEnter menu num > ");
		scanf("%d", &kiosk);

		switch(kiosk){
			case 1:
				read();
				break;
			case 2:
				list_all();
				break;
			case 3:
				list_category();
				break;
			case 4:
				search_menu();
				break;
			case 5:
				order_guest();
				break;
			default :
				return ;
		}
	}
}

void create(){
	int choice;
	printf("\n1.load file 2. wirte keyboard > ");
	scanf("%d", &choice);

	if(choice == 1){
		char filename[20];
		printf("Enter file name to load > ");
		scanf("%s", filename);
		m_create_file(filename);
	}

	else{
		int category;
		char menu[20];
		int  price;
		int popular;
		char info[100];

		while(getchar()!='\n');
		printf("Menu Name > ");
		scanf("%s", menu);
		if(m_search_by_menu(menu)){
			printf("\n[DUPLICATED MENU NAME !]\n");
			return;
		}

		printf("Enter Category(1.COFFEE 2.NON-COFFEE 3.DESERT)> ");
		scanf("%d", &category);
		printf("Menu Price > ");
		scanf("%d",&price);
		printf("Popular level(1:soso 2.good 3.best) > ");
		scanf("%d", &popular);
		printf("Menu Information > ");
		while(getchar()!='\n');
		fgets(info, sizeof(info), stdin);	
		m_create_keyboard(menu,category, price, popular, info);

		printf("** Create Menu! **\n\n");
	}
}

void read(){
	int choice;
	char menu[20];
	printf("\n1.Read Menu(detail) 2.Read Menu Information(explain) > ");
	scanf("%d", &choice);
	printf("Menu name > ");
	scanf("%s", menu);

	CAFE* p = m_search_by_menu(menu);
	if(choice == 1 && p){
		printf("\n\n<%s's info.>\n\n",menu);
		printf("Category : %s \n", m_getcategory(p));
		printf("Price : %dwon \n", m_getprice(p));
		printf("Popular level : %s \n", m_getpopular(p));
		printf("-----------------------------------------\n\n");
#ifdef DEBUG
		printf("[DEBUG] READ COMPLETE !\n\n");
#endif
	}
	else if(choice == 2 && p){
		printf("\n<%s Information>\n\n%s \n\n", menu, m_getinformation(p));
	}
	else{
		printf("\n[%s] IS NOT MENU\n",menu);
		return ;
	}
}

void update(){
	int choice;
	int category, price, popular;
	char menu[20], info[100];

	printf("Enter update \n1.all 2.category 3.menu name 4.price 5.popular level 6.information > ");
	scanf("%d", &choice);

	printf("Enter update menu name > ");
	scanf("%s", menu);
	if(!m_search_by_menu(menu)){
		printf("\n[NO SEARCH MENU!]\n");
		return ;
	}
	CAFE* p = m_search_by_menu(menu);

	switch(choice){
		case 1:
			printf("Enter category (1.COFFEE 2.NON-COFFEE 3.DESERT) > ");
			scanf("%d", &category);
			printf("Enter menu name > ");
			scanf("%s", menu);
			printf("Enter price > ");
			scanf("%d", &price);
			printf("Enter popular level (1.Soso 2.Good 3.Great) > ");
			scanf("%d", &popular);
			while(getchar()!='\n');
			printf("Enter information > ");
			fgets(info, sizeof(info), stdin);
			m_update_all(category, menu, price, popular, info, p);
			break;
		case 2:
			printf("Enter category (1.COFFEE 2.NON-COFFEE 3.DESERT) > ");
			scanf("%d", &category);
			m_update_integer(choice, category, p);
			break;
		case 3:
			printf("Enter New menu name > ");
			scanf("%s", menu);
			m_update_string(choice, menu, p);
			break;
		case 4:
			printf("Enter price > ");
			scanf("%d", &price);
			m_update_integer(choice, price, p);
			break;
		case 5:
			printf("Enter popular level > ");
			scanf("%d", &popular);
			m_update_integer(choice, popular, p);
			break;
		case 6:
			printf("Enter information > ");
			while(getchar()!='\n');
			fgets(info, sizeof(info), stdin);
			m_update_string(choice, info, p);
			break;
		default :
			break;
	}

	return ;
}

void delete(){
	int choice;

	printf("1.all delete 2.delete one menu > ");
	scanf("%d", &choice);
	if(choice !=1 && choice != 2) return;

	if(choice == 1){
		m_delete_all();
		printf("\nCOMPLETE ALL DELETE\n");
	}
	else if(choice == 2){
		char menu[20];
		printf("Enter delete menu name > ");
		scanf("%s", menu);
		m_delete_menu(menu);
	}

	return;
}

void list_all(){
	int list_count = m_count();
	CAFE* records[MAX];
	m_get_all(records);
	printf("\n [Category] Menu name / price / popular level \n\n");
	for(int i=0; i < list_count ; i++){
		CAFE* p = records[i];
		printf("%d. %s\n", i + 1, m_to_string(p));
	}
#ifdef DEBUG
	printf("\n\n[DEBUG] Show Complelte List !\n\n");
#endif
}

void list_category(){
	int choice;
	int i, j=1;
	int list_count = m_count();
	printf("Enter Category (1.COFFEE 2.NON-COFFEE 3.DESERT) : ");
	scanf("%d", &choice);
	printf("\n");
	CAFE* records[MAX];
	m_get_all(records);
	for(i=0; i < list_count ; i++){
		CAFE* p = records[i];
		if(p && m_list_to_category(choice, p)){
			printf("%d. %s\n",j,m_list_to_category(choice, p));
			j++;
		}
	}

	printf("\n");
}

void list_sort(){
	printf("\n");
	m_sort();
	printf("\nCOMPLETE SORT!\n");
}

void search_menu(){
	char menu[20];
	printf("\nEnter Search Menu > ");
	scanf("%s", menu);

	CAFE* records[MAX];
	int size = m_get_all_by_menu(records, menu);
	printf("\n<SEARCH %d MENU>\n", size);
	for(int i=0; i<size; i++){
		CAFE* p = records[i];
		printf("%d. %s", i+1, m_to_string(p));
		printf("\n");
	}
	printf("\n");
}

void save(){
	char filename[20];
	printf("\nEnter File Name > ");
	scanf("%s", filename);
	m_save(filename);
	printf("\n[Save menu in %s !]\n\n",filename);
}

void piece(){
	int choice, piece_return;

	printf("\nStart cleaning up the memory? (1.YES 0.NO) ");
	scanf("%d", &choice);
	
	if(choice == 0) return ;
	
	piece_return = m_piece();
	
	if(piece_return == -1){
		printf("\nNo memory cleanup is required!\n");
		return ;
	}

	printf("\nMemory organaized number of %d !\n", piece_return);
	
	return;
}

void order_check(){
	if(o_first_available() == 0){
		printf("\nHAVE NOT ORDER..\n");
		return ;
	}

	int list_count = o_count();
	ORDER* records[MAX];
	o_get_all(records);
	printf("\n");	
	for(int i = 0 ; i < list_count ; i++){
		ORDER* p = records[i];
		printf("%d. %s\n", i+1, o_to_string(p));
	}
#ifdef DEBUG
	printf("\n\n[Show Complete List !]\n\n");
#endif
}

void order_update(){
	if(o_first_available()== 0){
		printf("\nHAVE NOT ORDER..\n");
		return ;
	}
	printf("\n");
	char guest[20];
	int choice;
	order_check();

	while(1){
		printf("\nEnter gets nickname > ");
		scanf("%s", guest);
		if(!o_search_by_guest(guest)){
			printf("No Search guest Nickname!\n");
		}
		else
			break;
	}
	
	printf("Did you offer the menu to the guest? (1.YES 0.NO) > ");
	scanf("%d", &choice);
	
	o_update_clear(o_search_by_guest(guest),choice);
#ifdef DEBUG
	printf("[DEBUG] complete update!\n");
#endif
}

void order_guest(){
	
	char guest[20];
	char menu[20];
	
	while(1){
		
		printf("\nEnter Nickname > ");
		scanf("%s", guest);
		if(o_search_by_guest(guest)){
			printf("[Duplication Nickname, try again!]\n");
		}
		else
			break;
	}
	printf("\n");
	list_all(); // menu 전체를 보여줌
	
	while(1){
		printf("\n\nEnter menu name > ");
		scanf("%s", menu);

		if(!m_search_by_menu(menu)){
			printf("\nNo search menu, try again !\n");
		}	
		else 
			break;
	}
	
	o_ordering(guest, menu);
}
