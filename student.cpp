#include <bits/stdc++.h>
#include "student.h"
using namespace std;
students::students(int rn,string n,int em,int mm,int sm,int lm,int cm)
{
   rollno=rn;
   name=n;	
   PC_marks=em;
   DM_marks=mm;
   LA_marks=sm;
   DA_marks=lm;
   OOPS_marks=cm;
   calculate();
}
int  students::get_rollno() 
{
return rollno;
}
int  students::get_PC_marks() 
{
return PC_marks;
}
int  students::get_DM_marks() 
{
return DM_marks;
}
int  students::get_LA_marks() 
{
return LA_marks;
}
int  students::get_DA_marks() 
{
return DA_marks;
}
int  students::get_OOPS_marks() 
{
return OOPS_marks;
}
char students::get_grade() 
{
return grade;
}
double students::get_average() 
{
return average;
}
string students::get_name()
{
return name;
}
void students::calculate()
{
average=(PC_marks+DM_marks+LA_marks+DA_marks+OOPS_marks)/5.0;
if(average>=90)
grade='A';
else if(average>=75)
grade='B';
else if(average>=50)
grade='C';
else
grade='F';
}




void students::compareh()
{
	cout<<"		  ------------------------------------------		  "<<endl;
        cout<<"		 |           COMPARE WITH HIGHEST          |		  "<<endl;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<endl;
        int found=0;
        int roll;
        int ADA,APC,ADM,ALA,AOOPS;
        int hnum,unum,hpc,upc,hdm,udm,hla,ula,hda,uda,hoops,uoops;
        string hname,uname;
        double havg=-1,uavg;
        char hg,ug;
        fstream file;
        file.open("studentz.txt", ios::in);
    	if (!file)
    	{
        	cout << "\n\t\t\tNo Data is Present..";
    	}
    	else
    	{
        cout << "\n\tEnter your Roll number: ";
        cin >> roll;
	while (!file.eof())
        {
        	file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
        	if(average>havg)
        	{
        		hname=name;hnum=rollno;hpc=PC_marks;hdm=DM_marks;hla=LA_marks;hda=DA_marks;hoops=OOPS_marks,havg=average,hg=grade;
        	}
        	if(roll==rollno)
        	{
                	uname=name;unum=rollno;upc=PC_marks;udm=DM_marks;ula=LA_marks;uda=DA_marks;uoops=OOPS_marks,uavg=average,ug=grade;
                	found++;
        	}
        }
        if(found>0){
        		cout<<endl<<endl;
        		cout<<"\t\t        \t"<<"Highest\t\t"<<"You";
        		cout<<endl<<endl;
        		cout << "\t\tName:      \t"<<hname<<"\t\t"<<uname;
           		cout<<endl<<endl;
                	cout << "\t\tRoll Number: \t"<<hnum<<"\t\t"<<unum;
                	cout<<endl<<endl;
                	cout << "\t\tPC marks: \t"<<hpc<<"\t\t"<<upc;
                	cout<<endl<<endl;
                	cout << "\t\tDM marks: \t"<<hdm<<"\t\t"<<udm;
                	cout<<endl<<endl;
                	cout << "\t\tLA marks: \t"<<hla<<"\t\t"<<ula;
                	cout<<endl<<endl;
                	cout << "\t\tDA marks: \t"<<hda<<"\t\t"<<uda;
                	cout<<endl<<endl;
                	cout << "\t\tOOPS marks: \t"<<hoops<<"\t\t"<<uoops;
                	cout<<endl<<endl;
                	cout << "\t\tAverage marks: \t"<<havg<<"\t\t"<<uavg;
                	cout<<endl<<endl;
                	cout << "\t\tGrade : \t"<<hg<<"\t\t"<<ug;
                	cout<<endl<<endl;
                	}
        else
        {
            cout<<endl<<endl;
            cout<<"    \t\tStudent roll number not found in Database..."<<endl<<endl;
        }
	}
}
void students::compare_class()
{
	cout<<"		  ------------------------------------------		  "<<endl;
        cout<<"		 |           COMPARE WITH CLASS             |		  "<<endl;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<endl;
        int found=0;
        int total=-1;
        int roll;
        int ADA,APC,ADM,ALA,AOOPS;
        double unum=0,hpc=0,upc=0,hdm=0,udm=0,hla=0,ula=0,hda=0,uda=0,hoops=0,uoops=0;
        string hname,uname;
        double havg=0,uavg;
        char hg,ug;
        fstream file;
        file.open("studentz.txt", ios::in);
    	if (!file)
    	{
        	cout << "\n\t\t\tNo Data is Present..";
    	}
    	else
    	{
        cout << "\n\tEnter your Roll number: ";
        cin >> roll;
        
	while (!file.eof())
        {
        	file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
        	hpc+=PC_marks;hdm+=DM_marks;hla+=LA_marks;hda+=DA_marks;hoops+=OOPS_marks;
        	if(roll==rollno){
                uname=name;unum=rollno;upc=PC_marks;udm=DM_marks;ula=LA_marks;uda=DA_marks;uoops=OOPS_marks,uavg=average,ug=grade;
                found++;
        	}
        	total++;
        }
        hpc-=PC_marks;hdm-=DM_marks;hla-=LA_marks;hda-=DA_marks;hoops-=OOPS_marks;
        hpc/=total;hdm/=total;hla/=total;hda/=total;hoops/=total;
        havg=(hpc+hdm+hla+hda+hoops)/5;
        if(havg>=90)
                hg='A';
                else if(havg>=75)
                hg='B';
                else if(havg>=50)
                hg='C';
                else
                hg='F';
        if(found>0)
        {
        		cout<<endl<<endl;
        		cout<<"\t\t        \t"<<"Class\t\t"<<"You";
        		cout<<endl<<endl;
        		cout << "\t\tName:      \t"<<"Total"<<"\t\t"<<uname;
           		cout<<endl<<endl;
                	cout << "\t\tRoll Number: \t"<<"---"<<"\t\t"<<unum;
                	cout<<endl<<endl;
                	cout << "\t\tPC marks: \t"<<hpc<<"\t\t"<<upc;
                	cout<<endl<<endl;
                	cout << "\t\tDM marks: \t"<<hdm<<"\t\t"<<udm;
                	cout<<endl<<endl;
                	cout << "\t\tLA marks: \t"<<hla<<"\t\t"<<ula;
                	cout<<endl<<endl;
                	cout << "\t\tDA marks: \t"<<hda<<"\t\t"<<uda;
                	cout<<endl<<endl;
                	cout << "\t\tOOPS marks: \t"<<hoops<<"\t\t"<<uoops;
                	cout<<endl<<endl;
                	cout << "\t\tAverage marks: \t"<<havg<<"\t\t"<<uavg;
                	cout<<endl<<endl;
                	cout << "\t\tGrade : \t"<<hg<<"\t\t"<<ug;
                	cout<<endl<<endl;
         }
        else
        {
            cout<<endl<<endl;
            cout<<"    \t\tStudent roll number not found in Database..."<<endl<<endl;
        }
	}
}
void students::display_all(){
  teacher::display_all();
}
void students::attempts(){
    teacher::display_attempts();
 }
void students::search_by_rollno(){
    teacher::search_by_rollno();
 }
