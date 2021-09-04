void profit(){

    float tot{};
    cout << "\n\tProfit report: " << endl;
    cout << "Number of students: ";
    cout << stud_count << endl;
    for (int i{};i < stud_count;i++){
        tot += stud[i].total_pay;
    }
    school.total = tot;
    school.expense = tot * 0.75;
    school.net = school.total - school.expense;
    cout << "Total profit: ";
    cout << school.total << " birr." <<endl;
    cout << "Expenses: " << school.expense << " birr." << endl;
    cout << "Net profit: " << school.net << " birr." << endl;
    retrial(1);
}
void table(int i){
      int name;
          name = 31 - strlen(stud[i].name);
          cout << "SMS" << stud[i].stud_id << " | " << stud[i].name << setw(name) << " "
               << "| " << setw(4) << stud[i].age <<" | " << setw(6) << char(toupper(stud[i].sex))
               <<" | " << setw(7) << stud[i].pay_date.dd << "/" << setw(2) << stud[i].pay_date.mm << "/"
               << setw(4) << stud[i].pay_date.yy << " | " << setw(4) << stud[i].total_pay << " birr." << endl;
          cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

void admin(){

    system("cls");
    int password{1234};
    int num;
    cout << "\nAdministrator access required!" << endl;
    cout << "Password: ";
    cin >> num;
    for (int i = 0; i < 2;i++){
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
