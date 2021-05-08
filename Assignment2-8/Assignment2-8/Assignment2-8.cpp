#include <iostream>

using namespace std;

class Animal {
private:
	int Foodchain; // 먹이사슬 변수
	int Distance; // 간 거리 변수
	bool Arrival; // 도착했는지 안는지 확인
public:
	Animal(int Foodchain) { //Animal생성자
		Arrival = false;
		Distance = 0;
		this->Foodchain = Foodchain;
	}
	virtual void run() = 0; //가상함수
	int getFoodchain() { //private 값을 반환하는 get매소드
		return this->Foodchain;
	}
	int getDistance() {//private 값을 반환하는 get매소드
		return this->Distance;
	}
	bool getArrival() {//private 값을 반환하는 get매소드
		return this->Arrival;
	}
	void setFoodchain(int Foodchain) {//private의 값을 변경하는 set매소드
		this->Foodchain = Foodchain;
	}
	void setDistance(int Distance) {//private의 값을 변경하는 set매소드
		this->Distance = Distance;
	}
	void setArrival(bool Arrival) {//private의 값을 변경하는 set매소드
		this->Arrival = Arrival;
	}
};

class Snake : public Animal {
public:
	Snake(int Foodchain) : Animal(Foodchain) {

	}
	virtual void run() {
		setDistance(getDistance() + 1); // 기존값에 Snake는 1만큼 움직이기 때문에 +1을해줌
		if (getDistance() > 10) // distance가 10 이상이면 도착했기 때문에 Arrival을 도착으로 바꾸어줌(true)
			setArrival(true); //Arrival을 true로 바꾸어줌
	}
};

class Frog : public Animal {
public:
	Frog(int Foodchain) : Animal(Foodchain) {

	}
	virtual void run() {
		setDistance(getDistance() + 2); // 기존값에 frog는 2만큼 움직이기 때문에 +2해줌
		if (getDistance() > 10) // distance가 10 이상이면 도착했기 때문에 Arrival을 도착으로 바꾸어줌(true)
			setArrival(true); //Arrival을 true로 바꾸어줌
	}
};

class Eagle : public Animal {
public:
	Eagle(int Foodchain) : Animal(Foodchain) {

	}
	virtual void run() {
		setDistance(getDistance() + 4); //기존값에 Eagle은 4만큼 움직이기 때문에 +4를 해줌
		if (getDistance() > 10) // distance가 10이상이면 도착했기 때문에 Arrival을 도착으로 바꾸어줌(true);
			setArrival(true); // Arrival 값 true
	}
};

class Tiger : public Animal {
public:
	Tiger(int Foodchain) : Animal(Foodchain) {

	}
	virtual void run() {
		setDistance(getDistance() + 3);
		if (getDistance() > 10)
			setArrival(true);
	}
};

