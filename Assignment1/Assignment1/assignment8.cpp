#include <iostream>
#include <Windows.h>

using namespace std;
#define MAX 5



void print(char arr[][MAX]) { //arr�� �׸��� �Լ��̴�.
	system("cls"); //�ܼ�â�� �����.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

bool move_valid(char temp, int row, int column , char arr[][MAX]) {
	bool possible = true;
	if (temp == 'a') { // �������� �� �� �ִ��� �Ǵ��Ѵ�. ���� ���� �ִ°�쵵 �Ǻ��Ѵ�.
		if (column == 0 || arr[row][column - 1] == 'a')
			possible = false;
	}
	else if (temp == 's') { // ������ �� �� �ִ��� �Ǵ��Ѵ�. ���� �ؿ� �ִ� ��쵵 �Ǻ��Ѵ�.
		if (row == MAX - 1 || arr[row + 1][column] == 'a')
			possible = false;
	}
	else if (temp == 'd') { // ���������� �� �� �ִ��� �Ǵ��Ѵ�. ���� ���� �ʿ� �ִ� ��쵵 �Ǻ��Ѵ�.
		if (column == MAX - 1 || arr[row][column + 1] == 'a')
			possible = false;
	}
	else if (temp == 'w') { // �������� �� �� �ִ��� �Ǵ��Ѵ� ���� ���ʿ� �ִ� ��쵵 �Ǻ��Ѵ�.
		if (row == 0 || arr[row - 1][column] == 'a')
			possible = false;
	}
	return possible;
}

bool valid(int row, int column , int visited[][MAX]) {
	bool row_possible = true; //��,�Ϸ� �� �� �ִ��� �Ǵ��ϴ� bool����
	bool column_possible = true; //��,��� �� �� �ִ��� �Ǵ��ϴ� bool����
	if (row == 0 && visited[row + 1][column] == 1) //���Ϸ� �� �� �ִ� �� �Ǵ��Ѵ�. (���������ִ� ���� ���� �ؿ� �ִ� ��쵵 �������ش�.)
		row_possible = false; 
	else if (row == MAX - 1 && visited[row - 1][column] == 1)
		row_possible = false;
	else if (visited[row - 1][column] == 1 && visited[row + 1][column] == 1)
		row_possible = false;

	if (column == 0 && visited[row][column + 1] == 1) //�¿�� �� �� �ִ��� �Ǵ��Ѵ�.(���ʳ� ������ ���� �ִ� ��쵵 �Ǵ����ش�.)
		column_possible = false;
	else if (column == MAX - 1 && visited[row][column - 1] == 1)
		column_possible = false;
	else if (visited[row][column - 1] == 1 && visited[row][column + 1] == 1)
		column_possible = false;
	if (row_possible == false && column_possible == false) //���Ͽ� �¿찡 ��� �� �� ���ٸ� false�� ��ȯ �Ѱ��̶� �� �� ������ true�� ��ȯ
		return false;
	else
		return true;
}

int main() {
	bool End = true; //arr�� �̵��� �������� �Ǻ��ϴ� bool����
	char arr[MAX][MAX]; //5x5�� �迭
	int visited[MAX][MAX]; //arr�� �湮�ߴ����� �˷��ִ� ����
	for (int i = 0; i < MAX; i++) { // ������ arr == '0'���� visited�� ��� false�� �ʱ�ȭ
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = '0';
			visited[i][j] = 0;
		}
	}
	arr[0][0] = 'a'; //arrù ������ a�̹Ƿ� ����
	visited[0][0] = 1; // 0,0�� a�̹Ƿ� �湮�ߴٰ� üũ
	char Command; // command�� �޴� ����
	int a_row = 0, a_column = 0; //���� ��ġ�� �˷��ִ� ����
	while (End) { // End��� bool ������ true �϶��� ����ؼ� �ݺ�
		print(arr); //arr�� ���
		cout << "Command : "; 
		cin >> Command; 
		if (Command == 'a') { //Ŀ�ǵ尡 a�� �� Ȯ��
			if (move_valid(Command, a_row, a_column,arr)) { //�����ִ� ������� �Ǻ��ϴ� move_valid�Լ��� �ҷ���
				a_column--; // a�� ������ column�� -1�̱⶧���� ��ġ�� �ٲپ���
				arr[a_row][a_column] = 'a'; //�ٲ���ġ�� �����߱� ������ 'a'���Է�
				visited[a_row][a_column] = 1; //visited = ture
			}
		}
		else if (Command == 's') {
			if (move_valid(Command, a_row, a_column, arr)) {//�����ִ� ������� �Ǻ��ϴ� move_valid�Լ��� �ҷ���
				a_row++; // s�� ������ ��ĭ�̱� ������ a_row�� ++
				arr[a_row][a_column] = 'a';
				visited[a_row][a_column] = 1;
			}
		}
		else if (Command == 'w') {
			if (move_valid(Command, a_row, a_column, arr)) {//�����ִ� ������� �Ǻ��ϴ� move_valid�Լ��� �ҷ���
				a_row--; // w�� ���� ��ĭ�̱⶧���� a_row�� --���ش�
				arr[a_row][a_column] = 'a';
				visited[a_row][a_column] = 1;
			}
		}
		else if (Command == 'd') {
			if (move_valid(Command, a_row, a_column, arr)) {//�����ִ� ������� �Ǻ��ϴ� move_valid�Լ��� �ҷ���
				a_column++; // d�� ���������� ��ĭ�̹Ƿ� a_column�� -- ���ش�.
				arr[a_row][a_column] = 'a';
				visited[a_row][a_column] = 1;
			}
		}
		else {
			cout << "�߸��� �Է��Դϴ�."; //Command�̿��� ������ �ԷµǸ� �ٽ� �Է��ϰ��Ѵ�.
			Sleep(1000); // �߸��� �Է��Դϴٸ� 1�ʵ��� �����ְ� �ؿ��� �ٽ� redraw�Ѵ�.
		}
		End = valid(a_row, a_column, visited); // ���� ��ġ���� �� �Ʒ� ������ �������� �� �� �ִ��� �Ǵ��Ѵ�. �ƴϸ� End = false ���ǰ� �ݺ����� �����
	}
	print(arr);
	cout << "Command : END";
}