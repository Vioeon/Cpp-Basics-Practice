#include<iostream>

using namespace std;

class ArrayUtil {
    public:
    //s1�� s2�� ������ ���ο� �迭�� ���� �����Ͽ� ����
    static int* concat(int s1[], int size1, int s2[], int size2, int&retSize);
    //s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����
    static int* remove(int s1[], int size1, int s2[], int size2, int&retSize);
};
//concat() �����մϴ�.
int* ArrayUtil::concat(int s1[], int size1, int s2[], int size2, int&retSize){
    //retsize = size1 + size2;
    //int *p = new int[retsize];
    // p <- s1�迭 �������
    // p <- s2�迭 �������
    // return p;
    retSize = size1 + size2;
    int *p = new int[retSize];
    
    for(int i=0; i<size1; i++){
        p[i] = s1[i];
    }
    for(int i=0; i<size2; i++){
        p[i+size1] = s2[i];
    }
    return p;
}
//remove() �����մϴ�.
int* ArrayUtil::remove(int s1[], int size1, int s2[], int size2, int&retSize){
    int *p = new int[size1];

    retSize = size1;

    for(int i=0; i<size1; i++){  // p s1�迭 �� ����
        p[i] = s1[i];
    }

    for(int i=0; i<retSize; i++){
        for(int j=0; j<size2; j++){
            if(p[i] == s2[j]){
                
                for(int k=i; k<retSize; k++){
                    p[k] = p[k+1];
                }
                retSize--;
            }
        }
    }
    return p;
}

int main() {
    int xcount = 0, ycount = 0;
    int *x, *y;

    //x�迭�� ������ ����(1~5)�� �Է� �޴´�. //�Է� ���� ����ŭ x�迭�� ���� �����Ѵ�. //������ �Է� �޾� x�迭�� �����Ѵ�.
    while(xcount < 1 || xcount > 5){
        cout << "x�迭�� ����(1~5)�� �� ��? " << endl;
        cin >> xcount;
    }
    x = new int[xcount];
    cout << "\nx�迭�� ������ ���� �Է� : " << endl;
    for(int i=0; i < xcount; i++){
        cin >> x[i];
    }
    
    //y�迭�� ������ ����(1~5)�� �Է� �޴´�. //�Է� ���� ����ŭ y�迭�� ���� �����Ѵ�. //������ �Է� �޾� x�迭�� �����Ѵ�.
    while(ycount < 1 || ycount > 5){
        cout << "y�迭�� ����(1~5)�� �� ��? " << endl;
        cin >> ycount;
    }
    y = new int[ycount];
    cout << "\ny�迭�� ������ ���� �Է� : " << endl;
    for(int i=0; i < ycount; i++){
        cin >> y[i];
    }

    int retsize = 0;

    ArrayUtil A;
    //concat() �Լ��� ȣ���Ѵ�.
    // �迭�� ��°�� �����ϴ°� �Ұ����ϱ� ������ �����Ҵ�� �迭�� �����ͷ� �޾ƾ��Ѵ�.
    int *conarr = A.concat(x, xcount, y, ycount, retsize);
    cout << "\nx�迭�� y�迭�� ������ �迭�� ";
    for (int i = 0; i < retsize; i++) cout << conarr[i] << ' ';
    cout << endl;

    //remove() �Լ��� ȣ���Ѵ�.
    int *remarr = A.remove(x, xcount, y, ycount, retsize);
    cout << "\nx�迭���� y�迭�� ���Ҹ� ������ ���, x�迭�� ������ " << retsize << "��, ";
    for (int i = 0; i < retsize; i++) cout << remarr[i] << ' ';
    cout << endl;

    //���� �Ҵ�� ��� ������ ���� �Ѵ�.
    delete[] x;
    delete[] y;
}