void print(char arr[]) {
	for (int i = 1; i < 11; i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
}

int main() {
	Animal* snake = new Snake(3); //Snake 객체 생성
	Animal* frog = new Frog(4); //Frog 객체 생성
	Animal* eagle = new Eagle(2); // Eagle 객체 생성
	Animal* tiger = new Tiger(1); // Tiger 객체생성
	char arr[11]; // 달리기 시합하는 판 선언
	int count = 0; // 몇번 째 달리는지 count
	char sequence[5]; // S,F,E,T의 각각 순서 받는 배열
	bool end = true; //반복문의 조건
	int snake_row = -1; //snake의 시작 순서저장 변수
	int frog_row = -1; // frog의 시작 순서 저장 변수
	int eagle_row = -1; // eagle의 시작 순서 저장 변수
	int tiger_row = -1; // tiger의 시작 순서 저장 변수
	cout << "Select Animal Sequence(S,F,E,T / ex : S F T E) :";
	for (int i = 0; i < 4; i++) {
		cin >> sequence[i]; // 순서 입력받기
		if (sequence[i] == 'S')
			snake_row = i + 1; //만약 받으면 +1번에 순서를 저장
		else if (sequence[i] == 'F')
			frog_row = i + 1;//만약 받으면 +1번에 순서를 저장
		else if (sequence[i] == 'T')
			tiger_row = i + 1;//만약 받으면 +1번에 순서를 저장
		else if (sequence[i] == 'E')
			eagle_row = i + 1;//만약 받으면 +1번에 순서를 저장

	}
	if (snake_row != -1 && frog_row != -1 && tiger_row != -1 && eagle_row != -1) { // S,T,E,F중 안받은 값이 있으면 작동 x
		while (end) {
			for (int i = 0; i < 11; i++) {
				arr[i] = '0';
			} // 달리는 판을 '0'으로 초기화
			if (count >= frog_row) { //순번째부터 계속 출발하게 하는 조건문
				frog->run(); // frog가 달리는(Distance)를 변경하는 매소드 호출  
				if (frog->getArrival() == false) {  //frog가 도착했는지 확인 안했으면 호출 x
					if (arr[frog->getDistance()] == '0') { // 빈공간이면 Frog가 도착
						arr[frog->getDistance()] = 'F'; // '0'대신 Frog출력
					}
					else {
						frog->setDistance(0); //빈공간이 아니라면 먹이사슬 최하이기 때문에 잡아먹혀 distance값을 0으로 초기화
					}
				}
			}
			if (count >= snake_row) { // 순번째부터 계속 출발하게 하는 조건문
				snake->run(); // snake가 달리는(Distance)를 변경하는 매소드 호출
				if (snake->getArrival() == false) { //snake가 도착했는지 확인 안했으면 호출x
					if (arr[snake->getDistance()] == '0') { // 빈공간이면 Snake가 도착
						arr[snake->getDistance()] = 'S'; // '0'자리에 S넣기
					}
					else if (arr[snake->getDistance()] == 'F') { // Frog가 가야하는 자리에 있으면 잡아먹음
						arr[snake->getDistance()] = 'S'; // S출력
						frog->setDistance(0); // Frog는 잡아먹혔으므로 Distance를 0으로 초기화
					}
				}
			}
			if (count >= eagle_row) { //순번 째부터 계속 출발하게 하는 조건문
				eagle->run(); // eagle이 달리는(Distance)를 변경하는 매소드 호출
				if (eagle->getArrival() == false) { // Eagle이 도착했는지 확인 안했으면 호출 x
					if (arr[eagle->getDistance()] == '0') { // 빈공간이면 eagle이 도착
						arr[eagle->getDistance()] = 'E'; // Eagle 넣어주기
					}
					else if (arr[eagle->getDistance()] == 'F') { // Frog를 만나면 먹이사슬이 위이므로 잡아먹음
						arr[eagle->getDistance()] = 'E'; //frog자리에 Eagle출력
						frog->setDistance(0); // frog는 잡아먹혔으므로 Distance를 0으로 초기화
					}
					else if (arr[eagle->getDistance()] == 'T') {
						eagle->setDistance(0); // Tiger을 만나면 먹이사슬이 위인 존재이므로 eagle의 Distance를 0으로 초기화
					}
					else if (arr[eagle->getDistance()] == 'S') { // Snake를 만나면 먹이사슬이 위이므로 잡아먹음
						arr[eagle->getDistance()] = 'E'; // snake자리에 Eagle 추가
						snake->setDistance(0); // Snake의 Distance를 0으로 초기화
					}
				}
			}
			if (count >= tiger_row) { //타이거의 순번째부터 tiger을 계속출발시킴
				tiger->run(); // tiger의 Distance값을 변경시키는 매소드 호출
				if (tiger->getArrival() == false) { //tiger이 이미 도착했으면 출발하지 않게함
					if (arr[tiger->getDistance()] == '0') { // 빈공간이면 
						arr[tiger->getDistance()] = 'T'; // Tiger을 자리에 넣음
					}
					else if (arr[tiger->getDistance()] == 'F') { //tiger은 먹의사슬의 정점이므로 Frog를 잡아먹음
						arr[tiger->getDistance()] = 'T'; // Frog자리에 T를 입력
						frog->setDistance(0); // Frog의 Distance값을 0으로 초기화
					}
					else if (arr[tiger->getDistance()] == 'E') { // tiger은 먹이사슬의 정점이므로 Eagle을 잡아먹음
						arr[tiger->getDistance()] = 'T'; // eagle자리에 T를 입력
						eagle->setDistance(0); // eagle의 Distance값을 0으로 초기화
					}
					else if (arr[tiger->getDistance()] == 'S') { // snake는 Tiger에게 잡아먹힘
						arr[tiger->getDistance()] = 'T'; // snake자리에 T입력
						snake->setDistance(0); // Snake는 잡아먹혔으므로 Distance값을 0으로 초기화
					}
				}
			}

			count++; //count를 증가시킴
			print(arr); // 달리는 트랙 출력
			if (frog->getArrival() && snake->getArrival() && tiger->getArrival() && eagle->getArrival()) //4동물이 모두 도착했을때
				end = false; // 반복문 종료
		}
	}
	else { //4동물을 모두 입력하지 않았을 때 종료
		cout << "입력 오류입니다 " << endl;
	}
	delete frog;// frog의 메모리 해제
	delete snake; // snake의 메모리 해제
	delete eagle; //eagle의 메모리 해제
	delete tiger; // tiger의 메모리 해제
}