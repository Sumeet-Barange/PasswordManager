#include <iostream>
#include <fstream>
#include <string>
#include "vault.h"
#include "auth.h"
#include "utils.h"
#include "json.hpp"
using json = nlohmann::json;
using namespace std;


void addCredential(const string& username) {
    string website,login,encryptedPassword;
    cout<<"Enter website :";
    cin>>website;
    cout<<"Enter login username :";
    cin>>login;
    cout<<"Enter password :";
    cin>>encryptedPassword;

    string hashed_password = encryptedPassword;
    for(char& ch : hashed_password){
        ch = ch^0x55;
    }
    string hashed_login = login;
    for(char& ch : hashed_login){
        ch = ch^0x55;
    }
    string hashed_website = website;
    for(char& ch : hashed_website){
        ch = ch^0x55;
    }
    
    json vault;
    ifstream inFile("vault_" + username + ".json");
    if (inFile.is_open()) {
    inFile >> vault;
    inFile.close();
    }

    vault.push_back({
    {"website", hashed_website},
    {"login", hashed_login},
    {"password", hashed_password}
    });

    ofstream outFile("vault_" + username + ".json");
    outFile << vault.dump(4);  // 4 = indent
    outFile.close(); 
}



void viewAllCredentials(const string& username){
    string website,login,encryptedPassword;
    json vault;
    ifstream file("vault_" + username + ".json");
    if (!file.is_open()) {
    cout << "No credentials found for user.\n";
    return;
    }
    file >> vault;
    file.close();


    cout<<"\n Saved Credentials \n";
    cout<<"Website\t\tUsername\tPassword\n";

    for (auto& entry : vault) {
    string website = entry["website"];
    string login = entry["login"];
    string password = entry["password"];

    for (char& ch : website) ch ^= 0x55;
    for (char& ch : login) ch ^= 0x55;
    for (char& ch : password) ch ^= 0x55;

    cout << website << "\t\t" << login << "\t\t" << password << endl;
    }

}


void deleteCredential(const string& username) {
    string targetwebsite;
    bool found = false;
    cout << "Enter website to delete: ";
    cin >> targetwebsite;

    for (char& ch : targetwebsite) ch ^= 0x55;

   
    json vault;
    ifstream inFile("vault_" + username + ".json");
    if (!inFile.is_open()) {
        cout << "No credentials found for user.\n";
        return;
    }
    inFile >> vault;
    inFile.close();

   
    json updatedVault = json::array();
    for (auto& entry : vault) {
        if (entry["website"] == targetwebsite) {
            found = true; 
        } else {
            updatedVault.push_back(entry);
        }
    }

    
    ofstream outFile("vault_" + username + ".json");
    outFile << updatedVault.dump(4);
    outFile.close();

   
    if (found) {
        cout << "Credential deleted successfully.\n";
    } else {
        cout << "No matching credential found.\n";
    }
}






void vaultMenu(const string& username){
    int choice;
    
    while (true){
        cout << "\nVault Menu for " << username << endl;
        cout << "Press 1 to Add a new credential" << endl;
        cout << "Press 2 to View all saved credentials" << endl;
        cout << "Press 3 to Delete a credential" << endl;
        cout << "Press 4 to Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {   
         addCredential(username);
         
        }
        
        else if (choice == 2)
        { 
        viewAllCredentials(username);
        
        }
        else if (choice == 3)
        {
         deleteCredential(username);
         break;
        }
        else if (choice == 4)
        {
         cout << "Logging out...\n";
         return;
        }
        else
        {  
          cout<<"Invalid choice. Try again."<<endl;
        }
       }
}