#include<iostream>
#include<cstring>

using namespace std;

class Person {
    char *name;  // C���α׷��� ���
public:
    Person() = default;
    Person(const char *n);
    Person(const Person &person); //���� ������
    Person(Person&& p); //�̵� ������
    ~Person() { cout << "�Ҹ��� ����" << endl; };
    void show(string obj);
};
Person::Person(const char *n){
    cout << "������ ����" << endl;
    this->name = new char[strlen(n)+1];
    strcpy(this->name, n);
}
Person::Person(const Person &person){  // ���� ������
    cout << "���� ������ ����" << endl;
    int len = strlen(person.name);
    this->name = new char[len+1];
    strcpy(this->name, person.name);
}
Person::Person(Person&& p){  // �̵� ������
    cout << "�̵� ������ ����" << endl;
    int len = strlen(p.name);
    this->name = new char[len+1];
    strcpy(this->name, p.name);

    p.name = nullptr;
}

void Person::show(string obj){
    if(this->name == nullptr)
    cout << obj << "name = " << endl;
    else
    cout << obj << "name = " << this->name << endl;
}

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