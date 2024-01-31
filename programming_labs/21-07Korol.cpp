#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

#define PI			3.1415926
#define EULER		2.7182818

using namespace std;


// Контрольні запитання (виділенні курсивом перші два, тому на них і відповідаю):
// Оператори розгалуження: if, else if, else, switch case
// Оператори циклу: for, while, do while


void func1(), func2(), func3(), func4(), func5(), func6(), cinClear();

int main() {

	int taskCount = 6;

	while (true) {

		system("cls");
		cout << "Group ES-21, Korol, #6\n";

		int n;

		for (int i = 1; i <= taskCount; i++) {
			cout << i << " - Task " << i << '\n';
		}
		cout << "0 - Exit\n";

		cout << "Choose task: ";
		cin >> n;

		while (cin.fail()) {

			cinClear();

			for (int i = 1; i <= taskCount; i++) {
				cout << i << " - Task " << i << '\n';
			}
			cout << taskCount+1 << " - Exit\n";

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
			func4();
			break;
		case 5:
			func5();
			break;
		case 6:
			func6();
			break;
		case 0:
			return 0;
			break;

		default:
			continue;
		}

	}

	return 0;
}

void wait(int duration) {

	for (int i = 0; i < duration; i++) {
		cout << duration - i << "... ";
		Sleep(1000);
	}

}

void cinClear() {

	system("cls");

	cin.clear();
	cin.ignore(256, '\n');
	cout << "Check input and try again.\n";

}

void func1() {

	system("cls");

	int n, x;
	cout << "Enter count of loops: ";
	cin >> n;
	cout << "Enter x: ";
	cin >> x;

	while (cin.fail() || n < 0 || x < 0) {

		cinClear();

		cout << "Enter count of loops again (bigger than 0): ";
		cin >> n;
		cout << "Enter x (x > 0): ";
		cin >> x;
	}

	double sum = 0;

	for (int i = 1; i < n+1; i++) {
		sum += pow(x, i) / (x + pow(3, i));
	}

	cout << "Answer: " << setprecision(3) << sum << '\n';

	wait(3);

}

float func2_equtations(float x) {

	double y;

	if (x < 0)
		y = x * x + 1;
	else if (x >= 0 && x <= 1.4)
		y = cos(0.8f * x * PI);
	else if (x > 1.4f)
		y = x - 2.1f;

	return y;
}

void func2() {

	system("cls");

	int answ;
	cout << "1 - do full cicle\n2 - enter X\n3 - exit\n";
	cin >> answ;

	while (cin.fail() || answ < 1 || answ > 3) {

		cinClear();

		cout << "1 - do full cicle\n2 - enter X\n";
		cin >> answ;

	}

	switch (answ) {
	case 1: {

		float y;
		for (float x = -1; x <= 2; x += 0.2) {
			y = func2_equtations(x);
			cout << "X: " << x << "\tY: " << y << '\n';
		}

		cout << "Wait for any key...\n";
		_getch();

		break;
	}

	case 2: {
		float x;
		cout << "X in range [-1, 2]:\nX: ";
		cin >> x;

		while (cin.fail() || x < -1 || x > 2) {

			cinClear();

			cout << "X in range [-1, 2]:\nX: ";
			cin >> x;
		}

		float y = func2_equtations(x);

		cout << "X: " << x << "\tY: " << y << '\n';

		wait(5);
		break;
	}

	case 3:
		return;

	}

}

float func3_equtations(float x) {

	float y;

	if (x > 0.5f) {
		y = (x * x - 5 * x + 6) / (x * x + 1);
	}
	else if (x <= -0.5f) {
		y = pow(x, 2 / 3) - pow((x * x - 1), 1 / 3) + pow(EULER, 0.2f);
	}
	else {
		y = NAN;
	}

	return y;

}

