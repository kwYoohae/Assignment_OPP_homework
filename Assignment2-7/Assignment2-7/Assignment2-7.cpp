#include <iostream>

using namespace std;

class 대학 {
private:
	char U_Name[20];
	int year;
	char U_StuID[20];
public:
	대학();
	char* get_UName() { //private U_Name에 대한 get함수
		return U_Name;
	}
	int get_year() { // private year에 대한 get함수
		return year;
	}
	char* get_UStuID() { // private에 U_stuId에 대한 get 함수
		return U_StuID;
	}
	bool find_ID(char stuID[]) { // find_ID라는 StudentID가 있는지 없는지 확인하는 매소드
		if (strcmp(stuID, U_StuID) == 0)
			return true; // 있으면 true를 반환
		return false; // 없으면 false를 반환
	}

};
대학::대학() { //대학의 생성자에서 cin으로 private 변수를 받음
	cout << "학교 :";
	cin >> U_Name;
	cout << "학번 :";
	cin >> U_StuID;
	cout << "학년 :";
	cin >> year;
}
class 컴퓨터정보공학 :public 대학 { // 대학에 상속되어있는 컴퓨터정보공학 클래스
private:
	char Object_Oriented_Programing;
	char Digtal_Logic_Circuit;
public:
	컴퓨터정보공학();
	char get_Object_Oriented_Programing() { // Object_Oriented_Programing을 retrun해주는 매소드
		return Object_Oriented_Programing;
	}
	char get_Digital_Logic_Circuit() { // Digital Logic Circuit을 return 해주는 매소드
		return Digtal_Logic_Circuit;
	}
};

컴퓨터정보공학::컴퓨터정보공학() { // 컴퓨터정보공학의 생성자에서 cin으로 private변수를 받음
	cout << "객체지향프로그래밍 학점 :";
	cin >> Object_Oriented_Programing;
	cout << "디지털논리회로 학점 :";
	cin >> Digtal_Logic_Circuit;
}

class 학생정보 :public 컴퓨터정보공학 {// 컴퓨터정보공학에 상속되어있는 학생정보
private:
	char Name[10];
	int age;
public:
	학생정보();
	char* get_Name() {  // Name이라는 private 변수를 return 
		return Name;
	}
	int get_age() { // age라는 private라는 변수를 return
		return age;
	}
	bool find_Name(char Name[]) { // Name이 맞는지 확인하는 bool형 매소드
		if (strcmp(Name, this->Name) == 0) // class의 Name 매개변수의 Name이 맞는지 확인
			return true; // 맞으면 true를 리턴
		return false; // 틀리면 false를 리턴
	}
};

학생정보::학생정보() { // 학생정보의 private 변수를 cin으로 입력받는 생성자
	cout << "이름 :";
	cin >> Name;
	cout << "나이 :";
	cin >> age;
}

int main() {
	학생정보** student = new 학생정보 * [100]; //학생정보의 2차원 배열 할당
	int count = 0; //지금까지 몇명이 신청했는지 확인하는 변수
	char Name[20]; // find함수에서 이름을 찾기위해 이름을 받는 변수
	char stuID[20]; // find함수에서 학번을 찾기위해 StudentId를 받는 변수
	char command[20]; // 커맨드를 입력받는 변수
	bool end = true; // 반복문의 해제 조건
	while (end) {
		cin >> command; // 커맨드를 입력받는다.
		if (strcmp(command, "INSERT") == 0) { //Command가 "INSERT"인지 확인
			if (count < 100) { // 학생의 수가 100보다 작다면 
				student[count] = new 학생정보; // 학생정보를 동적할당
				count++; // 학생수가 올라간것을 나타냄
			}
			else
				cout << "Limit Number is 100" << endl; //0~99명 보다 크면 Limit Number is 100을 출력
		}
		else if (strcmp(command, "FIND") == 0) { // Command가 "FIND"인지 확인
			cin >> Name >> stuID; // 찾을 값들을 입력받음
			int index = -1; // 찾는 값의 인덱스 번호를 -1로 초기화
			for (int i = 0; i < count; i++) {
				if (student[i]->find_ID(stuID) == true && student[i]->find_Name(Name) == true) { //find_ID와 find_Name매소드를 이용해서 값을찾는다
					index = i; // 만약 두값을 동시에 만족하는 데이터가 있으면 그때의 student의 번호를 index의 저장
				}
			}
			if (index != -1) { // 두값을 만족하지 못한느 데이터가 있으면 초기 값이 -1 이므로 -1이 아닌값이면 학생의 정볼르 출력
				cout << '\n' << '\n';
				cout << "학교:" << student[index]->get_UName() << endl;
				cout << "학번:" << student[index]->get_UStuID() << endl;
				cout << "학년:" << student[index]->get_year() << endl;
				cout << "객체지향프로그래밍 학점: " << student[index]->get_Object_Oriented_Programing() << endl;
				cout << "디지털논리회로 학점: " << student[index]->get_Digital_Logic_Circuit() << endl;
			}
		}
		else if (strcmp(command, "EXIT") == 0) { // Command가 "EXIT"인지 확인
			end = false; // 반복문종료
			for (int i = 0; i < count; i++) {
				delete[] student[i]; // 학생수만큼 동적할다을 해제
			}
			delete[] student; //객체를 동적할당 해제
		}
	}
}
