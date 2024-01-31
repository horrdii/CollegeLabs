#include <iostream>
#include <cmath>
std::stringstream stream;

using namespace std;

#define MAX 100

void sortStrings(char arr[][MAX], int n)
{
	char temp[MAX];

	// Sorting strings using bubble sort
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{
				strcpy_s(temp, arr[j]);
				strcpy_s(arr[j], arr[j + 1]);
				strcpy_s(arr[j + 1], temp);
			}
		}
	}
}

int main()
{
	int x, y, a, b, c;

	for (float x = 0; x <= 5; x+=0.31) {
		if (x < 2) {
			y = pow(a, b - x) + c;
			cout << setprecision(3) << endl;
		}
	}
	if (x < 2) {
		
	}
}

