#include<iostream>

using namespace std;

class Person {
    string name;
public:
    Person() = default;
    Person(string n) : name {n} { cout << "������ ����" << endl; };
    Person(const Person &person); //���� ������
    Person(Person&& p); //�̵� ������
    ~Person() { cout << "�Ҹ��� ����" << endl; };
    void show(string obj) { cout << obj << " name = "<< name << endl; }
};

Person::Person(const Person &person){  // ���� ������
    cout << "���� ������ ����" << endl;
    this->name = person.name;
}
Person::Person(Person&& p){  // �̵� ������
    cout << "�̵� ������ ����" << endl;
    this->name = p.name;

    p.name.clear();  // clear()�޼ҵ�� p��ü�� �޸𸮸� ����ش�.
}
//
//���� �����ڿ� �̵� �����ڸ� �����ϼ���. //

int main() {
     cout << "-1----------" << endl;
    Person dan("daniel");  // ������ ȣ�� name = daniel
    Person ben = Person("benny");  // ������ ȣ�� name = daniel
    cout << "-2----------" << endl;
    Person mvdan = move(dan);  // �̵� ������ ȣ�� mvdan�� dan�� �������� �ѱ�-> dan�����
    cout << "-3----------" << endl;
    Person cpben = ben;  // ���� ������ ȣ�� ������ ben��ü�� cpben��ü�� ����
    Person cpmvdan(mvdan);  // ���� ������ ȣ�� mvdan�� cpmvdan�� ����
    // mvden�� �Ű����� move(dan)�� �־ �����.
    cout << "-4----------" << endl;
    dan.show("dan");  // x dan�� �������� mvdan�� �Ѿ�� dan���� �������� �����Ƿ� ���X
    ben.show("ben");  // benny
    mvdan.show("mvdan");  // daniel
    cpben.show("cpben");  // benny
    cpmvdan.show("cpmvdan");  // daniel
    return 0;
}