/* 
  파일이름: main.c
  작 성 자:최유신, 26-06-16
  하 는 일: 최종 여행 경비 N빵 정산프로그램
*/

#include <stdio.h>
#include <stdlib.h>


#define SIZE 3

// [함수 모듈화] 함수 선언(프로토타입)
double calcTotal(double arr[], int size);
double calDiscount(int people, double total);
void printResult(char name[], char dc, int people, double local, double krw);

int main()
{
  system("chcp 65001");
int menu;


while(1)
{
 printf("\n1. 글로벌 정산기/ 0. 종료 :");
 scanf("%d", menu);

 if(menu==0)
 {
  printf("프로그램을 종료합니다.\n");
  break;

 }
 if(menu!=1)
 continue;

 char dc;  //문자 배열 이니셜을 이름(문자열)로 확장 destinationCode
 char name[30]; //문자 배열 이니셜을 이름(문자열)로 확장
 int tp;    // totalPeople
 double expense[SIZE]; //[배열] 여러 항목의 경비를 하나로 묶음 
 double total, rate =0.0, individual,krw;

 //데이터 입력

 printf("대표자 이름 입력 : ");
 scanf("%s", name);
 printf(" 지역 코드 입력(E/U/J):");
 scanf("%c",&dc);
 printf(" 총인원수 입력 :");
 scanf("%d", &tp);

 printf("식비, 숙박비,교통비 금액을 차례로 입력:\n");
 for(int i=0; i<size; i++)
 {
  scanf("%lf", &expense[i]);

 }


  //환율 설정

  if(dc=='E'|| dc =='e')
  {
    rate=1450.0;
  }
  else if(dc== 'U'|| dc=='u')
  {
    rate= 1350.0;
  }
  else if(dc=='J'|| dc=='j')
  {
    rate=900.0;
  }
  else
  {
    printf("잘못된 지역 코드입니다\n");
    continue;
  }

  //[데이터 전달] 함수 호출을 통한 계산 처리
  total= calcTotal(expenses,SIZE); //배열을 매개변수로 전달
 double dc_rate= calDiscount(tp, total);
 total= total*(1.0 - dc_rate);//할인 적용

 individual = total/tp;
 krw= individual*rate;

 //[출력 함수 모듈화] 결과 출력 함수 호출
 printResult(name, dc,tp, individual,krw);

}
return 0;

}



===========함수구현부==========
//기능: 배열 요소를 모두 더해 총합을 구한다
double calcTotal(double arr[], int size)
{
  double sum=0;
  for(int i=0; i<size; i++)
  {
    sum+= arr[i];
  }
  return sum;
}

//기능: 인원과 총액에 따른 할인율 반환

double calcDiscount(int people, double total)
{
  if(people>=5&& total >=1000.0)
  {
    return 0.05; //5% 할인

  }
  return 0;
}

//기능: 독립된 블록에서 최종 결과를 양식에 맞춰 출력

void printResult( char name[], char dc, int people, double local, double krw)
{

  printf("\n[최종 정산 결과]\n");
  printf(" 정산 대표자 : %s 님\n", name);
  printf("총인원수 :%d 명\n",people);
  printf("1인당 현지 금액 : %.2f", local);

  if(dc=='E'|| dc =='e')
  {
    printf("EUR\n");
  }
  else if(dc== 'U'|| dc=='u')
  {
    printf("USD\n");

  }
  else if(dc=='J'|| dc=='j')
  {
    printf("JPY\n");

  }

  printf("1인당 한국 원화: %.0f 원\n",krw);
}










