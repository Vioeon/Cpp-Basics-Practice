#include <iostream>
#include <string>

using namespace std;

void find2replace(string &fstr, string &fhas, string &fre, bool &fresult) {
    // find �Լ��� ã�ƾ� �Ѵ�.
    // fing�� -1�� �ɋ����� �ݺ��ؼ� ã�ƾ� �Ѵ�.
    // replace() �Լ��� �ʿ��ϴ�.
    // replace�Լ��� ������ ���̰� �ʿ��ϴ�.
    // ���̸� ã�� length()�Լ��� �ʿ���
    // �ݺ��� �ʿ���
    while(1){
        int n = fstr.find(fhas);
        fstr.replace(n, fhas.length(), fre);

        if(fstr.find(fhas) == -1){
            fresult = true;
            break;
        }
    }
}

int main(){
    std::string str = "C++ programming";
    std::string has = "+";
    string replace = "p";
    bool result = false;

    cout << "���� �� ���ڿ� = " << str << endl;

    find2replace(str, has, replace, result);
    
    if (result == true)
        cout << "���� �� ���ڿ� = " << str << endl;
    else
        cout << str << "���� " << has << "�� �߰����� ����." << endl;
    return 0;
}