#include <iostream>
#include <string>

using namespace std;

//== main() 에서 처리 ==
class Pizza {
    string *size; //포인터만 선언
public:
     Pizza() = default;
     ~Pizza();
     void setSize(string s); //s 를 size 에 대입
    string getSize();
};
Pizza::~Pizza() {
    delete size; //위에 포인터선언을했기때문에 delete필요
    cout << "소멸자 I Had it all." <<endl;
}
void Pizza::setSize(string s) {
    Pizza::size = new string(s);
}
string Pizza::getSize() {
    return *Pizza::size; // *이 없으면 주소가 된다.
}

int main() {
    int count; //사용자한테 입력받을 변수
    Pizza *p;
    string sml;

    cout <<"피자 몇 판? "; //run타임때 실행, 동적, new를 사용
    cin >> count;
    p = new Pizza[count]; //객체 생성 - 디폴트생성자`

    cout << "피자 크기는(small, medium, large)? ";
    cin >> sml;
    for (int i = 0; i < count; i++) {
        p[i].setSize(sml);
    }
    cout << endl;
    for (int i = 0; i < count; i++) {
         cout << i << ") " << p[i].getSize() << " Pizza Yammy" << endl;
    }
    cout << endl;

    delete[] p; //멤버 메모리 해제, 메인안에서 new를 사용하면 메인에서 delete사용 필수
    return 0;
}

//Manager사용하는 방식 강추 필수
class Pizza {
    string *size;
public:
    Pizza() = default;
    ~Pizza();
    void setSize(string s); //s 를 size 에 대입
    string getSize();
};
Pizza::~Pizza() {
    delete size;
    cout << "소멸자 I Had it all." <<endl;
}
void Pizza::setSize(string s) {
    Pizza::size = new string(s); //size가 포인터여서 new사용
}
string Pizza::getSize() {
 return *Pizza::size;  //return *size 해도 된다.
}

class PizzaManager {
    int count;
    Pizza *p;
    string sml;
public:
    PizzaManager() {
        cout <<"피자 몇 판? ";
        cin >> count;
        p = new Pizza[count]; //객체 생성 - 디폴트생성자`

        cout << "피자 크기는(small, medium, large)? ";
        cin >> sml;
        for (int i = 0; i < count; i++) {
            p[i].setSize(sml);
        }
    }
    void status() {
    //Pizza 클래스 타입의 배열의 각 요소마다 getSize() 호출
    for (int i = 0; i < count; i++) {
        cout << i << ") " << p[i].getSize() << " Pizza Yammy" << endl;
    }
    cout << endl;
    }
    ~PizzaManager() {
        delete[] p; //멤버 메모리 해제, 생성자에 new사용해서 소멸자에 delete필수
    }
};

int main() {
    PizzaManager pm; // 생성자 생성 , main에서 하던일을 pizzamanager의 생성자에 다 넣는다
    pm.status(); //Pizza 클래스 타입의 배열의 각 요소마다 getSize() 호출
    return 0;
}
