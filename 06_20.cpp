#include<iostream>
#include<cstring>

using namespace std;

class Person {
    char *name;  // C프로그래밍 방식
public:
    Person() = default;
    Person(const char *n);
    Person(const Person &person); //복사 생성자
    Person(Person&& p); //이동 생성자
    ~Person() { cout << "소멸자 실행" << endl; };
    void show(string obj);
};
Person::Person(const char *n){
    cout << "생성자 실행" << endl;
    this->name = new char[strlen(n)+1];
    strcpy(this->name, n);
}
Person::Person(const Person &person){  // 복사 생성자
    cout << "복사 생성자 실행" << endl;
    int len = strlen(person.name);
    this->name = new char[len+1];
    strcpy(this->name, person.name);
}
Person::Person(Person&& p){  // 이동 생성자
    cout << "이동 생성자 실행" << endl;
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