#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1	// SUCCESS 등을 변수로 설정하지 않고 #define 로 쓴건 
#define FAIL 2		// 굳이 변수를 추가하여 코드를 길게 하지 않고 단순화시키기 위함
#define LIMIT 3		// Java 의 final 같은 기능

int check(int id, int password);

int main(){
	
	int id, password, result;
	
	while(1){
		printf("Id : ");	scanf(" %d", &id);
		printf("Password : ");	scanf(" %d", &password);
		result = check(id, password);
		if( result == SUCCESS ) break;
	}
	printf("로그인 성공\n");
	
	return 0;
}

int check(int id, int password){
	
	static int super_id = 1234;			//static을 씀으로써 while에서 check 함수가 켜질 때 마다 
	static int super_password = 5678;	//아이디와 비밀번호를 생성하지 않고 프로그램이
	static int try_count = 0;			//마칠 때까지 값을 고정시키기 위함
	try_count++;
	
	if( id == super_id && password == super_password){
		return SUCCESS;
	}
	else{
		if( try_count == LIMIT){
			printf("횟수 초과\n");
			exit(1);
		}
		return FAIL;
	}
	
} 