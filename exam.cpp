#include <bits/stdc++.h>
#include "exam.h"
using namespace std;

void exam::display_attempts()
{
     fstream file;
    int found = 0;
    file.open("studentz.txt", ios::in);
    if (!file)
    {
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<"		 |             ATTEMPTED/NOT                |		  "<<endl;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        int rollnum;
        int ADA,APC,ADM,ALA,AOOPS;
        int rollno,PC_marks,DM_marks,LA_marks,DA_marks,OOPS_marks;
        string name;
        double average;
        char grade;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<"		 |             ATTEMPTED/NOT                |		  "<<endl;
        cout<<"		  ------------------------------------------		  "<<endl;
        cout<<endl;
        cout << "\n\tEnter Roll No. of Student Which You Want to Search: ";
        cin >> rollnum;
        file >> rollno >> name >> PC_marks >> DM_marks >> LA_marks >> DA_marks >> OOPS_marks >> average >> grade>>APC>>ADM>>ALA>>ADA>>AOOPS  ;
        while (!file.eof())
        {
            if (rollnum==rollno)
            {
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t1-"<<" "<<"ATTEMPTED"<<endl;
            cout<<"\t\t\t0-"<<" "<<"NOT ATTEMPTED"<<endl;
            cout<<endl;
            cout << "\n\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << rollno << endl;
            cout << "\t\t\t PC EXAM: " << APC << endl;
            cout << "\t\t\t DM EXAM: " << ADM << endl;
            cout << "\t\t\t LA EXAM: " << ALA << endl;
            cout << "\t\t\t DA EXAM: " << ADA<< endl;
            cout << "\t\t\t OOPS EXAM: " << AOOPS<< endl;
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
