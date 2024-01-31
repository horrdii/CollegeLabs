#include <iostream>
#include <string>

using namespace std;

struct House {
	string Country, City, Street;
	int HouseNum, FlatCount;
	bool hasInternet;

	House() {};

	House(string Country, string City, string Street, bool hasInternet) {
		this->Country = Country;
		this->City = City;
		this->Street = Street;
		this->hasInternet = hasInternet;

		HouseNum = rand() % 20 + 1;
		FlatCount = rand() % 100 + 100;
	}

};

void printHouse(House h);


int main() {

	House* houses[3] = {
		new House("Kokraina", "Chervonovodovoljsk", "of Saint Mommy", true)	,
		new House("Kraina", "Goromoroforsk", "of Black Liberty", false),
		new House("Bobarina", "Rofosomg", "of White Liberty", true)
	};

	for (House* h : houses) {
		printHouse(*h);
	}

}

void printHouse(House h) {
	
	cout << "Country: " << h.Country
		<< "\nCity: " << h.City
		<< "\nStreet: " << h.Street
		<< "\nHouse number: " << h.HouseNum
		<< "\nFlat count: " << h.FlatCount
		<< "\nHas internet: " << (h.hasInternet ? "Yes" : "No")
		<< endl << endl;

}



//ЕКЗАМЕНАЦІЙНИЙ БІЛЕТ № ____10_____	Король Гордій Олександрович
//Написати програму, в яка містить структуру, що описує 
//об'єкт будинок і складається зі змінних, в яких знаходиться інформація про місто (в якому будинок знаходиться), 
//вулиця, номер будинку, кількість квартир в будинку, наявність інтернету в будинку (проведено чи ні, 
//задати логічною/булевою змінною). Сформувати масив структур (не менше 3 елементів), в якому   
//номер будинку та кількість квартир заповнюється випадковими числами з діапазону від 1 до 20 та від 100 до 200, 
//відповідно, іншим елементам присвоюються значення в програмі. Вивести на консоль дані по важному елементу масиву.
