#include <iostream>

using namespace std;

int find_equal(char** arr, int count) { //int형 함수로 단어장에 있는 단어에서 비교후 같은단어가 있으면 index값을 반환
	char* temp = new char[20]; //find 단어가 소문자일 때는 대문자 대문자일때는 소문자로 받는 포인터
	int cmp_low = -1; // 대문자,소문자의 index값 저장 변수가 둘다 없으면 초기값인 -1반환
	int cmp_up = -1; // 소문자, 대문자의 index값 저장 변수가 둘다 없으면 초기값인 -1반환
	if (arr[count][0] >= 'A' && arr[count][0] <= 'Z') { // find에서 받은 변수가 대문자일 경우 temp에 소문자 저장
		for (int i = 0; i < strlen(arr[count]); i++) {
			temp[i] = arr[count][i] + 32;
		}
	}
	else {//반대로 소문자일 경우 대문자로 저장
		for (int i = 0; i < strlen(arr[count]); i++) {
			temp[i] = arr[count][i] - 32;
		}
	}
	temp[strlen(arr[count])] = '\0'; //char형 포인터의 마지막 값은 '\0'을 넣어줘 끝을 만듬
	for (int i = 0; i < count; i++) { //find하는 단어가 있는지 확인
		if (strcmp(arr[i], arr[count]) == 0) {
			cmp_low = i; //있으면 index값 저장
		}
		if (strcmp(arr[i], temp) == 0) {
			cmp_up = i;
		}
	}
	delete[] temp; //사용이 끝난 temp의 포인터는 메모리 해제
	if (cmp_low > -1 || cmp_up > -1) { //대소문자 둘중 하나라도 값이 있었으면 있던 index값 출력
		if (cmp_low > -1)
			return cmp_low;
		else
			return cmp_up;
	}
	return -1; //없다면 -1 반환

}

void print(char** arr, int count) { //단어장에 있는 단어 출력 프로그램
	for (int i = 0; i <= count; i++) {
		cout << i << '.' << arr[i] << endl;
	}
}

