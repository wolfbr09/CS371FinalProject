#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
public:
    virtual ~Person() {}                    
    virtual string getUsername() = 0;       
};

#endif
