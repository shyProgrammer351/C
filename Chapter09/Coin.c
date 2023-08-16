#include <stdio.h>
#include <stdlib.h>

typedef struct _Coin { 					
	int _500;
	int _100;
	int _50;
	int _10;
} Coin;    

// 돈을 입력받는 함수 시작 
int getPayment()
{
	int payment = 0;

	// 사용자에게 돈을 입력받기 
	printf( "잔돈을 입력하세요: " );
	scanf( "%d", &payment ); 						

	// 돈을 입력받는 함수 종료 
	return payment;
}

// 동전 개수를 계산하는 함수 시작 
Coin* getCoins( int payment )			
{
	// 동전 변수 동적 할당
	Coin* coin = (Coin*)malloc( sizeof(Coin) );

	// 잔액에서 500원짜리 동전 개수 계산하고, 잔액 재조정 
	coin->_500 = payment / 500;							
	payment = payment % 500;						

	// 잔액에서 100원짜리 동전 개수 계산하고, 잔액 재조정 
	coin->_100 = payment / 100;							
	payment = payment % 100;					

	// 잔액에서 50원짜리 동전 개수 계산하고, 잔액 재조정 
	coin->_50  = payment / 50;							
	payment = payment % 50;						

	// 잔액에서 10원짜리 동전 개수 계산하고, 잔액 재조정 
	coin->_10  = payment / 10;							
	payment = payment % 10;					

	// 동전 개수를 계산하는 함수 종료 
	return coin;
}

// 프로그램 시작 
int main()
{
	int payment = 0;						
	Coin* coin = NULL;								

	// 사용자에게 돈을 입력받기 
	payment = getPayment();

	// 동전 개수를 계산 
	coin = getCoins( payment );

	// 동전 개수를 출력 
	printf( "%d원을 500원짜리동전 %d개,100원짜리동전 %d개,50원짜리동전 %d개,10원짜리동전 %d개로 거슬러 드립니다.", 
		payment, coin->_500, coin->_100, coin->_50, coin->_10 );		

	// 동적 할당 받은 동전 변수 반납
	free( coin );									

	// 프로그램 종료 
	return 0;
}

