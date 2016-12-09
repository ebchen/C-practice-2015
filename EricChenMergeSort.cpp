// Merge Sort of Link List
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
class Rnode //node class
{
public:
	int r;
	Rnode *next;
	Rnode() { r = 0; next = nullptr; }
};

void printList(Rnode *pHead)
{
	Rnode *	pCurrent = pHead;

	while (pCurrent != nullptr)
	{
		printf("%i\n", pCurrent->r);
		pCurrent = pCurrent->next;
	};
	putchar('\n');
};

Rnode* mergeSort(Rnode *pHead)
{	//divide
	if (pHead == NULL || pHead -> next == nullptr)
	{
		return pHead;
	}
	Rnode* pLeft = pHead;
	Rnode* pLeftTail = pLeft;
	Rnode* pRight = pHead->next;
	Rnode* pRightTail = pRight;
	Rnode* pNext = pRight->next;
	while (pNext != nullptr)
	{
		pLeftTail -> next = pNext;
		pLeftTail = pNext;
		if (pNext->next == nullptr) break; //if an odd number of elements
		pRightTail -> next= pNext->next;
		pRightTail = pNext->next;
		pNext = pNext->next->next;
	}
	pLeftTail->next = nullptr;
	pRightTail->next = nullptr;	
	Rnode* mergeLeft = mergeSort(pLeft);
	Rnode* mergeRight = mergeSort(pRight);

	//merge
	if (mergeRight == NULL) return mergeLeft; //if only 1 list
	if (mergeLeft == NULL) return mergeRight;
	Rnode* pMergeHead = NULL;
	if (mergeLeft->r <= mergeRight->r) //compares head values
	{
		pMergeHead = mergeLeft;
		mergeLeft = mergeLeft->next;
	}
	else 
	{
		pMergeHead = mergeRight;
		mergeRight = mergeRight->next;
	}
	Rnode* pMergeCurrent = pMergeHead;
	while (mergeLeft != NULL && mergeRight != NULL)
	{
		if (mergeLeft->r <= mergeRight->r)
		{
			pMergeCurrent->next = mergeLeft;
			mergeLeft = mergeLeft->next;
			pMergeCurrent = pMergeCurrent->next;
		}
		else
		{
			pMergeCurrent -> next = mergeRight;
			mergeRight = mergeRight->next;
			pMergeCurrent = pMergeCurrent->next;
		}
	}
	if (mergeLeft != NULL) pMergeCurrent->next = mergeLeft;
	if (mergeRight != NULL)pMergeCurrent->next = mergeRight;

	return pMergeHead;
}

int main()
{
	srand((unsigned)time(NULL)); // randomize the seed
	Rnode *const pHead = new Rnode;
	pHead->r = rand();
	Rnode *pLast = pHead;  // access the last node

						   // generate 10 random numbers and append to the list
	for (int i = 0; i < 9; i++)
	{
		Rnode* pNew = new Rnode; // generate new node
		pNew->r = rand();		// put data, a random number, to it
		pLast->next = pNew;	// connect to the last node
		pLast = pNew;			// update the pLast pointer
	}

	printList(pHead);
	printList(mergeSort(pHead));
	getchar();
	return 0;
}

