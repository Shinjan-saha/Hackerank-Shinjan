#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a, b;
    double x, y;
    scanf("%d %d %lf %lf", &a, &b, &x, &y);
    printf("%d %d\n%0.1lf %0.1lf", a+b, (a-b), x+y, (x-y));
    return 0;
}
