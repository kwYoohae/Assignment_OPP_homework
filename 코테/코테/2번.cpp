#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char command[10] = { 0 , };
    int count = 0; // ���� ��ȣ
    int j = 0;
    char** word = new char* [100];

    word[0] = new char[100];


Restart:
    while (strcmp(command, "END") != 0) {
        cin >> command;


        if (strcmp(command, "INSERT") == 0) {

           //INSERT �Ҷ����� �Ҵ����ش�.

            if (count > 100) {
                cout << "IS FULL" << endl;
                goto Restart; //�ܾ 100�� ���� ������ IS FULL ����ϸ鼭 ���� ����.
            }

            cin >> word[count];



            for (int k = 0; k < count; k++) {
                if (_stricmp(word[k], word[count]) == 0) { // ��ҹ��� ���� ���� ���� �ܾ� �Է½� ������
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
            char F_word[20]; //ã�� ���� �ܾ�

            cin >> F_word;


            for (int t = 0; t < count; t++) {
                if (_stricmp(word[t], F_word) == 0) { //��ҹ��� �������� �ʰ� ���ڿ� �񱳷� �����ܾ� ã��  
                    cout << t << "." << word[t] << endl;
                    goto Restart;
                }
            }

            cout << "Not Found\n"; // ���� �ܾ� ������ ���

        }
    }
    for (int i = 0; i < count; i++) {
        delete[] word[i];
    }
    delete[] word;

    return 0;

}


/*

   �ؾߵǴ°�  : �빮�� �ҹ��� �ٲ��ִ°�.
   �ٲ۴��� ���� �ٽ� ��ȯ?

*/