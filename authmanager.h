#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <iostream>
#include "user.h"

using namespace std;

class AuthManager {
private:
    User users[100];      
    int userCount = 0;    
public:
    bool registerUser(const string& id, const string& password) {
        for (int i = 0; i < userCount; ++i) {
            if (users[i].getId() == id) {
                cout << "User already exists!\n";
                return false;
            }
        }
        if (userCount < 100) {
            users[userCount++] = User(id, password);
            return true;
        } else {
            cout << "User limit reached!\n";
            return false;
        }
    }

    bool loginUser(const string& id, const string& password) {
        for (int i = 0; i < userCount; ++i) {
            if (users[i].getId() == id && users[i].checkPassword(password)) {
                return true;
            }
        }
        return false;
    }
};

#endif
