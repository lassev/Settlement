#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int number;
  float amountPayed;
  float balance;
} student;

float absValue(float a){
  if (a<0) {
    a = -a;
   }
  return a;
 }

char * payOrReceive(float n){
  if (n<0){
    return "pays";
    } else {
     return "receives"; 
    }
  }

char * whatsMyName(int i){
    switch(i){
    case 0: return "John";
    case 1: return "Peter";
    case 2: return "William";
    default: return "I dont have a name";
 }
}

int main(int arc, char*argv[]){
   int a;
  float b;
  student first={0, 0, 0}, second={0, 0, 0}, third={0, 0, 0};
  scanf("%d %f", &a, &b);
  first.number=a;
  first.amountPayed=b;
  scanf("%d %f", &a, &b);
  second.number=a;
  second.amountPayed=b; 
  scanf("%d %f", &a, &b);
  third.number=a;
  third.amountPayed=b;
  
   if (first.amountPayed == second.amountPayed && first.amountPayed == third.amountPayed){
    printf("%s receives 0\n%s receives 0\n%s receives 0\n", whatsMyName(first.number), whatsMyName(second.number), whatsMyName(third.number));
  } else {
  
      float total = first.amountPayed + third.amountPayed + second.amountPayed;
      float share = total/3;
      first.balance = first.amountPayed - share;
      third.balance = third.amountPayed -share;
      second.balance = second.amountPayed - share;

    if(first.amountPayed <= second.amountPayed && first.amountPayed <= third.amountPayed){
     printf("%s pays %.2lf \n", whatsMyName(first.number), absValue(first.balance));
     if (second.amountPayed<=third.amountPayed){
      printf("%s %s %.2lf \n", whatsMyName(second.number), payOrReceive(second.balance), absValue(second.balance));
      printf("%s receives %.2lf \n", whatsMyName(third.number), third.balance);
     } else {
	printf("%s %s %.2lf \n", whatsMyName(third.number), payOrReceive(third.balance), absValue(third.balance));
	printf("%s receives %.2lf \n", whatsMyName(second.number), absValue(second.balance));
     }
    }
     
     
     if(second.amountPayed < first.amountPayed && second.amountPayed <= third.amountPayed){
      printf("%s pays %.2lf \n", whatsMyName(second.number), absValue(second.balance));
	  if (first.amountPayed<=third.amountPayed){
	  printf("%s %s %.2lf \n", whatsMyName(first.number), payOrReceive(first.balance), absValue(first.balance));
	  printf("%s receives %.2lf \n", whatsMyName(third.number), third.balance);
	  } else {
	    printf("%s %s %.2lf \n", whatsMyName(third.number), payOrReceive(third.balance), absValue(third.balance));
	    printf("%s %s %.2lf \n", whatsMyName(first.number), payOrReceive(first.balance), absValue(first.balance));
	  }
     }
	  
      if(third.amountPayed < first.amountPayed && third.amountPayed < second.amountPayed){
      printf("%s pays %.2lf \n", whatsMyName(third.number), absValue(third.balance));
	  if (first.amountPayed<=second.amountPayed){
	  printf("%s %s %.2lf \n", whatsMyName(first.number), payOrReceive(first.balance), absValue(first.balance));
	  printf("%s %s %.2lf \n", whatsMyName(second.number), payOrReceive(second.balance), absValue(second.balance));
	  } else {
	    printf("%s %s %.2lf \n", whatsMyName(second.number), payOrReceive(second.balance), absValue(second.balance));
	    printf("%s %s %.2lf \n", whatsMyName(first.number), payOrReceive(first.balance), absValue(first.balance));
	  }
      }
  }
  
  return 0;
}
