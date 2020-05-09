# CRUD KIOSK Project - june-may
-------------

## 프로젝트 계획이유
> 카페를 자주가는 고객으로서 메뉴가 많다면 어떤 메뉴가 있는지 파악하기 조차 어려운 경우가 많았습니다. 하지만 KIOSK를 사용 했을 경우에는 메뉴를 전체적으로 파악하기 쉬워 선택하기 편했던 기억이 있었습니다. 
> 이러한 기억을 바탕으로 프로젝트를 개발하게 되었습니다.
> 고객의 입장에서 계획했던 프로그램은 직접 관리 할 수 있는 관리자가 필요하다는 것을 느낄 수 있었고 카페의 사장과 직원들을 위해서 쉽게 메뉴를 추가하고 삭제하고 수정할 수 있는 기능을 구현해야 했습니다. 계획을 하면서  자연스럽게 많은 기능을 포함하게 되었고 가장 처음으로 계획한 큰 프로젝트가 되었습니다.
> 
> 이 프로그램은 다양한 기능을 담고 있습니다.
> KIOSK project는 손님과 카페 관리자가 손쉽게 메뉴를 접근 할 수 있는 기능들이 구현되어있습니다.  
> 카페에서 손님이  사용하는 KIOSK의 역할과 카페 관리자가 메뉴의 데이터를 다룰 때에 필요한 기능을 담고 있습니다.
> 카페 관리자는 CRUD 기능과 함께 메뉴 정렬, 단어별 검색, 주문내역 출력, 주문내역 수정 등의 기능을 사용 할 수 있습니다. 
> 카페의 손님은 읽기기능과 단어별 검색, 메뉴를 주문할 수 있는 기능을 사용 할 수 있습니다. 
> KIOSK 프로그램을 통해서 손님과 카페 관리자가 손쉽게 메뉴에 관한 기능을 관리할 수 있었으면 좋겠습니다. 



## Makefile 실행 설명
------------

1. 실행 파일 이름 : main

1.1 디버깅을 사용할 경우 
	
	$ make 
	$ ./main

1.2 디버깅을 사용하지 않을 경우 

	$ make main
	$ ./main



## KIOSK Project 기능 설명
------------


### [mode 선택 기능]
--------------

1. Manager 기능-> 관리자가 사용하는 기능(메뉴추가, 업데이트, 삭제, 주문내역 확인 등)
2. Guest 기능 -> 손님이 사용하는 기능(메뉴확인, 주문하기 등)
3. 나가기 기능 -> KIOSK 종료


### [Manager, 카페 관리자  기능]
---------------

1. Create
	+ file에서 메뉴를 읽어서 메뉴를 추가하는 기능 
	+ 직접 메뉴 이름, 카테고리, 가격, 인기정도, 설명을 입력하여 추가하는 기능
	
2. Read(menu, information)
	+ menu의 이름을 입력하면 카테고리, 이름, 가격, 인기정도를 출력시켜주는 기능
	+ menu의 이름을 입력하면 설명을 출력시켜주는 기능
	
3. Update
	+ menu의 전체적인 내용을 수정 할 수 있는 기능
	+ menu의 이름을 수정 할 수 있는 기능
	+ menu의 카테고리를 수정 할 수 있는 기능
	+ menu의 가격을 수정 할 수 있는 기능
	+ menu의 인기정도를 수정 할 수 있는 기능
	+ menu의 설명을 수정 할 수 있는 기능

4. Delete
	+ 전체 menu를 삭제하는 기능
	+ 삭제하고 싶은 menu의 이름을 입력하면, 입력한 menu를 삭제하는 기능

5. List(all)
	+ 전체 menu의 카테고리, 이름, 가격, 인기정도를 확인 할 수 있는 기능


6. List(category)
	+ 원하는 카테고리를 입력하면, 그 카테고리에 있는 menu의 카테고리, 이름, 가격, 인기정도를 확인 할 수 있는 기능

7. Search(menu)
	+ 단어나, 알파벳을 입력하면 입력한 내용이 포함되어있는 menu를 출력해주는 기능

8. Sort
	+ 카테고리별로 정렬해주는 기능

9. Save
	+ 현재 메뉴를 text 파일로 저장 할 수 있는 기능

10. Piece sort
	+ 삭제한 데이터의 빈공간을 정리해주는 기능

11. Order check
	+ 손님이 주문한 내역을 확인 할 수 있는 기능(손님의 별명, 주문한 메뉴, 제공완료 여부 출력)

12. Order update
	+ 손님에게 주문한 메뉴를 제공한 경우 제공 완료 여부를 변경 할 수 있게 해주는 기능

0. quit
	+ Manager mode와 Guest mode를 선택하는 화면으로  나갈 수 있는 기능 

### [Guest mode, 손님  기능]
-----------------

1. Read(menu, information)
	+ menu의 이름을 입력하면 카테고리, 이름, 가격, 인기정도를 출력시켜주는 기능
	+ menu의 이름을 입력하면 설명을 출력시켜주는 기능

2. List(all)
	+ 전체 menu의 카테고리, 이름, 가격, 인기정도를 확인 할 수 있는 기능

3. List(category)
	+ 원하는 카테고리를 입력하면, 그 카테고리에 있는 menu의 카테고리, 이름, 가격, 인기정도를 확인 할 수 있는 기능

4. Search(menu)
	+ 단어나, 알파벳을 입력하면 입력한 내용이 포함되어있는 menu를 출력해주는 기능

5. Order
	+ 별명을 입력한 후에 원하는 메뉴의 이름을 입력하면 주문 할 수 있는 기능

0. quit
	+ Manager mode와 Guest mode를 선택하는 화면으로 나갈 수 있는 기능 



------------------------------------------	
지금까지 june-may의 CRUDKIOSK Project에 대한 README 파일 내용이었습니다.

봐주셔서 감사합니다!

