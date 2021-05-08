#include <iostream>

using namespace std;

int find_equal(char** arr, int count) { //int�� �Լ��� �ܾ��忡 �ִ� �ܾ�� ���� �����ܾ ������ index���� ��ȯ
	char* temp = new char[20]; //find �ܾ �ҹ����� ���� �빮�� �빮���϶��� �ҹ��ڷ� �޴� ������
	int cmp_low = -1; // �빮��,�ҹ����� index�� ���� ������ �Ѵ� ������ �ʱⰪ�� -1��ȯ
	int cmp_up = -1; // �ҹ���, �빮���� index�� ���� ������ �Ѵ� ������ �ʱⰪ�� -1��ȯ
	if (arr[count][0] >= 'A' && arr[count][0] <= 'Z') { // find���� ���� ������ �빮���� ��� temp�� �ҹ��� ����
		for (int i = 0; i < strlen(arr[count]); i++) {
			temp[i] = arr[count][i] + 32;
		}
	}
	else {//�ݴ�� �ҹ����� ��� �빮�ڷ� ����
		for (int i = 0; i < strlen(arr[count]); i++) {
			temp[i] = arr[count][i] - 32;
		}
	}
	temp[strlen(arr[count])] = '\0'; //char�� �������� ������ ���� '\0'�� �־��� ���� ����
	for (int i = 0; i < count; i++) { //find�ϴ� �ܾ �ִ��� Ȯ��
		if (strcmp(arr[i], arr[count]) == 0) {
			cmp_low = i; //������ index�� ����
		}
		if (strcmp(arr[i], temp) == 0) {
			cmp_up = i;
		}
	}
	delete[] temp; //����� ���� temp�� �����ʹ� �޸� ����
	if (cmp_low > -1 || cmp_up > -1) { //��ҹ��� ���� �ϳ��� ���� �־����� �ִ� index�� ���
		if (cmp_low > -1)
			return cmp_low;
		else
			return cmp_up;
	}
	return -1; //���ٸ� -1 ��ȯ

}

void print(char** arr, int count) { //�ܾ��忡 �ִ� �ܾ� ��� ���α׷�
	for (int i = 0; i <= count; i++) {
		cout << i << '.' << arr[i] << endl;
	}
}

void sort(char* arr[], int count) { //�ܾ �Է¹����� �������ִ� �Լ�
	int index = count; //������ count���� ����Ǿ� �ֱ� ������ ���ľ˰��� �ȵ��� ��ġ������ ������ �׳� count���� �����ϱ� ���� ������ index = count��� ������
	int len = strlen(arr[count]); //�Է¹��� �ܾ��� ���̸� �޴� ����
	for (int i = 0; i < count; i++) {
		bool cmp = true; //�ܾ ���ϴ� �ܾ�� ������ ū�� ���ϴ� ����
		if (index != count) //���� �˰��� ���� �ѹ��̶� index�� ���氪�� ������ �� ��� �ݺ��� Ż��
			break;
		if (len >= strlen(arr[i])) { //���� ���� �ܾ��� ���̰� ���ϴ� �ܾ��� ���̺��� ũ�ų� ���� ���
			for (int j = 0; j < len; j++) {
				bool arr_count = false; //��ҹ��� ���ؼ� (��,��),(��,��),(��,��),(��,��)�� ��츦 ������ ���Ѻ���
				bool arr_i = false; //��ҹ��� ���ؼ� (��,��),(��,��),(��,��),(��,��)�� ��츦 ������ ���Ѻ���
				if (cmp == false)
					break;
				if (arr[i][j] >= 'a' && arr[i][j] <= 'z') //�񱳰��� �ҹ��ڸ� true
					arr_i = true;
				if (arr[count][j] >= 'a' && arr[count][j] <= 'z') //�񱳰��� �ҹ��ڸ� true
					arr_count = true;

				if (arr_i == true && arr_count == true) { //�Ѵ� �ҹ����ϰ��
					if (arr[i][j] > arr[count][j]) { //���ϴ� �ܾ �ξ��� ū���� index�� ���� index�� �ְ� �ݺ��� Ż��
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j]) { //���ϴ� �ܾ �������� ���� �ʿ䰡 ���� ������ cmp ������ false�Է��ϰ� ���ؼ� ���� �ܾ�ΰ����� �ϱ�
						cmp = false;
					}
				}
				else if (arr_i == true) { //���ϴ� �ܾ �ҹ����ϰ��
					if (arr[i][j] - 32 > arr[count][j]) {//���ϴ� �ܾ �ξ��� ū���� index�� ���� index�� �ְ� �ݺ��� Ż��
						index = i;
						break;
					}
					else if (arr[i][j] - 32 < arr[count][j]) { //���ϴ� �ܾ �������� ���� �ʿ䰡 ���� ������ cmp ������ false�Է��ϰ� ���ؼ� ���� �ܾ�ΰ����� �ϱ�
						cmp = false;
					}
				}
				else if (arr_count == true) { //�Է��� �ܾ �ҹ����� ���
					if (arr[i][j] > arr[count][j] - 32) {//���ϴ� �ܾ �ξ��� ū���� index�� ���� index�� �ְ� �ݺ��� Ż��
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j] - 32) { //���ϴ� �ܾ �������� ���� �ʿ䰡 ���� ������ cmp ������ false�Է��ϰ� ���ؼ� ���� �ܾ�ΰ����� �ϱ�
						cmp = false;
					}
				}
				else { //�Ѵ� �빮���� ���
					if (arr[i][j] > arr[count][j]) {//���ϴ� �ܾ �ξ��� ū���� index�� ���� index�� �ְ� �ݺ��� Ż��
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j]) { //���ϴ� �ܾ �������� ���� �ʿ䰡 ���� ������ cmp ������ false�Է��ϰ� ���ؼ� ���� �ܾ�ΰ����� �ϱ�
						cmp = false;
					}
				}
			}
		}
		else {//���� ���� �ܾ��� ���̰� ���ϴ� �ܾ��� ���̺��� �������
			for (int j = 0; j < strlen(arr[i]); j++) { //�ܾ��� ���̸�ŭ �ݺ���
				bool arr_count = false; //������ ��ҹ��� ��
				bool arr_i = false; // ������ ��ҹ��� ��
				if (cmp == false) //cmp��� ������ ������ ũ�Ⱑ �������� ���� �ʿ䰡 �����Ƿ� ���� ���ڷ� �����ϱ� ���� ����
					break; //������ �ݺ����� ������ ���� �ܾ�� ��
				if (arr[i][j] >= 'a' && arr[i][j] <= 'z') //���ϴ� �ܾ �ҹ����� ��� true
					arr_i = true;
				if (arr[count][j] >= 'a' && arr[count][j] <= 'z') //�Է��� �ܾ �ҹ����� ��� true
					arr_count = true;
				if (arr_i == true && arr_count == true) { //�Ѵ� �ҹ����� ���
					if (arr[i][j] > arr[count][j]) {
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j]) {
						cmp = false;
					}
				}
				else if (arr_i == true) { //���ϴ� ���� �ҹ����� ���
					if (arr[i][j] - 32 > arr[count][j]) {
						index = i;
						break;
					}
					else if (arr[i][j] - 32 < arr[count][j]) {
						cmp = false;
					}
				}
				else if (arr_count == true) { //�Է��� ���� �ҹ����� ���
					if (arr[i][j] > arr[count][j] - 32) {
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j] - 32) {
						cmp = false;
					}
				}
				else { //�Ѵ� �빮���� ���
					if (arr[i][j] > arr[count][j]) {
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j]) {
						cmp = false;
					}
				}
			}
		}
	}
	if (count != 0 || index == count) { //index�� ���� �˰��򿡼� �ѹ��� �ȵ��� �׳� count�� ���� �н�/ �ܾ����� �ܾ� ������ ȥ���� ���� �н�
		for (int i = count + 1; i >= index; i--) { //count���� �Էµȴܾ ����Ǿ������Ƿ� 
			arr[i] = arr[i - 1]; //������ ��ġ���� �ڷ� ���ܾ ��
		}
		arr[index] = arr[count + 1]; //count�� �Է��� �ܾ ��ĭ���з��� count +1�� �����Ƿ� count+1�� �ִ� ���� index�� ���� ��ġ�� �Ű���

	}
}


