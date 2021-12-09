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
    void print(); //show()�Լ��� �̿��Ͽ� vec�� ����� ��� Student ��ü ���� ���
};

void Manager::run() {
    cout << ">> ���Ϳ� �л� �����͸� �����մϴ�." << endl;
    input2save();
    cout << ">> ���Ϳ� ����� ��� �л� �����͸� ����մϴ�." << endl;
    print();
}

void Manager::input2save() {
 //Student ��ü�� ���õ� ������ �Է� �޾� vec�� ����
    string n;
    int i;
    int count;

    cout << "�л� �����͸� �Է��ϼ���.(�Է� ����� quit)" << endl;
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
    cout << count << " ���� �л��� ����Ǿ����ϴ�." << endl;
    cout << endl;
}

void Manager::print() {
 //show()�Լ��� �̿��Ͽ� vec�� ����� ��� Student ��ü ���� ���
    for(auto &v : vec){
        v.show();
    }
}

int main(){
    Manager man;
    man.run();
}