#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>                                  // rand 함수 헤더파일 선언
#include <time.h>                                    // time 함수 헤더파일 선언
#define SIZE 5
#define SIZE2 25
void initialize();                                   // 빙고판 초기화
void set_rand(int* array);
void swap(int* x, int* y);
void erase_bingo(int arr[5][5], int number); // 선택된 숫자를 지우는 함수
void print_bingo(int arr[5][5]);
void print_winner(int winner);
int get_number(int from);                    // 0: user, 1: computer
int checked[25];                                     // = 전역변수들
int count = 0;
int check_bingo(int arr[5][5]);              // 선택된 숫자의 위치를 확인하는 함수
int ubingo[5][5];                                    // 사용자의 빙고판 = 전역변수
int cbingo[5][5];                                    // 컴퓨터의 빙고판
void main() {
    int number, uwin, cwin;
    initialize();                                // 빙고판 초기화
    do {
        printf("--<사용자 빙고판>--\n"); print_bingo(ubingo);       // 사용자의 빙고판 출력
        number = get_number(0);                                             // 사용자의 번호 선택
        erase_bingo(ubingo, number);
        erase_bingo(cbingo, number);
        number = get_number(1);                                             // 컴퓨터의 번호 선택
        erase_bingo(ubingo, number);
        erase_bingo(cbingo, number);
        // 빙고 완성 확인
        uwin = check_bingo(ubingo);
        cwin = check_bingo(cbingo);
    } while ((uwin == 0) && (cwin == 0));                // 1이 되면 승자가 생긴거니까 아래로 진행 (0:아직, 1:빙고완성)
    printf("--<사용자 결과>-- \n"); print_bingo(ubingo); // 사용자의 빙고판 출력
    printf("--<컴퓨터 결과>-- \n"); print_bingo(cbingo); // 컴퓨터의 빙고판 출력
    print_winner(cwin * 2 + uwin);
    // 사용자가 이기면(uwin=1), case=1
    // 컴퓨터가 이기면(cwin=1), case=2
    // 비기면(uwin=cwin=1), case=3, 그 이외는 에러(default)
}
void initialize() {                                         // 빙고판 초기화 함수
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
void erase_bingo(int arr[5][5], int number) {        // 입력받은 number와 같은 수를 0으로 만드는 함수
    int x, y;
    for (y = 0; y < SIZE; y++) {                                      // x,y를 일일이 바꿔가면서 number와 같은지 확인
        for (x = 0; x < SIZE; x++) {
            if (arr[y][x] == number) {
                arr[y][x] = 0;
            }
        }
    }
}
void print_bingo(int arr[5][5]) {            // 빙고판 출력하는 함수
    int x, y;
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            if (arr[y][x] != -1) {        //-1인 이유는 딱히 없음. 그냥 왠만하면 무조건 출력
                printf("%7d", arr[y][x]);
            }
            else {                                       // 에러난 경우인데, 경우가 왠만하면 없음
                printf("XerrorX");
            }
        }
        printf("\n\n");
    }
}
void print_winner(int winner) {                      // 승자를 출력하는 함수
    switch (winner) {
    case 1:                                                     // uwin=1일때
        printf("사용자가 이겼습니다.\n");
        break;
    case 2:                                                     // cwin=1일때
        printf("컴퓨터가 이겼습니다.\n");
        break;
    case 3:                                                     //uwin=cwin=1일때
        printf("비겼습니다.\n");
        break;
    default:                                                    //에러??
        printf("err\n");
        break;
    }
}
int get_number(int frm) {                            // 숫자를 입력받는 함수
    int number;
    int x, retry;
    do {
        retry = 0;
        if (frm == 0) {                              // 0: user, 1: computer
            printf(">> 1~25 사이의 숫자를 입력하세요 :__");
            scanf("%d", &number);
            if (number < 1 || number > 25) {
                retry = 1;                            // retry=1이면 입력에러 다시 입력하게 해야함
            }
        }
        else {                                               // 컴퓨터가 입력하는 부분
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
    } while (retry == 1);                        //retry=1이면, 다시 입력해야하므로 do구문으로 돌아가게함
    checked[count++] = number;
    if (frm == 0) {
        printf("> 사용자가 '%d'를 선택했습니다. \n", number);
    }
    else {
        printf("> 컴퓨터가 '%d'를 선택했습니다. \n\n", number);
    }
    return number;
}
int check_bingo(int arr[5][5]) {             // 빙고판 확인하는 함수
    int x, y, sum;                                       //한 줄의 합이 0이 되면 빙고이므로 sum 변수 선언
    for (y = 0; y < SIZE; y++) {                       // x축 확인
        sum = 0;                                             // 각 줄마다 합을 구해야하므로 for구문 안에 sum 초기화
        for (x = 0; x < SIZE; x++) {
            sum += arr[y][x];
        }
        if (sum == 0) {
            return 1;
        }
    }
    for (x = 0; x < SIZE; x++) {                       // y축 확인
        sum = 0;
        for (y = 0; y < SIZE; y++) {
            sum += arr[y][x];
        }
        if (sum == 0) {
            return 1;
        }
    }
    sum = 0;                                                    // 대각선은 한줄뿐이므로 for구문 밖에서 sum 초기화
    for (x = 0; x < SIZE; x++) {                              // 대각선 확인
        sum += arr[x][x];
    }
    if (sum == 0) {
        return 1;
    }
    sum = 0;
    for (x = 0; x < SIZE; x++) {                       // 대각선 확인
        sum += arr[x][SIZE - x - 1];
    }
    if (sum == 0) {
        return 1;
    }
    return 0;                                                   // check_bingo = 0이면, 아직 승자 ㄴㄴ이므로 main함수에서 do~while문 못 벗어나서 반복됨
}