#ifndef __STUDENT
#define __STUDENT
#include "teacher.h"
#include "exam.h"
#include <string.h>
using namespace std;
class students: public teacher
{
private:
int rollno;
string name;
int PC_marks, DM_marks, LA_marks, DA_marks, OOPS_marks;
double average;
char grade;

public:
students(int ,string ,int ,int,int ,int ,int);
void calculate();
int get_rollno() ;
string get_name();
double get_average();
int get_PC_marks();
int get_DM_marks();
int get_LA_marks();
int get_DA_marks();
int get_OOPS_marks();
char get_grade();
void search_by_rollno();
void compareh();
void compare_class();
void display_all();
void attempts();
};
#endif
