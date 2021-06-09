#pragma once
class node
{
private:
	int data; // data값
	node* rNext; //row의 nect
	node* rPrev; // row의 prev
	node* cNext; // column의 next
	node* cPrev; // column의 prev
	node* hNext; // height의 next
	node* hPrev; // height의  prev
public:
	node(); // 생성자
	~node(); // 소멸자

	node* getRnext(); //값을 반환하는 매소드
	node* getRprev();//값을 반환하는 매소드
	node* getCnext();//값을 반환하는 매소드
	node* getCprev();//값을 반환하는 매소드
	node* getHprev();//값을 반환하는 매소드
	node* getHnext();//값을 반환하는 매소드
	int getData();//값을 반환하는 매소드

	void setRnext(node* pTemp); // 값을 변경하는 매소드
	void setRprev(node* pTemp);// 값을 변경하는 매소드
	void setCnext(node* pTemp);// 값을 변경하는 매소드
	void setCprev(node* pTemp);// 값을 변경하는 매소드
	void setHprev(node* pTemp);// 값을 변경하는 매소드
	void setHnext(node* pTemp);// 값을 변경하는 매소드
	void setData(int temp);// 값을 변경하는 매소드
};

