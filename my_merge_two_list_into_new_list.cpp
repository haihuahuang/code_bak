
#include <iostream>
#include <stdio.h>

typedef struct _Node
{
	int value;
	struct _Node *next;
}Node;

Node *MergeList(Node *listA, Node *listB);
void PrintList(Node *head);

int main()
{
	Node lista, nodea, listb, nodeb, nodec;
	lista.value = 2;
	nodea.value = 2;
	nodec.value = 19;
	lista.next = &nodea;
	nodea.next = &nodec;
	nodec.next = NULL;
	listb.value = 3;
	nodeb.value = 4;
	listb.next = &nodeb;
	nodeb.next = NULL;

	Node *listc = MergeList( &lista, &listb );
	PrintList(listc);
	system("pause");
	return 0;
}


/*
@brief merge two sorted lists to a new list which is sorted , too !

@param   in : listA 
@param   in : listB

@return  pHead  the new list of head
*/
Node *MergeList(Node *listA, Node *listB)
{
	Node *pHead = (Node *)malloc(sizeof(Node));
	if ( NULL == pHead )
	{
		printf("error, line %d malloc failed \n", __LINE__);
		return NULL;
	}
	pHead->next = NULL;

	Node *pNode = NULL;
	Node *pLink = pHead;

	// if the list head just is without data use 
	listA = NULL != listA ? listA->next : listA;
	listB = NULL != listB ? listB->next : listB;

	while( NULL != listA && NULL != listB )
	{
		pNode = (Node *)malloc(sizeof(Node));
		if ( NULL == pNode )
		{
			printf("error, line %d malloc failed \n", __LINE__);
			return pHead;
		}

		if ( listA->value <= listB->value )
		{
			pNode->value = listA->value;
			listA = listA->next;
		}
		else
		{
			pNode->value = listB->value;
			listB = listB->next;
		}
		pNode->next = NULL;
		pLink->next = pNode;
		pLink = pLink->next;
	}
			
	while ( NULL != listA )
	{
		pNode = (Node *)malloc(sizeof(Node));
		if ( NULL == pNode )
		{
			printf("error, line %d malloc failed \n", __LINE__);
			return pHead;
		}

		pNode->value = listA->value;
		listA = listA->next;
		pNode->next = NULL;
		pLink->next = pNode;
		pLink = pLink->next;
	}

	while ( NULL != listB )
	{
		pNode = (Node *)malloc(sizeof(Node));
		if ( NULL == pNode )
		{
			printf("error, line %d malloc failed \n", __LINE__);
			return pHead;
		}

		pNode->value = listB->value;
		listB = listB->next;
		pNode->next = NULL;
		pLink->next = pNode;
		pLink = pLink->next;
	}

	return pHead;
}

void PrintList(Node *head)
{
	if ( NULL == head )
	{
		printf("error, list is NULL\n");
		return ;
	}

	// if the list head just is without data use 
	head = head->next;

	while( NULL != head )
	{
		printf("%d\t", head->value);
		head = head->next;
	}
	printf("\n");
}