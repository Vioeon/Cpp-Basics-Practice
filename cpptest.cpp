#include <iostream>
#include <iomanip>
using namespace std;

class Array {
    double *ptr;  // == double ptr[?] 앞으로 모든 소스는 이렇게 사용할거임
    int size;
public:
    Array(int size);  // 배열 생성함
    ~Array();  //delete [] 필요
    void show(string name);
    //[] 연산자 중복
    //= 연산자 중복
    double& operator[](int index);
    Array& operator=(const Array &op);
};
Array::Array(int s) : size(s){  // 생성자
    ptr = new double[size];
}
Array::~Array(){  // 소멸자
    delete [] ptr;
}
void Array::show(string name){
    cout << name << " = { ";
    for(int i = 0; i < size; i++){
        cout << ptr[i] << " ";
    }
    cout << "}" << endl;
}
double& Array::operator[](int index){
    if(index < 0 || index >= size){
        cout << "인덱스 범위 초과 오류" << endl;
        exit(1);
    }
    return ptr[index];
}

Array& Array::operator=(const Array &op){  // &op 는 레퍼런스 참조임
    if(this == &op){  // &op 는 주소 임 *** 아주 중요함 *** 
        return *this;
    }
    delete ptr;  // main에서 이미 생성되어 있으므로 메모리 초기화함
    ptr = nullptr;
    size = op.size;
    ptr = new double[size];  //  다시 생성

    for(auto i=0; i < size; i++){
        this->ptr[i] = o p.ptr[i];
    }
    return *this;  // 리턴타입이 & 레퍼런스여서 포인터를 써야한다.
}

int main() {
    int size;
    cout << "array size ? ";
    cin >> size;

    Array arr(size), brr(size);

    for (int i = 0; i < size; i++) {
        cout << i << ") input>> ";
        cin >> arr[i];
    }
    arr.show("arr");

    brr = arr;  // = 대입 연산자를 만들어야 함
    brr.show("brr");

    brr[2] = 34.5;
    brr[4] = 56.3;
    arr.show("arr");
    brr.show("brr");

    return 0;
}