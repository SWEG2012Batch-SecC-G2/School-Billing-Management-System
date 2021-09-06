void set_intake(){

       cout << "Enter new intake capacity: ";
       cin >> intake_cap;
       stud1 = new studInfo[intake_cap];
       for (int i{};i < intake_cap;i++){
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
        if (stud_count >= intake_cap){
            cout << "You have removed " << stud_count - intake_cap
                 << " students from the registration list." << endl;
            stud_count = intake_cap;
        }
        retrial(1);
}
void set_pay(){

    int cnum;
    cout << "\n How many course prices will you be changing(max = 5): ";
    cout << "\n\t\tCourses" << endl;
    cout << "\t1. Mathematics." << endl;
    cout << "\t2. Physics." << endl;
    cout << "\t3. Biology." << endl;
    cout << "\t4. Chemistry." << endl;
    cout << "\t5. English." << endl;
    cout << "Choice: ";
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
}
void overdue(){

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
    for (int i{};i < stud_count;i++){
        if (today.yy <= stud[i].pay_date.yy &&
            today.mm <= stud[i].pay_date.mm &&
            today.dd <= stud[i].pay_date.dd){
           cout << "No overdue payments." << endl;
        }
        else{
          table(i);
        }
    }
    retrial(1);
}
