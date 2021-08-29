#include<iostream>
#include<string.h>
using namespace std;

struct Date{
    int dd, mm, yy;
};

struct studInfo{
	char name[30],sex;
	int age,stud_id;
    Date reg_date, pay_date;
};

char retry;
int intake_cap{1'000};
int stud_count{};
studInfo *stud = new studInfo[intake_cap];
studInfo *stud1 = nullptr;

void new_reg();
void admin();
void set_intake();
void overdue();

void mainmenu()
{
    system("cls");
    int n;
    cout << "\t\tSidney Middle School.\n\t    Billing Management Directory." << endl;
    here:
    cout << "\n\t\tMain Menu" << endl;
    cout << "\n\t1. Registration options." << endl;
    cout << "\t2. Administration options." << endl;
    cout << "\t3. Student list and search options." << endl;
    cout << "\t4. Statistical reports." << endl;
    cout << "\t5. System developers." << endl;
    cout << "\n Choice: ";
    cin >> n;
    switch (n){
       case 1: new_reg();
                break;
       case 2: admin();
                break;
       case 3: break;
       case 4: break;
       case 5: break;
       default:
         cout << "Invalid choice, would you like to try again(y/n)?" << endl;
         cin >> retry;
         if (tolower(retry) == 'y'){
            system("cls");
            goto here;
         }
         else{
             system("cls");
             cout << "Have a nice day!" << endl;
             return;
         }
         break;
    }
}

int main()
{
   system("color f0");
   mainmenu();
}
void new_reg(){

      system("cls");
      here:
      int choice;
      cout << "\n\t1. Register a student." << endl;
      cout << "\t2. Check payment status." << endl;
      cout << "\n Choice: ";
      cin >> choice;
      switch (choice){
       case 1: break;
       case 2: overdue();
                return;
                break;
       default:
         cout << "Invalid choice, would you like to try again(y/n)?" << endl;
         cin >> retry;
         if (tolower(retry) == 'y'){
            system("cls");
            goto here;
         }
         else{
             system("cls");
             cout << "Have a nice day!" << endl;
             return;
         }
         break;
    }
      int num;
      cout << "\nEnter the number of people to register: ";
      cin >> num;

      if(stud_count + num >= intake_cap){
        cout << "Sorry there isn't enough vacancies for this academic term!" << endl;
        cout << " Do you want to go back to the main menu(y/n)" << endl;
        cout << "Choice: ";
        cin >> retry;
         if (tolower(retry) == 'y'){
            mainmenu();
             return;
         }
         else{
             system("cls");
             cout << "Have a nice day!" << endl;
             return;
         }
      }
      int id = 1000;
      for (int i = stud_count;i < stud_count + num;i++){
          cout << "--------------------";
          cout << "\nName: "; cin.ignore();
          gets(stud[i].name);
          cout << "\nAge: ";
          cin >> stud[i].age;
          cout << "\nSEX: ";
          cin >> stud[i].sex;
          cout << "\nToday's date: 'day'/'month'/'year' with spaces: ";
          cin >> stud[i].reg_date.dd >> stud[i].reg_date.mm
              >> stud[i].reg_date.yy;
          cout << "--------------------\n" << endl;
          stud[i].pay_date.dd = stud[i].reg_date.dd;
          stud[i].pay_date.mm = stud[i].reg_date.mm + 1;
          stud[i].pay_date.yy = stud[i].reg_date.yy;
          stud[i].stud_id = id + i;
      }
      stud_count += num;

      cout << " Do you want to go back to the main menu(y/n)" << endl;
      cout << "Choice: ";
      cin >> retry;
      if (tolower(retry) == 'y'){
            mainmenu();
             return;
      }
      else{
             system("cls");
             cout << "Have a nice day!" << endl;
             return;
      }
}
void admin(){

    system("cls");
    start:
    int n;
    cout << "\n\t1. Set intake capacity." << endl;
    cout << "\t2. Set payment for courses." << endl;
    cout << "\t3. Register school expenses." << endl;
    cout << "\t4. Calculate profit." << endl;
    cout << "\n Choice: ";
    cin >> n;
    switch (n){
       case 1: set_intake();
                  break;
       case 2: break;
       case 3: break;
       case 4: break;
       default:
         cout << "Invalid choice, would you like to try again(y/n)?" << endl;
         cin >> retry;
         if (tolower(retry) == 'y'){
            system("cls");
            goto start;
         }
         else{
             system("cls");
             cout << "Have a nice day!" << endl;
             return;
         }
         break;
    }
}
void set_intake(){

       cout << "Enter new intake capacity: ";
       cin >> intake_cap;
       stud1 = new studInfo[intake_cap];
       for (int i{};i < intake_cap;i++){
             stud1[i] = stud[i];
       }
        delete []stud;
        stud = stud1;
        delete []stud1;
        stud1 = nullptr;
        if (stud_count >= intake_cap){
            cout << "You have removed " << stud_count - intake_cap
                 << " from the registration list." << endl;
        }
}
void overdue(){

    Date today;
    cout << "Enter today's date with spaces (dd/mm/yy): ";
    cin >> today.dd >> today.mm >> today.yy;
    system("cls");
    cout << "Result." << endl;
    cout << "ID" << "\tName" << "\t\tSex"<< endl;
    for (int i{};i < stud_count;i++){
        if (today.yy <= stud[i].pay_date.yy &&
            today.mm <= stud[i].pay_date.mm &&
            today.dd <= stud[i].pay_date.dd){
           cout << "No overdue payments." << endl;
        }
        else{
          cout << stud[i].stud_id << "\t" << stud[i].name
               << "\t\t"<< char(toupper(stud[i].sex)) << endl;
        }
    }
}
