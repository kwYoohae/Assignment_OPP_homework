#include <iostream>

using namespace std;

class Animal {
private:
	int Foodchain; // ���̻罽 ����
	int Distance; // �� �Ÿ� ����
	bool Arrival; // �����ߴ��� �ȴ��� Ȯ��
public:
	Animal(int Foodchain) { //Animal������
		Arrival = false;
		Distance = 0;
		this->Foodchain = Foodchain;
	}
	virtual void run() = 0; //�����Լ�
	int getFoodchain() { //private ���� ��ȯ�ϴ� get�żҵ�
		return this->Foodchain;
	}
	int getDistance() {//private ���� ��ȯ�ϴ� get�żҵ�
		return this->Distance;
	}
	bool getArrival() {//private ���� ��ȯ�ϴ� get�żҵ�
		return this->Arrival;
	}
	void setFoodchain(int Foodchain) {//private�� ���� �����ϴ� set�żҵ�
		this->Foodchain = Foodchain;
	}
	void setDistance(int Distance) {//private�� ���� �����ϴ� set�żҵ�
		this->Distance = Distance;
	}
	void setArrival(bool Arrival) {//private�� ���� �����ϴ� set�żҵ�
		this->Arrival = Arrival;
	}
};

class Snake : public Animal {
public:
	Snake(int Foodchain) : Animal(Foodchain) {

	}
	virtual void run() {
		setDistance(getDistance() + 1); // �������� Snake�� 1��ŭ �����̱� ������ +1������
		if (getDistance() > 10) // distance�� 10 �̻��̸� �����߱� ������ Arrival�� �������� �ٲپ���(true)
			setArrival(true); //Arrival�� true�� �ٲپ���
	}
};

class Frog : public Animal {
public:
	Frog(int Foodchain) : Animal(Foodchain) {

	}
	virtual void run() {
		setDistance(getDistance() + 2); // �������� frog�� 2��ŭ �����̱� ������ +2����
		if (getDistance() > 10) // distance�� 10 �̻��̸� �����߱� ������ Arrival�� �������� �ٲپ���(true)
			setArrival(true); //Arrival�� true�� �ٲپ���
	}
};

