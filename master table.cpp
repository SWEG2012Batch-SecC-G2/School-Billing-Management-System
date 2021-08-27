#include<iostream>
using namespace std;

void mainmenu();

int main()
{
   system("color f0");
   mainmenu();
}
void mainmenu()
{
    here:
    int n;
    cout << "\n\t\tMain Menu" << endl;
    cout << "\n\t1. Registration options." << endl;
    cout << "\t2. Administration options." << endl;
    cout << "\t3. Statistical reports." << endl;
    cout << "\t4. Search option." << endl;
    cout << "\n Choice: ";
    cin >> n;
    switch (n){
       case 1: break;
       case 2: break;
       case 3: break;
       case 4: break;
       default:
         cout << "Invalid choice, would you like to try again(y/n)?" << endl;
         char retry;
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
