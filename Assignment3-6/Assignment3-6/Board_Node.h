#pragma once

class Board_Node {
private:
	Board_Node* pNext;
	Board_Node* pPrev;
	bool right_up;
	bool finish_line;
	bool left_down;
	bool center;
	bool left_up;
	int position;

public:
	Board_Node() {
		pNext = nullptr;
		pPrev = nullptr;
		right_up = false;
		finish_line = false;
		left_down = false;
		center = false;
		left_up = false;
		position = 0;
	}

	void setPos(int temp) {
		position = temp;
	}

	void setNext(Board_Node* pTemp) {
		pNext = pTemp;
	}

	void setPrev(Board_Node* pTemp) {
		pPrev = pTemp;
	}

	void setRight_up(bool temp) {
		right_up = temp;
	}

	void setLeft_up(bool temp) {
		left_up = temp;
	}

	void setLeft_down(bool temp) {
		left_down = temp;
	}

	void setFinsh(bool temp) {
		finish_line = temp;
	}

	void setCenter(bool temp) {
		center = temp;
	}

	Board_Node* getNext() {
		return pNext;
	}

	Board_Node* getPrev() {
		return pPrev;
	}

	bool getRight_up() {
		return right_up;
	}
	bool getLeft_up() {
		return left_up;
	}
	bool getLeft_down() {
		return left_down;
	}
	bool getCenter() {
		return center;
	}
	bool getFinish() {
		return finish_line;
	}

	int getPos() {
		return position;
	}

};