#include <iostream>

using namespace std;

void find2replace(string &fstr, string &fhas, string &fre, bool &fresult) {
    int i = 0;
    // find �Լ��� ã�ƾ� �Ѵ�.
    // fing�� -1�� �ɋ����� �ݺ��ؼ� ã�ƾ� �Ѵ�.
    // replace() �Լ��� �ʿ��ϴ�.
    // replace�Լ��� ������ ���̰� �ʿ��ϴ�.
    // ���̸� ã�� length()�Լ��� �ʿ���
    // �ݺ��� �ʿ���
    
    while (fstr[i]) {
        if (fstr[i] == fre) {
            fresult = true; //�߰���. �Լ� ����
        }
        if(i == strlen(fstr)){
            break;
        }
        i++;
    }
}

//
//find2replace() �Լ��� �����մϴ�. //
int main() {
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