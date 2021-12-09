#include<iostream>

using namespace std;

class Person {
    string name;
public:
    Person() = default;
    Person(string n) : name {n} { cout << "생성자 실행" << endl; };
    Person(const Person &person); //복사 생성자
    Person(Person&& p); //이동 생성자
    ~Person() { cout << "소멸자 실행" << endl; };
    void show(string obj) { cout << obj << " name = "<< name << endl; }
};

Person::Person(const Person &person){  // 복사 생성자
    cout << "복사 생성자 실행" << endl;
    this->name = person.name;
}
Person::Person(Person&& p){  // 이동 생성자
    cout << "이동 생성자 실행" << endl;
    this->name = p.name;

    p.name.clear();  // clear()메소드로 p객체의 메모리를 비워준다.
}
//
//복사 생성자와 이동 생성자를 구현하세요. //

int main() {
     cout << "-1----------" << endl;
    Person dan("daniel");  // 생성자 호출 name = daniel
    Person ben = Person("benny");  // 생성자 호출 name = daniel
    cout << "-2----------" << endl;
    Person mvdan = move(dan);  // 이동 생성자 호출 mvdan에 dan의 소유권을 넘김-> dan사라짐
    cout << "-3----------" << endl;
    Person cpben = ben;  // 복사 생성자 호출 원래의 ben객체를 cpben객체에 복사
    Person cpmvdan(mvdan);  // 복사 생성자 호출 mvdan이 cpmvdan에 복사
    // mvden의 매개변수 move(dan)이 있어서 복사됨.
    cout << "-4----------" << endl;
    dan.show("dan");  // x dan의 소유권이 mvdan에 넘어가서 dan에는 소유권이 없으므로 출력X
    ben.show("ben");  // benny
    mvdan.show("mvdan");  // daniel
    cpben.show("cpben");  // benny
    cpmvdan.show("cpmvdan");  // daniel
    return 0;
}