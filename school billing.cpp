#include <iostream>
#include <string>
using namespace std;
void reg_new();
void menuchoice();
void liststud();
void delet();
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
studentInformation studentInfo[10000];  //assuming the maximum number of students to 10000


int cho,stud1=1;
int main(){

menuchoice();

}



void menuchoice(){
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
     case 1: reg_new();
              break;
     case 2: reg_new();
             break;
     case 3: liststud();
             break;
}
}



void reg_new(){
int back1;

system ("cls");
cout<<"--------------------";
cout<<"\nenter name: ";
cin>>studentInfo[stud1].fname;
cout<<"\nlast name: ";
cin>>studentInfo[stud1].lname;
cout<<"\nage: ";
cin>>studentInfo[stud1].age;
cout<<"\nsex: ";
cin>>studentInfo[stud1].sex;
cout<<"\ndate: ('day', 'month' , 'year')\n";
cout<<"day: ";
cin>>studentInfo[stud1].bod.dd;
cout<<"month: ";
cin>>studentInfo[stud1].bod.mm;
cout<<"year: ";
cin>>studentInfo[stud1].bod.yy;
cout<<"--------------------";
++::stud1;
cout<<"\n\npress '1'to go back to menu else any key to exit\n";
cin>>back1;
if(back1==1){
    menuchoice();
}
else {
    exit(1);
}
}

void liststud(){
system ("cls");
cout<<"------------------   list of all registered students   ------------------\n";
cout<<"\nfirst name     last name\tage\tsex\tdate\n";
for(int i=1 ; i<10,000 ; i++){

        cout<<studentInfo[i].fname<<"     "<<studentInfo[i].lname<<"\t"<<studentInfo[i].age<<"\t"<<studentInfo[i].sex<<"\t"<<studentInfo[i].bod.dd<<"/"<<studentInfo[i].bod.mm<<"\t"<<studentInfo[i].bod.yy;

}
}

/* void delet(){
    string name1;
cout<<"enter the 'first name' and 'last name' of the person to delete the information"
cin>>name1;
for(int i=1 ; i<10000 ; i++){
    if(students[i].fname==name1 && students[i].lname==name1)
}
}   */