void sort(char* arr[], int count) { //단어를 입력받으면 정렬해주는 함수
	int index = count; //변수가 count값에 저장되어 있기 때문에 정렬알고리즘에 안들어가고 위치변동이 없으면 그냥 count값에 저장하기 위해 변수를 index = count라고 저장함
	int len = strlen(arr[count]); //입력받은 단어의 길이를 받는 변수
	for (int i = 0; i < count; i++) {
		bool cmp = true; //단어가 비교하는 단어보다 작은지 큰지 비교하는 변수
		if (index != count) //정렬 알고리즘에 의해 한번이라도 index가 변경값이 있으면 그 즉시 반복문 탈출
			break;
		if (len >= strlen(arr[i])) { //만약 넣을 단어의 길이가 비교하는 단어의 길이보다 크거나 같을 경우
			for (int j = 0; j < len; j++) {
				bool arr_count = false; //대소문자 비교해서 (대,대),(소,소),(대,소),(소,대)인 경우를 따지기 위한변수
				bool arr_i = false; //대소문자 비교해서 (대,대),(소,소),(대,소),(소,대)인 경우를 따지기 위한변수
				if (cmp == false)
					break;
				if (arr[i][j] >= 'a' && arr[i][j] <= 'z') //비교값이 소문자면 true
					arr_i = true;
				if (arr[count][j] >= 'a' && arr[count][j] <= 'z') //비교값이 소문자면 true
					arr_count = true;

				if (arr_i == true && arr_count == true) { //둘다 소문자일경우
					if (arr[i][j] > arr[count][j]) { //비교하는 단어가 훨씬더 큰경우는 index에 현재 index값 넣고 반복문 탈출
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j]) { //비교하는 단어가 작은경우는 비교할 필요가 없기 때문에 cmp 변수에 false입력하고 위해서 다음 단어로가도록 하기
						cmp = false;
					}
				}
				else if (arr_i == true) { //비교하는 단어만 소문자일경우
					if (arr[i][j] - 32 > arr[count][j]) {//비교하는 단어가 훨씬더 큰경우는 index에 현재 index값 넣고 반복문 탈출
						index = i;
						break;
					}
					else if (arr[i][j] - 32 < arr[count][j]) { //비교하는 단어가 작은경우는 비교할 필요가 없기 때문에 cmp 변수에 false입력하고 위해서 다음 단어로가도록 하기
						cmp = false;
					}
				}
				else if (arr_count == true) { //입력한 단어만 소문자일 경우
					if (arr[i][j] > arr[count][j] - 32) {//비교하는 단어가 훨씬더 큰경우는 index에 현재 index값 넣고 반복문 탈출
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j] - 32) { //비교하는 단어가 작은경우는 비교할 필요가 없기 때문에 cmp 변수에 false입력하고 위해서 다음 단어로가도록 하기
						cmp = false;
					}
				}
				else { //둘다 대문자일 경우
					if (arr[i][j] > arr[count][j]) {//비교하는 단어가 훨씬더 큰경우는 index에 현재 index값 넣고 반복문 탈출
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j]) { //비교하는 단어가 작은경우는 비교할 필요가 없기 때문에 cmp 변수에 false입력하고 위해서 다음 단어로가도록 하기
						cmp = false;
					}
				}
			}
		}
		else {//만약 넣을 단어의 길이가 비교하는 단어의 길이보다 작을경우
			for (int j = 0; j < strlen(arr[i]); j++) { //단어의 길이만큼 반복문
				bool arr_count = false; //문자의 대소문자 비교
				bool arr_i = false; // 문자의 대소문자 비교
				if (cmp == false) //cmp라는 변수는 문자의 크기가 작을경우는 비교할 필요가 없으므로 다음 문자로 변경하기 위한 변수
					break; //작으면 반복문을 끝내고 다음 단어로 비교
				if (arr[i][j] >= 'a' && arr[i][j] <= 'z') //비교하는 단어가 소문자일 경우 true
					arr_i = true;
				if (arr[count][j] >= 'a' && arr[count][j] <= 'z') //입력한 단어가 소문자일 경우 true
					arr_count = true;
				if (arr_i == true && arr_count == true) { //둘다 소문자일 경우
					if (arr[i][j] > arr[count][j]) {
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j]) {
						cmp = false;
					}
				}
				else if (arr_i == true) { //비교하는 값만 소문자일 경우
					if (arr[i][j] - 32 > arr[count][j]) {
						index = i;
						break;
					}
					else if (arr[i][j] - 32 < arr[count][j]) {
						cmp = false;
					}
				}
				else if (arr_count == true) { //입력한 값만 소문자일 경우
					if (arr[i][j] > arr[count][j] - 32) {
						index = i;
						break;
					}
					else if (arr[i][j] < arr[count][j] - 32) {
						cmp = false;
					}
				}
				else { //둘다 대문자일 경우
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
	if (count != 0 || index == count) { //index가 정렬 알고리즘에서 한번도 안들어가서 그냥 count일 경우는 패스/ 단어장의 단어 개수가 혼자일 때는 패스
		for (int i = count + 1; i >= index; i--) { //count값에 입력된단어가 저장되어있으므로 
			arr[i] = arr[i - 1]; //들어가야할 위치부터 뒤로 모든단어를 밈
		}
		arr[index] = arr[count + 1]; //count에 입력한 단어가 한칸씩밀려서 count +1에 있으므로 count+1에 있는 값을 index로 넣을 위치에 옮겨줌

	}
}


int main() {
	char* command = new char[20]; //command값을 받는 변수 20만큼 크기를 할당해줌
	char** arr = new char* [101]; //단어장 2중포인터를 101개 만큼 할당
	int count = 0; //단어장이 몇개가 생성됬는지 카운트
	bool end = true; // 종료조건이 끝나기 전까지 while문에 넣어서 계속 돌려줌
	arr[count] = new char[20]; //단어장 값을 하나 생성
	while (end) {
		cin >> command; //커맨드입력
		if (strcmp(command, "INSERT") == 0) { //커맨드와 INSERT 라는 단어인지 확인
			if (count > 99) // 단어장의 갯수가 100개를 넘어가면 다음 INSERT부터 is Full 출력
				cout << "is Full" << endl;
			else {
				cin >> arr[count]; // 단어입력
				if (find_equal(arr, count) == -1) { //find_equal 함수를 통해 대소문자둘다 있는 단어장에 있는 값인지 확인
					sort(arr, count); //단어를 위치에 맞게 정렬
					print(arr, count); //단어를 정렬한 후 지금까지 단어들을 모두 출력
					count++; //단어장의 단어 개수 늘리기
					arr[count] = new char[20]; // 다음에 받을 단어를 위해 동적할당해서 생성
				}
				else
					print(arr, count - 1); // 단어장 받은단어를 arr의 마지막 번지에 저장해서 마지막 번지 빼고 출력한다.
			}
		}
		else if (strcmp(command, "FIND") == 0) { //command가 FIND인지 확인
			cin >> arr[count];
			if (find_equal(arr, count) == -1) { //단어장에 있는지 확인하고 없으면 Not Found를 출력
				cout << "Not Found" << endl;
			}
			else {
				int index = find_equal(arr, count); //단어장에 있으면 find_equal함수에서 그 단어의 인덱스 값을 반환해 저장
				cout << index << "." << arr[index] << '\n'; //단어를 출력
			}
		}
		else if (strcmp(command, "END") == 0) { //command가 END인지 확인
			end = false; //반복문종료
			delete[] command; //command동적할당 해제
			for (int i = 0; i <= count; i++) { // 지금까지 할당 했던 단어들 모두 해제
				delete[] arr[i];
			}
			delete[] arr;
		}
		else
			cin.clear(); // 명령어가 아닌 입력은 다시받아야 함으로 저장된 버퍼 삭제
	}
}