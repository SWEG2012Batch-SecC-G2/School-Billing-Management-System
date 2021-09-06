               /* School Billing Management System
                  * Register, Update, Delete student information and produce receipt
                  * Administrator sets course payment and intake capacity
                  * Produce various statistical reports in tabular format
                  * Move across the program with ease
                  * Admin Password = 1234
               */
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct Courselist{
    string cNames[5];
    float price[5]{};
};

struct Date{
    int dd, mm, yy;
};
//stores student information
struct studInfo{
	char name[30],sex;
	int age,stud_id{};
    Date reg_date, pay_date;
    Courselist courses;
    float total_pay{};

};

struct Schoolinfo{
    float total,expense;
    float net;
};
//Global variables
int intake_cap{1000};
int id = 1000;
int stud_count{};  //counts enrolled students
float prices[5]{700, 500, 550, 450, 600}; // default course price
float ctaken[5]{};
studInfo *stud = new studInfo[stud_count];  // pointer to dynamic stud array
studInfo *stud1 = nullptr;

//functions used
void new_reg();
void admin();
void set_intake();
void set_pay();
void overdue();
void profit();
void Coursechoice(int studnum);
inline void table(int i);  // output table records
void reorder();  //order records in ascending order
void statreport();
void searching();
void edit();  // edit record
void deletion();  // delete record
inline void retrial(int a);  //for traversing program
void menu(){  // master table
    system("cls");
    int n;
    here:
    cout << "\n\t\t   Sidney Middle School." << endl;
    cout << "\t\tBilling Management Directory." << endl;
    cout << "\n\t\tMain Menu" << endl;
    cout << "\n\t1. Registration options." << endl;
    cout << "\t2. Administration options." << endl;
    cout << "\t3. Statistical reports." << endl;
    cout << "\t4. System developers." << endl;
    cout << "\n Choice: ";
    cin >> n;
    switch (n){
       case 1: new_reg();
                break;
       case 2: admin();
                break;
       case 3: statreport();
                break;
       case 4: system("cls");
               cout << "\n\tDevelopers: " << endl;
               cout << "\n\t\tName               ID" << endl;
               cout << "\n\t1. Elsabeth Kahsay    ETS 0241/12" << endl;
               cout << "\t2. Elshaday Dereje    ETS 0243/12" << endl;
               cout << "\t3. Eyobed Mesfin      ETS 0271/12" << endl;
               cout << "\t4. Natan Mekebib      ETS 1029/12 (Group Leader)" << endl;
               cout << "\n\n\tInstructor: Chere Lemma." << endl;
               retrial(1);  // goes to menu
                break;
       default: if (true){
                  retrial(2); // goes to previous page
                  goto here;
                }
         break;
    }
}
int main(){
   system("color f0");  //white cmd screen
   menu();
}
inline void retrial(int a){
   char retry;
   switch(a){
       case 1: cout << "\n Do you want to go back to the main menu(y/n)" << endl;
               cout << "Choice: ";
               cin >> retry;
               if (tolower(retry) == 'y'){
                   menu();
                  exit(0);
               }
               else{
                  system("cls");
                  cout << "Have a nice day!" << endl;
                  exit(0);
               }
               break;
      case 2: cout << "Invalid choice, would you like to try again(y/n)?" << endl;
              cin >> retry;
              if (tolower(retry) == 'y'){
                 system("cls");
                 return;
              }
              else{
                 system("cls");
                 cout << "Have a nice day!" << endl;
                 exit(0);
              }
              break;
   }
}
void new_reg(){
      system("cls");
      start:
      int choice;
      cout << "\tUser menu" << endl;
      cout << "\n\t1. Register a student." << endl;
      cout << "\t2. Check payment status." << endl;
      cout << "\t3. Enrollment availability and courses." << endl;
      cout << "\t4. Search options." << endl;
      cout << "\t5. Edit record." << endl;
      cout << "\t6. Delete record." << endl;
      cout << "\n Choice: ";
      cin >> choice;
      switch (choice){
       case 1: break;
       case 2: overdue();
                break;
       case 3: system("cls");
               cout << "\n\t    Courses" << endl;
               cout << "\t1. Mathematics." << endl;
               cout << "\t2. Physics." << endl;
               cout << "\t3. Biology." << endl;
               cout << "\t4. Chemistry." << endl;
               cout << "\t5. English." << endl;
               cout << "\nThere are " << intake_cap - stud_count
                    << " available spots for this academic year." << endl;
                  retrial(1);
                  break;
       case 4: searching();
                  break;
       case 5: edit();
                  break;
       case 6: deletion();
                  break;
       default: if (true){
                  retrial(2);
                  goto start;  //wrong input retry
                }
         break;
    }
      int num;
      cout << "\nEnter the number of people to register: ";
      cin >> num;
      if(stud_count + num >= intake_cap){  // check for vacancy
        cout << "Sorry there isn't enough vacancies for this academic term!" << endl;
        retrial(1);
      }
      stud1 = new studInfo[stud_count + num]; // resize array for new record
       for (int i{};i < stud_count;i++){
          strcpy(stud1[i].name, stud[i].name);
          stud1[i].age = stud[i].age;
          stud1[i].sex = stud[i].sex;
          stud1[i].reg_date.dd = stud[i].reg_date.dd;
          stud1[i].reg_date.mm = stud[i].reg_date.mm;
          stud1[i].reg_date.yy = stud[i].reg_date.yy;
          stud1[i].pay_date.dd = stud1[i].reg_date.dd;
          stud1[i].pay_date.mm = stud1[i].reg_date.mm + 1;
          stud1[i].pay_date.yy = stud[i].reg_date.yy;
          stud1[i].stud_id = stud[i].stud_id;
          stud1[i].courses = stud[i].courses;
          stud1[i].total_pay = stud[i].total_pay;
       }
        delete []stud;  // copy values and delete previous array
        stud = stud1;   // pass address to first pointer to reuse second pointer
        stud1 = nullptr;
      system("cls");
      for (int i = stud_count;i < stud_count + num;i++){
          cout << "--------------------";
          cout << "\nName: "; cin.ignore();
          gets(stud[i].name);
          strupr(stud[i].name);   //change all letters to CAPITAL
          cout << "\nAge: ";
          cin >> stud[i].age;
          cout << "\nSEX(M/F): ";
          cin >> stud[i].sex;
          cout << "\nToday's date(dd/mm/yy): with spaces: ";
          cin >> stud[i].reg_date.dd >> stud[i].reg_date.mm
              >> stud[i].reg_date.yy;
          stud[i].pay_date.dd = stud[i].reg_date.dd;
          stud[i].pay_date.mm = stud[i].reg_date.mm + 1;  //payment is 1 month after registration
          stud[i].pay_date.yy = stud[i].reg_date.yy;
          stud[i].stud_id = id++;  // id is assigned
          Coursechoice(i);
          system("cls");
      }
      for (int i = stud_count;i < stud_count + num;i++){  //display receipt for user
          cout << "\nReceipt: " << endl;
          cout << "----------------------------" << endl;
          cout << "\nStudent ID: SMS" << stud[i].stud_id << endl;
          cout << "Name: " << stud[i].name << endl;
          cout << "Age: " << stud[i].age << " ";
          cout << "\nSEX: " << char(toupper(stud[i].sex)) << endl;
          cout << "Payment date: " << stud[i].pay_date.dd << "/"
               << stud[i].pay_date.mm << "/" << stud[i].pay_date.yy << endl;
          for (int j{};stud[i].courses.price[j];j++){
                cout << stud[i].courses.cNames[j] << " Price: "
                     << stud[i].courses.price[j] << endl;
          }
          cout << "Total Payment: "<< stud[i].total_pay << " birr." << endl;
          cout << "----------------------------\n" << endl;
      }
      stud_count += num;
      reorder();  // put in ascending order after entry
      retrial(1);
}
void admin(){
    system("cls");
    int password{1234};  // admin password
    int num;
    cout << "\nAdministrator access required!" << endl;
    cout << "Password: ";
    cin >> num;
    for (int i = 0; i < 3;i++){
       if (num != password ){
            cout << "Wrong password!" << endl;
            cout << "Try again: ";
            cin >> num;
       }
       else
            goto start;
    }
    cout << "Too many attempts!" << endl;
    cout << "Good bye!!!" << endl;
          exit(0);
    start:
    system("cls");
    int n;
    cout << "\tAdministrator menu" << endl;
    cout << "\n\t1. Set intake capacity." << endl;
    cout << "\t2. Set payment for courses." << endl;
    cout << "\t3. School expenses/Profit report." << endl;
    cout << "\n Choice: ";
    cin >> n;
    switch (n){
       case 1: set_intake();
                  break;
       case 2: set_pay();
                  break;
       case 3: profit();
                  break;
       default:
         if (true){
            retrial(2);
            goto start;
         }
         break;
    }
}
void set_intake(){  // change student intake
       cout << "Enter new intake capacity: ";
       cin >> intake_cap;
       if (stud_count >= intake_cap){
            cout << "You have removed " << stud_count - intake_cap
                 << " students from the registration list." << endl;
            stud_count = intake_cap;
            stud1 = new studInfo[stud_count]; // resize array for new capacity
            for (int i{};i < stud_count;i++){
                strcpy(stud1[i].name, stud[i].name);
                stud1[i].age = stud[i].age;
                stud1[i].sex = stud[i].sex;
                stud1[i].reg_date.dd = stud[i].reg_date.dd;
                stud1[i].reg_date.mm = stud[i].reg_date.mm;
                stud1[i].reg_date.yy = stud[i].reg_date.yy;
                stud1[i].pay_date.dd = stud1[i].reg_date.dd;
                stud1[i].pay_date.mm = stud1[i].reg_date.mm + 1;
                stud1[i].pay_date.yy = stud[i].reg_date.yy;
                stud1[i].stud_id = stud[i].stud_id;
                stud1[i].courses = stud[i].courses;
                stud1[i].total_pay = stud[i].total_pay;
            }
            delete []stud;
            stud = stud1;
            stud1 = nullptr;
        }
        retrial(1);
}
void set_pay(){   // change course prices
    system("cls");
    int cnum;
    cout << "\n\t    Courses" << endl;
    cout << "\t1. Mathematics." << endl;
    cout << "\t2. Physics." << endl;
    cout << "\t3. Biology." << endl;
    cout << "\t4. Chemistry." << endl;
    cout << "\t5. English." << endl;
    cout << "\n How many course prices will you be changing(max = 5): ";
    cin >> cnum;
    int cchoice;
    if (cnum >= 1 && cnum <= 5){
        for (int i{};i < cnum; i++){
            cout << "Course number: ";
            cin >> cchoice;
            cout << "Enter new price: ";
            cin >> prices[cchoice];
        }
    }
    retrial(1);
}
void overdue(){  // notify payment overdue
    int countt{};
    Date today;
    cout << "Enter today's date with spaces (dd/mm/yy): ";
    cin >> today.dd >> today.mm >> today.yy;
    system("cls");
    cout << "Result:" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << " ID " << setw(4) << " " << "| Name "
         << setw(26) << " " << "| Age " << setw(1) << " "
         << "| SEX " << setw(3) << " " << "| Payment date " << setw(3) << " "
         << "|Total Payment " << setw(10) << " " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    for (int i{};i < stud_count;i++){                // check todays date with pay date
        if (today.yy <= stud[i].pay_date.yy &&
            today.mm <= stud[i].pay_date.mm &&
            today.dd <= stud[i].pay_date.dd){
             continue;
        }
        else{
          table(i);  //generates individual table elements
          countt++;
        }
    }
     if (countt == 0){
        cout << "No overdue payments." << endl;
      }
    retrial(1);
}
void Coursechoice(int studnum){   // input courses to take
    start:
    system("cls");
    int cnum;
    cout << "\n\t\tCourse Menu" << endl;
    cout << "\n\t1. Mathematics." << endl;
    cout << "\t2. Physics." << endl;
    cout << "\t3. Biology." << endl;
    cout << "\t4. Chemistry." << endl;
    cout << "\t5. English." << endl;
    cout << "\n How many courses will you be taking: ";
    cin >> cnum;
    if (cnum > 5){
         if (true){
            retrial(2);
            goto start;
         }
    }
    int choices;
    stud[studnum].total_pay = 0;
    for (int i{};i < cnum;i++){
      here:
      cout << "Course number: ";
      cin >> choices;
      switch(choices){
        case 1: stud[studnum].courses.cNames[i] = "Mathematics";
                stud[studnum].courses.price[i] = prices[0];
                ctaken[0]++;   // count students in Maths course
                  break;
        case 2: stud[studnum].courses.cNames[i] = "Physics";
                stud[studnum].courses.price[i] = prices[1];
                ctaken[1]++;  // count students in Physics course
                  break;
        case 3: stud[studnum].courses.cNames[i] = "Biology";
                stud[studnum].courses.price[i] = prices[2];
                ctaken[2]++;  //...
                  break;
        case 4: stud[studnum].courses.cNames[i] = "Chemistry";
                stud[studnum].courses.price[i] = prices[3];
                ctaken[3]++;  //...
                   break;
        case 5: stud[studnum].courses.cNames[i] = "English";
                stud[studnum].courses.price[i] = prices[4];
                ctaken[4]++;  //...
                  break;
        default:  cout << "Invalid input." << endl;
                  cout << "Try again!" << endl;
                  goto here;
                    break;
      }
      stud[studnum].total_pay += stud[studnum].courses.price[i];  //calculate total pay
    }
}
void profit(){   // school profit
    float tot{};
    Schoolinfo school;
    cout << "\n  Profit report: " << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Number of students: ";
    cout << stud_count << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    for (int i{};i < stud_count;i++){
        tot += stud[i].total_pay;
    }
    school.total = tot;
    school.expense = tot * 0.75;    // each course costs 75% of total profit
    school.net = (school.total - school.expense) * 0.85;  // profit after expenses and tax
    cout << "Total profit: ";
    cout << school.total << " birr." <<endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Expenses: " << school.expense << " birr." << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Net profit: " << school.net << " birr." << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    retrial(1);
}
void table(int i){  // output individual table elements
      int name;
          name = 31 - strlen(stud[i].name);
          cout << "SMS" << stud[i].stud_id << " | " << stud[i].name << setw(name) << " "
               << "| " << setw(4) << stud[i].age <<" | " << setw(6) << char(toupper(stud[i].sex))
               <<" | " << setw(7) << stud[i].pay_date.dd << "/" << setw(2) << stud[i].pay_date.mm << "/"
               << setw(4) << stud[i].pay_date.yy << " | " << setw(4) << stud[i].total_pay << " birr." << endl;
          cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}
