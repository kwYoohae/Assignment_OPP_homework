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
	char str[200]; // command�� �д� ����
	char command[100]; // command�� ������ ����
	char command_list[100]; //command ���� ��ɾ �޴� ����
	memset(str, NULL, 200); // �ʱ�ȭ
	memset(command, NULL, 100); // �ʱ�ȭ
	memset(command_list, NULL, 100); // �ʱ�ȭ
	int cnt = 0; // ���ڸ� ���� ����
	fstream ReadCommand("command.txt"); // command.txt�� �б�
	while (ReadCommand.is_open()) { // ������ ������ ���� ��
		while (true) { //�ݺ����� ����
			ReadCommand.getline(str,200); // ���پ� command.txt�� �ϰϿ�
			if (!str[0]) { // �ƹ��͵� ������ ������ �ݺ��� ����
				break;
			}
			for (int i = 0; str[i] != ' '; i++,cnt++) {
				command[i] = str[i]; // command�� ' '�� ���ö����� ����
				if (str[i] == '\0')
					break; // '\0'�� ����������
			}
			cnt++; // ' '�� �ǳʶٱ� ���� cnt�� �÷���
			for (int i = 0; str[cnt] != '\0'; i++, cnt++) {
				command_list[i] = str[cnt]; // command�ڿ� ������ ���� �б����ؼ� ����ϴ� ����
			}
			if (strcmp(command,"LOAD") == 0) {
				Open_Category(&Time, "time.txt"); //time.txt�� �о tree�� ����� �Լ�
				Open_Category(&Product, "product.txt");//product.txt�� �о tree�� ����� �Լ�
				Open_Category(&Location, "location.txt");//location.txt�� �о tree�� ����� �Լ�
				raw_cube.Make_Cube(count_low(&Product, 3), count_low(&Location, 3), count_low(&Time, 3)); //cube�� ����� �żҵ� ȣ��
				raw_cube.Make_tree(&Time, &Location, &Product, 3); //cube�� ���̴� tree�� ����� �żҵ� ȣ��
				//Load_sales(&raw_cube); // sales.txt�� ������ ������ �����ϴ� �żҵ� ȣ��
				//raw_cube.Print();
				//raw_cube.WriteLog(command);
				view_cube.Make_Cube(count_low(&Product, 3), count_low(&Location, 3), count_low(&Time, 3)); // cube�� ����� �żҵ� ȣ��
				view_cube.Make_tree(&Time, &Location, &Product, 2); // cube�� ���̴� tree�� ����� �żҵ� ȣ��(���� ���ڴ� ������ ǥ��)
				view_cube.copyData(&raw_cube); // rawcube�� ���� �����͸� ����
				view_cube.Make_View(&Time, &Location, &Product); // viewť�긦 ��������� raw���� �� ���� �������� ����� �żҵ� ȣ��
				///view_cube.Print();
				view_cube.WriteLog(command); // log�� �ۼ��ϴ� �żҵ� ȣ��
			}
			else if (strcmp(command, "ROTATE") == 0) {
				//view_cube.Print();
				//view_cube.check();
				view_cube.Rotate(command_list); // rotate�� �����ϴ� �żҵ� ȣ��
				//view_cube.check();
				view_cube.WriteLog(command); // �α׸� �ۼ��ϴ� �żҵ� ȣ��
				//raw_cube.Rotate(command_list);
				//raw_cube.WriteLog(command);
			}
			else if (strcmp(command, "EXIT") == 0) {
				raw_cube.delete_cube(); // rawť�� ���� �żҵ� ȣ��
				view_cube.delete_cube(); // viewť�� ���� �żҵ� ȣ��
				break;
			}
			memset(str, NULL, 200); // �� �ʱ�ȭ
			memset(command, NULL, 100); //  �� �ʱ�ȭ
			memset(command_list, NULL, 100); // �� �ʱ�ȭ
			cnt = 0; // ���ʱ�ȭ
		}
		ReadCommand.close(); //command.txt������ ����
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

void Open_Category(tree* type_Data, const char* text_file) { // ������ �о� Ʈ���� �����ϴ� �żҵ� ȣ��
	ifstream readFile(text_file); // ����� txt������ ����
	if (!readFile.is_open()) { // ���� txt������ ���� ��
		cout << "Error" << endl;
		readFile.close();
	}
	tree_node* pParent = type_Data->getRoot(); // prent��� ���� root�� ������
	char temp[100];
	char data[100];
	int len = 0;
	int count = -1;
	while (true) { // �ݺ�������
		tree_node* pTemp = nullptr; // pTemp �ʱ�ȭ
		int i = 0; // �ʱ�ȭ
		memset(temp, NULL, 100); //�ʱ�ȭ
		memset(data, NULL, 100); // �ʱ�ȭ
		readFile.getline(temp, 100, '\n'); //'\n'�� ������ ���� txt������ ���پ� �о��
		if (temp[0] == NULL) // ���� �ƹ��͵� ���� �� �ݺ��� ���� 
			break;
		if (count == -1) { // root�� ���� count�� Ȯ���Ͽ� root�� ����
			while (temp[len] != '\0') { // �̸��� txt���Ͽ��� �����ؼ� �о��
				data[i] = temp[len];
				len++;
				i++;
				if (temp[len] == ' ') { // ' '�� ������(���⸶�� �ܾ ����)
					i = 0;
					Insert_data(type_Data, type_Data->getRoot(), data); // data�� �ִ� �żҵ� ȣ��
					memset(data, NULL, 100); // data�ʱ�ȭ
					len++; // len�� �ø�
				}
				else if (temp[len] == '\0') { // ���࿡ ������ ������
					Insert_data(type_Data, type_Data->getRoot(), data); //�������ܾ ����
					memset(data, NULL, 100); // ������ �ʱ�ȭ
				}
			}
			pParent = type_Data->getRoot(); // pParent�� root�� 
			count++;// count����
			len = 0;
		}
		else { // root�� ���� root�� �ڽĳ����� ������ ��
			while (temp[len] != ' ') { // ' '�� ���� ������ ������
				data[len] = temp[len];
				len++;
			}
			pTemp = pParent->getDown(); 
			while (pTemp->getNext()) { // root�� �ڽ��� �ڸų�带 Ȯ��
				if (strcmp(pTemp->getData(), data) == 0) // �Է��� ���� ���� ��尡 ������ ����
					break;
				else
					pTemp = pTemp->getNext();
			}
			if (pTemp) { // pTemp�� �����ϴ� ���̸�(�������� �ڸų�忡 ������
				memset(data, NULL, 100); // data�� �ʱ�ȭ
				len++;
				while (temp[len] != '\0') { // ���� ������ �о��
					data[i] = temp[len];
					len++;
					i++;
					if (temp[len] == ' ') { // ���� �϶����� ���� ����
						i = 0;
						Insert_data(type_Data, pTemp, data); // ���� �����ϴ� �żҵ� ȣ��
						memset(data, NULL, 100); // �о���°� �ʱ�ȭ
						len++;
					}
					else if (temp[len] == '\0') { // ������ ���� ��������
						Insert_data(type_Data, pTemp, data); // �������ܾ �־���
						memset(data, NULL, 100);//�ʱ�ȭ
					}
				}
			}
			len = 0;
		}
	} 
	readFile.close();
}

int count_low(tree* Tree, int number) { // �ڽĳ���� ������ ��� �����ִ� �żҵ�
	int count = 0;
	tree_node* pTemp = Tree->getRoot(); // root�� ������
	tree_node* pParent = pTemp;
	for (int i = 1; i < number; i++) { // ���� �Է��� ������ŭ ������ ������
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) // �ؿ� �ڽĳ�尡 ������ ����
			break;
	}
	
	while (pTemp) { //�ڽĳ����� �����ִ� �ݺ���
		count++;
		pTemp = pTemp->getNext(); // ��� �ڸų��� �̵�
		if (!pTemp) {
			pParent = pParent->getNext(); // �ڽĳ���� �ڸų�尡 �������̸� parent���� �̵���Ű�� �� �ڽĳ�� count
			if (!pParent)
				break;
			pTemp = pParent->getDown(); // �ڽĳ�带 �������ؼ� ������
		}
	}
	return count; //����ȯ
}

