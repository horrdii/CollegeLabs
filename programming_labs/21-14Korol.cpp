#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;


//Питання:
//1. Види потоків: fstream, ifstream, ofstream
//2. Для потоків ввода, вивода та помилок
//3. Iostream



struct House
{
	int id;

	string country, city, street, houseNumber;
	int apartmentsCount, floorsCount;
	bool hasInternet;
};

const int housesCount = 3;

void cinClear(), func1(), func2(), printHouseInfo(House h);


int main() {

	ofstream file;

	string countries[] = { "Empire of the Romance", "Sweden", "Denmark" };
	string cities[] = { "Hebedu", "Birka", "Caupang" };
	string streets[] = { "of Saint Papich", "Heroiv Dnipra", "of Red Lights" };

	srand(time(NULL));

	for (int i = 0; i < housesCount; i++) {
		
		House h;

		h.id = i;

		h.country = countries[rand() % 3];
		h.city = cities[rand() % 3];
		h.street = streets[rand() % 3];
		h.houseNumber = to_string((int)(1 + rand() % 300));

		h.floorsCount = (int)(1 + rand() % 2) == 1
			? 5 : 13;
		h.apartmentsCount = h.floorsCount == 5
			? int(1 + rand() % 20) : int(100 + rand() % 101);

		h.hasInternet = bool(int(rand() % 2));

		file.open("Houses/" + to_string(h.id) + ".txt", fstream::trunc);
		if (!file.is_open()) {
			cout << "Error while open file\n";
			return -1;
		}

		file << h.id << '\n'
			<< h.country << '\n'
			<< h.city << '\n'
			<< h.street << '\n'
			<< h.houseNumber << '\n'
			<< h.floorsCount << '\n'
			<< h.apartmentsCount << '\n'
			<< (h.hasInternet ? 't' : 'f') << endl << endl;

		file.close();
	}

	while (true) {

		system("cls");
		cout << "Group ES-21, Korol, #14\n";

		int n;
		cout << "1 - Get information about houses\n2 - Filter houses by internet\n0 - Exit\n";
		cout << "Choose task: ";
		cin >> n;

		while (cin.fail()) {

			cinClear();

			cout << "1 - Get information about houses\n2 - Filter houses by internet\n0 - Exit\n";
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
		case 0:
			return 0;
			break;

		default:
			continue;
		}

	}

	file.close();

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

void printHouseInfo(House h) {
	cout << "Id: " << h.id << '\n';
	cout << "Address: \n"
		<< "\tCountry: " << h.country << '\n'
		<< "\tCity: " << h.city << '\n'
		<< "\tStreet: " << h.street << '\n'
		<< "\tHouse number: " << h.houseNumber << '\n';

	cout << "Floors: " << h.floorsCount << '\n';
	cout << "Apartments count: " << h.apartmentsCount << '\n';
	cout << "Has internet: " << (h.hasInternet ? '+' : '-') << '\n';
}

House fileToHouse(ifstream& file) {
	
	string line;
	House h;

	getline(file, line);
	h.id = stoi(line);
	getline(file, line);
	h.country = line;
	getline(file, line);
	h.city = line;
	getline(file, line);
	h.street = line;
	getline(file, line);
	h.houseNumber = line;
	getline(file, line);
	h.floorsCount = stoi(line);
	getline(file, line);
	h.apartmentsCount = stoi(line);
	getline(file, line);
	h.hasInternet = line == "t" ? true : false;

	return h;
}


void func1() {

	while (true) {
		system("cls");

		ifstream file;
		House emptyH;
		House houses[housesCount];

		for (int i = 0; i < housesCount; i++) {
			file.open("Houses/" + to_string(i) + ".txt");
			if (!file.is_open()) {
				cout << "Error while opening file\n";
				houses[i] = emptyH;
				continue;
			}
			houses[i] = fileToHouse(file);
			file.close();
		}

		for (House h : houses) {
			cout << (h.id + 1) << "\t" << h.country << ", " << h.city
				<< ", st. " << h.street << " #" << h.houseNumber << '\n';
		}
		cout << "0\tExit\n";

		int n;

		cout << "Choose house: ";
		cin >> n;

		while (cin.fail() || n > housesCount) {
			cinClear();
			cout << "Choose house: ";
			cin >> n;
		}

		system("cls");
		if (n == 0)
			return;

		printHouseInfo(houses[n - 1]);
		waitForKey();
	}
}

void func2() {

	while (true) {
		system("cls");

		ifstream file;
		House emptyH;
		House houses[housesCount];

		for (int i = 0; i < housesCount; i++) {
			file.open("Houses/" + to_string(i) + ".txt");
			if (!file.is_open()) {
				cout << "Error while opening file\n";
				houses[i] = emptyH;
				continue;
			}
			houses[i] = fileToHouse(file);
			file.close();
		}

		int iCount = 0, noICount = 0;

		cout << "With internet:\n";
		for (House h : houses) {
			if (h.hasInternet) {
				cout << (h.id + 1) << "\t" << h.country << ", " << h.city
					<< ", st. " << h.street << " #" << h.houseNumber << '\n';
				iCount++;
			}
		}
		cout << "\nWithout internet:\n";
		for (House h : houses) {
			if (!h.hasInternet) {
				cout << (h.id + 1) << "\t" << h.country << ", " << h.city
					<< ", st. " << h.street << " #" << h.houseNumber << '\n';
				noICount++;
			}
		}
		cout << "\n0\tExit\n\n";
		cout << "With internet " << iCount << ", without " << noICount << '\n';
		int n;

		cout << "Choose house: ";
		cin >> n;

		while (cin.fail() || n > housesCount) {
			cinClear();
			cout << "Choose house: ";
			cin >> n;
		}

		system("cls");
		if (n == 0)
			return;

		printHouseInfo(houses[n - 1]);
		waitForKey();
	}

}