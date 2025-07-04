#include <iostream>
#include<string>

using namespace std;

string hashPassword(const string& password) {
    string hashed = password;
    for(char& ch : hashed){
        ch = ch^0x55;
    }
    return hashed;
}