#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#include "student.h"
#include "teacher.h"
using namespace std;
int main()
{
     
     cout<<endl;
     cout<<endl;
     cout<<"		  ----- STUDENT REPORT MANAGEMENT SYSTEM -----		  "<<endl;
     cout<<endl;
     cout<<"    Enter your designation: ";
     string type;
     while(1)
     {
                   cin>>type;
                   if(type=="TEACHER"||type=="teacher"||type=="Teacher"||type=="STUDENT"||type=="Student"||type=="student")
                   break;
                   cout<<endl;
                   cout<<"\t\t\t!!Oops.. Wrong Designation!!"<<endl<<endl;
                   cout<<"    Enter correct designation: ";          
     }
     cout<<endl;
     cout<<endl;
     if(type=="TEACHER"||type=="teacher"||type=="Teacher")
     {
     cout<<"		       ----------------------------------		  "<<endl;
     cout<<"		      |           FACULTY PART           |		  "<<endl;
     cout<<"		       ----------------------------------		  "<<endl; 
     cout<<endl;
     cout<<endl;
     cout<<"    ENTER YOUR PASSWORD: ";
    
        string des;
        cin>>des;
        
         cout<<endl;
        if(des=="TEACHER"||des == "teacher"||des=="Teacher")
      {   
         int select1;  
         do
         {
           cout<<"\n\tMENU";
           cout<<"\n\t1.Create_student_record";
           cout<<"\n\t2.Delete student record";
           cout<<"\n\t3.Modify student record";
           cout<<"\n\t4.Display all students records ";
           cout<<"\n\t5.Search student record";
           cout<<"\n\t6.Check whether you attempted all subjects or not";
           cout<<"\n\t7.Logout";
           cout<<endl<<endl;
           cout<<"	Select your option (1/2/3/4/5/6/7): ";
           cin>>select1;
           while(select1>7 || select1<1){
           	cout<<"\n\t\tInvalid Choice.."<<endl<<endl;
           	cout<<"\tPlease select your choice correctly(1/2/3/4/5/6): ";
           	cin>>select1;
           }
           cout<<endl;
           int num=-1;
           if(select1==1)
           {
           cout<<"\n\n\tEnter student roll number: "; 
           cin>>num;
           } 
           teacher t;
         switch(select1)
        {
         case 1: 
               t.create_student(num);
               break;
         case 2:     
               t.delete_student();
               break;   
         case 3:
               t.modify_data();
               break;
         case 4:
               t.display_all();
               break;
         case 5:
         	t.search_by_rollno();
         	break;
         case 6:
         	t.attempt();
         	break;
         case 7:
         long long int j;
               cout<<"\n\t\t\tlogging out..."<<endl;
         	for (int i = 0; i < 1000000000; i++)
  		{
   		}         	
	       cout<<"\n\t\t\t!!See you again..logged out!!"<<endl<<endl;
               break;
                   
        }
        }while(select1!=7);
     }else
    {
       cout<<"\n\t\t\t!!Oops.. Wrong Password!!"<<endl<<endl;
    }
    }
     else if(type=="STUDENT"||type=="Student"||type=="student")
     {
     cout<<"		       ----------------------------------"<<endl;
     cout<<"		      |           STUDENT PART           |"<<endl;
     cout<<"		       ----------------------------------"<<endl;
     cout<<endl;
     cout<<endl; 
     cout<<"    ENTER YOUR PASSWORD STUDENT: ";
     string sp;
     cin>>sp;
     if(sp=="STU" || sp == "stu"||sp=="Stu")
     {
          
        int select;
           do 
           {
           cout<<"\n\tMENU";
           cout<<"\n\t1.Search student record";
           cout<<"\n\t2.Display all students records ";
           cout<<"\n\t3.Compare with highest";
           cout<<"\n\t4.Compare with class";
           cout<<"\n\t5.Check whether you attempted all subjects or not";
           cout<<"\n\t6.Exit";
           cout<<"\n\n\t What is your Choice (1/2/3/4/5/6): ";
           cin>>select;
           while(select>6 || select<1){
           	cout<<"\n\t\tInvalid Choice.."<<endl<<endl;
           	cout<<"\tPlease select your choice correctly(1/2/3/4/5/6): ";
           	cin>>select;
           }
           cout<<endl;
           students stud1(-1,"balayya",0,0,0,0,0);
            switch(select)
            { 
         
         case 1: 
                stud1.search_by_rollno();
                break;
               
         case 2: 
                stud1.display_all();
                break;
                   
         case 3: 
         	stud1.compareh();
               break;
                   
         case 4:
         	stud1.compare_class();
                break;
         case 5:
               stud1.attempts();
               break;
         case 6:
               cout<<"\n\t\t\tlogging out..."<<endl;
         	for (int i = 0; i < 1000000000; i++)
  		{
   		}         	
	        cout<<"\n\t\t\t!!See you again..logged out!!"<<endl<<endl;
                break;
         
            }
       }while(select!=6);  
       
    }
    else
    {
       cout<<"\n\t\tWrong Password"<<endl<<endl;
    }
  }
return 0;
}