void func3() {

	system("cls");

	int answ;
	cout << "1 - do full cicle\n2 - enter X\n3 - exit\n";
	cin >> answ;

	while (cin.fail() || answ < 1 || answ > 3) {

		cinClear();

		cout << "1 - do full cicle\n2 - enter X\n";
		cin >> answ;

	}

	switch (answ) {
	case 1: {

		float y;
		for (float x = -1; x <= 2; x += 0.5f) {
			y = func3_equtations(x);

			if (y != NAN)
				cout << "X: " << x << "\tY: " << y << '\n';
		}

		cout << "Wait for any key...\n";
		_getch();

		break;
	}

	case 2: {
		float x;
		cout << "X in range [-2, -0.5] && (0.5, 2]:\nX: ";
		cin >> x;

		while (cin.fail() || x < -2 || x > 2 || x > -0.5f && x <= 0.5f) {

			cinClear();

			cout << "X in range [-2, -0.5] && (0.5, 2]:\nX: ";
			cin >> x;
		}

		float y = func3_equtations(x);

		cout << "X: " << x << "\tY: " << y << '\n';

		wait(5);
		break;
	}

	case 3:
		return;

	}

}

void func4() {

	system("cls");

	int n, x;
	cout << "Enter count of loops: ";
	cin >> n;
	cout << "Enter x (x > 0): ";
	cin >> x;

	while (cin.fail() || x < 0 || n < 0) {

		cinClear();

		cout << "Enter count of loops again: ";
		cin >> n;
		cout << "Enter x: ";
		cin >> x;
	}

	float sum = 0;

	for (int i = 1; i < n+1; i++) {
		float x1 = x - 2 * i;
		float x2 = x - 2 * (i - 1);
		if(x2 != 0)
			sum += x1 / x2;
	}

	cout << "Answer: " << setprecision(3) << sum << '\n';

	wait(3);

}

float func5_equtations(float x, float y) {

	float z;

	if (x > y) {
		z = (x * x) / pow(x - 5, 3);
	}
	else {
		z = pow(x - 2, 3) / (y * pow(x - 5, 4));
	}

	return z;
}

void func5() {
	system("cls");

	int answ;
	cout << "1 - do full cicle\n2 - enter X and Y\n3 - exit\n";
	cin >> answ;

	while (cin.fail() || answ < 1 || answ > 3) {

		cinClear();

		cout << "1 - do full cicle\n2 - enter X and Y\n3 - exit\n";
		cin >> answ;

	}

	switch (answ) {
	case 1: {

		float z, x = 1, y = -4;
		while (x <= 10 && x >= 1 && y >= -4 && y <= 3) {
			z = func5_equtations(x, y);

			cout << "X: " << x << "\tY: " << y << "\tZ: " << z << '\n';
			x += 2;
			y += 1;
		}

		cout << "Wait for any key...\n";
		_getch();

		break;
	}

	case 2: {
		float x, y;
		cout << "X in range [1, 10] and Y in range [-4, 3]:\nX: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;

		while (cin.fail() || x < 1 || x > 10 || y < -4 || y > 3) {

			cinClear();

			cout << "X in range [1, 10] and Y in range [-4, 3]:\nX: ";
			cin >> x;
			cout << "Y: ";
			cin >> y;

		}

		float z = func5_equtations(x, y);

		cout << "X: " << x << "\tY: " << y << "\tZ: " << z << '\n';

		wait(5);
		break;
	}

	case 3:
		return;

	}
}

float func6_equtations(float x) {

	float y;

	if (x < 2) {
		y = pow(2, 3 - x) + 7;
	}else if (x >= 2 && x <= 4) {
		y = pow(3, 7 - x) + 2;
	}
	else {
		y = pow(7, 2 - x) + 3;
	}

	return y;

}

void func6() {

	system("cls");

	int answ;
	cout << "1 - do full cicle\n2 - enter X\n3 - exit\n";
	cin >> answ;

	while (cin.fail() || answ < 1 || answ > 3) {

		cinClear();

		cout << "1 - do full cicle\n2 - enter X\n";
		cin >> answ;

	}

	switch (answ) {
	case 1: {

		float y;
		for (float x = 0; x <= 5; x += 0.31f) {
			y = func6_equtations(x);
			cout << "X: " << x << "\tY: " << y << '\n';

		}

		cout << "Wait for any key...\n";
		_getch();

		break;
	}

	case 2: {
		float x;
		cout << "X in range [0, 5]:\nX: ";
		cin >> x;

		while (cin.fail() || x < 0 || x > 5) {

			cinClear();

			cout << "X in range [0, 5]:\nX: ";
			cin >> x;
		}

		float y = func6_equtations(x);

		cout << "X: " << x << "\tY: " << y << '\n';

		wait(5);
		break;
	}

	case 3:
		return;

	}

}