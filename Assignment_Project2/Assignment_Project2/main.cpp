#include "Node.h"
#include "tree.h"
#include "cube.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <crtdbg.h>
using namespace std;

void Print_Check(tree_node* pTemp);

void Open_Category(tree* type_Data, const char* text_file);
void Insert_data(tree* type, tree_node* pParent, char* data);
void Load_sales(cube* Cube);
int count_low(tree* Tree, int number);
//int Role_up(tree* product, tree* time, tree* , cube* raw, cube* view);
void insert_data(cube* Cube, char* product, char* location, char* time, int data);
int main() {
	tree Product; //Product tree
	tree Location; // location tree
	tree Time; // time tree
	cube raw_cube; // raw cube
	cube view_cube; // view cube
	char str[200]; // command를 읽는 변수
	char command[100]; // command를 저장할 변수
	char command_list[100]; //command 뒤의 명령어를 받는 변수
	memset(str, NULL, 200); // 초기화
	memset(command, NULL, 100); // 초기화
	memset(command_list, NULL, 100); // 초기화
	int cnt = 0; // 글자를 세는 변수
	fstream ReadCommand("command.txt"); // command.txt를 읽기
	while (ReadCommand.is_open()) { // 파일이 열렸을 때만 들어감
		while (true) { //반복문을 실행
			ReadCommand.getline(str,200); // 한줄씩 command.txt를 일겅옴
			if (!str[0]) { // 아무것도 읽히지 않으면 반복문 종료
				break;
			}
			for (int i = 0; str[i] != ' '; i++,cnt++) {
				command[i] = str[i]; // command를 ' '가 나올때까지 받음
				if (str[i] == '\0')
					break; // '\0'이 나오면종료
			}
			cnt++; // ' '를 건너뛰기 위해 cnt를 올려줌
			for (int i = 0; str[cnt] != '\0'; i++, cnt++) {
				command_list[i] = str[cnt]; // command뒤에 나오는 수를 읽기위해서 사용하는 변수
			}
			if (strcmp(command,"LOAD") == 0) {
				Open_Category(&Time, "time.txt"); //time.txt를 읽어서 tree로 만드는 함수
				Open_Category(&Product, "product.txt");//product.txt를 읽어서 tree로 만드는 함수
				Open_Category(&Location, "location.txt");//location.txt를 읽어서 tree로 만드는 함수
				raw_cube.Make_Cube(count_low(&Product, 3), count_low(&Location, 3), count_low(&Time, 3)); //cube를 만드는 매소드 호출
				raw_cube.Make_tree(&Time, &Location, &Product, 3); //cube의 쓰이는 tree를 만드는 매소드 호출
				//Load_sales(&raw_cube); // sales.txt에 저장한 값들을 저장하는 매소드 호출
				//raw_cube.Print();
				//raw_cube.WriteLog(command);
				view_cube.Make_Cube(count_low(&Product, 3), count_low(&Location, 3), count_low(&Time, 3)); // cube를 만드는 매소드 호출
				view_cube.Make_tree(&Time, &Location, &Product, 2); // cube에 쓰이는 tree를 만드는 매소드 호출(뒤의 숫자는 계층을 표시)
				view_cube.copyData(&raw_cube); // rawcube가 가진 데이터를 복사
				view_cube.Make_View(&Time, &Location, &Product); // view큐브를 만들기위해 raw보다 더 낮은 계층으로 만드는 매소드 호출
				///view_cube.Print();
				view_cube.WriteLog(command); // log를 작성하는 매소드 호출
			}
			else if (strcmp(command, "ROTATE") == 0) {
				//view_cube.Print();
				//view_cube.check();
				view_cube.Rotate(command_list); // rotate를 실행하는 매소드 호출
				//view_cube.check();
				view_cube.WriteLog(command); // 로그를 작성하는 매소드 호출
				//raw_cube.Rotate(command_list);
				//raw_cube.WriteLog(command);
			}
			else if (strcmp(command, "EXIT") == 0) {
				raw_cube.delete_cube(); // raw큐브 삭제 매소드 호출
				view_cube.delete_cube(); // view큐브 삭제 매소드 호출
				break;
			}
			memset(str, NULL, 200); // 값 초기화
			memset(command, NULL, 100); //  값 초기화
			memset(command_list, NULL, 100); // 값 초기화
			cnt = 0; // 값초기화
		}
		ReadCommand.close(); //command.txt파일을 닫음
	}
	return 0;
	_CrtDumpMemoryLeaks();
}



