#pragma once

class moving {
private:
	int step;
	moving* pNext;
public:
	moving();
	~moving();
	int getStep();
	moving* getNext();

	void setStep(int temp);
	void setNext(moving* pTemp);

};
