#include <iostream>
#include <string>
using namespace std;

struct date{
int dd,mm,yy;
};
struct studentInformation{
string fname;
string lname;
int age;
char sex;
date bod;
};

studentInformation studentInfo[500];  //assuming the maximum number of students to 500
studentInformation *stu=studentInfo;
void reg_new(studentInformation studentInfo[]);
void menuchoice(studentInformation studentInfo[]);
void liststud(studentInformation studentInfo[]);
void add_stud(studentInformation studentInfo[], int &);
void delet(studentInformation studentInfo[]);
void searchf(studentInformation studentInfo[]);

int cho,stud1=1,r=0,m=0;
string menu2;

int main(){

menuchoice(studentInfo);

}


void menuchoice(studentInformation studentInfo[]){
    system ("cls");
cout<<"   STUDENT INFORMATION:\n\n";
	  cout<<"===============================\n";
      cout<<"\n\t1:   to insert new a student information\n";
	  cout<<"\n\t2:   to add student information on list\n";
      cout<<"\n\t3:   to view all recorded students\n";
      cout<<"\n\t4:   to delete student information from the list\n";
      cout<<"\n\t5:   to search students\n";
	  cout<<"\n\t6    exit\n";
	  cout<<"\n\t================================\n";
      cout<<"\n\n\tenter your choice: ";
	  cin>>cho;
switch(cho){
     case 1: reg_new(studentInfo);
              break;
     case 2: add_stud(studentInfo, m);
             break;
     case 3: liststud(studentInfo);
             menuchoice(studentInfo);
             break;
    case 4:  delet(studentInfo);
             break;
    case 5: searchf(studentInfo);
            break;
    case 6: exit(1);
}
}



void reg_new(studentInformation studentInfo[]){
int back1;

system ("cls");
cout<<"--------------------";

cout<<"how many number of student's information you want to add "; cin>>m;

for(int i=0;i<m;i++)
{
cout<<"\n======enter the "<<i+1<<" student details======\n";
    cout<<"\nenter name: ";
cin>>studentInfo[i].fname;
cout<<"\nlast name: ";
cin>>studentInfo[i].lname;
cout<<"\nage: ";
cin>>studentInfo[i].age;
cout<<"\nsex: ";
cin>>studentInfo[i].sex;
cout<<"\ndate: ('day', 'month' , 'year')\n";
cout<<"day: ";
cin>>studentInfo[i].bod.dd;
cout<<"month: ";
cin>>studentInfo[i].bod.mm;
cout<<"year: ";
cin>>studentInfo[i].bod.yy;
r++;
}

cout<<"\n\npress '1'to go back to menu else any key to exit\n";
cin>>back1;
if(back1==1){
    menuchoice(studentInfo);
}
else {
    exit(1);
}
}

void liststud(studentInformation studentInfo[]){
system ("cls");
cout<<"------------------   list of all registered students   ------------------\n";
cout<<"\nfirst name\t\tlast name\t\tage\t\tsex\t\tdate\n";
for(int i=0 ; i<r ; i++){

        cout<<studentInfo[i].fname<<"\t\t\t"<<studentInfo[i].lname<<"\t\t\t"<<studentInfo[i].age<<"\t\t"<<studentInfo[i].sex<<"\t\t"<<studentInfo[i].bod.dd<<"/"<<studentInfo[i].bod.mm<<"/"<<studentInfo[i].bod.yy<<endl;
}

        cout<<"\npress any number for menu list";
        cin>>menu2;

}


void add_stud(studentInformation studentInfo[], int &stud){
    system("cls");
cout<<"enter the "<<stud<<"student details\n";
cout<<"\nenter name: ";
cin>>studentInfo[m].fname;
cout<<"\nlast name: ";
cin>>studentInfo[m].lname;
cout<<"\nage: ";
cin>>studentInfo[m].age;
cout<<"\nsex: ";
cin>>studentInfo[m].sex;
cout<<"\ndate: ('day', 'month' , 'year')\n";
cout<<"day: ";
cin>>studentInfo[m].bod.dd;
cout<<"month: ";
cin>>studentInfo[m].bod.mm;
cout<<"year: ";
cin>>studentInfo[m].bod.yy;
  ++stud;

cout<<"\n\nnew student information is sucessfully added !!!!";

cout<<"\npress any number for menu list";
        cin>>menu2;
}


 void delet(studentInformation studentInfo[]){
    string name1,name2;
    system ("cls");
cout<<"enter the 'first name' and 'last name' of the person to delete the information";
cin>>name1>>name2;
for(int i=0 ; i<500 ; i++){
    if(studentInfo[i].fname==name1 && studentInfo[i].lname==name1){
        studentInfo[i].fname ="deleted item";
        studentInfo[i].lname="-";
        studentInfo[i].age=0;
        studentInfo[i].sex=0;
        studentInfo[i].bod.dd=0;
        studentInfo[i].bod.mm=0;
        studentInfo[i].bod.yy=0;
        cout<<"\n\nsuccessfully deleted \n";
        cout<<"\npress 1 to check the item from the list ";
        cin>>cho;
        if(cho==1){
          liststud(studentInfo);
        }
    }
        else if(studentInfo[i].fname!=name1 && studentInfo[i].lname!=name1)
                continue;
                cout<<"\nno match result found ";
        }
    }


    void searchf(studentInformation studentInfo[]){

        system ("cls");
        here:
        cout<<"enter name of student: ";
        cin>>menu2;
        cout<<"\nfirst name\t\tlast name\t\tage\t\tsex\t\tdate\n";
        for(int i=0 ; i<500 ; i++){
    if(studentInfo[i].fname==menu2){

        cout<<studentInfo[i].fname<<"\t\t\t"<<studentInfo[i].lname<<"\t\t\t"<<studentInfo[i].age<<"\t\t"<<studentInfo[i].sex<<"\t\t"<<studentInfo[i].bod.dd<<"/"<<studentInfo[i].bod.mm<<"/"<<studentInfo[i].bod.yy<<endl;
        cout<<"\npress any number for menu list";
        cin>>menu2;
        menuchoice(studentInfo);
     }
    }
    cout<<"\n\nNot found!!  please write the correct name again ";
    goto here;
}
