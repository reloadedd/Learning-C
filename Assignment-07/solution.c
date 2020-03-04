#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	float a, b, c, x1, x2;

	printf("Enter the value of variable 'A' >>> ");
	scanf("%f", &a);
	printf("Enter the value of variable 'B' >>> ");
	scanf("%f", &b);
	printf("Enter the value of variable 'C' >>> ");
	scanf("%f", &c);

	x1 = -(b / (2 * a)) + sqrt(pow((b / (2 * a)), 2) - (c / a));
	x2 = -(b / (2 * a)) - sqrt(pow((b / (	2 * a)), 2) - (c / a));

	printf("The solution using the '-' operator is: %f\n", x1);
	printf("The solution using the '+' operator is: %f\n", x2);
	return 0;
}