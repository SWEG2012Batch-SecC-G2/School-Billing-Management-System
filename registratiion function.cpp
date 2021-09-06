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
          cin >> stud[i].reg_date.dd >> stud[i].reg_date.mm>> stud[i].reg_date.yy;
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
