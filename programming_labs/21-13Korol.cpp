#include <iostream>
#include <conio.h>
#include <random>
#include <chrono>
#include <ctime>
#include <fstream>


using namespace std;

#pragma warning(disable : 4996)

//For time
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


enum SortType
{
	bubble = 1,
	insertion = 2,
};

void cinClear(), waitForKey(), Sort(SortType sortType);

int main() {

	while (true) {

		system("cls");
		cout << "Gordey Korol ES-21\n";
		cout << "1 - Bubble sort\n2 - Insertion sort\n0 - Exit\n";
		
		int answ;
		cin >> answ;

		while (cin.fail()) {
			cin.clear();

			cout << "Gordey Korol ES-21\n";
			cout << "1 - Bubble sort\n2 - Paste sort\n0 - Exit\n";
			cin >> answ;

		}

		switch (answ) {
		case 1:
			Sort(SortType::bubble);
			break;
		case 2:
			Sort(SortType::insertion);
			break;
		
		case 0:
			return 0;
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


int** createMassives() {

	int* m1 = new int[100];
	int* m2 = new int[1000];
	int* m3 = new int[10000];

	for (int i = 0; i < 100; i++) {
		m1[i] = rand() % 100000;
		m2[i] = rand() % 100000;
		m3[i] = rand() % 100000;
	}
	for (int i = 100; i < 1000; i++) {
		m2[i] = rand() % 100000;
		m3[i] = rand() % 100000;
	}
	for (int i = 1000; i < 10000; i++) {
		m3[i] = rand() % 100000;
	}

	int** returnMassive = new int*[3] {m1, m2, m3};

	return returnMassive;

}


void BubbleSort(int* m, int massiveSize),
		InsertionSort(int* m, int massiveSize);

void Sort(SortType sortType) {
	int* m1 = new int[100];
	int* m2 = new int[1000];
	int* m3 = new int[10000];

	int** massives = createMassives();

	m1 = massives[0];
	m2 = massives[1];
	m3 = massives[2];

	delete massives;

	//Time of start sorting
	auto t1 = high_resolution_clock::now();
	//Temp time
	auto t2 = high_resolution_clock::now();

	switch (sortType) {
	case SortType::bubble: {

		ofstream file("13_bubble.txt");
		if (file.is_open()) {
			time_t start_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
			file << ctime(&start_time) << endl;
		}
		else
			break;

		BubbleSort(m1, 100);
		t2 = high_resolution_clock::now();
		auto ms = duration_cast<milliseconds>(t2 - t1);
		cout << "Time passed (ms): " << ms.count() << '\n';
		t1 = t2;

		BubbleSort(m2, 1000);
		t2 = high_resolution_clock::now();
		ms = duration_cast<milliseconds>(t2 - t1);
		cout << "Time passed (ms): " << ms.count() << '\n';
		t1 = t2;

		BubbleSort(m3, 10000);
		t2 = high_resolution_clock::now();
		ms = duration_cast<milliseconds>(t2 - t1);
		cout << "Time passed (ms): " << ms.count() << '\n';
		t1 = t2;

		waitForKey();
		break;
	}
	case SortType::insertion: {

		ofstream file("13_insertion.txt");
		if (file.is_open()) {
			time_t start_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
			file << ctime(&start_time) << endl;
			file.close();
		}
		else
			break;

		InsertionSort(m1, 100);
		t2 = high_resolution_clock::now();
		auto ms = duration_cast<milliseconds>(t2 - t1);
		cout << "Time passed (ms): " << ms.count() << '\n';
		t1 = t2;

		InsertionSort(m2, 1000);
		t2 = high_resolution_clock::now();
		ms = duration_cast<milliseconds>(t2 - t1);
		cout << "Time passed (ms): " << ms.count() << '\n';
		t1 = t2;

		InsertionSort(m3, 10000);
		t2 = high_resolution_clock::now();
		ms = duration_cast<milliseconds>(t2 - t1);
		cout << "Time passed (ms): " << ms.count() << '\n';
		t1 = t2;

		waitForKey();
		break;
	}
	}

	delete m1, m2, m3;

}

void BubbleSort(int* m, int massiveSize) {

	int temp, compareCount = 0, exchangeCount = 0;
	ofstream file ("13_bubble.txt", ios_base::app);

	for (int i = 0; i < massiveSize; i++) {
		cout << m[i] << ' ';
		file << m[i] << ' ';
	}
	cout << '\n';
	file << endl << endl;

	for (int i = 0; i < massiveSize; i++) {
		for (int j = i + 1; j < massiveSize; j++)
		{
			if (m[j] < m[i]) {
				temp = m[i];
				m[i] = m[j];
				m[j] = temp;
				exchangeCount++;
			}
			compareCount++;
		}
	}

	cout << '\n\n';
	for (int i = 0; i < massiveSize; i++) {
		cout << m[i] << ' ';
		file << m[i] << ' ';
	}
	cout << "\n";
	file << endl;

	file << "Cound of passes: " << compareCount << "\tCount of exchanges: " << exchangeCount << endl << endl;

	cout << "Count of passes: " << compareCount << '\n';
	cout << "Count of exchanges: " << exchangeCount << '\n';

	file.close();
}

void InsertionSort(int* m, int massiveSize) {

	int compareCount = 0, exchangeCount = 0;
	int j, key;
	ofstream file("13_insertion.txt", ios_base::app);

	for (int i = 0; i < massiveSize; i++) {
		cout << m[i] << ' ';
		file << m[i] << ' ';
	}
	cout << '\n';
	file << endl << endl;

	for (int i = 1; i < massiveSize; i++)
	{
		key = m[i];
		j = i - 1;

		compareCount++;
		while (j >= 0 && m[j] > key)
		{
			m[j + 1] = m[j];
			j = j - 1;
			exchangeCount++;
			compareCount++;
		}
		m[j + 1] = key;
	}

	cout << '\n\n';
	for (int i = 0; i < massiveSize; i++) {
		cout << m[i] << ' ';
		file << m[i] << ' ';
	}
	cout << '\n';
	file << endl;

	file << "Cound of passes: " << compareCount << "\tCount of exchanges: " << exchangeCount << endl << endl;

	cout << "Count of passes: " << compareCount << '\n';
	cout << "Count of exchanges: " << exchangeCount << '\n';

}