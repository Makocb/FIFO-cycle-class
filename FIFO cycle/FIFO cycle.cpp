#include <iostream>

class arrFIFO {
private:
	int len, position;
	int arr[];
public:

	arrFIFO(int len)
	{
		this->len = len;
	}

	void fillArr()
	{
		int temp = 0;
		int i = position;
		while (temp != NAN)
		{
			std::cin >> temp;
			arr[i] = temp;
			i++;
			i %= len;
		}
		position = i;
	}

};


class arrPtrFIFO
{
private:
	struct member
	{
		member* root;
		member* next;
		int value;
	};
	int len;
	member* currentPos;
public:
	arrPtrFIFO(int len)
	{
		member* arr = new member;
		member* nextArr = new member;
		//currentPos = new member; 
		//currentPos = arr;
		arr->next = nextArr;
		nextArr->root = arr;
		currentPos = nextArr;
		for (int i = 0; i < len; i++)
		{
			//arr->next = nextArr;
			//nextArr->root = arr;
			arr = new member;
			arr = nextArr;
			nextArr = new member;
			arr->next = nextArr;
			nextArr->root = arr;
		}
		nextArr->next = currentPos;
		currentPos->root = nextArr;
	}

	void printArr() {
		member* checkPos = currentPos->root;
		while (checkPos != currentPos) {
			std::cout << currentPos->value << " ";
			currentPos = currentPos->next;
		}
	}

	void fillArr()
	{
		int temp = 1;
		while (temp != 0)
		{
			std::cin >> temp;
			currentPos->value = temp;
			currentPos = currentPos->next;
		}
	}

	~arrPtrFIFO()
	{
		member* checkPos = currentPos->root;
		while (currentPos->next != checkPos)
		{
			member* checkPos = currentPos->root;
			delete currentPos->root;
			currentPos = currentPos->next;
		}
		delete currentPos->root;
	}
};

int main()
{
	arrPtrFIFO* arr = new arrPtrFIFO(5);
	arr->fillArr();
	arr->printArr();
	delete arr;

}