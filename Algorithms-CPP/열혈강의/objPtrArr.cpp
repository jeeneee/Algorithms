//
//  objPtrArr.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 05/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char * name;
    int age;
public:
    Person(const char * myname, const int myage): age(myage) {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    Person() {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }
    void SetPersonInfo(char * myname, int myage) {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo() const {
        cout << "이름: " << name << ", ";
        cout << "나이: " << age << endl;
    }
    ~Person() {
        delete []name;
        cout << "called destructor! " << endl;
    }
};

int main() {
    Person * parr[3];
    char namestr[100];
    int age;
    
    for (int i = 0; i < 3; i++) {
        cout << "이름: ";
        cin >> namestr;
        cout << "나이: ";
        cin >> age;
        parr[i] = new Person(namestr, age);
    }
    
    parr[0]->ShowPersonInfo();
    parr[1]->ShowPersonInfo();
    parr[2]->ShowPersonInfo();
    delete parr[0];
    delete parr[1];
    delete parr[2];

    return 0;
}
