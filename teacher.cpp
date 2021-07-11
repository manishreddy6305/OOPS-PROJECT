#include <bits/stdc++.h>
#include <fstream>
#include "student.h"
#include "teacher.h"
using namespace std;
void teacher::create_student(int num)
{
   int rn;
   int found=0;
   string name;
   int ADA,APC,ADM,ALA,AOOPS;
   int PC,DM,LA,DA,OOPS;
   rn=num;
   fstream pfile;
   pfile.open("studentz.txt",ios::in);
   if (!pfile)
    {
        cout << "\n\t\t\tNo Data is Present..";
        pfile.close();
    }
    else
    {
        string name;
    	int rollno,PC_marks,DM_marks,LA_marks,DA_marks,OOPS_marks;
    	char grade;
    	double average;
      pfile >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade >>APC>>ADM>>ALA>>ADA>>AOOPS ;
      while(!pfile.eof())
      {
         if (rn==rollno)
            {
                cout<<endl;
                cout<<"	  	Student data already exits. You can modify it."<<endl<<endl;
                found++;
                break;
            }
            pfile >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade >>APC>>ADM>>ALA>>ADA>>AOOPS ;
      }
    }
   if(found==0)
   {
   cout<<"\n\n\tEnter student name: "; 
   cin>>name;
   cout<<endl;
   cout<<"\n\tAll marks should be out of 100";
   cout<<endl;
   cout<<"\n\tEnter marks in Professional Communication : "; 
   cin>>PC;
   if(PC==0)
   APC=0;
   else
   APC=1;
   cout<<"\n\tEnter marks in Discrete Mathematics:  ";
    cin>>DM;
    if(DM==0)
    ADM=0;
    else
    ADM=1;
   cout<<"\n\tEnter marks in Linear Algebra:  ";
   cin>>LA;
   if(LA==0)
   ALA=0;
   else
   ALA=1;
   cout<<"\n\tEnter marks in Data Structure:  ";
   cin>>DA;
   if(DA==0)
   ADA=0;
   else
   ADA=1;
  cout<<"\n\tEnter marks in OOPS:  ";
  cin>>OOPS;
  if(OOPS==0)
   AOOPS=0;
   else
   AOOPS=1;
   students stud(rn,name,PC,DM,LA,DA,OOPS);
   ofstream student_records;
   student_records.open("studentz.txt",ios::app|ios::out);
   student_records<<stud.get_rollno()<<" ";
   student_records<<stud.get_name()<<" ";
   student_records<<stud.get_PC_marks()<<" ";
   student_records<<stud.get_DM_marks()<<" ";
   student_records<<stud.get_LA_marks()<<" ";
   student_records<<stud.get_DA_marks()<<" ";
   student_records<<stud.get_OOPS_marks()<<" ";
   student_records<<stud.get_average()<<" ";
   student_records<<stud.get_grade()<<" ";
   student_records<<APC<<" ";
   student_records<<ADM<<" ";
   student_records<<ALA<<" ";
   student_records<<ADA<<" ";
   student_records<<AOOPS<<" "<<endl;
   student_records.close();
   cout<<"\n\n\tStudent record Has Been Created ";
   cout<<endl;
   cout<<endl;
   }
}
void teacher::delete_student()
{
    fstream file, file1;
    int found = 0;
    int  roll;
     int ADA,APC,ADM,ALA,AOOPS;
    cout<<"		       --------------------------------------------"<<endl;
     cout<<"		      |           DELETE STUDENT DETAILS           |"<<endl;
     cout<<"		       --------------------------------------------"<<endl; 
    file.open("studentz.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
    	string name;
    	int rollno,PC_marks,DM_marks,LA_marks,DA_marks,OOPS_marks;
    	char grade;
    	double average;
        cout << "\n\tEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade >>APC>>ADM>>ALA>>ADA>>AOOPS ;
        while (!file.eof())
        {
            if (roll != rollno)
            {
                file1 <<rollno<< " " << name << " " << PC_marks << " " << DM_marks << " " << LA_marks << " " << DA_marks << " "<<OOPS_marks<<" "<<average<<" "<<grade<<" "<<APC<<" "<<ADM<<" "<<ALA<<" "<<ADA<<" "<<AOOPS<<"\n";
            }
            else
            {
                found++;
            }
            file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        else
         cout << "\n\t\t\tSuccessfully Deleted Data\n";
        file1.close();
        file.close();
        remove("studentz.txt");
        rename("record.txt", "studentz.txt");
    }
}

void teacher::modify_data()
{
    fstream file, file1;
    int rollnum;
    int found = 0;
  
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<"		 |           STUDENT MODIFY DETAILS         |		  "<<endl;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<endl;
    file.open("studentz.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
    	string name;
    	int ADA,APC,ADM,ALA,AOOPS;
    	int rollno,PC_marks,DM_marks,LA_marks,DA_marks,OOPS_marks;
    	char grade;
    	double average;
        cout << "\n\tEnter Roll No. of Student which you want to Modify: ";
        cin >> rollnum;
        file1.open("record.txt", ios::app | ios::out);
        file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
        while (!file.eof())
        {
            if (rollnum!=rollno)
                file1 <<rollno<< " " << name << " " << PC_marks << " " << DM_marks << " " << LA_marks << " " << DA_marks << " "<<OOPS_marks<<" "<<average<<" "<<grade<<" "<<APC<<" "<<ADM<<" "<<ALA<<" "<<ADA<<" "<<AOOPS<<"\n";
            else
            {   
                string n;
                int rolln;
                int PCmarks, DMmarks, LAmarks, DAmarks,OOPSmarks;
                int ADA,APC,ADM,ALA,AOOPS;
                double avg;
                char g;
                cout<<"\n\n\tEnter student name: "; 
                cin>>n;
                cout<<endl;
                cout<<"\n\n\tEnter student roll no: "; 
                cin>>rolln;
                cout<<endl;
                cout<<"\n\tAll marks should be out of 100";
                cout<<endl;
   		 cout<<"\n\tEnter marks in Professional Communication : "; 
                cin>>PCmarks;
                if(PCmarks==0)
                APC=0;
   		else
   		APC=1;
   		cout<<"\n\tEnter marks in Discrete Mathematics:  ";
    		cin>>DMmarks;
    		if(DMmarks==0)
    		ADM=0;
    		else
    		ADM=1;
   		cout<<"\n\tEnter marks in Linear Algebra:  ";
   		cin>>LAmarks;
   		if(LAmarks==0)
   		ALA=0;
   		else
   		ALA=1;
   		cout<<"\n\tEnter marks in Data Structure:  ";
   		cin>>DAmarks;
   		if(DAmarks==0)
   		ADA=0;
   		else
   		ADA=1;
  		cout<<"\n\tEnter marks in OOPS:  ";
  		cin>>OOPSmarks;
  		if(OOPSmarks==0)
               AOOPS=0;
               else
               AOOPS=1;
                avg=(PCmarks+DMmarks+LAmarks+DAmarks+OOPSmarks)/5;
                if(avg>=90)
                g='A';
                else if(avg>=75)
                g='B';
                else if(avg>=50)
                g='C';
                else
                g='F';
                file1<<rolln<<" "<<n<<" "<<PCmarks<<" "<<DMmarks<<" "<<LAmarks<<" "<<DAmarks<<" "<<OOPSmarks<<" "<<avg<<" "<<g<<" "<<APC<<" "<<ADM<<" "<<ALA<<" "<<ADA<<" "<<AOOPS<<"\n";
                found++;
            }
              file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
            
        }
        if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
         else
         cout<<"\n\t\t\tRecord modified succesfully!!"<<endl<<endl;
        file1.close();
        file.close();
        remove("studentz.txt");
        rename("record.txt", "studentz.txt");
        cout<<endl;
        cout<<endl;
    }
}
void teacher::display_all()
{

    fstream file;
    cout<<endl;
     cout<<"		  ------------------------------------------		  "<<endl;
     cout<<"		 |           STUDENT RECORD TABLE           |		  "<<endl;
     cout<<"		  ------------------------------------------		  "<<endl;
    file.open("studentz.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {  
    	string name;
    	int rollno,PC_marks,DM_marks,LA_marks,DA_marks,OOPS_marks;
    	int ADA,APC,ADM,ALA,AOOPS;
    	char grade;
    	double average;
    	 file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
    	while(!file.eof())
       {
           
            cout << "\n\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << rollno << endl;
            cout << "\t\t\t PC Marks: " << PC_marks << endl;
            cout << "\t\t\t DM MARKS: " << DM_marks << endl;
            cout << "\t\t\t LA MARKS: " << LA_marks << endl;
            cout << "\t\t\t DA MARKS: " << DA_marks<< endl;
            cout << "\t\t\t OOPS MARKS: " << OOPS_marks<< endl;
            cout << "\t\t\t Average MARKS: " << average<< endl;
            cout << "\t\t\t GRADE: " << grade<< endl<<endl;
             file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
       }
    }
    file.close();
}

void teacher::search_by_rollno()
{
    fstream file;
    int found = 0;
    file.open("studentz.txt", ios::in);
    if (!file)
    {
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<"		 |           STUDENT RECORD TABLE           |		  "<<endl;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        int rollnum;
        int ADA,APC,ADM,ALA,AOOPS;
        string name;
    	int rollno,PC_marks,DM_marks,LA_marks,DA_marks,OOPS_marks;
    	char grade;
    	double average;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<"		 |           STUDENT RECORD TABLE           |		  "<<endl;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<endl;
        cout << "\n\tEnter Roll No. of Student Which You Want to Search: ";
        cin >> rollnum;
        file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
        while (!file.eof())
        {
            if (rollnum==rollno)
            {
            cout << "\n\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << rollno << endl;
            cout << "\t\t\t PC Marks: " << PC_marks << endl;
            cout << "\t\t\t DM MARKS: " << DM_marks << endl;
            cout << "\t\t\t LA MARKS: " << LA_marks << endl;
            cout << "\t\t\t DA MARKS: " << DA_marks<< endl;
            cout << "\t\t\t OOPS MARKS: " << OOPS_marks<< endl;
            cout << "\t\t\t Average MARKS: " << average<< endl;
            cout << "\t\t\t GRADE: " << grade<< endl;
            found++;
            }
            file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        file.close();
    }

}

void teacher::attempt(){
    exam::display_attempts();
 }
