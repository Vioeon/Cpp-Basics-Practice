#include <iostream>
#include <iomanip>
using namespace std;

class Array{
    int capacity; //데이터 최대용량, int전체조건 힙영역에 들어가는 vector구현하라
    int size; //데이터 저장된 수
    int *arr; //힙에 생성된 배열의 첫번째 요소를 가리키는 포인터, 배열을 의미
public:
    Array() = default;
    Array(int capacity);
    ~Array();
    void insert(); // 인플레이스 벡
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
        cout << "데이터" << value << "는 추가할 수 없습니다. 배열이 가득찼습니다." << endl;
        return;
    }
    arr[size] = value;
    size++;
}
void Array::print() const{
setw(4) // 4자리의 위치에 정수를 출력해달라 include 필요
    cout << "arr = ";
}

int main(){
    int count;
    cout << "array size? ";
    cin >> count;

    Array array1(count); //객체생성, 생성자호출, 크기가 count 인 배열 생성

    for (int i = 0; i < count; i++) { 
        array1.insert(i+10); 
    }
    array1.print();
    array1.insert(34);
    cout << endl;

    return 0;
}
