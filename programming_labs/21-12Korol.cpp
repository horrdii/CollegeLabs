#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;


//Питання:
//1.	Функція програмування — фрагмент програмного коду, до якого можна звернутися з іншого місця програми
//2.	Які змінні називаються локальними ? Які можна викликати тільки з 
//3.	Вони пишуться при оголошенні фукнції типом повернення, який записується перед назвою підпрограмми.
//4.	Формальні - ті, що створюються в оголошенні функції. Формальні - ті, що передаються.



struct House
{
	int id;

	string country, city, street, houseNumber;
	int apartmentsCount, floorsCount;
	bool hasInternet;
};

const int housesCount = 3;
House houses[housesCount];

void cinClear(), func1(), func2(), printHouseInfo(House h);


int main() {
	string countries[] = { "Empire of the Romance", "Sweden", "Denmark" };
	string cities[] = { "Hebedu", "Birka", "Caupang" };
	string streets[] = { "of Saint Papich", "Heroiv Dnipra", "of Red Lights" };

	srand(time(NULL));

	for (int i = 0; i < housesCount; i++) {
		houses[i].id = i;

		houses[i].country = countries[rand() % 3];
		houses[i].city = cities[rand() % 3];
		houses[i].street = streets[rand() % 3];
		houses[i].houseNumber = to_string((int)(1 + rand() % 300));

		houses[i].floorsCount = (int)(1 + rand() % 2) == 1
			? 5 : 13;
		houses[i].apartmentsCount = houses[i].floorsCount == 5
			? int(1 + rand() % 20) : int(100 + rand() % 101);

		houses[i].hasInternet = bool(int(rand() % 2));
	}

	while (true) {

		system("cls");
		cout << "Group ES-21, Korol, #11\n";

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



void func1() {

	while (true) {
		system("cls");

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