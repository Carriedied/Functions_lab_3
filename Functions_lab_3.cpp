#include <iostream>
#include <vector>

using namespace std;

bool IsPrime(int n);
void PrintPrimesInRange(int a, int b);
void PrintFriendlyPrimes(int a, int b);

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b;

    cout << "Введите диапазон [a, b]: ";

    cin >> a >> b;

    if (a > b)
    {
        cout << "Помойму вы что-то перепутали";

        return 0;
    }

    PrintPrimesInRange(a, b);
    PrintFriendlyPrimes(a, b);

    return 0;
}

bool IsPrime(int n) 
{
    if (n <= 1) 
        return false;

    if (n <= 3) 
        return true;

    if (n % 2 == 0 || n % 3 == 0) 
        return false;

    for (int i = 5; i * i <= n; i += 6) 
    {
        if (n % i == 0 || n % (i + 2) == 0) 
        {
            return false;
        }
    }
    return true;
}

void PrintPrimesInRange(int a, int b) 
{
    cout << "Простые числа в диапазоне [" << a << ", " << b << "]:\n";

    for (int i = a; i <= b; ++i) 
    {
        if (IsPrime(i)) 
        {
            std::cout << i << " ";
        }
    }
    std::cout << "\n\n";
}

void PrintFriendlyPrimes(int a, int b) 
{
    cout << "Дружественные числа в диапазоне [" << a << ", " << b << "]:\n";

    for (int i = a; i <= b - 2; ++i) 
    {
        if (IsPrime(i) && IsPrime(i + 2)) 
        {
            cout << "(" << i << ", " << i + 2 << ")\n";
        }
    }

    cout << "\n";
}
