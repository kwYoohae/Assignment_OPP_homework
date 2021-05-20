#include <iostream>
#include <fstream>
#include "Data_1D.h"
#include "Data_1D.h"
#include "Data_2D.h"
#include "Student_Node.h"
#include <crtdbg.h>

using namespace std;

int main() {
	Data_1D<char> data_1d; //1차원배열을 저장하는 변수
	Data_2D<int> year_2d; //year에 대한 2차원배열을 저장하는 변수
	Data_2D<char> name_2d; //name에 대한 2차원배열을 저장하는 변수
	Data_2D<char*> major_2d;//major에 대한 2차원배열을 저장하는 변수
	bool end = true; 
	int command;
	char str[100];
	char Id[100];
	char major[100];
	char name[100];
	ifstream readFile("student.txt"); // student파일을 읽어옴
	if (!readFile.is_open()) { // 파일이 열리지않을경우
		readFile.close();
		ofstream writeFile; // outputstream으로 새로연다
		writeFile.open("student.txt"); //student.txt파일이 없으면새로생성
		writeFile.close(); // 파일을 닫음
		ifstream readFile("student.txt"); // student.txt를 연다.
	}
	while (readFile) { // readFile을 다읽을 때까지 반복
		int len = 0; // 단어의 길이를 count하는 변수
		memset(str, NULL, 100);  // 변수초기화
		memset(Id, NULL, 100);// 변수초기화
		memset(major, NULL, 100);// 변수초기화
		memset(name, NULL, 100);// 변수초기화
		readFile.getline(str, 100, '\n'); // 단어를 읽어옴
		if (str[0] == NULL) // 단어가 읽는것이 끝나 읽어올 단어가 없을 시
			break;
		for (; str[len] != ','; len++) { // ,까지 읽어와 id를 저장
			Id[len] = str[len];
		}
		len++;
		for (int i = 0; str[len] != ','; i++, len++) { // 다음 ,까지 읽어와 major를 저장
			major[i] = str[len];
		}
		for (int i = 0; i <= strlen(str); i++ , len++) { // 끝까지 읽어와서 name을 저장
			name[i]= str[len+1];
		}
		Student_Node* pNew = new Student_Node; //노드 생성
		pNew->setMajor(major); // 새로생성한 student_node에 전공저장
		pNew->setStudentId(Id);// 새로생성한 student_node에 학번저장
		pNew->setName(name);// 새로생성한 student_node에 이름저장
		data_1d.Insert_input<Student_Node>(pNew); // Input순서로 1차원배열에 넣음
		name_2d.Insert<char>(pNew); // 2차원배열에 넣음
		major_2d.Insert<char*>(pNew); // 2차원배열에 넣음
		year_2d.Insert<int>(pNew); // 2차원배열에 넣음
	}
	readFile.close(); // 파일읽기종료
	//name_2d.Insert(&data_1d);
	//major_2d.Insert<char*>(&data_1d);
	while (end) {
		cout << "1. Print File" << endl;
		cout << "2. Print by ID" << endl;
		cout << "3. Print by Major" << endl;
		cout << "4. Print by Name" << endl;
		cout << "5. Program End" << endl;
		cout << "CMD>> ";
		cin >> command; // command를 받음
		if (command == 1) { // input순서로 출력
			data_1d.print(); //1차워배열의 출력매소드 호출
		}
		else if (command == 2) { // year순으로 출력
			cout << "Print by ID" << '\n';
			year_2d.print<int>(); // year순으로 출력하는 매소드 호출
		}
		else if (command == 3) { // major순으로 출력
			cout << "Print by Major" << '\n';
			major_2d.print<char*>(); // major순으로 출력하는 매소드 호출
		}
		else if (command == 4) { // ID순으로 출력
			cout << "Print by Name" << '\n';
			name_2d.print<char>(); // ID순으로 출력하는 매소드 호출
		} 
		else if(command == 5){
			end = false; // 반복문종료
			major_2d.delete_data<char*>(); // major_2d의 데이터 변수 동적할당해제
			major_2d.Remove_data<char*>(); // major에 있는 1D노드 동적할당해제
			year_2d.Remove_data<int>(); // year에 있는 1d노드 동적할당해제
			name_2d.Remove_data<char>(); // name에 있는 1d노드 동적할당해제
			data_1d.Remove_1d(); // Student_node동적할당 해제
		}
		else { // command가 아닌 항목입력시
			cout << "wrong input" << endl; 
		}
	}
	return 0;
}