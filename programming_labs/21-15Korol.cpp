#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

void func1(), func2(), func3(), func4(), func5(), cinClear(), waitForKey();
int countOfFilesInFolder();

struct House
{
	int id;

	string country, city, street, houseNumber;
	int apartmentsCount, floorsCount;
	bool hasInternet;
};

int housesCount;

int main() {

	housesCount = countOfFilesInFolder();

	while (true) {

		system("cls");
		cout << "Group ES-21, Korol, #15\n";

		int n;
		cout << "1 - Read files data\n2 - Enter new / Change data\n3 - Print requested number of objects" << 
			"\n4 - Display the number of houses without the internet\n" << 
			"5 - Display a list of buildings without the internet\n" <<
			"0 - Exit\n";
		cout << "Choose task: ";
		cin >> n;

		while (cin.fail()) {

			cinClear();

			cout << "1 - Read files data\n2 - Enter new / Change data\n3 - Print requested number of objects" <<
				"\n4 - Display the number of houses without the internet\n" <<
				"5 - Display a list of buildings without the internet\n" <<
				"0 - Exit\n";
			cout << "Choose task: ";
			cin >> n;

		}

		switch (n) {
		case 1:
			system("cls");
			func1();
			waitForKey();
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

		case 0:
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

int countOfFilesInFolder() {
	
	int i = 0;
	fstream f;
	while (true) {
		f.open("Houses/" + to_string(i) + ".txt");
		if (!f.is_open())
			break;
		f.close();
		i++;
	}
	
	return i;
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

void houseToFile(House h) {

	ofstream file("Houses/" + to_string(h.id) + ".txt", fstream::trunc);

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

void func1() {
	ifstream file;
	int id = 0;

	while(true) {
		file.open("Houses/" + to_string(id) + ".txt");
		if (!file.is_open()) {
			break;
		}

		printHouseInfo(fileToHouse(file));
		cout << '\n';

		file.close();
		id++;
	}

}

void func2() {

	system("cls");

	ifstream file;
	House h;

	for (int i = 0; i < housesCount; i++) {
		file.open("Houses/" + to_string(i) + ".txt");
		if (!file.is_open())
			break;
		h = fileToHouse(file);

		cout << to_string(i + 1) << "\t" << h.country << ", " << h.city << ", st. "
			<< h.street << ", " << h.houseNumber << "\t "
			<< (h.hasInternet ? "Internet+" : "Internet-")
			<< '\n';

		file.close();
	}

	cout << to_string(housesCount + 1) << "\t New house...\n";
	cout << "0\tExit\n";

	int answ;
	cout << "Choose task: ";
	cin >> answ;

	if (answ == 0) {
		return;
	}
	else if (answ <= housesCount) {
		
		House h;
		h.id = answ - 1;

		cout << "Country: ";
		cin >> h.country;

		cout << "City: ";
		cin >> h.city;

		cout << "Street: ";
		cin >> h.street;

		cout << "House number: ";
		cin >> h.houseNumber;

		cout << "Count of floors: ";
		cin >> h.floorsCount;

		cout << "Count of apartments: ";
		cin >> h.apartmentsCount;

		cout << "Has internet? (t/f): ";
		char internet;
		cin >> internet;
		h.hasInternet = internet == 't' ? true : false;

		houseToFile(h);

	}
	else if (answ == housesCount + 1) {
		House newHouse;

		newHouse.id = housesCount++;

		cout << "Country: ";
		cin >> newHouse.country;

		cout << "City: ";
		cin >> newHouse.city;

		cout << "Street: ";
		cin >> newHouse.street;

		cout << "House number: ";
		cin >> newHouse.houseNumber;

		cout << "Count of floors: ";
		cin >> newHouse.floorsCount;

		cout << "Count of apartments: ";
		cin >> newHouse.apartmentsCount;

		cout << "Has internet? (t/f): ";
		char internet;
		cin >> internet;
		newHouse.hasInternet = internet == 't' ? true : false;

		houseToFile(h);
		
	}
	else {
		return;
	}

	system("cls");
	func1();
	waitForKey();

}

void func3() {
	system("cls");
	cout << "How much houses do you want to print? (max " + to_string(housesCount) + ")\n";
	
	int answ;
	cin >> answ;

	if (cin.fail())
	{
		cinClear();
		cout << "How much houses do you want to print? (max " + to_string(housesCount) + ")\n";
		cin >> answ;
	}

	ifstream file;
	House h;

	for (int i = 0; i < (answ > housesCount ? housesCount : answ); i++) {
		file.open("Houses/" + to_string(i) + ".txt");
		if (!file.is_open())
			break;
		h = fileToHouse(file);

		cout << to_string(i + 1) << "\t" << h.country << ", " << h.city << ", st. "
			<< h.street << ", " << h.houseNumber << "\t " 
			<< (h.hasInternet ? "Internet+" : "Internet-")
			<< '\n';

		file.close();
	}

	waitForKey();

}

void func4() {

	ifstream file;
	House h;
	int noInternetHousesCount = 0;

	for (int i = 0; i < housesCount; i++) {
		file.open("Houses/" + to_string(i) + ".txt");
		if (!file.is_open())
			break;
		h = fileToHouse(file);
		if (!h.hasInternet)
			noInternetHousesCount++;
		file.close();
	}

	cout << "Number of house without the internet " << noInternetHousesCount << '\n';
	waitForKey();

}

void func5() {
	ifstream file;
	House h;
	int internetHousesCount = 0;

	for (int i = 0; i < housesCount; i++) {
		file.open("Houses/" + to_string(i) + ".txt");
		if (!file.is_open())
			break;
		h = fileToHouse(file);
		if (h.hasInternet)
			internetHousesCount++;
		file.close();
	}

	cout << "Number of house without the internet " << internetHousesCount << '\n';
	waitForKey();
}