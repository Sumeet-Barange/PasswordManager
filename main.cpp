#include <iostream>
#include "auth.h"
#include "utils.h"
#include "vault.h"
using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n_=_=_=_=_=_=_=_=_=_Password Manager_=_=_=_=_=_=_=_=_=_" << endl;
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {   if (registerUser()) cout << "Registration complete.\n";
            else cout << "Registration failed.\n";
            
        }
        
        else if (choice == 2)
        {   string username = loginUser();
            if (!username.empty()) {
            cout << "Login complete.\n";
            vaultMenu(username);  
            }   
            else {
            cout << "Login failed.\n";
            }
        }
           
        
        else if (choice == 3)
        {
            cout<<"Exiting... Goodbye!"<<endl;
            break;
        }
        
        else
        {  
          cout<<"Invalid choice. Try again."<<endl;
        }
       }    
   



    return 0;
}
