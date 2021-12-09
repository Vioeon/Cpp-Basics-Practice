#include <iostream>
#include <string>

using namespace std;

//== main() ���� ó�� ==
class Pizza {
    string *size; //�����͸� ����
public:
     Pizza() = default;
     ~Pizza();
     void setSize(string s); //s �� size �� ����
    string getSize();
};
Pizza::~Pizza() {
    delete size; //���� �����ͼ������߱⶧���� delete�ʿ�
    cout << "�Ҹ��� I Had it all." <<endl;
}
void Pizza::setSize(string s) {
    Pizza::size = new string(s);
}
string Pizza::getSize() {
    return *Pizza::size; // *�� ������ �ּҰ� �ȴ�.
}

int main() {
    int count; //��������� �Է¹��� ����
    Pizza *p;
    string sml;

    cout <<"���� �� ��? "; //runŸ�Ӷ� ����, ����, new�� ���
    cin >> count;
    p = new Pizza[count]; //��ü ���� - ����Ʈ������`

    cout << "���� ũ���(small, medium, large)? ";
    cin >> sml;
    for (int i = 0; i < count; i++) {
        p[i].setSize(sml);
    }
    cout << endl;
    for (int i = 0; i < count; i++) {
         cout << i << ") " << p[i].getSize() << " Pizza Yammy" << endl;
    }
    cout << endl;

    delete[] p; //��� �޸� ����, ���ξȿ��� new�� ����ϸ� ���ο��� delete��� �ʼ�
    return 0;
}

//Manager����ϴ� ��� ���� �ʼ�
class Pizza {
    string *size;
public:
    Pizza() = default;
    ~Pizza();
    void setSize(string s); //s �� size �� ����
    string getSize();
};
Pizza::~Pizza() {
    delete size;
    cout << "�Ҹ��� I Had it all." <<endl;
}
void Pizza::setSize(string s) {
    Pizza::size = new string(s); //size�� �����Ϳ��� new���
}
string Pizza::getSize() {
 return *Pizza::size;  //return *size �ص� �ȴ�.
}

class PizzaManager {
    int count;
    Pizza *p;
    string sml;
public:
    PizzaManager() {
        cout <<"���� �� ��? ";
        cin >> count;
        p = new Pizza[count]; //��ü ���� - ����Ʈ������`

        cout << "���� ũ���(small, medium, large)? ";
        cin >> sml;
        for (int i = 0; i < count; i++) {
            p[i].setSize(sml);
        }
    }
    void status() {
    //Pizza Ŭ���� Ÿ���� �迭�� �� ��Ҹ��� getSize() ȣ��
    for (int i = 0; i < count; i++) {
        cout << i << ") " << p[i].getSize() << " Pizza Yammy" << endl;
    }
    cout << endl;
    }
    ~PizzaManager() {
        delete[] p; //��� �޸� ����, �����ڿ� new����ؼ� �Ҹ��ڿ� delete�ʼ�
    }
};

int main() {
    PizzaManager pm; // ������ ���� , main���� �ϴ����� pizzamanager�� �����ڿ� �� �ִ´�
    pm.status(); //Pizza Ŭ���� Ÿ���� �迭�� �� ��Ҹ��� getSize() ȣ��
    return 0;
}
