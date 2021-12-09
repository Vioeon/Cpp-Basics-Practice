#include<iostream>
#include<string>

using namespace std;

void message_print(string&& a){  // Rvalue ���۷����� �Ķ���ͷ� ���� �� '&&' �� ����
    cout << "message = " << a << endl;
}
void message_print(string& a){
    cout << "lvalue reference : " << a << endl;
}
int main() {
    string stra = "apple";  // lvalue
    string strb = "banana";  // lvalue
    message_print(stra);  // lvalue
    message_print(strb);  // lvalue
    message_print(move(stra));  // rvalue �� �ȴ�.
    message_print(stra + strb);  // lvalue + lvalue = rvalue �� �ȴ�
    return 0;
}