void reorder(){   // orders records by name
    for (int i{};i < stud_count;i++){
        for (int j{};j < stud_count - 1;j++){
            if (stricmp(stud[j + 1].name, stud[j].name) <= 1 || stud[j].name[0] == '\0'){
                swap(stud[j + 1], stud[j]);  // swap function switches values
            }
        }
    }
}
void statreport(){  // produce statistical reports
    system("cls");
    int countt{};
    start:
    cout << "\n\t\tStatistics and Report Menu" << endl;
    cout << "\n\t1. Student list." << endl;
    cout << "\t2. Students above 15 years of age." << endl;
    cout << "\t3. Students less than 15 years of age." << endl;
    cout << "\t4. Number of students taking each course." << endl;
    cout << "\t5. Students paying over 1000 birr." << endl;
    cout << "\n Choice: ";
    int report;
    cin >> report;
    system("cls");
    cout << "Result:" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << " ID " << setw(4) << " " << "| Name "
         << setw(26) << " " << "| Age " << setw(1) << " "
         << "| SEX " << setw(3) << " " << "| Payment date " << setw(3) << " "
         << "|Total Payment " << setw(10) << " " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    switch(report){
       case 1: for (int i{};i < stud_count;i++){
                 table(i);  // output list 1 by 1
                 countt++;
               }
               if (countt == 0){
                  cout << "No results." << endl;
               }
                retrial(1);
               break;
       case 2: for (int i{};i < stud_count;i++){
                 if (stud[i].age >= 15){   // output age above 15
                      table(i);
                      countt++;
                 }
               }
               if (countt == 0){
                  cout << "No results." << endl;
               }
                retrial(1);
                break;
       case 3: for (int i{};i < stud_count;i++){
                 if (stud[i].age < 15){
                      table(i);
                      countt++;
                 }
               }
               if (countt == 0){
                  cout << "No results." << endl;
               }
                retrial(1);
                break;
       case 4: system("cls");  // students taking each course
               cout << "_________________________________" << endl;
               cout << "| Courses     | No. of students |" << endl;
               cout << "---------------------------------" << endl;
               cout << "| Mathematics | " << setw(10) << ctaken[0] << setw(7) <<"|"<< endl;
               cout << "| Physics     | " << setw(10) << ctaken[1] << setw(7) <<"|"<< endl;
               cout << "| Biology     | " << setw(10) << ctaken[2] << setw(7) <<"|"<< endl;
               cout << "| Chemistry   | " << setw(10) << ctaken[3] << setw(7) <<"|"<< endl;
               cout << "| English     | " << setw(10) << ctaken[4] << setw(7) <<"|"<< endl;
               cout << "---------------------------------" << endl;
                retrial(1);
                  break;
       case 5: for (int i{};i < stud_count;i++){
                 if (stud[i].total_pay >= 1000){
                      table(i);
                 }
               }
                retrial(1);
                break;
       default:  if (true){
                   retrial(2);
                   goto start;
                 }
                    break;
   }
}
void searching(){   // search function
      system("cls");
      int countt{},num;
      char str[30];
      cout << "Enter search by \n1. Name or \n2. ID: " << endl;
      cout << "Choice: "; cin >> num;
      system("cls");
      if (num == 1){
          cout << "Enter the name: "; cin.ignore();
          gets(str);
      }
      else if (num == 2){
          cout << "Enter the ID: ";
          cin >> num;
      }
      else
          retrial(1);
      system("cls");
      cout << "\nResult: " << endl;
      cout << "----------------------------------------------------------------------------------------------------------------" << endl;
      for (int i{}; i < stud_count; i++){
        if (stricmp(stud[i].name, str) == 0 || stud[i].stud_id == num){  // checks for name or id
            table(i);
            countt++;
        }
      }
      if (countt == 0){
        cout << "No matching results." << endl;
      }
      retrial(1);
}
void edit(){   // edit record
      system("cls");
      int num, countt{};
      cout << "Enter your ID number:";
      cin >> num;
      for (int i{}; i < stud_count; i++){
        if (stud[i].stud_id == num){
          cout << "--------------------";
          cout << "\nName: "; cin.ignore();
          gets(stud[i].name);
          strupr(stud[i].name);
          cout << "\nAge: ";
          cin >> stud[i].age;
          cout << "\nSEX(M/F): ";
          cin >> stud[i].sex;
          Coursechoice(i);
          system("cls");
          countt++;  // if 0 no results match
        }
      }
      if (countt == 0){
        cout << "No matching results." << endl;
      }
      else
        cout << "Successfully edited entry!" << endl;
      reorder(); // reorder after editing record
      retrial(1);
}
void deletion(){  // delete record
      system("cls");
      int num, countt{};
      cout << "Enter your ID number:";
      cin >> num;
      for (int i{}; i < stud_count; i++){
        if (stud[i].stud_id == num){   // delete individual entries
          stud[i].stud_id = 0;
          stud[i].name[0] = '\0';
          stud[i].age = 0;
          stud[i].sex = '\0';
          stud[i].reg_date.dd = 0;
          stud[i].reg_date.mm = 0;
          stud[i].reg_date.yy = 0;
          stud[i].pay_date.dd = 0;
          stud[i].pay_date.mm = 0;
          stud[i].pay_date.yy = 0;
          stud[i].total_pay = 0;
          for (int j{};j < 5;j++){
             stud[i].courses.cNames[j] = '\0';
             stud[i].courses.price[j] = 0;
          }
          countt++;
        }
      }
      if (countt == 0){
        cout << "No matching results." << endl;
      }
      else
        cout << "Successfully deleted entry!" << endl;
      reorder();
      --stud_count;  // decrease student count after deleting
      stud1 = new studInfo[stud_count]; // new array of student count
      int resizer{};
       for (int i{};i < stud_count;i++){
          here:
          if (resizer > stud_count){ // stop copying when limit reached
            break;
          }
          else if (stud[resizer].stud_id == 0){  // if id = 0 skip copy
                  resizer++;  goto here;
          }
          else {  // copy values to new array
            strcpy(stud1[i].name, stud[resizer].name);
            stud1[i].age = stud[resizer].age;
            stud1[i].sex = stud[resizer].sex;
            stud1[i].reg_date.dd = stud[resizer].reg_date.dd;
            stud1[i].reg_date.mm = stud[resizer].reg_date.mm;
            stud1[i].reg_date.yy = stud[resizer].reg_date.yy;
            stud1[i].pay_date.dd = stud[resizer].pay_date.dd;
            stud1[i].pay_date.mm = stud[resizer].pay_date.mm;
            stud1[i].pay_date.yy = stud[resizer].pay_date.yy;
            stud1[i].stud_id = stud[resizer].stud_id;
            stud1[i].courses = stud[resizer].courses;
            stud1[i].total_pay = stud[resizer].total_pay;
            resizer++;
          }
       }
        delete []stud;  // copy values and delete previous array
        stud = stud1;   // pass address to reuse pointer
        stud1 = nullptr;
        retrial(1);
}
