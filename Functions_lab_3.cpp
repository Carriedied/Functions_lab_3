#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

bool IsPrime(int num) 
{
    if (num <= 1) 
        return false;

    if (num == 2) 
        return true;

    if (num % 2 == 0) 
        return false;

    for (int i = 3; i * i <= num; i += 2) 
    {
        if (num % i == 0) 
            return false;
    }

    return true;
}

void PrintPrimesRange(int a, int b) 
{
    cout << "Простые числа в диапазоне [" << a << ", " << b << "]: ";

    for (int i = a; i <= b; ++i) 
    {
        if (IsPrime(i)) 
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

void FindTwinPrimes(int a, int b) 
{
    cout << "Дружественные числа (пары простых, отличающихся на 2) в диапазоне [" << a << ", " << b << "]: ";

    bool found = false;

    for (int i = a; i <= b - 2; ++i) 
    {
        if (IsPrime(i) && IsPrime(i + 2)) 
        {
            cout << "(" << i << ", " << i + 2 << ") ";

            found = true;
        }
    }

    if (!found) 
    {
        cout << "не найдены.";
    }

    cout << endl;
}

void Run1Task() 
{
    int a, b;

    cout << "Введите диапазон [a, b]: ";
    cin >> a >> b;

    PrintPrimesRange(a, b);
    FindTwinPrimes(a, b);
}

long long Factorial(int n) 
{
    if (n < 0) 
        return -1;

    long long result = 1;

    for (int i = 2; i <= n; ++i) 
    {
        result *= i;
    }

    return result;
}

long long SumFactorialsEven(int m, int n) 
{
    long long sum = 0;

    for (int i = m; i <= n; ++i) 
    {
        if (i % 2 == 0) 
        {
            sum += Factorial(i);
        }
    }

    return sum;
}

void Run2Task() 
{
    int m, n;

    cout << "Введите m и n: ";
    cin >> m >> n;

    if (m > n) 
    {
        cout << "Ошибка: m должно быть не больше n." << endl;
    }
    else 
    {
        long long result = SumFactorialsEven(m, n);

        cout << "Сумма факториалов четных чисел от " << m << " до " << n << ": " << result << endl;
    }
}

int DigitSum(int num) 
{
    int sum = 0;

    num = abs(num);

    while (num > 0) 
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void FindMinMaxDigitSum() 
{
    int n;

    cout << "Введите количество чисел: ";
    cin >> n;

    if (n <= 0) 
    {
        cout << "Некорректное количество чисел." << endl;

        return;
    }

    vector<int> numbers(n);
    vector<int> sums(n);

    for (int i = 0; i < n; ++i) 
    {
        cout << "Введите число " << i + 1 << ": ";
        cin >> numbers[i];

        sums[i] = DigitSum(numbers[i]);
    }

    int min_sum = sums[0], max_sum = sums[0];
    int min_idx = 0, max_idx = 0;

    for (int i = 1; i < n; ++i) 
    {
        if (sums[i] < min_sum) 
        {
            min_sum = sums[i];
            min_idx = i;
        }

        if (sums[i] > max_sum) 
        {
            max_sum = sums[i];
            max_idx = i;
        }
    }

    cout << "Число с наименьшей суммой цифр (" << min_sum << "): " << numbers[min_idx] << endl;
    cout << "Число с наибольшей суммой цифр (" << max_sum << "): " << numbers[max_idx] << endl;
}

void Run3Task() 
{
    FindMinMaxDigitSum();
}

double CircleArea(double r) 
{
    return M_PI * r * r;
}

double RectangleArea(double a, double b) 
{
    return a * b;
}

double RightTriangleArea(double a, double b) 
{
    return 0.5 * a * b;
}

void PrintMenu() 
{
    cout << "1. Площадь круга" << endl;
    cout << "2. Площадь прямоугольника" << endl;
    cout << "3. Площадь прямоугольного треугольника" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите фигуру: ";
}

void CalculateAreas() 
{
    int choice;
    double a, b, r, result;
    bool running = true;

    while (running) 
    {
        PrintMenu();

        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Введите радиус круга: ";
                cin >> r;

                if (r < 0) 
                {
                    cout << "Радиус не может быть отрицательным." << endl;
                }
                else 
                {
                    result = CircleArea(r);

                    cout << fixed << setprecision(6);
                    cout << "Площадь круга: " << result << endl;
                }
                break;
            case 2:
                cout << "Введите длину прямоугольника: ";
                cin >> a;

                cout << "Введите ширину прямоугольника: ";
                cin >> b;

                if (a < 0 || b < 0) 
                {
                    cout << "Длина и ширина не могут быть отрицательными." << endl;
                }
                else 
                {
                    result = RectangleArea(a, b);

                    cout << fixed << setprecision(6);
                    cout << "Площадь прямоугольника: " << result << endl;
                }
                break;
            case 3:
                cout << "Введите длину первого катета: ";
                cin >> a;

                cout << "Введите длину второго катета: ";
                cin >> b;

                if (a < 0 || b < 0) 
                {
                    cout << "Катеты не могут быть отрицательными." << endl;
                }
                else 
                {
                    result = RightTriangleArea(a, b);

                    cout << fixed << setprecision(6);
                    cout << "Площадь прямоугольного треугольника: " << result << endl;
                }
                break;
            case 0:
                cout << "Завершение работы программы." << endl;

                running = false;
                break;
            default:
                cout << "Некорректный выбор. Пожалуйста, введите 0, 1, 2 или 3." << endl;
        }
    }
}

void Run4Task() 
{
    CalculateAreas();
}


int main() 
{
    setlocale(LC_ALL, "Russian");

    int task_choice;

    cout << "Выберите задачу: ";
    cin >> task_choice;

    switch (task_choice) 
    {
        case 1:
            Run1Task();
            break;
        case 2:
            Run2Task();
            break;
        case 3:
            Run3Task();
            break;
        case 4:
            Run4Task();
            break;
        default:
            cout << "Некорректный выбор задачи." << endl;
    }

    return 0;
}