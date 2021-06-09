#pragma once
class tree_node {
private:
	char data[100]; // 데이터 값
	int low; // 계층값
	tree_node* pUp; // 윗값
	tree_node* pDown; // 아랫값
	tree_node* pNext; // 다음값
	tree_node* pPrev; // 이전값
public:
	tree_node(); // 생성자
	~tree_node(); // 소멸자

	int getLow(); //값을 반환해주는 매소드
	tree_node* getUp();//값을 반환해주는 매소드
	tree_node* getDown();//값을 반환해주는 매소드
	char* getData();//값을 반환해주는 매소드
	tree_node* getNext();//값을 반환해주는 매소드
	tree_node* getPrev();//값을 반환해주는 매소드

	void setLow(int temp); // 값을 변경하는 매소드
	void setUp(tree_node* pTemp);// 값을 변경하는 매소드
	void setDown(tree_node* pTemp);// 값을 변경하는 매소드
	void setData(char* pTemp);// 값을 변경하는 매소드
	void setNext(tree_node* pTemp);// 값을 변경하는 매소드
	void setPrev(tree_node* pTemp);// 값을 변경하는 매소드
};