// Merge sort algorithm for Doubly Linked list

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

struct node
{
	int data;
	node* next;
	node* prev;
	node() { next = nullptr; prev = nullptr; }
};
struct both
{
	node* pHead = NULL;
	node* pTail = NULL;
	both() { pHead = NULL; pTail = NULL;}
};
void printList(node* pHead, node* pTail)
{
	printf("From head to tail: ");
	while (pHead != nullptr)
	{
		printf("%d ", pHead->data);
		pHead = pHead->next;
	}
	putchar('\n');

	printf("From tail to head: ");
	while (pTail != nullptr)
	{
		printf("%d ", pTail->data);
		pTail = pTail->prev;
	}
	putchar('\n');
}

both* mergeSort(node* pHead, node* pTail) 
{
	both* pBoth = new both;
	if (pHead == NULL || pHead->next == nullptr || pTail->prev == nullptr)
	{
		pBoth->pHead = pHead;
		pBoth->pTail = pTail;
		return pBoth;
	}
	node* pLeft = pHead;
	node* pRight = pTail;
	while (pLeft != pRight && pLeft->next != pRight)
	{
		pLeft = pLeft->next;
		pRight = pRight->prev;
	}
	if (pLeft == pRight)
	{
		pRight = pRight->next;
		pLeft->next = nullptr;
		pRight->prev = nullptr;
	}
	else
	{
		pLeft->next = nullptr;
		pRight->prev = nullptr;
	}
	//std::cout << "obama ";
	//printList(pHead, pLeft);
	//std::cout << "obama2 ";
	//printList(pRight, pTail);
	both* mergeLeft = mergeSort(pHead, pLeft);
	both* mergeRight = mergeSort(pRight, pTail);
	node* pListHead = NULL;
	node* pListTail = NULL;
	if (mergeLeft == NULL || mergeLeft->pHead == NULL) return mergeRight;
	if (mergeRight == NULL|| mergeRight->pHead == NULL ) return mergeLeft;
	if (mergeLeft->pHead->data <= mergeRight->pHead->data)
	{
		pListHead = mergeLeft->pHead;
		pListTail = pListHead;
		mergeLeft->pHead = mergeLeft->pHead->next;
		if (mergeLeft->pHead != nullptr) mergeLeft->pHead->prev = nullptr;
	}
	else
	{
		pListHead = mergeRight->pHead;
		pListTail = pListHead;
		mergeRight->pHead = mergeRight->pHead->next;
		if (mergeRight->pHead != nullptr) mergeRight->pHead->prev = nullptr;
	}
	pListHead->prev = nullptr;
	while (mergeLeft->pHead != NULL && mergeRight->pHead != NULL)
	{
		if (mergeLeft->pHead->data <= mergeRight->pHead->data)
		{
			pListTail->next = mergeLeft->pHead;
			pListTail->next->prev = pListTail;
			pListTail = pListTail->next;
			mergeLeft->pHead = mergeLeft->pHead->next;
			if(mergeLeft->pHead != NULL)mergeLeft->pHead->prev = nullptr;
		}
		else if (mergeRight->pHead->data < mergeLeft->pHead->data)
		{
			pListTail->next = mergeRight->pHead;
			pListTail->next->prev = pListTail;
			pListTail = pListTail->next;
			mergeRight->pHead = mergeRight->pHead->next;
			if(mergeRight->pHead != NULL) mergeRight->pHead->prev = nullptr;
		}
	}
	if (mergeLeft->pHead != NULL)
	{
		pListTail->next = mergeLeft->pHead;
		pListTail->next->prev = pListTail;

	}
	else if (mergeRight->pHead != NULL)
	{
		pListTail->next = mergeRight->pHead;
		pListTail->next->prev = pListTail;
	}
	while (pListTail->next)
	{
		pListTail = pListTail->next;
	}
	pBoth->pHead = pListHead;
	pBoth->pTail = pListTail;
	return pBoth;
}

int main()
{
	srand((unsigned)time(NULL)); // randomize the seed
	node * pHead = new node;
	pHead->data = rand();
	node *pTail = pHead;  // access the last node

						  // generate random numbers and append to the list
	for (int i = 0; i <5; i++)
	{
		node* pNew = new node;	// generate new node
		pNew->data = rand();	// insert a random number
		pTail->next = pNew;		// tail node next is the new node
		pNew->prev = pTail;		// new node previous is the tail node
		pTail = pNew;			// new node is the tail node now
	}

	printList(pHead, pTail);
	both*result=mergeSort(pHead, pTail);
	printList(result->pHead, result->pTail);
	
	getchar();
	return 0;
}


