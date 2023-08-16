#include <stdio.h>
#include <stdlib.h>

typedef struct _Time { 						
	int hours;
	int minutes;
	int seconds;
} Time;    

// 전체 초를 입력받는 함수 시작 
int getTotalSeconds()
{
	int totalSeconds = 0;
	// 사용자에게 전체 초를 입력받기 
	printf( "초를 입력하세요 : " );
	scanf( "%d", &totalSeconds ); 					

	// 전체 초를 입력받는 함수 종료 
	return totalSeconds;
}

// 시, 분, 초를 계산하는 함수 시작  
Time* calculateTime( int totalSeconds )	
{
	Time* time = (Time*)malloc( sizeof(Time) );

	// 전체 초가 몇 시간인지 계산 
	time->hours = totalSeconds / ( 60 * 60 );			

	// 남은 시간 재조정
	totalSeconds = totalSeconds % ( 60 * 60 );

	// 남은 시간이 몇 분인지 계산 
	time->minutes = totalSeconds / 60;				

	// 남은 시간이 몇 초인지 계산 
	time->seconds = totalSeconds % 60;				

	// 시, 분, 초를 계산하는 함수 종료 
	return time;
} 

// 프로그램 시작 
int main()
{
	int totalSeconds = 0;	
	Time* time = NULL;						

	// 전체 초를 입력받기 
	totalSeconds = getTotalSeconds();

	// 시, 분, 초를 계산 
	time = calculateTime( totalSeconds );

	// 시, 분, 초를 출력 
	printf( "%d초는 %d시간 %d분 %d초입니다.", totalSeconds, time->hours, time->minutes, time->seconds ); 

	// 동적 할당 받은 동전 변수 반납
	free( time );									

	// 프로그램 종료 
	return 0;
}

