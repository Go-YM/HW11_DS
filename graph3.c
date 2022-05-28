#include <stdio.h>
#include <stdlib.h>
//<stdio.h>�� <stdlib.h>�� ���������� �ҽ��� Ȯ���ϵ��� ����

#define TRUE 1
#define FALSE 0
//TRUE�� FALSE�� ��� 1�� 0���� ����
#define MAXSIZE 10
//MAXSIZE�� ��� 10���� ����

//���߹ݺ��� ���ϱ����� �迭 visited�� ���������� ����
int visited[MAXSIZE]={0,};

//GraphNode ����ü ����
typedef struct GraphNode{
	int key;    //GraphNode�� ���� �����ϴ� ����
	struct GraphNode* link; //GraphNode�� ���� ���� ����Ű�� ������
}GraphNode;

//GraphType ����ü ����
typedef struct GraphType{
    int index;    //list�� index�� �����ϴ� ����
    GraphNode* Vlist[MAXSIZE];   //GraphNode�� Vertex ���� �����ϴ� list
}GraphType;

//BFS���� ���� �����ϱ� ���� Queuetype����ü ����
typedef struct Queuetype{
    int element[MAXSIZE];  
    int front,rear;
    int size;
}Queuetype;

//Queue�� �ʱ�ȭ �ϴ� �Լ�
void initializeQueue(Queuetype *q)
{
    q->size=0;
    //size 0���� �ʱ�ȭ
    q->front=-1;
    q->rear=-1; 
    //rear?�� front -1�� �ʱ�ȭ
    for(int i=0;i<MAXSIZE;i++)
    {   //q�� ���ҵ� ���� 0���� �ʱ�ȭ
        q->element[i] = 0;
    }
}

//queue�� item�� �߰��ϴ� �Լ�
void enqueue(Queuetype *q,int item)
{
    q->element[++(q->rear)] = item;
    q->size++;
}

//queue�� item�� �����ϴ� �Լ�
int dequeue(Queuetype *q)
{
    int item;
    item = q->element[++(q->front)];
    q->size--;
    return item;
}

//Graph�� �ʱ�ȭ �Լ�
void Initialize(GraphType* graph)
{
    graph->index = 0; //GraphType�� index�� 0���� �ʱ�ȭ
    for(int a=0;a<MAXSIZE;a++)
    {   //GraphType�� list�� NULL�� �ʱ�ȭ (key�� link)
        graph->Vlist[a]=NULL;
    }
}

//Graph�� Vertex�� �߰� �Լ�
void InsertVertex(GraphType* graph)
{
    //Graph�� Vertex�� MAXSIZE���� Ŭ��
    if(((graph->index)+1)>MAXSIZE)
    {
        printf("Cannot Insert more Vertex!\n"); //���� �޼��� ���
        return; //NULL ��ȯ
    }
    //index ���� (�����Է°��)
    graph->index++;    
}

//Graph�� Edge�� �߰� �Լ�
void InsertEdge(GraphType* graph,int n1,int n2)
{
    GraphNode* Vertex;
    //�����Ϸ��� Vertex�� �������� �ʴ� ���
    if((n1>=graph->index)||(n2>=graph->index))
    {
        printf("Check the Vertex index!\n");    //�����޽��� ���
        return; //NULL ��ȯ
    }
    //Vertex �����Ҵ��� ���� (�����Է°��)
    Vertex = (GraphNode*)malloc(sizeof(GraphNode));
    Vertex->key = n2;
    Vertex->link = graph->Vlist[n1];
    graph->Vlist[n1] = Vertex;
}

//���̿켱Ž�� �Լ�
void DFS(GraphType* graph,int v)
{
    GraphNode* w;
    //GraphNode ������ ���� w����
    visited[v] = 1;
    //���߹湮�� ���ϱ� ���� visited �迭�� 1 ����
    printf("%d ",v);
    //w�� �̿��Ͽ� Vlist�� �ȴ� for��
    for(w = graph->Vlist[v];w;w=w->link)
    {
        if(!visited[w->key])    //�湮 ���� �ʾ��� ���
        {
            DFS(graph,w->key);  //�ش� �ε������� ��� ȣ��
        }
    }
}

