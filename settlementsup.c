#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* type definition of student */
typedef struct student {
  int who;     /* 0=John, 1=Peter, 2=William */
  float paid;  /* amount that student paid   */
  float balance; /* amount of money the student needs to pay   */
} student;

/* global variables */
student firstStudent, secondStudent, thirdStudent;

float absValue(float x) {
  if(x<0){
    return -x;
  } else {
    return x;
  }
}

/************************************************************************
 * ABSTRACT DATA TYPE: the following functions form the ADT student.
 * Do not change the ADT part of this program !
 */

/* read the info of a student from the keyboard and return it. */
void readStudent(student *stud) {
  scanf("%d %f", &stud->who, &stud->paid);
}

/* print the name of a student. */
void printNameOfStudent(student stud) {
  printf("%s", (stud.who == 0 ? "John" : 
  (stud.who == 1 ? "Peter" : "William")));
}

/* returns the amount that a student paid. */
float paidByStudent(student stud) {
  return stud.paid;
}

float balanceOfStudent(student stud) {
 return stud.balance; 
}

/* swaps two students */
void swapStudents(student *a, student *b) {
  student h = *a;
  *a = *b;
  *b = h;
}

void setBalance(student *stud, float total) {
  stud->balance = total/3 - stud->paid;
}

char * payOrReceive(student stud) {
  if(stud.balance > 0) {
    return "pays";
  } else {
    return "receives";
  }
}

void printResultForStudent(student stud) {
  printNameOfStudent(stud);
  printf(" %s %5.2f\n", payOrReceive(stud), 
	 absValue(balanceOfStudent(stud)));
}

/************************************************************************/


/* remainder of the program in which the ADT student is used. */

/*
 * Reads the entire input from the keyboard and stores 
 * it in the appropriate global variables.
 */
void readInput() {
  readStudent(&firstStudent);
  readStudent(&secondStudent);
  readStudent(&thirdStudent);
}

void setBalances(){
  float total = paidByStudent(firstStudent)
		  +paidByStudent(secondStudent)
		    +paidByStudent(thirdStudent);
  setBalance(&firstStudent, total);
  setBalance(&secondStudent, total);
  setBalance(&thirdStudent, total);
}

void printResults(){
  printResultForStudent(firstStudent);
  printResultForStudent(secondStudent);
  printResultForStudent(thirdStudent);
}

int main(int argc, char*argv[]) {
  readInput();
  
   /*order the students in sequence of who paid most */
  if(paidByStudent(firstStudent) > paidByStudent(secondStudent)) {
    swapStudents(&firstStudent, &secondStudent);
  } 
  if(paidByStudent(secondStudent) > paidByStudent(thirdStudent)) {
    swapStudents(&secondStudent, &thirdStudent);
  }
  if(paidByStudent(firstStudent) > paidByStudent(secondStudent)) {
    swapStudents(&firstStudent, &secondStudent);
  }

  setBalances();
  printResults();
  return 0;
}
