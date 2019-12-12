//
//  NameCard.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 05/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
    enum {CLERK, SENIOR, ASSIST, MANAGER};
    void ShowPosition(int pos) {
        switch (pos) {
            case CLERK:
                cout << "사원" << endl;
                break;
            case SENIOR:
                cout << "주임" << endl;
                break;
            case ASSIST:
                cout << "대리" << endl;
                break;
            case MANAGER:
                cout << "과장" << endl;
                break;
        }
    }
}

class NameCard {
private:
    char * name;
    char * company;
    char * phone;
    int pos;
    
public:
    NameCard(const char *_name, const char *_comp_name,
             const char *_tel, const int _pos): pos(_pos) {
        name = new char[strlen(_name) + 1];
        company = new char[strlen(_comp_name) + 1];
        phone = new char[strlen(_tel) + 1];
        strcpy(name, _name);
        strcpy(company, _comp_name);
        strcpy(phone, _tel);
    }
    void ShowNameCardInfo() const {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << phone << endl;
        cout << "직급: "; COMP_POS::ShowPosition(pos);
        cout << endl;
    }
    ~NameCard() {
        delete []name;
        delete []company;
        delete []phone;
    }
};

int main() {
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    
    return 0;
}
