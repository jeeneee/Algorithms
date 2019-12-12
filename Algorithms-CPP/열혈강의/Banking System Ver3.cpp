//
//  Banking System Ver3.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/21.
//  Copyright © 2019 장우진. All rights reserved.
//

/*
 Banking System Ver 0.3
 Account 클래스 깊은 복사 생성자 적용
 */

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);        // 메뉴출력
void MakeAccount(void);     // 계좌개설
void DepositMoney(void);    // 입금
void WithdrawMoney(void);   // 출금
void ShowAllAccInfo(void);  // 잔액조회

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account {
private:
  int accID;      // 계좌번호
  int balance;    // 잔  액
  char *cusName;  // 고객이름
  
public:
  // 초기화
  Account(int ID, int money, char *name) : accID(ID), balance(money) {
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
  }
  
  Account(const Account &ref) : accID(ref.accID), balance(ref.balance) {
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
  }
  
  // 계좌 가져오기
  int GetAccID() { return accID; }
  
  // 입금
  void Deposit(int money) { balance += money; }
  
  // 출금액 반환 (부족 시 0 반환)
  int Withdraw(int money) {
    if (balance < money)
      return 0;
    
    balance -= money;
    return balance;
  }
  
  // 계좌 정보 출력
  void ShowAccInfo() {
    cout << "계좌 ID: " << accID << endl;
    cout << "이름: " << cusName << endl;
    cout << "잔액: " << balance << endl;
  }
  
  // 소멸자
  ~Account() {
    delete []cusName;
  }
};

Account * accArr[100];
int accNum = 0;

int main() {
  int choice;
  while (1) {
    ShowMenu();
    cout << "선택: ";
    cin >> choice;
    cout << endl;
    
    switch (choice) {
      case MAKE:
        MakeAccount();
        break;
      case DEPOSIT:
        DepositMoney();
        break;
      case WITHDRAW:
        WithdrawMoney();
        break;
      case INQUIRE:
        ShowAllAccInfo();
        break;
      case EXIT:
        for (int i = 0; i < accNum; ++i)
          delete accArr[i];
        return 0;
      default:
        cout << "Illegal selection.." << endl;
    }
  }
  
  return 0;
}

void ShowMenu(void) {
  cout << "-----Menu-----" << endl;
  cout << "1. 계좌개설" << endl;
  cout << "2. 입  금" << endl;
  cout << "3. 출  금" << endl;
  cout << "4. 계좌정보 전체 출력" << endl;
  cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void) {
  int id;
  char name[NAME_LEN];
  int balance;
  
  cout << "[계좌개설]" << endl;
  cout << "계좌ID: "; cin >> id;
  cout << "이름: "; cin >> name;
  cout << "입금액: "; cin >> balance;
  cout << endl;
  
  accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void) {
  int money;
  int id;
  cout << "[입  금]" << endl;
  cout << "계좌ID: "; cin >> id;
  cout << "입금액: "; cin >> money;
  
  for (int i = 0; i < accNum; ++i) {
    if (accArr[i]->GetAccID() == id) {
      accArr[i]->Deposit(money);
      cout << "입금완료" << endl;
      return;
    }
  }
  cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney(void) {
  int money;
  int id;
  cout << "[출  금]" << endl;
  cout << "계좌ID: "; cin >> id;
  cout << "출금액: "; cin >> money;
  
  for (int i = 0; i < accNum; ++i) {
    if (accArr[i]->GetAccID() == id) {
      if (accArr[i]->Withdraw(money) == 0) {
        cout << "잔액부족" << endl << endl;
        return;
      }
      cout << "출금완료" << endl << endl;
      return;
    }
  }
  cout << "유효하지 않은 ID 입니다." << endl << endl;
}
void ShowAllAccInfo(void) {
  for (int i = 0; i < accNum; ++i) {
    accArr[i]->ShowAccInfo();
    cout << endl;
  }
}
