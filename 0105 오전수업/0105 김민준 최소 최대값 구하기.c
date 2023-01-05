#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int main(void)
{
	int prices[SIZE] = { 0 };
	int idex[SIZE] = { 0 };
	int i, minimum, maximum;


	printf("--------------------------------\n");
	printf("1 2 3 4 5 6 7 8 9 10\n");
	printf("--------------------------------\n");
	srand((unsigned)time(NULL));
	for (i = 0; i < SIZE; i++) {
		prices[i] = (rand() % 10) + 1;
		printf("%-3d ", prices[i]);
	}
	printf("\n\n");

	minimum = prices[0];
	for (i = 1; i < SIZE; i++)
	{
		if (prices[i] < minimum)
			minimum = prices[i];
	}
	printf("최솟값은 %d입니다.\n", minimum);

	maximum = prices[0];
	for (i = 1; i < SIZE; i++)
	{
		if (prices[i] < maximum)
			maximum = prices[i];
	}
	printf("최대값은 %d입니다.\n", maximum);

	for (i = 1; i < SIZE; i++)
	{
		++idex[prices[i]];
	}
	for (i = 1; i < SIZE; i++)
	{
		printf("%d점  %d개\n", i, idex[i]);
	}


	return 0;

}