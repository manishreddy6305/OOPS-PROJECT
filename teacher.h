#ifndef __TEACHER
#define __TEACHER
#include<string>
#include "student.h"
#include "exam.h"
using namespace std;
class teacher:public exam
{ 
public:
void create_student(int);
void delete_student();
void modify_data();
void display_all();
void search_by_rollno();
void attempt();
};
#endif
