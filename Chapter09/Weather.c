#include <stdio.h>			

// 문자열 최대 길이는 1024
#define MAX_STR_LEN 1024	
						
// 프로그램시작 
int main()
{
	// 날씨 정보를 저장하는 변수 초기화
	char month[MAX_STR_LEN] = "";
	char day[MAX_STR_LEN] = "";
	char week[MAX_STR_LEN] = "";
	char weatherReport[MAX_STR_LEN] = "";
	char precaution[MAX_STR_LEN] = "";
	int  lowSeoul = 0;
	int  lowChuncheon = 0;
	int  lowDaejeon = 0;
	int  lowGwangju = 0;
	int  lowBusan = 0;
	int  lowJeju = 0;
	int  highSeoul = 0;
	int  highChuncheon = 0;
	int  highDaejeon = 0;
	int  highGwangju = 0;
	int  highBusan = 0;
	int  highJeju = 0;
	
	// 파일 관련 변수 초기화
	char filename[MAX_STR_LEN] = "";
	char line[MAX_STR_LEN] = "";
	FILE *inFile = NULL;										

	// 파일 열기 
	printf( "파일이름을 입력해 주세요 : " );
	scanf( "%s", filename );
	if ( ( inFile = fopen( filename, "rt" ) ) == NULL ) 						
	{
		printf( "[오류] 파일을 열 수 없습니다!" );
		return -1;
	}

	// 파일에서 날짜별 날씨 정보를 읽어오기 
	while ( fgets( line, MAX_STR_LEN, inFile ) != NULL ) 						
	{					
		// 날짜, 기상특보, 최저기온, 최고기온 등 주요 날씨 정보를 추출 
		if( sscanf( line, "%s %s %s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
			month, day, week, weatherReport, precaution,			
			&lowSeoul, &lowChuncheon, &lowDaejeon, 	&lowGwangju, &lowBusan, &lowJeju,
			&highSeoul, &highChuncheon, &highDaejeon, &highGwangju, &highBusan, &highJeju ) == 0 )
		{
			printf( "[오류] 한 경기씩 주요 경기 내용 읽어올 수 없습니다." );
			break;
		}

		// 추출한 정보를 바탕으로 날씨 기사를 자동으로 생성 
		printf("\n%s월 %s일 %s요일, 아침 날씨입니다.", month, day, week );
		printf("\n아침 최저기온은 서울 %d도, 춘천 %d도, 대전 %d도, 광주 %d도, 부산 %d도, 제주 %d도로 예상됩니다.",
			  lowSeoul, lowChuncheon, lowDaejeon, lowGwangju, lowBusan, lowJeju );
		printf("\n낮 최고기온은 서울 %d도, 춘천 %d도, 대전 %d도, 광주 %d도, 부산 %d도, 제주 %d도로 예상됩니다.",
			  highSeoul, highChuncheon, highDaejeon, highGwangju, highBusan, highJeju );
		printf("\n일부 지방에 %s가 발효중입니다. 출근길 %s 운전에 유의해야 합니다.", 
			  weatherReport, precaution );
		printf("\n이상 날씨였습니다.\n웨더봇 기자" );	
	}

	// 파일 닫기 
	fclose( inFile );											

	// 프로그램 종료 
	return 0;
}

