#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Student{
    string name;
    int id;
public:
    Student() = default;
    Student(string name, int id) : name(name), id(id) {};
    ~Student() = default;
    void show() { cout << "name: " << name << ", id: " << id << endl; }
};

class Manager{
    vector<Student> vec;
public:
    void run();
    void input2save();
    void print(); //show()함수를 이용하여 vec에 저장된 모든 Student 객체 정보 출력
};

void Manager::run() {
    cout << ">> 벡터에 학생 데이터를 저장합니다." << endl;
    input2save();
    cout << ">> 벡터에 저장된 모든 학생 데이터를 출력합니다." << endl;
    print();
}

void Manager::input2save() {
 //Student 객체와 관련된 정보를 입력 받아 vec에 저장
    string n;
    int i;
    int count;

    cout << "학생 데이터를 입력하세요.(입력 종료는 quit)" << endl;
    while(true){
        cout << "name : ";
        getline(cin, n);
        if(n == "quit"){
            break;
        }
        cout << "id : ";
        cin >> i;
        cin.ignore();

        count++;
        vec.emplace_back(n, i);
    }
    cout << count << " 명의 학생이 저장되었습니다." << endl;
    cout << endl;
}

void Manager::print() {
 //show()함수를 이용하여 vec에 저장된 모든 Student 객체 정보 출력
    for(auto &v : vec){
        v.show();
    }
}

int main(){
    Manager man;
    man.run();
}