#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float n, k;
	while (1)
	{
		printf("\n학점(4.3,  종료:음수):");
		scanf("%f", &n);
		if (n < 0) break;
		k = 100 / 4.3 * n;
		printf("학점:%.1f --> 100만점 환산: %.1f\n", n, k);
	}
	return 0;
}
