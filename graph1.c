#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//<stdio.h>,<stdlib.h>,<string.h>를 컴파일 전에 소스에 확장 하도록 지시

typedef struct Node{
	int key;
	struct Node* link;
}Node;

void Initialize()
{
	
}

void InsertVertex()
{

}

void InsertEdge()
{

}

void DFS()
{

}

void BFS()
{

}

void Quie()
{

}

//Graph Search 프로그램의  메인함수
int main(void)
{
	char command;	//사용자로부터 명령을 입력받을 command 선언
	int key;		//사용자로부터 값을 입력받을 key 선언
	int count = 0; 	//연결리스트를 생성하기 전에 다른 명령을 실행하지 못하도록 막는 변수 count 선언

	printf("[----- [고영민] [2019038003] -----]\n");

	do{// q or Q가 입력되기전까지 실행하는 무한 루프문
		//메뉴 출력
		printf("-----------------------------------------------------------\n");
		printf("                       Graph Searches                      \n");
		printf("-----------------------------------------------------------\n");
		printf(" Initialize Graph	   = z\n");
		printf(" Insert Vertex		   = v			Insert Edge			= e\n");
		printf(" Depth First Search	   = d			Breath First Search	= b\n");
		printf(" Print Graph		   = p			Quit 				= q\n");
		printf("-----------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//command값을 사용자로부터 입력 받음

		switch(command) {	//command의 값에 따라 실행하는 switch문
		case 'z': case 'Z':	//command가 z or Z 일때
			Initialize();
			break;
		case 'v': case 'V':	//command가 v or V 일때
			scanf("%d",&key);
			InsertVertex();
			break;
		case 'e': case 'E':	//command가 e or E 일때
			break;
		case 'd': case 'D':	//command가 d or D 일때
			break;
		case 'b': case 'B':	//command가 b or B 일때
			break;
		case 'p': case 'P':	//command가 p or P 일떄
			break;
		case 'q': case 'Q':	//command가 q or Q 일때
			break;
		default:			//command가 잘못 입력 되었을때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;	//1 반환
}