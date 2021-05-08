#include <iostream>
#include <string.h>
#include "node.h"
#include "list.h"

using namespace std;


int main() {
	list List; // list설명
	char word[20]; //단어를 받는 변수
	bool exit = true; // while문의 조건 변수
	int count = 0; // 단어의 개수가 몇개인지 세는 변수
	while (exit) {
		cout << "CMD(Word/exit)>> ";
		cin >> word;//단어를 입력받음
		if (strcmp(word,"exit") == 0) { //exit를 입력하면 
			exit = false; // exit가 false가 되면서 반복문이 종료됨
		}
		else if (count == 0) { // 처음 입력할때
			List.Insert(word, count); // List의 Insert매소드 호출
			List.Print(); // 단어를 출력
			count++; // 단어의 개수 추가
		}
		else {
			if (List.backward_word(word)) { // 뒤에문자와 입력단어가 이어지는지 확인하는 매소드
				if (List.Search_equal(word)) { // 같은 문자가 지금까지 있었는지 확인
					List.Insert(word, count); // 값을 입력
					List.Print(); //값을 출력
					count++; // 단어의 개수 추가
				}
				else {
					cout << "Already Exists. " << endl; // 이미 있는 단어일 때 출력
				}
			}
			else {
				cout << "Not Chained" << endl; //마지막단어의 마지막 글자와 입력한 첫번째 글자가 안이어질 때 사용
			}

		}
	}
	
}