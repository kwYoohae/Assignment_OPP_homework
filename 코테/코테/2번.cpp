#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char command[10] = { 0 , };
    int count = 0; // 저장 번호
    int j = 0;
    char** word = new char* [100];

    word[0] = new char[100];


Restart:
    while (strcmp(command, "END") != 0) {
        cin >> command;


        if (strcmp(command, "INSERT") == 0) {

           //INSERT 할때마다 할당해준다.

            if (count > 100) {
                cout << "IS FULL" << endl;
                goto Restart; //단어가 100개 보다 많으면 IS FULL 출력하면서 저장 안함.
            }

            cin >> word[count];



            for (int k = 0; k < count; k++) {
                if (_stricmp(word[k], word[count]) == 0) { // 대소문자 구분 없이 같은 단어 입력시 미저장
                    goto Restart;
                }
            }
            if (count != 0) {
                for (int i = 0; i < count; i++) {
                    if (_stricmp(word[i], word[count]) > 0) { //
                        for (int s = count + 1; s >= i; s--) {
                            word[s] = word[s - 1];
                        }
                        word[i] = word[count + 1];  //   app  apple app

                    }
                }
           }


                count++;
            if (count != 0) {
                word[count] = new char[100];
           }
            
            for (int i = 0; i < count; i++) {
                cout << i << "." << word[i] << endl;
            }

        }

        if (strcmp(command, "FIND") == 0) {
            char F_word[20]; //찾고 싶은 단어

            cin >> F_word;


            for (int t = 0; t < count; t++) {
                if (_stricmp(word[t], F_word) == 0) { //대소문자 구분하지 않고 문자열 비교로 같은단어 찾기  
                    cout << t << "." << word[t] << endl;
                    goto Restart;
                }
            }

            cout << "Not Found\n"; // 같은 단어 없을시 출력

        }
    }
    for (int i = 0; i < count; i++) {
        delete[] word[i];
    }
    delete[] word;

    return 0;

}


/*

   해야되는것  : 대문자 소문자 바꿔주는거.
   바꾼다음 비교후 다시 변환?

*/