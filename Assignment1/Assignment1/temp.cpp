#include <iostream>
#define MAX 100
using namespace std;


//Ư�����ڸ� ���ִ� �Լ�
char* ESS(char a[]) {
    int size = strlen(a);
    int i = 0;

    for (i = 0; i < size; i++) {
        if (a[i] < 'A' || a[i] > 'Z') {
            memmove(a + i, a + i + 1, strlen(a));
        }
        else {
            break;
        }
        ESS(a);
    }

    return a;

}


int main() {
    char arr[MAX] = { 0 };

    gets_s(arr);

    int size = strlen(arr);
    //�빮�ڸ� �ҹ��ڷ� �ٲ�
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] += 32;
        }
    }
    char* M = ESS(arr);
    cout << arr << endl;


}