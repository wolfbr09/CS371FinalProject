#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Login.h"
using namespace std;

class Person {
protected:
    Login* login;

public:
    Person(Login* loginPtr) : login(loginPtr) {}
    virtual ~Person() { delete login; }
    
    virtual string getUsername() { 
        return (login != nullptr) ? login->getUsername() : "";
    };
    Login* getLogin() { return login; }
};

#endif
