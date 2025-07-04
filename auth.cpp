#include <iostream>
#include <fstream>
#include <string>

#include "auth.h"
#include "utils.h"

using namespace std;

//1. Register
bool registerUser(){
    string username , password ;
    cout<<"Enter new username :";
    cin>>username;
    cout<<"Enter new password :";
    cin>>password;
    
    string hashed = hashPassword(password);

    ofstream file("users.txt", ios::app);  // append mode
    if (!file.is_open()) {
        cout << "Error opening user database.\n";
        return false;
    }   

    file<<username<<" "<<hashed<<endl;
    file.close();

    cout<<"User registered sucessfully! \n";
    return true;
}

//2. Login
string loginUser() {
    string username , password;
    cout<<"Enter username :";
    cin>>username;
    cout<<"Enter password :";
    cin>>password;

    string hashed = hashPassword(password);

    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "Error opening user database.\n";
        
    }

    string storedUsername, storeHash;
    while(file>>storedUsername>>storeHash){
        if(storedUsername == username && storeHash == hashed){
            cout<<"Login successfully!\n";
            return username;
        }
    }
    cout << "Invalid username or password.\n";
    return "";
}