class Eagle : public Animal {
public:
	Eagle(int Foodchain) : Animal(Foodchain) {

	}
	virtual void run() {
		setDistance(getDistance() + 4); //�������� Eagle�� 4��ŭ �����̱� ������ +4�� ����
		if (getDistance() > 10) // distance�� 10�̻��̸� �����߱� ������ Arrival�� �������� �ٲپ���(true);
			setArrival(true); // Arrival �� true
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
	Animal* snake = new Snake(3); //Snake ��ü ����
	Animal* frog = new Frog(4); //Frog ��ü ����
	Animal* eagle = new Eagle(2); // Eagle ��ü ����
	Animal* tiger = new Tiger(1); // Tiger ��ü����
	char arr[11]; // �޸��� �����ϴ� �� ����
	int count = 0; // ��� ° �޸����� count
	char sequence[5]; // S,F,E,T�� ���� ���� �޴� �迭
	bool end = true; //�ݺ����� ����
	int snake_row = -1; //snake�� ���� �������� ����
	int frog_row = -1; // frog�� ���� ���� ���� ����
	int eagle_row = -1; // eagle�� ���� ���� ���� ����
	int tiger_row = -1; // tiger�� ���� ���� ���� ����
	cout << "Select Animal Sequence(S,F,E,T / ex : S F T E) :";
	for (int i = 0; i < 4; i++) {
		cin >> sequence[i]; // ���� �Է¹ޱ�
		if (sequence[i] == 'S')
			snake_row = i + 1; //���� ������ +1���� ������ ����
		else if (sequence[i] == 'F')
			frog_row = i + 1;//���� ������ +1���� ������ ����
		else if (sequence[i] == 'T')
			tiger_row = i + 1;//���� ������ +1���� ������ ����
		else if (sequence[i] == 'E')
			eagle_row = i + 1;//���� ������ +1���� ������ ����

	}
	if (snake_row != -1 && frog_row != -1 && tiger_row != -1 && eagle_row != -1) { // S,T,E,F�� �ȹ��� ���� ������ �۵� x
		while (end) {
			for (int i = 0; i < 11; i++) {
				arr[i] = '0';
			} // �޸��� ���� '0'���� �ʱ�ȭ
			if (count >= frog_row) { //����°���� ��� ����ϰ� �ϴ� ���ǹ�
				frog->run(); // frog�� �޸���(Distance)�� �����ϴ� �żҵ� ȣ��  
				if (frog->getArrival() == false) {  //frog�� �����ߴ��� Ȯ�� �������� ȣ�� x
					if (arr[frog->getDistance()] == '0') { // ������̸� Frog�� ����
						arr[frog->getDistance()] = 'F'; // '0'��� Frog���
					}
					else {
						frog->setDistance(0); //������� �ƴ϶�� ���̻罽 �����̱� ������ ��Ƹ��� distance���� 0���� �ʱ�ȭ
					}
				}
			}
			if (count >= snake_row) { // ����°���� ��� ����ϰ� �ϴ� ���ǹ�
				snake->run(); // snake�� �޸���(Distance)�� �����ϴ� �żҵ� ȣ��
				if (snake->getArrival() == false) { //snake�� �����ߴ��� Ȯ�� �������� ȣ��x
					if (arr[snake->getDistance()] == '0') { // ������̸� Snake�� ����
						arr[snake->getDistance()] = 'S'; // '0'�ڸ��� S�ֱ�
					}
					else if (arr[snake->getDistance()] == 'F') { // Frog�� �����ϴ� �ڸ��� ������ ��Ƹ���
						arr[snake->getDistance()] = 'S'; // S���
						frog->setDistance(0); // Frog�� ��Ƹ������Ƿ� Distance�� 0���� �ʱ�ȭ
					}
				}
			}
			if (count >= eagle_row) { //���� °���� ��� ����ϰ� �ϴ� ���ǹ�
				eagle->run(); // eagle�� �޸���(Distance)�� �����ϴ� �żҵ� ȣ��
				if (eagle->getArrival() == false) { // Eagle�� �����ߴ��� Ȯ�� �������� ȣ�� x
					if (arr[eagle->getDistance()] == '0') { // ������̸� eagle�� ����
						arr[eagle->getDistance()] = 'E'; // Eagle �־��ֱ�
					}
					else if (arr[eagle->getDistance()] == 'F') { // Frog�� ������ ���̻罽�� ���̹Ƿ� ��Ƹ���
						arr[eagle->getDistance()] = 'E'; //frog�ڸ��� Eagle���
						frog->setDistance(0); // frog�� ��Ƹ������Ƿ� Distance�� 0���� �ʱ�ȭ
					}
					else if (arr[eagle->getDistance()] == 'T') {
						eagle->setDistance(0); // Tiger�� ������ ���̻罽�� ���� �����̹Ƿ� eagle�� Distance�� 0���� �ʱ�ȭ
					}
					else if (arr[eagle->getDistance()] == 'S') { // Snake�� ������ ���̻罽�� ���̹Ƿ� ��Ƹ���
						arr[eagle->getDistance()] = 'E'; // snake�ڸ��� Eagle �߰�
						snake->setDistance(0); // Snake�� Distance�� 0���� �ʱ�ȭ
					}
				}
			}
			if (count >= tiger_row) { //Ÿ�̰��� ����°���� tiger�� �����߽�Ŵ
				tiger->run(); // tiger�� Distance���� �����Ű�� �żҵ� ȣ��
				if (tiger->getArrival() == false) { //tiger�� �̹� ���������� ������� �ʰ���
					if (arr[tiger->getDistance()] == '0') { // ������̸� 
						arr[tiger->getDistance()] = 'T'; // Tiger�� �ڸ��� ����
					}
					else if (arr[tiger->getDistance()] == 'F') { //tiger�� ���ǻ罽�� �����̹Ƿ� Frog�� ��Ƹ���
						arr[tiger->getDistance()] = 'T'; // Frog�ڸ��� T�� �Է�
						frog->setDistance(0); // Frog�� Distance���� 0���� �ʱ�ȭ
					}
					else if (arr[tiger->getDistance()] == 'E') { // tiger�� ���̻罽�� �����̹Ƿ� Eagle�� ��Ƹ���
						arr[tiger->getDistance()] = 'T'; // eagle�ڸ��� T�� �Է�
						eagle->setDistance(0); // eagle�� Distance���� 0���� �ʱ�ȭ
					}
					else if (arr[tiger->getDistance()] == 'S') { // snake�� Tiger���� ��Ƹ���
						arr[tiger->getDistance()] = 'T'; // snake�ڸ��� T�Է�
						snake->setDistance(0); // Snake�� ��Ƹ������Ƿ� Distance���� 0���� �ʱ�ȭ
					}
				}
			}

			count++; //count�� ������Ŵ
			print(arr); // �޸��� Ʈ�� ���
			if (frog->getArrival() && snake->getArrival() && tiger->getArrival() && eagle->getArrival()) //4������ ��� ����������
				end = false; // �ݺ��� ����
		}
	}
	else { //4������ ��� �Է����� �ʾ��� �� ����
		cout << "�Է� �����Դϴ� " << endl;
	}
	delete frog;// frog�� �޸� ����
	delete snake; // snake�� �޸� ����
	delete eagle; //eagle�� �޸� ����
	delete tiger; // tiger�� �޸� ����
}