#include <iostream>
using namespace std;

void enrollment_availability();
void notify_payment_overdue();

struct date{
int dd,mm,yy;
};

date today;
date deadline{10,12,2021};
date due_date;

struct studentInformation{
	string name;
	int age,grade;
	string fname;
    string lname;
    char sex;
    date bod;
};

studentInformation studInfo;

struct course{
	int intake_capacity;
	float cgpa;
};

course courseInfo;

void enrollment_availability()
{

int choice;
cout<<"Enter the grade of student: ";
cin>>studInfo.grade;
if(courseInfo.intake_capacity<10000){
	cout<<"There is an available spot."<<endl;
	cout<<"Enter CGPA: "<<endl;
	cin>>courseInfo.cgpa;

	if(courseInfo.cgpa>=2.0){
		cout<<"You are eligible to enroll."<<endl;
		cout<<"Enter 1 to proceed or any number to exit "<<endl;
		cin>>choice;

		switch(choice){
		case 1://reg_new();   call a function  that records student info
				break;
		default:
		    break;
		}
	}
	else
		cout<<"Your CGPA should be 2.0 or more to enroll."<<endl;

}
else
	cout<<"Sorry, there are no available spots."<<endl;

}

void notify_payment_overdue()
{
    cout<<"Enter todays date: (date/month/year)"<<endl;
    cin>>today.dd>>today.mm>>today.yy;

    deadline.yy-today.yy=due_date.yy;
    deadline.mm-today.mm=due_date.mm;
    deadline.dd-today.dd=due_date.dd;

    //tell how many days have passed after calculating the above
}


int main()
{

enrollment_availability();
return 0;
}



