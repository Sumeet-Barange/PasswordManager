#include <string>
#ifndef VAULT_H
#define VAULT_H
using namespace std;

//1. VaultMenu
void vaultMenu(const std::string& username);

//2. Add Credential feature
void addCredential(const std::string& username);

//3. View Saved Credential feature
void viewAllCredentials(const std::string& username);

//4. Delete Saved Credential feature
void deleteCredential(const std::string& username);





#endif