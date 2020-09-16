/*
  ***Ödev öncesi bilgilendirme***
  1->Part 1 kýsmýnda inputu operator sayi1 sayi2 þeklinde aldým(hepsini ayný line da)
  2->Part1 fonksiyonum eger sadece sayi veya harf girersek çýkýyor yani bitiyor (örnegin-> 5 veya a gibi seyler girerse)
  */ 





#include <stdio.h>
#include <string.h>
// define
#define first_size 10
#define second_size 10
#define third_size 2
#define max 100
void print(int input){ // part 3 print a shape
  /* initilazing*/
  int spaces=0;
  int stars=0;
  int i=0;
  int k=0;
  spaces=input-1; /* space assignment */
  for(i=0;i<input;i++){
    /* printing spaces */
    for(k=0;k<spaces;k++) printf(" ");
    printf("/");
    /* printing stars */
    for(k=0;k<stars;k++) printf("*");
    printf("\\");
    spaces--;
    stars=stars+2;
    printf("\n");
  }
  spaces++;
  stars=stars-2;
  for(i=0;i<input;i++){
    /*printing spaces */
    for(k=0;k<spaces;k++) printf(" ");
    printf("\\");
    /*printing stars  */
    for(k=0;k<stars;k++) printf("*");
    printf("/");
    
    spaces++;
    //printf("%d",spaces);
    stars=stars-2;
    printf("\n");
  }
}
void take_grades(int homework[] ){
  int i=0;
  for(i=0;i<first_size;i++){
    printf("%d->",i+1);
    scanf("%d",&homework[i]);
    while(homework[i]<0 || homework[i]>100){
      printf("Please again");
      scanf("%d",&homework[i]);
    }
  } 
} 
void take_exam_grades(int exam[]){
  int i=0;
  for(i=0;i<third_size;i++){
    printf("%d->",i+1);
    scanf("%d",&exam[i]);
    while(exam[i]<0 || exam[i]>100){
      printf("Please again");
      scanf("%d",&exam[i]);
    }
  } 
} 
double calculate_homework(int homework[]){
  int i;
  double total=0.0;
  for(i=0;i<first_size;i++) total=homework[i]+total;
  return total/(double)first_size ;
}
double calculate_lab(int exam[]){
  int i;
  double total=0.0;
  for(i=0;i<second_size;i++) total=exam[i]+total;
  return total/(double)second_size ;
} 
double calculate_all(int home_grad,int midfin[],int lab){
  double result;
  result = ((double)home_grad * 10/100) + ((double)lab * 20/100) + ((double)midfin[0] * 30/100) + ((double)midfin[1] * 40/100); // (double) -> typecasting
  return result ;
}
void print_result_part2(int result){
  printf("result -> %d",result);
}
int add(int number1 ,int number2){ // add 
  printf("\n%d",number1+number2);
  return number1+number2 ;
}
int sub(int number1 ,int number2){  // sub
  printf("\n%d",number1-number2);
  return number1-number2 ;
}
int multip(int number1 ,int number2){ // multip
  printf("\n%d",number1*number2);
  return (number1 * number2);
}
int divid(int number1 ,int number2){  // divid
  if(number2==0){
    printf("Error");
    return -1;
  }
  printf("\n%d",number1/number2);
  return number1 /number2 ;
}
int powe(int number1 ,int number2){ // powe
  int i=0;
  int result=1;
  for(i=0;i<number2;i++){
    result=result*number1;
  }
  return result;
}
int modul(int number1 ,int number2){ // modul
  return number1%number2 ;
}
int doit(int add(int first,int second),int first_number,int second_number){ // doit 
  return add(first_number,second_number);
}
int find_spaces(char str[],char str2[]){ // find spaces in a string 
  int i=0;
  int k=0;
  int spaces=0;
  while(str[i]==' '){
    i++;
  }
  for(k=0;k<strlen(str);k++){
    str2[k]=str[i];
    i++;
  }
  for(i=0;i<strlen(str)-1;i++){
    if(str2[i]==' ' && str2[i+1]!=' ') spaces++ ;  
  }
  return spaces; // returning number of spaces
}
void calculator(){
  char str[max];
  char str2[max];
  char oper[2];
  int spc=0;
  int first_number=0;
  int second_number = 0;
  int result=0;
  int i=0;
  while(fgets(str,100,stdin) ){
    //;
    first_number=0;
    second_number=0;
    
    spc=find_spaces(str,str2);
    if(spc==0 && ((str2[0]>'0' && str2[0]<'9') || (str2[0]>='A' && str2[0]<='z'))){
      printf("\n");
      break;
    }
    else if(spc==1){
    //  printf("eski number %d",first_number);
      sscanf(str2,"%s %d",oper,&first_number);
      //printf("%s %d",oper, first_number);
    //  printf("eski number %d",first_number);
      second_number=first_number;
      first_number=result;
    //  printf("\nyeni number %d",first_number);
    }
    else if(spc==2){
      sscanf(str2,"%s %d %d",oper,&first_number,&second_number);
      //printf("%s %d %d",oper, first_number,second_number);
    }
    if(strlen(oper)==2){ // power
      result=doit(powe,first_number,second_number);
      printf("%d\n",result);
    }
    else if(strlen(oper)==1){
      if(oper[0]=='+'){ // addition 
        result=doit(add,first_number,second_number);
     //   printf("%d",result);
      }
      else if(oper[0]=='-'){ // substruction
        result=doit(sub,first_number,second_number);
     //   printf("%d",result);
      }
      else if(oper[0]=='*'){ // multipication
        result=doit(multip,first_number,second_number);
   //     printf("%d",result);
      }
      else if(oper[0]=='/'){ // divisor
        result=doit(divid,first_number,second_number);
   //     printf("\n%d",result);
      }
      else if(oper[0]=='%'){ // modul
        result=doit(modul,first_number,second_number);
        printf("%d\n",result);
      } 
    }
      i++;
  }
}

void menu(){
  int input;
  int homework[first_size];
  int lab[second_size];
  int exam[third_size];
  double a;
  double b;
  int choise = 1;
  int result;
  printf("1->Calculator\n2->Find average\n3->Printing\n4->Exit\n");
  printf("Choise : ");
  scanf("%d",&choise);
  while(choise!=4){
      switch(choise){
          case 1 :
            calculator();
            break;
      
          case 2:
            printf("Homework : \n");
            take_grades(homework);
            printf("Lab\n");
            take_grades(lab);
            printf("vize and final\n");
            take_exam_grades(exam);
            a=calculate_homework(homework);
            b=calculate_lab(lab);
            result=calculate_all(a, exam, b);
            print_result_part2(result);
            break;

       
          case 3:  
            printf("Input = ");
            scanf("%d",&input);
            print(input);
            break;
          
        }
          
       
    
    printf("\n1->Calculator\n2->Find average\n3->Printing\n4->Exit\n");  
    printf("Choise : ");
    scanf("%d",&choise);
  }
}

int main(){
  menu();
}