void Print_Check(tree_node* pTemp) {
	if (pTemp) {
		cout << pTemp->getData() << endl;
		Print_Check(pTemp->getDown());
		Print_Check(pTemp->getNext());
	}
}

void Insert_data(tree* type, tree_node* pParent, char* data) {
	if (!type->getRoot()) {
		tree_node* pNew = new tree_node;
		pNew->setData(data);
		type->setRoot(pNew);
	}
	else if (pParent == type->getRoot()) {
		tree_node* pNew = new tree_node;
		pNew->setData(data);
		if (!pParent->getDown())
			pParent->setDown(pNew);
		else {
			tree_node* pTemp = pParent->getDown();
			while (pTemp->getNext())
				pTemp = pTemp->getNext();
			tree_node* pNew = new tree_node;
			pNew->setData(data);
			pNew->setPrev(pTemp);
			pTemp->setNext(pNew);
		}
		pNew->setUp(pParent);
	}
	else {
		tree_node* pNew = new tree_node;
		pNew->setData(data);
		if (!pParent->getDown())
			pParent->setDown(pNew);
		else {
			tree_node* pTemp = pParent->getDown();
			while (pTemp->getNext())
				pTemp = pTemp->getNext();
			tree_node* pNew = new tree_node;
			pNew->setData(data);
			pNew->setPrev(pTemp);
			pTemp->setNext(pNew);
		}
		pNew->setUp(pParent);

	}
}

void Open_Category(tree* type_Data, const char* text_file) { // 파일을 읽어 트리를 구성하는 매소드 호출
	ifstream readFile(text_file); // 저장된 txt파읽을 읽음
	if (!readFile.is_open()) { // 만약 txt파일이 없을 때
		cout << "Error" << endl;
		readFile.close();
	}
	tree_node* pParent = type_Data->getRoot(); // prent라는 노드는 root를 가져옴
	char temp[100];
	char data[100];
	int len = 0;
	int count = -1;
	while (true) { // 반복문수행
		tree_node* pTemp = nullptr; // pTemp 초기화
		int i = 0; // 초기화
		memset(temp, NULL, 100); //초기화
		memset(data, NULL, 100); // 초기화
		readFile.getline(temp, 100, '\n'); //'\n'을 만날때 까지 txt파일을 한줄씩 읽어옴
		if (temp[0] == NULL) // 값이 아무것도 없을 때 반복문 종료 
			break;
		if (count == -1) { // root일 때를 count로 확인하여 root값 저장
			while (temp[len] != '\0') { // 이름을 txt파일에서 분할해서 읽어옴
				data[i] = temp[len];
				len++;
				i++;
				if (temp[len] == ' ') { // ' '을 만나면(띄어쓰기마다 단어를 저장)
					i = 0;
					Insert_data(type_Data, type_Data->getRoot(), data); // data를 넣는 매소드 호출
					memset(data, NULL, 100); // data초기화
					len++; // len을 늘림
				}
				else if (temp[len] == '\0') { // 만약에 문장이 끝나면
					Insert_data(type_Data, type_Data->getRoot(), data); //마지막단어를 넣음
					memset(data, NULL, 100); // 데이터 초기화
				}
			}
			pParent = type_Data->getRoot(); // pParent는 root로 
			count++;// count증가
			len = 0;
		}
		else { // root가 없고 root의 자식노드들을 저장할 때
			while (temp[len] != ' ') { // ' '를 만날 때까지 값저장
				data[len] = temp[len];
				len++;
			}
			pTemp = pParent->getDown(); 
			while (pTemp->getNext()) { // root의 자식중 자매노드를 확인
				if (strcmp(pTemp->getData(), data) == 0) // 입력한 값과 같은 노드가 있으면 멈춤
					break;
				else
					pTemp = pTemp->getNext();
			}
			if (pTemp) { // pTemp가 존재하는 값이면(같은값이 자매노드에 있으면
				memset(data, NULL, 100); // data값 초기화
				len++;
				while (temp[len] != '\0') { // 값을 끝까지 읽어옴
					data[i] = temp[len];
					len++;
					i++;
					if (temp[len] == ' ') { // 띄어쓰기 일때마다 값을 저장
						i = 0;
						Insert_data(type_Data, pTemp, data); // 값을 저장하는 매소드 호출
						memset(data, NULL, 100); // 읽어오는값 초기화
						len++;
					}
					else if (temp[len] == '\0') { // 문장의 끝을 만났을때
						Insert_data(type_Data, pTemp, data); // 마지막단어를 넣어줌
						memset(data, NULL, 100);//초기화
					}
				}
			}
			len = 0;
		}
	} 
	readFile.close();
}