int main() {
	char* command = new char[20]; //command���� �޴� ���� 20��ŭ ũ�⸦ �Ҵ�����
	char** arr = new char* [101]; //�ܾ��� 2�������͸� 101�� ��ŭ �Ҵ�
	int count = 0; //�ܾ����� ��� ��������� ī��Ʈ
	bool end = true; // ���������� ������ ������ while���� �־ ��� ������
	arr[count] = new char[20]; //�ܾ��� ���� �ϳ� ����
	while (end) {
		cin >> command; //Ŀ�ǵ��Է�
		if (strcmp(command, "INSERT") == 0) { //Ŀ�ǵ�� INSERT ��� �ܾ����� Ȯ��
			if (count > 99) // �ܾ����� ������ 100���� �Ѿ�� ���� INSERT���� is Full ���
				cout << "is Full" << endl;
			else {
				cin >> arr[count]; // �ܾ��Է�
				if (find_equal(arr, count) == -1) { //find_equal �Լ��� ���� ��ҹ��ڵѴ� �ִ� �ܾ��忡 �ִ� ������ Ȯ��
					sort(arr, count); //�ܾ ��ġ�� �°� ����
					print(arr, count); //�ܾ ������ �� ���ݱ��� �ܾ���� ��� ���
					count++; //�ܾ����� �ܾ� ���� �ø���
					arr[count] = new char[20]; // ������ ���� �ܾ ���� �����Ҵ��ؼ� ����
				}
				else
					print(arr, count - 1); // �ܾ��� �����ܾ arr�� ������ ������ �����ؼ� ������ ���� ���� ����Ѵ�.
			}
		}
		else if (strcmp(command, "FIND") == 0) { //command�� FIND���� Ȯ��
			cin >> arr[count];
			if (find_equal(arr, count) == -1) { //�ܾ��忡 �ִ��� Ȯ���ϰ� ������ Not Found�� ���
				cout << "Not Found" << endl;
			}
			else {
				int index = find_equal(arr, count); //�ܾ��忡 ������ find_equal�Լ����� �� �ܾ��� �ε��� ���� ��ȯ�� ����
				cout << index << "." << arr[index] << '\n'; //�ܾ ���
			}
		}
		else if (strcmp(command, "END") == 0) { //command�� END���� Ȯ��
			end = false; //�ݺ�������
			delete[] command; //command�����Ҵ� ����
			for (int i = 0; i <= count; i++) { // ���ݱ��� �Ҵ� �ߴ� �ܾ�� ��� ����
				delete[] arr[i];
			}
			delete[] arr;
		}
		else
			cin.clear(); // ��ɾ �ƴ� �Է��� �ٽù޾ƾ� ������ ����� ���� ����
	}
}