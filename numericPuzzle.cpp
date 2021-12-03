#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

bool checkTable(int table[], int size)
{

    if (table[0] > table[1] && table[1] > table[2] && table[2] > table[3] && table[3] > table[4] && table[4] > table[5] && table[5] > table[6] && table[6] > table[7] && table[7] > table[8])
    {

        return true;
    }

    return false;
}

// announce_result
void announceResult(bool res)
{
    cout << "the resutl is:" << res << endl;
    if (res)
    {
        cout << "Congratulations You have won the match!!!" << endl;
    }
    else
    {
        cout << "You lost!!!" << endl;
    }
}

void drawTable(int table[])
{
    cout << table[0] << "\t" << table[1] << "\t" << table[2] << endl;
    cout << table[3] << "\t" << table[4] << "\t" << table[5] << endl;
    cout << table[6] << "\t" << table[7] << "\t" << table[8] << endl;
}

struct _input
{
    int num1;
    int num2;
    int list[9];
} userInput;

// ask input
_input askInput()
{

    cout << "Please Enter First Number:\n";
    cin >> userInput.num1;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "Please Enter Second Number:\n";
    cin >> userInput.num2;

    return userInput;
}

// swap
void swap(_input choice, int table[])
{
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < 9; i++)
    {
        if (table[i] == choice.num1)
        {
            index1 = i;
        }
        else if (table[i] == choice.num2)
        {
            index2 = i;
        }
    }
    table[index1] = choice.num2;
    table[index2] = choice.num1;
}

bool isUnique(int list[], int randomNumber)
{

    for (int i = 0; i < 9; i++)
    {
        if (list[i] == randomNumber)
        {
            return false;
        }
    }

    return true;
}

_input setTable()
{
    _input randomInput;

    for (int i = 0; i < 9; i++)
    {
        int random = 1 + (rand() % 100);
        if (isUnique(randomInput.list, random))
        {
            randomInput.list[i] = random;
        }
        else
        {
            i -= 1;
        }
    }
    return randomInput;
}
int main()
{
    int size = 9;
    _input table = setTable();
    int counter = 0;
    bool sorted = false;
    while (!sorted)
    {
        drawTable(table.list);
        _input userEnteredInput = askInput();
        swap(userEnteredInput, table.list);
        bool result = checkTable(table.list, size);
        if (result)
        {
            announceResult(result);
            sorted = true;
        }
        counter++;
    }

    return 0;
}