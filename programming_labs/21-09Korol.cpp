#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


//Питання:
// Покажчик це тип даних, який вказує на ячейку в пам'яті комп'ютера з якимось значенням
// Масив з рваними краями, це символьний масив який створюється із покажчиків і може мати різну довжину рядків
// char* sur[countOfElements]

void main()
{

    cout << "Group ES-21, Korol, #9\n\n";


    const int surnamesCount = 12, surnameLength = 20;
    char sur[surnamesCount][surnameLength];
    const char* surPtrs[surnamesCount];
    const char* ptr = new char();

    cout << "Input surnames (surname length < " + to_string(surnameLength) + "): \n";

    try {
        for (int i = 0; i < surnamesCount; i++)
        {

            gets_s(sur[i], surnameLength);
            surPtrs[i] = sur[i];
        }
    }
    catch (...) {
        system("cls");
        cout << "\nCheck your input and try again: \n";

        cout << "Input surnames (surname length < " + to_string(surnameLength) + "): \n";
        for (int i = 0; i < surnamesCount; i++)
        {

            gets_s(sur[i], 20);
            surPtrs[i] = sur[i];
        }
    }

    

    cout << "\nNon sort list:\n";
    for (int i = 0; i < surnamesCount; i++)
        cout << surPtrs[i] << '\n';



    for (int k = 1; k < surnamesCount; k++)
        for (int i = 0; i < surnamesCount - k; i++)
            if (strcmp(surPtrs[i], surPtrs[i + 1]) > 0)
            {
                ptr = surPtrs[i];
                surPtrs[i] = surPtrs[i + 1];
                surPtrs[i + 1] = ptr;
            }

    cout << "\n Sorted by alphaber: \n";
    for (int i = 0; i < surnamesCount; i++)
        cout << surPtrs[i] << '\n';



    for (int k = 1; k < surnamesCount; k++)
        for (int i = 0; i < surnamesCount - k; i++)
            if (strlen(surPtrs[i]) > strlen(surPtrs[i+1]))
            {
                ptr = surPtrs[i];
                surPtrs[i] = surPtrs[i + 1];
                surPtrs[i + 1] = ptr;
            }

    cout << "\n Sorted by characters count: \n";
    for (int i = 0; i < surnamesCount; i++)
        cout << surPtrs[i] << "\t len: " << to_string(strlen(surPtrs[i])) << '\n';


    _getch();

}