int count_low(tree* Tree, int number) { // 자식노드의 개수를 모두 세어주는 매소드
	int count = 0;
	tree_node* pTemp = Tree->getRoot(); // root를 가져옴
	tree_node* pParent = pTemp;
	for (int i = 1; i < number; i++) { // 내가 입력한 계층만큼 밑으로 내려감
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) // 밑에 자식노드가 없으면 멈춤
			break;
	}
	
	while (pTemp) { //자식노드들을 세어주는 반복문
		count++;
		pTemp = pTemp->getNext(); // 계속 자매노드로 이동
		if (!pTemp) {
			pParent = pParent->getNext(); // 자식노드의 자매노드가 마지막이면 parent값을 이동시키고 또 자식노드 count
			if (!pParent)
				break;
			pTemp = pParent->getDown(); // 자식노드를 세기위해서 내려감
		}
	}
	return count; //값반환
}

void Load_sales(cube* Cube) { // sales.txt파일을 읽어서 값을 저장하기 위한 매소드
	ifstream readFile("sales.txt"); /// sales.txt파일을 읽어옴
	if (!readFile.is_open()) { // 파일이 닫혀있을 경우
		cout << "Error" << endl;
		readFile.close();
		return;
	}
	char temp[200];
	char product[200];
	char location[200];
	char time[200];
	int product_number = 0;
	int location_nubmer = 0;
	int time_number = 0;
	int data = 0;
	int len = 0;
	while (true) { // 반복문 실행
		memset(temp, NULL, 200); // 값초기화
		memset(product, NULL, 200); // 값초기화
		memset(location, NULL, 200); //값초기화
		memset(time, NULL, 200); // 값초기화
		data = 0; // 초기화
		readFile.getline(temp, 200, '\n'); //단어를 엔터를 친 구간까지 읽어옴
		if (temp[0] == NULL) // 읽어온값이 비어있을 때는 반복문 종료
			break; 
		for (int i = 0; temp[len] != ' '; i++, len++) {
			product[i] = temp[len]; // product값 저장
		}
		len++;
		for (int i = 0; temp[len] != ' '; i++, len++) {
			location[i] = temp[len]; // location값 저장
		}
		len++;
		for (int i = 0; temp[len] != ' '; i++, len++) {
			time[i] = temp[len];//time값 저장
		}
		len++;
		for (int i = 0; temp[len] != '\0'; i++, len++) { // 문자로된 data값을 int로 변환
			data += temp[len] - '0';
			data *= 10;
		}
		data /= 10; 
		insert_data(Cube, product, location, time, data); // 데이터값을 넣기위한 함수를 호출
		len = 0;
	}
	readFile.close(); // salse.txt파일을 닫음
}

void insert_data(cube* Cube, char* product, char* location, char* time, int data) { // 데이터를 넣어주는 매소드
	int p = 0; // product의 좌표값
	int l = 0; // location의 좌표값
	int t = 0; // time의 좌표값
	cube_1D* pTemp = Cube->getRow(); // cube의 row를 가져옴(time)
	while (pTemp) { // time의 데이터를 가져옴
		if (strcmp(pTemp->getData()->getData(), time) == 0) // 데이터를 입력해야하는 좌표를 찾음
			break;
		t++;
		pTemp = pTemp->getNext();
	}
	pTemp = Cube->getColumn();
	while (pTemp) { // location을 가져옴
		if (strcmp(pTemp->getData()->getData(), location) == 0)// 데이터를 입력해야하는 좌표를 찾음
			break;
		l++;
		pTemp = pTemp->getNext();
	}
	pTemp = Cube->getHeight();
	while (pTemp) { // product를 가져옴
		if (strcmp(pTemp->getData()->getData(), product) == 0)// 데이터를 입력해야하는 좌표를 찾음
			break;
		p++;
		pTemp = pTemp->getNext();
	}
	
	node* pNode = Cube->getHead();
	for (int i = 0; i < p; i++) { // product의 좌표만큼 height로 이동
		pNode = pNode->getHnext();
	} 
	for (int i = 0; i < l; i++) { // location의 좌표만큼 Column으로 이동
		pNode = pNode->getCnext();
	}
	for (int i = 0; i < t; i++) { // time의 좌표만큼 Row로 이동
		pNode = pNode->getRnext();
	}
	pNode->setData(data);
}

