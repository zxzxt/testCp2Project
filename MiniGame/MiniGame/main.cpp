#include <windows.h>
#include <iostream>
#include "KeyEvent.h"
#include <process.h>
#include "Frame.h"
#include "ExArray.h"
using namespace std;


void main()
{
	ExArray<int> arr1(3);
	ExArray<char> arr2(4);
	ExArray<double> arr3(5);

	arr1.addData(2);
	arr2.addData('A');
	arr3.addData(32.12);

	arr1.printData();
	arr2.printData();
	arr3.printData();

	int num1 = 10, num2 = 40;
	cout << "Before: " << num1 << ", " << num2 << endl;
	mySwap<int>(num1, num2);
	cout << "After: " << num1 << ", " << num2 << endl;

	double num1d = 121.11, num2d = 10.5;
	cout << "Before: " << num1d << ", " << num2d << endl;
	mySwap<double>(num1d, num2d);
	cout << "After: " << num1d << ", " << num2d << endl;

	ExArray<int> arr4(5);
	arr4.addData(10);

	mySwap<ExArray<int>>(arr1, arr4);
	arr1.printData();
	arr4.printData();

	/*
	try{
	Frame *f1 = new Frame;
	Frame *f2 = new Frame[10];

	delete f1;
	delete[] f2;
	}
	catch(string msg){
	cout << "Error msg: " << msg << endl;
	}
	*/
}

/*
class Game {

private:
	int x;
	int y;
	int direction;
	void gotoXY(int x, int y)
	{
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

public:
	Game()
	{
		x = 5;
		y = 5;
		direction = 0;
	}
	void setDirection(int i)
	{
		direction = i;
	}
	void move()
	{
		if (direction == 37)
			x--;
		else if (direction == 38)
			y--;
		else if (direction == 39)
			x++;
		else if (direction == 40)
			y++;

		system("cls");
		this->gotoXY(x, y);
		cout << x << "  " << y;
		cout << "бс";
	}
};


Game* game = new Game();

unsigned int __stdcall mythread(void*)
{
	int i = 0;
	while (1)
	{
		game->move();
		Sleep(500);
	}

	return 0;
}

unsigned int __stdcall keyEvent(void*)
{
	KeyEvent k;
	int i;
	while (1)
	{
		i = k.getkey();
		if (i != -1) game->setDirection(i);
	}

	return 0;
}


int main()
{
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}
*/