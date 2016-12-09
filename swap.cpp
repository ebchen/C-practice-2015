//
// swap() using 
// - pointers
// - references
//
#include <iostream>

void swap_ptr(int* p1, int* p2)
{
	int temp = *p1 ;
	*p1 = *p2;
	*p2 = temp;

}

void swap_ref(int &r1, int &r2)
{
	int temp = r1;
	r1 = r2;
	r2 = temp;
}

int main()
{
	int i = 88;
	int j = 99;
	std::cout << "i=" << i << ",j=" << j << std::endl;
	swap_ptr(&i, &j);
	std::cout << "i=" << i << ",j=" << j << std::endl;
	swap_ref(i, j);
	std::cout << "i=" << i << ",j=" << j << std::endl;
	getchar();
	return 0;
}
