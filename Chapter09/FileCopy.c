#include <stdio.h>

// 문자열 최대 길이는 1024
#define MAX_STR_LEN 1024	

// 프로그램시작 
int main()
{
	char line[MAX_STR_LEN] = "";

	// 파일 열기 
	FILE *inFile = fopen( "원본.txt", "rt" );			
	FILE *outFile = fopen( "복사본.txt", "wt" );			
	if ( ( inFile == NULL ) || ( outFile == NULL ) )		
	{
		printf( "[오류] 파일을 열 수 없습니다!" );
		return -1;
	}

	// 원본 파일 끝까지 한 줄씩 읽기 
	while ( fgets( line, MAX_STR_LEN, inFile ) != NULL ) 	
	{
		// 복사본 파일에 한 줄씩 쓰기 
		fprintf( outFile, "%s", line ); 			
	}

	// 파일 닫기 
	fclose( inFile );						
	fclose( outFile );							

	// 프로그램 종료 
	return 0;
}

