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



//��������ֲ���� ����� � ____10_____	������ ����� �������������
//�������� ��������, � ��� ������ ���������, �� ����� 
//��'��� ������� � ���������� � ������, � ���� ����������� ���������� ��� ���� (� ����� ������� �����������), 
//������, ����� �������, ������� ������� � �������, �������� ��������� � ������� (��������� �� �, 
//������ �������/������� ������). ���������� ����� �������� (�� ����� 3 ��������), � �����   
//����� ������� �� ������� ������� ������������ ����������� ������� � �������� �� 1 �� 20 �� �� 100 �� 200, 
//��������, ����� ��������� ������������ �������� � �������. ������� �� ������� ��� �� ������� �������� ������.
