// Calculate fibonacci sequence with pointers
//

#include "stdafx.h"
#define ARRAY_SIZE 20
#include<iostream>

static int fibonacciNum[ARRAY_SIZE];

int main(void)
{
	int *pN = fibonacciNum;
	
	*pN = 0;

	pN = &fibonacciNum[1];
	*pN = 1;
	for (int i = 2; i < ARRAY_SIZE; i++)
	{
		pN = &fibonacciNum[i];
		*pN = *(pN - 1) + *(pN - 2);
	}

	pN = &fibonacciNum[0];

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("fibonacci(%d): %d\n", i, *pN++);
	}

	getchar();
	return 0;
}


