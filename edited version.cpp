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
               cout << "\n\t\tCourses" << endl;
               cout << "\t 1. Mathematics." << endl;
               cout << "\t 2. Physics." << endl;
               cout << "\t 3. Biology." << endl;
               cout << "\t 4. Chemistry." << endl;
               cout << "\t 5. English." << endl;
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
                  goto start;
                }
         break;
    }
      int num;
      cout << "\nEnter the number of people to register: ";
      cin >> num;
      if(stud_count + num >= intake_cap){
        cout << "Sorry there isn't enough vacancies for this academic term!" << endl;
        retrial(1);
      }
      int id = 1000;
      for (int i = stud_count;i < stud_count + num;i++){
          cout << "--------------------";
          cout << "\nName: "; cin.ignore();
          gets(stud[i].name);
          strupr(stud[i].name);
          cout << "\nAge: ";
          cin >> stud[i].age;
          cout << "\nSEX(M/F): ";
          cin >> stud[i].sex;
          cout << "\nToday's date(dd/mm/yy): with spaces: ";
          cin >> stud[i].reg_date.dd >> stud[i].reg_date.mm
              >> stud[i].reg_date.yy;
          stud[i].pay_date.dd = stud[i].reg_date.dd;
          stud[i].pay_date.mm = stud[i].reg_date.mm + 1;
          stud[i].pay_date.yy = stud[i].reg_date.yy;
          stud[i].stud_id = id + i;
          Coursechoice(i);
          system("cls");
      }
      for (int i = stud_count;i < stud_count + num;i++){
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
      reorder();
      retrial(1);
                        }
void searching(){
      system("cls");
      int countt{},num;
      char str[30];
      cout << "Enter search by \n 1. Name or \n2.  ID: " << endl;
      cout << "Choice: "; cin >> num;
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
      cout << "Result: " << endl;
      for (int i{}; i < stud_count; i++){
        if (stricmp(stud[i].name, str) == 0 || stud[i].stud_id == num){
            table(i);
            countt++;
        }
      }
      if (countt == 0){
        cout << "No results." << endl;
      }
      retrial(1);
}
