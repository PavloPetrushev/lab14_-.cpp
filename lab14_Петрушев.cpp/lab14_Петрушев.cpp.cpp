// lab14_Петрушев.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

bool isPrime(int number) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

void fillPrimes(int primes[], int size) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count = 0;
    int number = 2; 

    while (count < size) {
        if (isPrime(number)) {
            primes[count] = number;
            count++;
        }
        number++;
    }
}

int interpolationSearch(int arr[], int size, int x) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int low = 0;
    int high = size - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            low = pos + 1;
        
        else
            high = pos - 1;
    }
    return -1; 
}

int main() {
    const int size = 15;
    int primes[size];

    fillPrimes(primes, size);

    std::cout << "Прості числа: ";
    for (int i = 0; i < size; i++) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;

    int x;
    std::cout << "Введіть число для пошуку: ";
    std::cin >> x;

    int result = interpolationSearch(primes, size, x);

    if (result != -1) {
        std::cout << "Число " << x << " знайдено на позиції " << result << "." << std::endl;
    }
    else {
        std::cout << "Число " << x << " не знайдено." << std::endl;
    }

    return 0;
}