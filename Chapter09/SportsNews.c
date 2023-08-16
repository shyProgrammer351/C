#include <stdio.h>

// 문자열 최대 길이는 1024
#define MAX_STR_LEN 1024	
						
// 프로그램시작 
int main()
{
	// 경기 내용을 저장하는 변수 초기화
	char date[MAX_STR_LEN] = "";
	char winningTeam[MAX_STR_LEN] = "";
	char losingTeam[MAX_STR_LEN] = "";
	int  winningPoint = 0;
	int  losingPoint = 0;
	char startingPitcherOfLosingTeam[MAX_STR_LEN] = "";
	char startingPitcherOfWinningTeam[MAX_STR_LEN] = "";
	char bestPlayer[MAX_STR_LEN] = "";
	char bestPlayPoint[MAX_STR_LEN] = "";
	int  scoreAtBestPlayPoint = 0;
	char missedPlayer[MAX_STR_LEN] = "";

	// 파일 관련 변수 초기화
	char filename[MAX_STR_LEN] = "";
	char line[MAX_STR_LEN] = "";
	FILE *inFile = NULL;							

	printf( "파일이름을 입력해 주세요 : " );
	scanf( "%s", filename );

	// 파일 열기 
	if ( ( inFile = fopen( filename, "rt" ) ) == NULL ) 			
	{
		printf( "[오류] 파일을 열 수 없습니다!" );
		return -1;
	}

	// 파일에서 한 경기씩 주요 경기 내용을 읽어오기 
	while ( fgets( line, MAX_STR_LEN, inFile ) != NULL ) 			
	{					
		// 경기일자, 경기팀, 점수, 선발투수 등 주요 경기 내용을 추출 
		if( sscanf( line, "%s\t%s\t%s\t%d\t%d\t%s\t%s\t%s\t%s\t%d\t%s\n", 
			date, winningTeam, losingTeam, &winningPoint, &losingPoint, 
			startingPitcherOfWinningTeam, startingPitcherOfLosingTeam, 
			bestPlayer, bestPlayPoint, &scoreAtBestPlayPoint, missedPlayer ) == 0 )
		{
			printf( "[오류] 한 경기씩 주요 경기 내용 읽어올 수 없습니다." );
			break;
		}

		// 추출한 내용을 바탕으로 스포츠 신문기사 자동 생성 
		printf( "\n\n( %s %d : %s %d )\n", 
			losingTeam, losingPoint, winningTeam, winningPoint );
		printf( "%s는 %s일 열린 프로야구 %s와의 홈 경기에서 %d-%d점으로 크게 패하며 ", 
			losingTeam, date, winningTeam, losingPoint, winningPoint );
		printf( "홈 팬들을 실망시켰다. \n%s는 %s을 선발로 등판시켰고 %s는 %s가 나섰다. ", 
		 losingTeam, startingPitcherOfLosingTeam, winningTeam, startingPitcherOfWinningTeam );
		printf( "%s는 %s이 맹활약을 펼쳤다. \n%s은 %s에 맞이한 타석에서 %d점을 뽑아내며, ", 
			winningTeam, bestPlayer, bestPlayer, bestPlayPoint, scoreAtBestPlayPoint );
		printf( "%s의 %d점차 승리를 이끈 일등공신이 됐다. \n%s는 %s을 끝까지 공략하지 못하며 ", 
			winningTeam, ( winningPoint - losingPoint ), losingTeam, missedPlayer );
		printf( "안방에서 %s에 %d점차 승리를 내주었다.", 
			winningTeam, ( winningPoint - losingPoint ) );
	}

	// 파일 닫기 
	fclose( inFile );								

	// 프로그램 종료 
	return 0;
}

