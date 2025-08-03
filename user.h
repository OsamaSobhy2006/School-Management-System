#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string id;
    string password;

public:
    User() {}
    User(string uid, string pass) {
        id = uid;
        password = pass;
    }

    string getId() const { return id; }
    string getPassword() const { return password; }

    bool checkPassword(const string& pass) const {
        return password == pass;
    }
};

#endif
