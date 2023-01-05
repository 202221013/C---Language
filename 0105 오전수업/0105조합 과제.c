#include<stdio.h>

int arr[] = { 1,2,3,4,5 }; //전역 변수로 선언
int Copy[5]; //arr배열을 복사하기 위한 배열

void print_Comb(int count);
void Combination(int n, int r, int c);

void print_Comb(int count) {
    for (int i = 0; i < count; i++) {
        printf("%d", Copy[i]);
    }
    printf("\n");
}
void Combination(int n, int r, int c) { //재귀함수
    if (r == 0) {
        print_Comb(c);
        return;
    }
    if (n < r) {
        return;
    }
    else {
        Copy[r - 1] = arr[n - 1];
        Combination(n - 1, r - 1, c);
        Combination(n - 1, r, c);
    }
}
int main() {
    Combination(5, 3, 3);
}