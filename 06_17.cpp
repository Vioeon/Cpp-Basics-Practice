#include<iostream>

using namespace std;

class Account {
    int balance; //�ܾ�
public:
    Account(int deposit) : balance(deposit) { };
    int getBalance() { return balance; }
    void setBalance(int deposit) { this->balance = deposit; }
    void show() {
    cout << "�ܾ��� " << balance << "�� �Դϴ�." << endl;
    }
};

void increaseBy(Account &facc, int fin){  // �Ű������� ���۷���(&)�� ����
    //int n = facc.getBalance() + fin;
    //facc.setBalance(n);
    facc.setBalance(facc.getBalance() + fin);
}
//
//increaseBy() �Լ��� �ۼ��մϴ�. //
int main() {
    Account acc(500);
    cout << "�Ա� �� "; acc.show();
    int in;
    cout << "�Աݾ� : ";
    cin >> in;
    increaseBy(acc, in);
    cout << "�Ա� �� "; acc.show();
}