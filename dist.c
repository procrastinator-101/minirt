#include <stdio.h>
#include <math.h>

int main()
{
	printf("enter x : ");
	double x = scanf("%lf", &x);
	printf("enter y : ");
	double y = scanf("\n%lf", &y);
	printf("dist = %lf\n", sqrt(x * x + y * y) * 2);
}
