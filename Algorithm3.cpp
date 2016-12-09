// Algorithm3.cpp : quick sort
//

#include "stdafx.h"
#include <iostream>

template <class T>
void quickSort(T a[], int left, int right) 
{
	int i = left, j = right;
	T tmp;

	//T pivot = a[(left + right) / 2];
	T median;
	T first = a[0];
	T last = a[right];
	T middle = a[(left + right) / 2];
	if ((first >= middle && first <= last) || (first >= last && first <= middle))
	{
		median = first;
	}
	else if ((middle >= first && middle <= last) || (middle >= last && middle <= first))
	{
		median = middle;
	}
	else if ((last >= middle && last <= first) || (last >= first && last <= middle))
	{
		median = last;
	}
	T pivot = median;
	


	/* partition */
	while (i <= j)
	{
		// if "in order" move indices
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;

		if (i <= j)  // if not, swap
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; 	j--; // move indices to next element
		}
	}
	
	/* recursion */
	if (left < j)
		quickSort(a, left, j);

	if (i < right)
		quickSort(a, i, right);
		
	return;
}

int main()
{
	int a[] = { 55, 61, 2, 8, 11, 0, 7, 10, 22, 32 };
	float b[] = { 1.2, 5.6, 12.346, 458.123, 33.0, 123123, 1205.2, 9.8, 22.3 };
	char c[] = { 'e', 'r', 'i', 'c', 'c','h','e','n','a' };
	quickSort <int> (a, 0, 8);
	quickSort <float>(b, 0, 8);
	quickSort <char>(c, 0, 8);

	for (int i = 0; i < 9; i++)
	{
		printf("%i ", a[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		printf("%f", b[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		printf("%c", c[i]);
	}

	getchar();
    return 0;
}

