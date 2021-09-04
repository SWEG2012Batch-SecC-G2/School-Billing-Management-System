void statreport(){
    system("cls");
    start:
    cout << "\n\t\tStatistics and Report Menu" << endl;
    cout << "\n\t1. Student list." << endl;
    cout << "\t2. Students above 18 years of age." << endl;
    cout << "\t3. Students less than 18 years of age." << endl;
    cout << "\t4. Number of students taking each course." << endl;
    cout << "\t5. Students paying over 1000 birr." << endl;
    cout << "\n Choice: ";
    int report;
    cin >> report;
    cout << "Result:" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << " ID " << setw(4) << " " << "| Name "
         << setw(26) << " " << "| Age " << setw(1) << " "
         << "| SEX " << setw(3) << " " << "| Payment date " << setw(3) << " "
         << "|Total Payment " << setw(10) << " " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    switch(report){
       case 1: for (int i{};i < stud_count;i++){
                 table(i);
               }
                retrial(1);
               break;
       case 2: for (int i{};i < stud_count;i++){
                 if (stud[i].age >= 18){
                      table(i);
                 }
               }
                retrial(1);
                break;
       case 3: for (int i{};i < stud_count;i++){
                 if (stud[i].age < 18){
                      table(i);
                 }
               }
                retrial(1);
                break;
       case 4: system("cls");
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
void reorder(){
    for (int i{};i < stud_count;i++){
        for (int j{};j < stud_count - 1;j++){
            if (stricmp(stud[j + 1].name, stud[j].name) <= 1){
                swap(stud[j + 1], stud[j]);
            }
        }
    }
}
