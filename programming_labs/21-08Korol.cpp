#include <iostream>
#include <string>
#include <conio.h>

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

void cinClear() {

	system("cls");

	cin.clear();
	cin.ignore(256, '\n');
	cout << "Check input and try again.\n";

}

void WaitForKey() {
	cout << "Wait for any key...\n";
	_getch();
}

void func1() {

	system("cls");

	string name;
	string names[] = {"Alan", "Heralt", "Orpheus"};
	
	cout << "Enter name: ";
	cin >> name;

	while (cin.fail()) {
		cin.clear();

		cin >> name;
	}

	for (string n : names) {
		if (n == name) {
			cout << "Hello " + name + "!\n";
			WaitForKey();
			return;
		}
	}

	cout << "Leave, noname\n";
	WaitForKey();
		

}

void func2() {

	system("cls");

	string s = "Don’t cut the bough you are sitting on";

	string word = "", shortest = string(' ', s.length()), longest = "", str;
	int shPos = 0, lnPos = 0;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			word += s[i];
			if(i != s.length() - 1)
				continue;
		}
		
		if (word.length() > longest.length()) {
			longest = word;
			lnPos = i + 1 - word.length();
		}
		if (word.length() < shortest.length()) {
			shortest = word;
			shPos = i + 1 - word.length();
		}

			word = "";

	}

	
	cout << "Shortest: " << shortest << " starts on pos " + to_string(shPos) 
			+ "\nLongest: " << longest << " starts on pos " + to_string(lnPos) + '\n';
	WaitForKey();

}

void func3() {

	system("cls");

	string str, returnStr;

	cout << "Enter string: ";
	cin >> str;

	while (cin.fail() && str.length() > 0) {
		cin.clear();

		cin >> str;
	}

	char lastChar = str[0];
	int lastCharCount = 1;

	for (int i = 1; i < str.length() - 1; i++) {

		if (lastChar == str[i]) {
			lastCharCount++;
			continue;
		}

		returnStr += lastCharCount > 1 
			? to_string(lastCharCount) + lastChar 
			: string(1, lastChar);

		lastChar = str[i];
		lastCharCount = 1;

	}

	if (str.length() > 1) {
		if (str[str.length() - 1] == str[str.length() - 2])
			lastCharCount++;

		returnStr += lastCharCount > 1
			? to_string(lastCharCount) + str[str.length() - 1]
			: string(1, str[str.length() - 1]);
	}

	cout << returnStr << '\n';
	WaitForKey();

}