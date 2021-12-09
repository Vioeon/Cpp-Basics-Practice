#include<iostream>
#include<string>

using namespace std;

void message_print(string&& a){  // Rvalue 레퍼런스를 파라미터로 받을 때 '&&' 를 쓴다
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
    message_print(move(stra));  // rvalue 가 된다.
    message_print(stra + strb);  // lvalue + lvalue = rvalue 가 된다
    return 0;
}