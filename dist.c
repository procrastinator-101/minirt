#include <stdio.h>
#include <math.h>

int main()
{
	double x;
	double y;
	printf("enter x : ");
	scanf("%lf", &x);
	printf("enter y : ");
	scanf("\n%lf", &y);
	printf("dist = %lf\n", sqrt(x * x + y * y) * 2);
}
