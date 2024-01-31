#include <iostream>

using namespace std;



// Контрольні питання:
// 1. Енумераторам можна: присвоювати цілочисельні значення; не присвоювати значення; присвоювати значення попередніх енумераторів(наприклад, COLOR_BLUE = COLOR_GRAY).

// 2. Енумератори можуть бути: від’ємними; не унікальними.



void getGrade();

int main() {

	cout << "#1\n";
	cout << "This program is created by Korol Godiy from group SE-21 (software engineering) in 2022\n";

	
	cout << "#2\n";
	int m, h, k;

	cout << "Enter your weight: ";
	cin >> m;
	cout << "\nEnter your height: ";
	cin >> h;

	while (cin.fail()) {

		cin.clear();
		cin.ignore(256, '\n');
		cout << "Check your input and try again.\n";

		cout << "Enter your weight: ";
		cin >> m;
		cout << "\nEnter your height: ";
		cin >> h;

	}

	k = m / h;
	if (k < 27)
		cout << "Okay\n";
	else if (k > 27 && k <= 30)
		cout << "You've got obesity\n";
	else
		cout << "You need to see a doctor\n";


	cout << "#3\n";
	getGrade();


	cout << "#4\n";
	int a, b, c;
	cout << "ax^2 + bx + c = 0\n";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	while (cin.fail()) {

		cin.clear();
		cin.ignore(256, '\n');

		cout << "Check your input and try again.\n";

		int a, b, c;
		cout << "ax^2 + bx + c = 0\n";
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		cout << "c: ";
		cin >> c;
	}

	cout << '\n';

	int d = b * b - 4 * a * c;
	if (d > 0)
		cout << "the equation has two roots\n";
	else if (d == 0)
		cout << "the equation has one root\n";
	else if (d < 0)
		cout << "the equtation has zero roots\n";

	//Квадратні рівняння мают максимум 2 розв'язки. Хіхіхі.

	
	return 0;
}


void getGrade() {
	
	cout << "Enter your grade: ";
	int grade;
	cin >> grade;
	
	while (cin.fail()) {

		cin.clear();
		cin.ignore(256, '\n');

		cout << "Check your input and try again.\n";
		cout << "Enter your grade: ";
		cin >> grade;
	}

	switch (grade) {
	case 1:
		cout << "Bad";
		break;
	case 2:
		cout << "Bad";
		break;
	case 3:
		cout << "Bad";
		break;
	case 4:
		cout << "not bad";
		break;
	case 5:
		cout << "not bad";
		break;
	case 6:
		cout << "not bad";
		break;
	case 7:
		cout << "good";
		break;
	case 8:
		cout << "good";
		break;
	case 9:
		cout << "good";
		break;
	case 10:
		cout << "very good";
		break;
	case 11:
		cout << "very good";
		break;
	case 12:
		cout << "very good";
		break;

	default:
		cout << "error. check your input and try again. \n";
		getGrade();
		break;

	}

	cout << '\n';

}