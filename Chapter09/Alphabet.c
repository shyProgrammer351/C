#include <stdio.h> 
#include <stdlib.h> 

// 문자열 최대 길이는 1024
#define MAX_STR_LEN 1024	

// 알파벳 소문자 단어를 입력받는 함수 시작 
char *getLowercase()	
{
	// 메모리 동적 할당
	char* lowercase = (char*)malloc( sizeof(char) * MAX_STR_LEN );

	// 알파벳 소문자 단어를 입력받기 
	printf("알파벳 소문자 단어를 입력하세요: " );
	scanf( "%s", lowercase );

	// 알파벳 소문자 단어를 입력는 함수 종료 
	return lowercase;
}

// 알파벳 소문자 단어를 대문자 단어로 변환하는 함수 시작 
char *getUppercase( char* lowercase )	
{
	int index = 0;
	char* uppercase = (char*)malloc( sizeof(char) * MAX_STR_LEN );

	// 알파벳 소문자 단어를 대문자 단어로 변환하기 
	for ( index = 0; lowercase[ index ] != '\0'; index++ )
	{
		uppercase[ index ] = lowercase[ index ] - 'a' + 'A';
	}

	// 문자열 마지막은 항상 '\0'으로 마무리
	uppercase[ index ] = '\0';

	// 알파벳 소문자 단어를 대문자 단어로 변환하는 함수 종료 
	return uppercase;
}

// 프로그램 시작 
int main()
{
	char* lowercase = NULL;									
	char* uppercase = NULL;									

	// 알파벳 소문자 단어를 입력받기 
	lowercase = getLowercase();
	// 알파벳 소문자 단어를 대문자 단어로 변환하기 
	uppercase = getUppercase( lowercase );

	// 알파벳 소문자 단어와 대문자 단어를 출력하기 
	printf("소문자 %s의 대문자는 %s입니다^^", lowercase, uppercase );

	// 동적 할당 받은 동전 변수 반납
	free( lowercase );									
	free( uppercase );									
		
	// 프로그램 종료 
	return 0;
}