//���̿켱Ž�� �Լ�
void BFS(GraphType* graph,int v)
{
    GraphNode *w;
    Queuetype q;
    //GraphNode ������ ���� w����
    //Queuetype ���� q����
    initializeQueue(&q);
    visited[v] = TRUE;
    //���� �湮�� ���ϱ� ���� visited�迭�� TURE ����
    printf("%d ",v);
    enqueue(&q,v);
    //q�� ũ�Ⱑ 0�� �ƴҶ� �ݺ��ϴ� while��
    while(q.size!=0)
    {
        v=dequeue(&q);
        //v�� dequeue�� �� ����
        for(w=graph->Vlist[v];w;w=w->link) //w�� �̿��Ͽ� Vlist�� �ȴ� for��
        {
            if(!visited[w->key])    //�湮 ���� �ʾ��� ���
            {
                visited[w->key] = TRUE; //�ش� ���� TRUE�� ����
                printf("%d ",w->key);   //�� ���
                enqueue(&q,w->key);     //�ش� �ε��� ���� ��� ȣ��
            }
        }
    }
}

//graph ��� �Լ�
void PrintGraph(GraphType* Vertex)
{
    for(int i=0;i<Vertex->index;i++)
    {
        GraphNode* temp = Vertex->Vlist[i];
        printf("Vertex[%d]'s adjacent list ",i);
        while(temp != NULL) //temp�� NULL�϶����� �ݺ��ϴ� while��
        {
            printf(" -> %d",temp->key); //temp�� key���
            temp = temp->link;  //temp�� link�� �̵�
        }
        printf("\n");
    }
}

//Graph Search ���α׷���  �����Լ�
int main(void)
{
	char command;	//����ڷκ��� ����� �Է¹��� command ����
	int key=0;		//����ڷκ��� ���� �Է¹��� key ����
    int n1,n2;
	int count = 0; 	//���Ḯ��Ʈ�� �����ϱ� ���� �ٸ� ����� �������� ���ϵ��� ���� ���� count ����

	printf("[----- [����] [2019038003] -----]\n");

    GraphType *node = (GraphType*)malloc(sizeof(GraphType));

	do{// q or Q�� �ԷµǱ������� �����ϴ� ���� ������
		//�޴� ���
		printf("---------------------------------------------------------------------\n");
		printf("                            Graph Searches                      \n");
		printf("---------------------------------------------------------------------\n");
		printf(" Initialize Graph	   = z\n");
		printf(" Insert Vertex		   = v		Insert Edge		= e\n");
		printf(" Depth First Search	   = d		Breath First Search	= b\n");
		printf(" Print Graph		   = p		Quit 			= q\n");
		printf("---------------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//command���� ����ڷκ��� �Է� ����

		switch(command) {	//command�� ���� ���� �����ϴ� switch��
		case 'z': case 'Z':	//command�� z or Z �϶�
			Initialize(node);
			break;
		case 'v': case 'V':	//command�� v or V �϶�
			InsertVertex(node);
			break;
		case 'e': case 'E':	//command�� e or E �϶�
            printf("Enter the Vertex's index : ");
            scanf("%d%d",&n1,&n2);
            InsertEdge(node,n1,n2);
			break;
		case 'd': case 'D':	//command�� d or D �϶�
            scanf("%d",&key);
            DFS(node,key);
            printf("\n");
            for(int i=0;i<MAXSIZE;i++)
            {
                visited[i] = 0;
            }
			break;
		case 'b': case 'B':	//command�� b or B �϶�
            scanf("%d",&key);
            BFS(node,key);
            printf("\n");
            for(int i=0;i<MAXSIZE;i++)
            {
                visited[i] = 0;
            }
			break;
		case 'p': case 'P':	//command�� p or P �ϋ�
            PrintGraph(node);
			break;
		case 'q': case 'Q':	//command�� q or Q �϶�
            free(node);
			break;
		default:			//command�� �߸� �Է� �Ǿ�����
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;	//1 ��ȯ
}