void Load_sales(cube* Cube) { // sales.txt������ �о ���� �����ϱ� ���� �żҵ�
	ifstream readFile("sales.txt"); /// sales.txt������ �о��
	if (!readFile.is_open()) { // ������ �������� ���
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
	while (true) { // �ݺ��� ����
		memset(temp, NULL, 200); // ���ʱ�ȭ
		memset(product, NULL, 200); // ���ʱ�ȭ
		memset(location, NULL, 200); //���ʱ�ȭ
		memset(time, NULL, 200); // ���ʱ�ȭ
		data = 0; // �ʱ�ȭ
		readFile.getline(temp, 200, '\n'); //�ܾ ���͸� ģ �������� �о��
		if (temp[0] == NULL) // �о�°��� ������� ���� �ݺ��� ����
			break; 
		for (int i = 0; temp[len] != ' '; i++, len++) {
			product[i] = temp[len]; // product�� ����
		}
		len++;
		for (int i = 0; temp[len] != ' '; i++, len++) {
			location[i] = temp[len]; // location�� ����
		}
		len++;
		for (int i = 0; temp[len] != ' '; i++, len++) {
			time[i] = temp[len];//time�� ����
		}
		len++;
		for (int i = 0; temp[len] != '\0'; i++, len++) { // ���ڷε� data���� int�� ��ȯ
			data += temp[len] - '0';
			data *= 10;
		}
		data /= 10; 
		insert_data(Cube, product, location, time, data); // �����Ͱ��� �ֱ����� �Լ��� ȣ��
		len = 0;
	}
	readFile.close(); // salse.txt������ ����
}

void insert_data(cube* Cube, char* product, char* location, char* time, int data) { // �����͸� �־��ִ� �żҵ�
	int p = 0; // product�� ��ǥ��
	int l = 0; // location�� ��ǥ��
	int t = 0; // time�� ��ǥ��
	cube_1D* pTemp = Cube->getRow(); // cube�� row�� ������(time)
	while (pTemp) { // time�� �����͸� ������
		if (strcmp(pTemp->getData()->getData(), time) == 0) // �����͸� �Է��ؾ��ϴ� ��ǥ�� ã��
			break;
		t++;
		pTemp = pTemp->getNext();
	}
	pTemp = Cube->getColumn();
	while (pTemp) { // location�� ������
		if (strcmp(pTemp->getData()->getData(), location) == 0)// �����͸� �Է��ؾ��ϴ� ��ǥ�� ã��
			break;
		l++;
		pTemp = pTemp->getNext();
	}
	pTemp = Cube->getHeight();
	while (pTemp) { // product�� ������
		if (strcmp(pTemp->getData()->getData(), product) == 0)// �����͸� �Է��ؾ��ϴ� ��ǥ�� ã��
			break;
		p++;
		pTemp = pTemp->getNext();
	}
	
	node* pNode = Cube->getHead();
	for (int i = 0; i < p; i++) { // product�� ��ǥ��ŭ height�� �̵�
		pNode = pNode->getHnext();
	} 
	for (int i = 0; i < l; i++) { // location�� ��ǥ��ŭ Column���� �̵�
		pNode = pNode->getCnext();
	}
	for (int i = 0; i < t; i++) { // time�� ��ǥ��ŭ Row�� �̵�
		pNode = pNode->getRnext();
	}
	pNode->setData(data);
}

