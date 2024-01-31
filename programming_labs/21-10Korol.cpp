#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;


void func1(), func2(), func3(), cinClear();

int main() {

	srand(time(NULL));

	while (true) {

		system("cls");
		cout << "Group ES-21, Korol, #10\n";

		int n;
		cout << "1 - Task 1\n2 - Task 2\n3 - Task 3\n4 - Exit\n";
		cout << "Choose task: ";
		cin >> n;

		while (cin.fail()) {

			cinClear();

			cout << "1 - Task 1\n2 - Task 2\n3 - Task 3\n4 - Exit\n";
			cout << "Choose task: ";
			cin >> n;

		}

		switch (n) {
		case 1:
			func1();
			break;
		case 2:
			func2();
			break;
		case 3:
			func3();
			break;
		case 4:
			return 0;
			break;

		default:
			continue;
		}

	}

}

void cinClear() {

	system("cls");

	cin.clear();
	cin.ignore(256, '\n');
	cout << "Check input and try again.\n";

}

void waitForKey() {
	cout << "Wait for any key...\n";
	_getch();
}


int* findMinAndMax(int* r, int arraySize) {

	int min = 301, max = 199;

	for (int i = 0; i < arraySize; i++) {
		if (r[i] > max)
			max = r[i];
		if (r[i] < min)
			min = r[i];
	}

	int* a = new int[2] { min, max };

	return a;
}

void func1() {

	const int arraySize = 10;
	int randoms[arraySize], min = 0, max = 0;

	for (int i = 0; i < arraySize; i++) {
		randoms[i] = 200 + rand() % 101;
	}

	int* minMaxArr;
	minMaxArr = findMinAndMax(randoms, arraySize);
	min = minMaxArr[0];
	max = minMaxArr[1];
	delete minMaxArr;

	for (int i = 0; i < arraySize; i++) {
		cout << (i+1) << '\t' << randoms[i] << '\n';
	}
	cout << "\nMin:\t" << min << "\nMax:\t" << max << '\n';


	waitForKey();
}


void func2() {
	const int arraySize = 10;
	int randoms[arraySize], min = 0, max = 0;

	for (int i = 0; i < arraySize; i++) {
		randoms[i] = rand() % 41 - 20;
	}

	for (int i = 0; i < arraySize; i++) {
		cout << (i+1) << '\t' << randoms[i] << '\n';
		if (randoms[i] > 0)
			randoms[i] = -randoms[i];
		else
			randoms[i] = 55;
	}

	cout << '\n';

	for (int i = 0; i < arraySize; i++) {
		cout << (i+1) << '\t' << randoms[i] << '\n';
	}


	waitForKey();
}


struct User {
	int Id;
	string Name, Surname, PhoneNumber, Profession;
	char Sex;
};

void printUser(User user) {

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	cout << "Id: "<< user.Id << '\n';
	cout << "Name: " << user.Name << '\n';
	cout << "Surname: " << user.Surname << '\n';
	cout << "Sex: " << user.Sex << '\n';
	cout << "Profession: " << user.Profession << '\n';
	cout << "Phone number: " << user.PhoneNumber << '\n';

}

void func3() {
	system("cls");

	const int usersCount = 2;
	User users[usersCount];

	users[0].Id = 0;
	users[0].Name = "Vitail";
	users[0].Surname = "Cal";
	users[0].Sex = 'm';
	users[0].PhoneNumber = "+380505555556";
	users[0].Profession = "Papich";

	users[1].Id = 1;
	users[1].Name = "Killer";
	users[1].Surname = "Bob";
	users[1].Sex = 'b';
	users[1].PhoneNumber = "+380506666667";
	users[1].Profession = "Killer";

	for (auto u : users) {
		printUser(u);
		cout << '\n';
	}

	waitForKey();
}