#include <iostream>
#include <string>
#include <process.h>
#include <windows.h>
#include "KeyEvent.h"
#include "Frame.h"
#include "ExArray.h"
#include <vector>
#include <list>
#include <map>
using namespace std;


class Word {
private:
	string word;
public:
	Word(string word)
	{
		this->word = word;
	}
	string getWord()
	{
		return this->word;
	}

};
void main()
{
	map<char, list<Word>>m;
	list<Word> aList;
	list<Word> bList;

	aList.push_back(Word("apple"));
	aList.push_back(Word("avoid"));
	aList.push_back(Word("appear"));

	bList.push_back(Word("bread"));
	bList.push_back(Word("bring"));
	bList.push_back(Word("bow"));

	m['a'] = aList;
	m['b'] = bList;

	map<char, list<Word>>::const_iterator iter = m.begin();

	while (iter != m.end())
	{
		cout << iter->first << ":" << endl;

		list<Word> temp = iter->second;
		list<Word>::const_iterator iter_list = temp.begin();

		while (iter_list != temp.end())
		{
			Word word = *iter_list;
			cout << word.getWord() << ", ";
			iter_list++;
		}
		cout << "\n===" << endl;
		iter++;
	}
}
/*
map<string, int>m;
m["seoul"] = 100;
m["busan"] = 200;
m["daegu"] = 120;

cout << m["seoul"] << m["busan"] << m["daegu"] << endl;
*/
/*
void dump(list<string> &i)
{
	list<string>::iterator iter = i.begin();

	while (iter != i.end())
	{
		cout << *iter << endl;
		iter++;
	}
}
*/
/*
list<string> names;

names.insert(names.begin(), "Konkuk");
names.insert(names.end(), "University");
names.insert(names.end(), "SCLab");
names.insert(names.end(), "CSY");

dump(names);
cout << "=====" << endl;
names.reverse();
dump(names);
*/
	/*
	vector<int> v;

	v.push_back(10);	//뒤에 삽입
	v.push_back(20);
	v.push_back(30);
	v.insert(v.begin(), 40); //앞에 삽입
	v.insert(v.begin(), 50);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "Access Index at 1 :" << v.at(1) << endl;	//at 활용


	v.erase(v.begin());		//삭제
	v.erase(v.end() - 1);


	vector<int>::iterator iter = v.begin();	//iter 가 맨 앞을 가리키고 있음
	cout << "Access Index at 1 with iterator : " << iter[1] << endl;

	while (iter != v.end())
	{
		cout << *iter << endl;
		iter++;
	}
}
	*/
	/*
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
	*/
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
		cout << "■";
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