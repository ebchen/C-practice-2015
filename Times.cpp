
#include <iostream>

int main()
{
	bool r;
	char o;
	int x, y, z;
	r = true;
	
	while (r) {
		printf("enter an integer: ");
		scanf("%d", &x);
		printf("enter an integer: ");
		scanf("%d", &y);
		z = x*y;
		printf("the product is %d ", z);
		getchar();
		getchar();
		printf("Do u want to continue? y or n: ");
		o = getchar();
		if (o == 'y') {
			r = true;
		}
		else{
			r = false;
		}
	}
	return 0;	
}