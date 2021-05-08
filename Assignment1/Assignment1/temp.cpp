#include <iostream>
#define MAX 100
using namespace std;


//특수문자를 없애는 함수
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
    //대문자를 소문자로 바꿈
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] += 32;
        }
    }
    char* M = ESS(arr);
    cout << arr << endl;


}