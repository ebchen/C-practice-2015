//
//
#include <iostream>

using namespace std;

void print(int ar[], int sz); 



class Solution
{
public:
	void reverseArray(int data[], int size)
	{
		for (int i = 0; i < size / 2; i++)
		{
			swapper(data, i, size - 1 - i);

		}
	}
	void swapper(int data[], int x, int y)
	{
		data[x] = data[x] ^ data[y];    //xor
		data[y] = data[x] ^ data[y];
		data[x] = data[x] ^ data[y];	
	}
};

int main()
{
	int data[] = { 1, 2, 3, 4, 5 ,6, 7, 8, 9, 10 };
	cout << "Before reversing the array: ";
	print(data, 10);
	Solution().reverseArray(data, 10);
	cout << "After  reversing the array: ";
	print(data, 10);
	//
	// Note: expecting to see something display like the following
	// Before reversing the array: 1, 2, 3, 4, 5 ,6, 7, 8, 9, 10,
	// After  reversing the array: 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
	//
	getchar();
	return 0;
}

// This is the definition.
void print(int ar[], int sz)
{
	cout << "Array[" << sz << "] ";
	for(int i = 0; i < sz; ++i)
	{
		cout << ar[i] << ',';
	}
	cout << endl;
}


