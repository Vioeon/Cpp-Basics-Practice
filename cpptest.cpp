#include <iostream>
#include <iomanip>
using namespace std;

class Array {
    double *ptr;  // == double ptr[?] ������ ��� �ҽ��� �̷��� ����Ұ���
    int size;
public:
    Array(int size);  // �迭 ������
    ~Array();  //delete [] �ʿ�
    void show(string name);
    //[] ������ �ߺ�
    //= ������ �ߺ�
    double& operator[](int index);
    Array& operator=(const Array &op);
};
Array::Array(int s) : size(s){  // ������
    ptr = new double[size];
}
Array::~Array(){  // �Ҹ���
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
        cout << "�ε��� ���� �ʰ� ����" << endl;
        exit(1);
    }
    return ptr[index];
}

Array& Array::operator=(const Array &op){  // &op �� ���۷��� ������
    if(this == &op){  // &op �� �ּ� �� *** ���� �߿��� *** 
        return *this;
    }
    delete ptr;  // main���� �̹� �����Ǿ� �����Ƿ� �޸� �ʱ�ȭ��
    ptr = nullptr;
    size = op.size;
    ptr = new double[size];  //  �ٽ� ����

    for(auto i=0; i < size; i++){
        this->ptr[i] = o p.ptr[i];
    }
    return *this;  // ����Ÿ���� & ���۷������� �����͸� ����Ѵ�.
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

    brr = arr;  // = ���� �����ڸ� ������ ��
    brr.show("brr");

    brr[2] = 34.5;
    brr[4] = 56.3;
    arr.show("arr");
    brr.show("brr");

    return 0;
}