#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>                                  // rand �Լ� ������� ����
#include <time.h>                                    // time �Լ� ������� ����
#define SIZE 5
#define SIZE2 25
void initialize();                                   // ������ �ʱ�ȭ
void set_rand(int* array);
void swap(int* x, int* y);
void erase_bingo(int arr[5][5], int number); // ���õ� ���ڸ� ����� �Լ�
void print_bingo(int arr[5][5]);
void print_winner(int winner);
int get_number(int from);                    // 0: user, 1: computer
int checked[25];                                     // = ����������
int count = 0;
int check_bingo(int arr[5][5]);              // ���õ� ������ ��ġ�� Ȯ���ϴ� �Լ�
int ubingo[5][5];                                    // ������� ������ = ��������
int cbingo[5][5];                                    // ��ǻ���� ������
void main() {
    int number, uwin, cwin;
    initialize();                                // ������ �ʱ�ȭ
    do {
        printf("--<����� ������>--\n"); print_bingo(ubingo);       // ������� ������ ���
        number = get_number(0);                                             // ������� ��ȣ ����
        erase_bingo(ubingo, number);
        erase_bingo(cbingo, number);
        number = get_number(1);                                             // ��ǻ���� ��ȣ ����
        erase_bingo(ubingo, number);
        erase_bingo(cbingo, number);
        // ���� �ϼ� Ȯ��
        uwin = check_bingo(ubingo);
        cwin = check_bingo(cbingo);
    } while ((uwin == 0) && (cwin == 0));                // 1�� �Ǹ� ���ڰ� ����Ŵϱ� �Ʒ��� ���� (0:����, 1:����ϼ�)
    printf("--<����� ���>-- \n"); print_bingo(ubingo); // ������� ������ ���
    printf("--<��ǻ�� ���>-- \n"); print_bingo(cbingo); // ��ǻ���� ������ ���
    print_winner(cwin * 2 + uwin);
    // ����ڰ� �̱��(uwin=1), case=1
    // ��ǻ�Ͱ� �̱��(cwin=1), case=2
    // ����(uwin=cwin=1), case=3, �� �ܴ̿� ����(default)
}
void initialize() {                                         // ������ �ʱ�ȭ �Լ�
    srand((unsigned int)time(NULL));
    set_rand((int*)ubingo);
    set_rand((int*)cbingo);
}
void set_rand(int* array) {
    int i;
    for (i = 0; i < SIZE2; i++) {
        array[i] = i + 1;
    }
    for (i = 0; i < SIZE2; i++) {
        swap(&array[i], &array[rand() % 25]);
    }
}
void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void erase_bingo(int arr[5][5], int number) {        // �Է¹��� number�� ���� ���� 0���� ����� �Լ�
    int x, y;
    for (y = 0; y < SIZE; y++) {                                      // x,y�� ������ �ٲ㰡�鼭 number�� ������ Ȯ��
        for (x = 0; x < SIZE; x++) {
            if (arr[y][x] == number) {
                arr[y][x] = 0;
            }
        }
    }
}
void print_bingo(int arr[5][5]) {            // ������ ����ϴ� �Լ�
    int x, y;
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            if (arr[y][x] != -1) {        //-1�� ������ ���� ����. �׳� �ظ��ϸ� ������ ���
                printf("%7d", arr[y][x]);
            }
            else {                                       // ������ ����ε�, ��찡 �ظ��ϸ� ����
                printf("XerrorX");
            }
        }
        printf("\n\n");
    }
}
void print_winner(int winner) {                      // ���ڸ� ����ϴ� �Լ�
    switch (winner) {
    case 1:                                                     // uwin=1�϶�
        printf("����ڰ� �̰���ϴ�.\n");
        break;
    case 2:                                                     // cwin=1�϶�
        printf("��ǻ�Ͱ� �̰���ϴ�.\n");
        break;
    case 3:                                                     //uwin=cwin=1�϶�
        printf("�����ϴ�.\n");
        break;
    default:                                                    //����??
        printf("err\n");
        break;
    }
}
int get_number(int frm) {                            // ���ڸ� �Է¹޴� �Լ�
    int number;
    int x, retry;
    do {
        retry = 0;
        if (frm == 0) {                              // 0: user, 1: computer
            printf(">> 1~25 ������ ���ڸ� �Է��ϼ��� :__");
            scanf("%d", &number);
            if (number < 1 || number > 25) {
                retry = 1;                            // retry=1�̸� �Է¿��� �ٽ� �Է��ϰ� �ؾ���
            }
        }
        else {                                               // ��ǻ�Ͱ� �Է��ϴ� �κ�
            number = rand() % 25 + 1;
        }
        if (retry == 0) {
            for (x = 0; x < count; x++) {
                if (checked[x] == number) {
                    retry = 1;
                    break;
                }
            }
        }
    } while (retry == 1);                        //retry=1�̸�, �ٽ� �Է��ؾ��ϹǷ� do�������� ���ư�����
    checked[count++] = number;
    if (frm == 0) {
        printf("> ����ڰ� '%d'�� �����߽��ϴ�. \n", number);
    }
    else {
        printf("> ��ǻ�Ͱ� '%d'�� �����߽��ϴ�. \n\n", number);
    }
    return number;
}
int check_bingo(int arr[5][5]) {             // ������ Ȯ���ϴ� �Լ�
    int x, y, sum;                                       //�� ���� ���� 0�� �Ǹ� �����̹Ƿ� sum ���� ����
    for (y = 0; y < SIZE; y++) {                       // x�� Ȯ��
        sum = 0;                                             // �� �ٸ��� ���� ���ؾ��ϹǷ� for���� �ȿ� sum �ʱ�ȭ
        for (x = 0; x < SIZE; x++) {
            sum += arr[y][x];
        }
        if (sum == 0) {
            return 1;
        }
    }
    for (x = 0; x < SIZE; x++) {                       // y�� Ȯ��
        sum = 0;
        for (y = 0; y < SIZE; y++) {
            sum += arr[y][x];
        }
        if (sum == 0) {
            return 1;
        }
    }
    sum = 0;                                                    // �밢���� ���ٻ��̹Ƿ� for���� �ۿ��� sum �ʱ�ȭ
    for (x = 0; x < SIZE; x++) {                              // �밢�� Ȯ��
        sum += arr[x][x];
    }
    if (sum == 0) {
        return 1;
    }
    sum = 0;
    for (x = 0; x < SIZE; x++) {                       // �밢�� Ȯ��
        sum += arr[x][SIZE - x - 1];
    }
    if (sum == 0) {
        return 1;
    }
    return 0;                                                   // check_bingo = 0�̸�, ���� ���� �����̹Ƿ� main�Լ����� do~while�� �� ����� �ݺ���
}