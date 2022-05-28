#include <stdio.h>
#include <stdlib.h>
//<stdio.h>와 <stdlib.h>를 컴파일전에 소스에 확장하도록 지시

#define TRUE 1
#define FALSE 0
//TRUE와 FALSE를 상수 1과 0으로 설정
#define MAXSIZE 10
//MAXSIZE를 상수 10으로 설정

//이중반복을 피하기위한 배열 visited를 전역변수로 선언
int visited[MAXSIZE]={0,};

//GraphNode 구조체 선언
typedef struct GraphNode{
	int key;    //GraphNode의 값을 저장하는 변수
	struct GraphNode* link; //GraphNode의 다음 값을 가르키는 포인터
}GraphNode;

//GraphType 구조체 선언
typedef struct GraphType{
    int index;    //list의 index를 저장하는 변수
    GraphNode* Vlist[MAXSIZE];   //GraphNode의 Vertex 들을 저장하는 list
}GraphType;

//BFS에서 값을 저장하기 위해 Queuetype구조체 선언
typedef struct Queuetype{
    int element[MAXSIZE];  
    int front,rear;
    int size;
}Queuetype;

//Queue를 초기화 하는 함수
void initializeQueue(Queuetype *q)
{
    q->size=0;
    //size 0으로 초기화
    q->front=-1;
    q->rear=-1; 
    //rear?와 front -1로 초기화
    for(int i=0;i<MAXSIZE;i++)
    {   //q의 원소들 전부 0으로 초기화
        q->element[i] = 0;
    }
}

//queue에 item을 추가하는 함수
void enqueue(Queuetype *q,int item)
{
    q->element[++(q->rear)] = item;
    q->size++;
}

//queue에 item을 제거하는 함수
int dequeue(Queuetype *q)
{
    int item;
    item = q->element[++(q->front)];
    q->size--;
    return item;
}

//Graph를 초기화 함수
void Initialize(GraphType* graph)
{
    graph->index = 0; //GraphType의 index를 0으로 초기화
    for(int a=0;a<MAXSIZE;a++)
    {   //GraphType의 list를 NULL로 초기화 (key와 link)
        graph->Vlist[a]=NULL;
    }
}

//Graph에 Vertex를 추가 함수
void InsertVertex(GraphType* graph)
{
    //Graph의 Vertex가 MAXSIZE보다 클때
    if(((graph->index)+1)>MAXSIZE)
    {
        printf("Cannot Insert more Vertex!\n"); //오류 메세지 출력
        return; //NULL 반환
    }
    //index 증가 (정상입력경우)
    graph->index++;    
}

//Graph에 Edge를 추가 함수
void InsertEdge(GraphType* graph,int n1,int n2)
{
    GraphNode* Vertex;
    //연결하려는 Vertex가 존재하지 않는 경우
    if((n1>=graph->index)||(n2>=graph->index))
    {
        printf("Check the Vertex index!\n");    //오류메시지 출력
        return; //NULL 반환
    }
    //Vertex 동적할당후 연결 (정상입력경우)
    Vertex = (GraphNode*)malloc(sizeof(GraphNode));
    Vertex->key = n2;
    Vertex->link = graph->Vlist[n1];
    graph->Vlist[n1] = Vertex;
}

//깊이우선탐색 함수
void DFS(GraphType* graph,int v)
{
    GraphNode* w;
    //GraphNode 포인터 변수 w선언
    visited[v] = 1;
    //이중방문을 피하기 위한 visited 배열에 1 저장
    printf("%d ",v);
    //w를 이용하여 Vlist를 훑는 for문
    for(w = graph->Vlist[v];w;w=w->link)
    {
        if(!visited[w->key])    //방문 하지 않았을 경우
        {
            DFS(graph,w->key);  //해당 인덱스부터 재귀 호출
        }
    }
}

//넓이우선탐색 함수
void BFS(GraphType* graph,int v)
{
    GraphNode *w;
    Queuetype q;
    //GraphNode 포인터 변수 w선언
    //Queuetype 변수 q선언
    initializeQueue(&q);
    visited[v] = TRUE;
    //이중 방문을 피하기 위한 visited배열에 TURE 저장
    printf("%d ",v);
    enqueue(&q,v);
    //q의 크기가 0이 아닐때 반복하는 while문
    while(q.size!=0)
    {
        v=dequeue(&q);
        //v에 dequeue한 값 저장
        for(w=graph->Vlist[v];w;w=w->link) //w를 이용하여 Vlist를 훑는 for문
        {
            if(!visited[w->key])    //방문 하지 않았을 경우
            {
                visited[w->key] = TRUE; //해당 값을 TRUE로 변경
                printf("%d ",w->key);   //값 출력
                enqueue(&q,w->key);     //해당 인덱스 부터 재귀 호출
            }
        }
    }
}

//graph 출력 함수
void PrintGraph(GraphType* Vertex)
{
    for(int i=0;i<Vertex->index;i++)
    {
        GraphNode* temp = Vertex->Vlist[i];
        printf("Vertex[%d]'s adjacent list ",i);
        while(temp != NULL) //temp가 NULL일때까지 반복하는 while문
        {
            printf(" -> %d",temp->key); //temp의 key출력
            temp = temp->link;  //temp를 link로 이동
        }
        printf("\n");
    }
}

//Graph Search 프로그램의  메인함수
int main(void)
{
	char command;	//사용자로부터 명령을 입력받을 command 선언
	int key=0;		//사용자로부터 값을 입력받을 key 선언
    int n1,n2;
	int count = 0; 	//연결리스트를 생성하기 전에 다른 명령을 실행하지 못하도록 막는 변수 count 선언

	printf("[----- [고영민] [2019038003] -----]\n");

    GraphType *node = (GraphType*)malloc(sizeof(GraphType));

	do{// q or Q가 입력되기전까지 실행하는 무한 루프문
		//메뉴 출력
		printf("---------------------------------------------------------------------\n");
		printf("                            Graph Searches                      \n");
		printf("---------------------------------------------------------------------\n");
		printf(" Initialize Graph	   = z\n");
		printf(" Insert Vertex		   = v		Insert Edge		= e\n");
		printf(" Depth First Search	   = d		Breath First Search	= b\n");
		printf(" Print Graph		   = p		Quit 			= q\n");
		printf("---------------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//command값을 사용자로부터 입력 받음

		switch(command) {	//command의 값에 따라 실행하는 switch문
		case 'z': case 'Z':	//command가 z or Z 일때
			Initialize(node);
			break;
		case 'v': case 'V':	//command가 v or V 일때
			InsertVertex(node);
			break;
		case 'e': case 'E':	//command가 e or E 일때
            printf("Enter the Vertex's index : ");
            scanf("%d%d",&n1,&n2);
            InsertEdge(node,n1,n2);
			break;
		case 'd': case 'D':	//command가 d or D 일때
            scanf("%d",&key);
            DFS(node,key);
            printf("\n");
            for(int i=0;i<MAXSIZE;i++)
            {
                visited[i] = 0;
            }
			break;
		case 'b': case 'B':	//command가 b or B 일때
            scanf("%d",&key);
            BFS(node,key);
            printf("\n");
            for(int i=0;i<MAXSIZE;i++)
            {
                visited[i] = 0;
            }
			break;
		case 'p': case 'P':	//command가 p or P 일떄
            PrintGraph(node);
			break;
		case 'q': case 'Q':	//command가 q or Q 일때
            free(node);
			break;
		default:			//command가 잘못 입력 되었을때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;	//1 반환
}