#include <iostream>
#include <iomanip>
using namespace std;

class SortedArray {
    int size; //���� �迭�� ũ��
    int *p; //���� �迭�� ���� ������
    void sort(); //���� �迭�� ������������ ����
public:
    SortedArray(); //p�� nullptr�� size�� 0���� �ʱ�ȭ
    SortedArray(SortedArray &arr); //���� ������
    SortedArray(int arr[], int size); //������. ���� �迭�� ũ�⸦ ���޹޾� p�� ���� �� sort() ȣ��
    ~SortedArray(); //�Ҹ���
    SortedArray operator+(SortedArray &b);
    SortedArray &operator=(const SortedArray &b); //���� �迭�� b �迭�� ����
    void show(string name); //�迭�� ���� ���
};

SortedArray::SortedArray(){
    p = nullptr;
    size = 0;
}
SortedArray::SortedArray(int arr[], int size){
    this->size = size;
    this->p = new int[size];

    for(int i=0; i<size; i++){
        this->p[i] = arr[i];
    }
    sort();
}
SortedArray::SortedArray(SortedArray &arr){ //���� ������
    this->size = arr.size;
    this->p = new int[size];

    for(int i=0; i<size; i++){
        this->p[i] = arr.p[i];
    }
    
}
SortedArray::~SortedArray(){
    if(p != nullptr){ 
        delete [] p;
    }
}
SortedArray SortedArray::operator+(SortedArray &b){
    SortedArray tmp;
    tmp.size = this->size + b.size;
    tmp.p = new int[tmp.size];

    for(int i=0; i < this->size; i++){
        tmp.p[i] = this->p[i];
    }
    for(int i=0; i < b.size; i++){
        tmp.p[i+this->size] = b.p[i];
    }
    tmp.sort();
    return tmp;
}
SortedArray &SortedArray::operator=(const SortedArray &b){
    if(this == &b){  // &b �� �ּ�
        return *this;
    }
    this->size = b.size;
    this->p = new int[b.size];

    for(auto i=0; i < b.size; i++){
        this->p[i] = b.p[i];
    }
    sort();
    return *this;  // ����Ÿ���� & ���۷������� �����͸� ����Ѵ�.
}

void SortedArray::show(string name){
    cout << name << " = { ";
    for(int i = 0; i < size; i++){
        cout << p[i] << " ";
    }
    cout << "}" << endl;
}

void SortedArray::sort() { //�������� ���� ����
    if (p == nullptr || size == 0)
    return;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size - 1; j++) {
            if (p[j] > p[j + 1]) {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};
    SortedArray a(n, 3), b(m, 4), c;  // ���������) ��ü�� ����鼭 �ʱ�ȭ�Ҷ� ��������� ȣ��

    c = a + b;  // ������Կ�����

    a.show("a");
    b.show("b");
    c.show("c");
}