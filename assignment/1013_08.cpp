#include <iostream>
#include <iomanip>
using namespace std;

class Array{
    int capacity; //������ �ִ�뷮, int��ü���� �������� ���� vector�����϶�
    int size; //������ ����� ��
    int *arr; //���� ������ �迭�� ù��° ��Ҹ� ����Ű�� ������, �迭�� �ǹ�
public:
    Array() = default;
    Array(int capacity);
    ~Array();
    void insert(); // ���÷��̽� ��
    void print();
}
Array::Array(int cap) : capacity(cap){
    arr = new int[capacity];
    size = 0;
}
Array::~Array(){
    delete [] arr;
}
void Array::insert(int value){
    if(size == capacity){
        cout << "������" << value << "�� �߰��� �� �����ϴ�. �迭�� ����á���ϴ�." << endl;
        return;
    }
    arr[size] = value;
    size++;
}
void Array::print() const{
setw(4) // 4�ڸ��� ��ġ�� ������ ����ش޶� include �ʿ�
    cout << "arr = ";
}

int main(){
    int count;
    cout << "array size? ";
    cin >> count;

    Array array1(count); //��ü����, ������ȣ��, ũ�Ⱑ count �� �迭 ����

    for (int i = 0; i < count; i++) { 
        array1.insert(i+10); 
    }
    array1.print();
    array1.insert(34);
    cout << endl;

    return 0;
}
