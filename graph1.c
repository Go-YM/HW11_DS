#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//<stdio.h>,<stdlib.h>,<string.h>�� ������ ���� �ҽ��� Ȯ�� �ϵ��� ����

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

//Graph Search ���α׷���  �����Լ�
int main(void)
{
	char command;	//����ڷκ��� ����� �Է¹��� command ����
	int key;		//����ڷκ��� ���� �Է¹��� key ����
	int count = 0; 	//���Ḯ��Ʈ�� �����ϱ� ���� �ٸ� ����� �������� ���ϵ��� ���� ���� count ����

	printf("[----- [����] [2019038003] -----]\n");

	do{// q or Q�� �ԷµǱ������� �����ϴ� ���� ������
		//�޴� ���
		printf("-----------------------------------------------------------\n");
		printf("                       Graph Searches                      \n");
		printf("-----------------------------------------------------------\n");
		printf(" Initialize Graph	   = z\n");
		printf(" Insert Vertex		   = v			Insert Edge			= e\n");
		printf(" Depth First Search	   = d			Breath First Search	= b\n");
		printf(" Print Graph		   = p			Quit 				= q\n");
		printf("-----------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//command���� ����ڷκ��� �Է� ����

		switch(command) {	//command�� ���� ���� �����ϴ� switch��
		case 'z': case 'Z':	//command�� z or Z �϶�
			Initialize();
			break;
		case 'v': case 'V':	//command�� v or V �϶�
			scanf("%d",&key);
			InsertVertex();
			break;
		case 'e': case 'E':	//command�� e or E �϶�
			break;
		case 'd': case 'D':	//command�� d or D �϶�
			break;
		case 'b': case 'B':	//command�� b or B �϶�
			break;
		case 'p': case 'P':	//command�� p or P �ϋ�
			break;
		case 'q': case 'Q':	//command�� q or Q �϶�
			break;
		default:			//command�� �߸� �Է� �Ǿ�����
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;	//1 ��ȯ
}