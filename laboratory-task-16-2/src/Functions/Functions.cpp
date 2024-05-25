#include "Functions.hpp"

/*================================================================================*/
/*================================= Ввод вектора =================================*/
/*================================================================================*/

bool checkString(std::string input) 
{
    for (char c : input) {
        if (!std::isdigit(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

void inputVector(std::vector<int>& in)
{
    std::string input;
    int number; 

    std::cout << "\nВведите числа:\t\t\t";
    std::getline(std::cin, input);

    if (!checkString(input)) {
        throw std::invalid_argument("Ошибка: в строке содержаться нечисловые символы");
    }

    std::string word;
    for (char c : input) {
        if (std::isdigit(c)) 
        {
            word += c;
        }
        else if (!word.empty()) {
            number = std::stoi(word);
            in.push_back(number);
            word = "";
        }
    }
    if (!word.empty()) {
        number = std::stoi(word);
        in.push_back(number);
    }

}

/*================================================================================*/
/*================================= Вывод вектора ================================*/
/*================================================================================*/

void printVector(const std::vector<int>& out)
{
    auto iterator = out.begin();
    std::cout << "Вектор чисел:\t\t";
    while (iterator != out.end()) {
        std::cout << *iterator << ' ';
        ++iterator;
    }
    std::cout << '\n';
}
/*================================================================================*/
/*============================ 1) Сумма чисел вектора ============================*/
/*================================================================================*/

int sumVector(const std::vector<int>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}

/*================================================================================*/
/*========================== 2) Количество чисел вектора =========================*/
/*================================================================================*/

size_t amountOfNumbers(const std::vector<int>& vec)
{
    return vec.size();
}

/*================================================================================*/
/*=== Сравнение и подсчет чисел вектора с заданным числом(через лямбда-функцию) ==*/
/*================================================================================*/

size_t operator< (int n, const std::vector<int>& vec) {
    return std::count_if(vec.begin(), vec.end(), [n](int x) { return x < n; });
}

size_t operator> (int n, const std::vector<int>& vec) {
    return std::count_if(vec.begin(), vec.end(), [n](int x) { return x > n; });
}

size_t operator==(int n, const std::vector<int>& vec) {
    return std::count(vec.begin(), vec.end(), n);
}

size_t operator!=(int n, const std::vector<int>& vec) {
    return amountOfNumbers(vec) - std::count_if(vec.begin(), vec.end(), [n](int x) {return x == n; });
}

size_t operator<= (int n, const std::vector<int>& vec) {
    return std::count_if(vec.begin(), vec.end(), [n](int x) { return x <= n; });
}

size_t operator>= (int n, const std::vector<int>& vec) {
    return std::count_if(vec.begin(), vec.end(), [n](int x) { return x >= n; });
}

/*================================================================================*/
/*=================== Заменa всех нулей средним арифметическим ===================*/
/*================================================================================*/

void averageArithmeticalWithoutZero(std::vector<int>& vec)
{
    int average = static_cast<int>(sumVector(vec) / amountOfNumbers(vec));
    std::cout << "\nСреднее арифметическое целой части вектора:\t" << sumVector(vec) << '/' << amountOfNumbers(vec) << '=' << average << std::endl;
    auto iterator = vec.begin();
    while (iterator != vec.end()) {
        if (*iterator > 0) {
            break;
        }
        if (*iterator == 0) {
            *iterator = average;
        }
        ++iterator;
    }
    printVector(vec);
}

/*====================================================================================================*/
/*=== Добавить к каждому элементу вектора сумму всех чисел из заданного интервала этого же вектора ===*/
/*====================================================================================================*/

void addToEachInInterval(std::vector<int>& vec, int start, int end) {
    if (start >= end || end > vec.size() || start < 0 || end < 0) {
        throw std::runtime_error("Ошибка: некорректный интервал!");
    }

    int sum = 0;
    std::cout << "Элементы указанного интервала:\t";
    for (size_t i = start; i < end; ++i) {
        sum += vec[i];
        std::cout << vec[i] << ' ';
    }
    std::cout << "\nСумма чисел из указанного интервала:\t" << sum;
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i] += sum;
    }
    std::cout << "\nРезультат работы блока\n";
    printVector(vec);
}


/*============================================================================================================================*/
/*=== Замена всех чисел, модуль которых есть четное число, на разность максимального и минимального элемента этого вектора ===*/
/*============================================================================================================================*/

void replaceEven(std::vector<int>& vec)
{
    int max = -2147483647, min = 2147483647;

    for (int n : vec)
    {
        [&max, n]() {max = (max < n ? n : max); }();
        [&min, n]() {min = (min > n ? n : min); }();
    }
    int replace = max - min;
    std::cout << "Максимальный элемент вектора:\t" << max;
    std::cout << "\nМинимальный элемент вектора:\t" << min;
    std::cout << "\nИх разность:\t" << replace << std::endl;

    for (int& n : vec)
    {
        [&n, &replace]() {n = (n % 2 == 0 ? replace : n); }();
    }
    printVector(vec);
}

/*====================================================================================================*/
/*========== Удаление из последовательности все равные по модулю числа, кроме первого из них =========*/
/*====================================================================================================*/

bool isDuplicate(const std::vector<int>& seen, int number) {
    for (int n : seen) {
        if (n == number) {
            return true;
        }
    }
    return false;
}

void removeDuplicatesExceptFirstAbs(std::vector<int>& vec) {
    std::vector<int> seen; // Вектор для отслеживания появлений чисел

    auto iterator = vec.begin();
    int absNum;
    while (iterator != vec.end()) {
        absNum = std::abs(*iterator);
        if (isDuplicate(seen, absNum)) {
            iterator = vec.erase(iterator); // После удаления элемент erase возвращает итератор на следующий элемент вектора
        }
        else {
            seen.push_back(absNum); // Добавляем число в список встреченных
            ++iterator;
        }
    }
    printVector(vec);
}
