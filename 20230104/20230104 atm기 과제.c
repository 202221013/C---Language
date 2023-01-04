#include <stdio.h>
void main()
{
	int choice, total, inputMoney, drawMoney;
	printf("초기 금액을 입력해주세요. :");
	scanf_s("%d", &total);
	while (1)
	{
		printf("1.예금 / 2.출금 / 3.잔고 / 4.종료 :");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			printf("현재 금액 : %d원\n", total);
			printf("얼마를 입금하시겠습니까? : ");
			scanf_s("%d", &inputMoney);
			total += inputMoney;
			printf("예금 성공! 현재 금액 : %d원\n\n\n", total);

		}
		else if (choice == 2)
		{
			printf("현재 금액 : %d원\n", total);
			printf("얼마를 출력하시겠습니까? :");
			scanf_s("%d", &drawMoney);
			if (drawMoney > total)
			{
				printf("예금 실패!\n\n\n");

			}
			else
			{
				total -= drawMoney;
				printf("출금 성공! 현재 잔금 : %d원\n\n\n", total);
			}
		}
		else if (choice == 3)
		{
			printf("현재 금액 : %d원\n\n\n", total);
		}
		else if (choice == 4)
		{
			printf("현재 금액 : %d원\n\n\n", total);
			break;
		}
		else
		{
			printf("잘못 입력했습니다.\n\n\n");
		}
	}
	system("pause");
}
