/* 
  파일이름: main.c
  작 성 자:최유신, 26-05-03
  하 는 일: 여행 경비 N빵 계산기 
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{ 
 system("chcp 65001"); 

// 필수조건1 의미 있는 변수 5개 이상 & 자료형 3개 이상(char,int,double)
char destinationCode;   //여행지코드
int totalPeople;                //여행 총 인원        
double totalExpense;               // 현지 화폐 총 지출액 (예:유로)
double exchangeRate = 0.0;            // 현재 환율 
double individualLocal;         // 1인당 현지 화폐 부담액
double individualKRW;          // 1인당 한국 원화 부담액 
double discountRate= 0.0;

// 필수조건2 입출력 함수 사용(printf,scanf)
printf(" ========== 글로벌 여행 경비 정산기 v2.0 ==========\n");
printf(" 현재 정산 지역 코드  (E : 유럽, U : 미국, J :일본): \n" );
scanf(" %c" , &destinationCode);

printf("1. 여행을 참여한 총 인원수를 입력하세요: ");
scanf("%d", &totalPeople);


printf(" 2. 현지에서 사용한 총 금액을 입력하세요:"); 
scanf("%lf", &totalExpense);
printf("--------------------------------------------------\n");  




  
//필수 조건3 다중 조건문 & 논리 연산자 사용

if(destinationCode == 'E' || destinationCode =='e')
{
  exchangeRate =1450.0;
  printf(" 유로 환율 1450원이 적용됩니다.\n");
}
else if ( destinaitonCode == 'U' || destinationCode == 'u')
{
  exchangeRate = 1350.0;
  printf(" 달러 환율 1350원이 적용됩니다.\n");
}
else if(  destinaitonCode == 'J' || destinaitonCode =='j')
{
  exchangeRate = 900.0;
  printf(" 엔 환율 900.0이 적용됩니다.\n");
}
else
{
  printf(" 잘못된 지역 코드입니다. 프로그램을 종료합니다.\n");
  return 0;
} 
  
//필수 조건3 중첩 조건문, 논리연산자 사용

if(totalPeople >0)
{
  if(totalPeople >=5 && totalExpense >=1000.0)
  {
    discountRate = 0.05;
    printf(" 단체 할인 5%%가 적용 되었습니다!\n");
  }
  else
  {
    printf(" 일반 정산 대상입니다.\n");
  }
}
else 
 {
  printf("인원수는 1명 이상이어야 합니다. 프로그램을 종료합니다.\n");
return 0;  
 }

totalExpense = totalExpense - (totalExpense * discountRate); 

  
individualLocal = totalExpense / totalPeople;
individualKRW = individualLocal * exchangeRate;



printf("\n=============== 최종 정산 결과 =============\n");
printf(" 총인원 :%d명\n ", totalPeople);
printf(" 1인당 현지 화폐 부담액 : %.2f  단위\n", individualLocal);
printf(" 1인당 한국 원화 부담액 : %.0f 원\n " ,individualKRW);
printf("=============================================\n");


return 0;
}









