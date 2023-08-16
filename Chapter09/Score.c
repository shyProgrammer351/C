#include <stdio.h> 
#include <stdlib.h> 

typedef struct ScoreInfo{ 							
	int korean;
	int english;
	int mathematics;
	double average;
} Score;                 

// 과목별 점수 및 평균을 구하는 함수 시작 
Score* getScores()								
{
	// 동적 메모리 할당
	Score *score = (Score*)malloc( sizeof( Score ) );

	// 국어 점수를 입력 
	printf( "0점 ~ 100점 사이의 국어 점수를 입력하세요: " );
	scanf( "%d", &( score->korean ) );					

	// 영어 점수를 입력 
	printf( "0점 ~ 100점 사이의 영어 점수를 입력하세요: " );
	scanf( "%d", &( score->english ) );					

	// 수학 점수를 입력 
	printf( "0점 ~ 100점 사이의 수학 점수를 입력하세요: " );
	scanf( "%d", &( score->mathematics ) );					

	// 평균 점수를 계산 
	score->average = (double)( score->korean + score->english + score->mathematics ) / 3; 	

	// 과목별 점수 및 평균을 구하는 함수 종료 
	return score;
}

// 프로그램시작 
int main()
{
	// 점수 초기화
	Score *score = NULL;

	// 과목별 점수 및 평균 구하기 
	score = getScores();

	// 과목별 점수 및 평균 출력 
	printf( "국어 %d점, 영어 %d점, 수학 %d점의 평균은 %.2f점입니다.",
		 score->korean, score->english, score->mathematics, score->average );		

	// 동적 할당 받은 동전 변수 반납
	free( score );		

	// 프로그램 종료 
	return 0;
}

