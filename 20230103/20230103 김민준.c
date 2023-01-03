// 0103 homework_diceBettinf.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷��� ����ǰų� ����˴ϴ�.
#define _CRT_SECURE_NOWARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dice_roll();
int betting(int left);

int main(void)
{
	int wallet[3] = { 1000,1000,1000 };
	int A_bet = 0, B_bet = 0, C_bet = 0;
	int A_dice = 0, B_dice = 0, C_dice = 0;
	int dice = 0;
	int i = 0;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		A_bet = betting(wallet[0]);
		B_bet = betting(wallet[1]);
		C_bet = betting(wallet[2]);

		wallet[0] -= A_bet;
		wallet[1] -= B_bet;
		wallet[2] -= C_bet;

		A_dice = dice_roll();
		B_dice = dice_roll();
		C_dice = dice_roll();

		printf("A : �ֻ��� �� ���� = %d, ���� = %d\n", A_dice, A_bet);
		printf("B : �ֻ��� �� ���� = %d, ���� = %d\n", B_dice, B_bet);
		printf("C : �ֻ��� �� ���� = %d, ���� = %d\n\n", B_dice, B_bet);

		dice = dice_roll();
		printf("\n������ �ֻ����� �� = %d\n", dice);

		wallet[0] += (A_dice == dice) ? 2 * A_bet : 0;
		wallet[1] += (B_dice == dice) ? 2 * B_bet : 0;
		wallet[2] += (C_dice == dice) ? 2 * C_bet : 0;

		printf("A�� ���� �ǵ� = %d\n", wallet[0]);
		printf("B�� ���� �ǵ� = %d\n", wallet[1]);
		printf("C�� ���� �ǵ� = %d\n", wallet[2]);



	}

}
int dice_roll() {
	return 1 + rand() % 6;
}
int betting(int left) {
	return 100 * (1 + rand() % (left / 2) / 100);
}
