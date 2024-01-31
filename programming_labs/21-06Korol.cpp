#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

#define PI			3.1415926
#define EULER		2.7182818

using namespace std;


void func1(), func2(), func3(), cinClear();

int main() {

	while (true) {

		system("cls");
		cout << "Group ES-21, Korol, #6\n";

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

	while (cin.fail()) {

		cinClear();

		cout << "Enter count of loops again: ";
		cin >> n;
		cout << "Enter x: ";
		cin >> x;
	}

	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += pow(x, i) / ( x + pow(3, i) );
	}

	cout << "Answer: " << setprecision(3) <<  sum << '\n';

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
		for (float x = -1; x <= 2; x+=0.2f) {
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
	else if (x <= 0.5f) {
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
		for (float x = -1; x <= 2; x+=0.5f) {
			y = func3_equtations(x);

			if( y != NAN )
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