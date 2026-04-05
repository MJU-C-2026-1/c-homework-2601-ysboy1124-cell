/* 
  파일이름: main.c
  작 성 자:최유신, 26-04-05
  하 는 일: 여행 경비 N빵 계산기 
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{ 
 system("chcp 65001"); 

// 필수조건1 의미 있는 변수 5개 이상 & 자료형 3개 이상(char,int,double)
char destinationCode = 'E' ;    //여행지코드(E: Europe)
int totalpeople;                //여행 총 인원        
int totalExpense;               // 현지 화폐 총 지출액 (예:유로)
double exchangeRate;            // 현재 환율 (1단위당 원화)
double individualLocal;         // 1인당 현지 화폐 부담액
double individualKRW;          // 1인당 한국 원화 부담액 

// 필수조건2 입출력 함수 사용(printf,scanf)
printf(" ========== 글로벌 여행 경비 정산기 v1.0 ==========\n");
printf(" 현재 정산 지역 코드 : %c (E : 유럽, U : 미국, J :일본)\n" , destinationCode);
printf("--------------------------------------------------\n");

printf("1. 여행을 참여한 총 인원수를 입력하세요: ");
scanf("%d", &totalpeople);

printf(" 2. 현지에서 사용한 총 금액을 입력하세요:"); 
scanf("%d", &totalExpense);

printf(" 3.현재 환율(1단위당 원화)을 입력하세요: ");  
scanf("%lf", &exchangeRate);

  
//필수 조건3 산술연산 사용(나누기, 곱하기)
// 1인당 현지 금액 계산 (실수 계산을 위해 형변환 효과 포함)  
individualLocal =(double)totalExpense / totalPeople ;

// 1인당 원화 금액 계산 (현지 금액 * 환율)
individualKRW = individualLocal * exchangeRate;

//최종 결과 출력
printf(" \n=================  정산결과 ===============\n ");  
printf(" 총인원 : %d명\n", totalPeople);  
printf(" 1인당 현지 화폐 부담액 : %.2f 단위\n", individualLocal);
printf(" 1인당 한국 원화 부담액 : %.0f 원 (절사기준)\n", individualKRW);
printf("=============================================\n");

  
return 0;  
}
