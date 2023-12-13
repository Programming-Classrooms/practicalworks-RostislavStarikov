/*Разработать шаблон функции для обработки массивов с элементами простого
арифметического типа и массивов, элементы которых – строки типа char*.
Продемонстрировать использование этого шаблона для конкретных динамических
массивов типа int, double, char*.
Для получения входных данных иметь три варианта:
-непосредственный ввод и запись в текстовый файл;
-генерирование с помощью датчика случайных чисел и запись в текстовый файл;
-ввод из текстового файла, а вывод - в консоль.
Вариант 11
Разработать шаблон функции, позволяющей расположить 
элементы последовательности в порядке убывания частоты их встречаемости*/
#include <iostream>
#include <fstream>
#include <ctime>


void checkInputFile(std::ifstream& fin)
{
    if (!fin.good())
    {
        throw "file isn't exist \n";
    }
    if (!fin)
    {
        throw "input file error \n";
    }
    if (fin.peek() == EOF)
    {
        throw "File is empty \n";
    }

}

void checkSize(double checksize, size_t &size)
{
    std::cout << "Enter size: ";
    std::cin >> checksize;
    if (checksize <= 0 || checksize != static_cast<int32_t>(checksize))
    {
        throw "Uncorrect size!!!\n";
    }
    size = static_cast<int32_t>(checksize);
}


template <typename T>
void printArray(T* arr, uint32_t size) {
    for (uint32_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

template <typename T>
void sortFrequency(T* arr, T** mtrx, int32_t size, uint32_t& position)
{

    for (int32_t i = 0; i < 2; ++i)
    {
        for (int32_t j = 0; j < size; j++)
        {
            mtrx[i][j] = NULL;
        }
    }

    position = 0;//current position in the matrix
    for (int32_t i = 0; i < size; ++i) // iterates through all the elements of the array
    {
        bool found = false; //was there an element in the array
        for (int32_t j = 0; j < position; ++j) //iterates through the elements of the matrix to the current position position
        {
            if (mtrx[0][j] == arr[i])
            {
                mtrx[1][j]++; //adding 1 to the counter
                found = true;
                break;
            }
        }
        if (!found)
        {
            mtrx[0][position] = arr[i]; // adds a value
            mtrx[1][position] = 1;
            ++position;
        }
    }
    // Sorted
    for (int32_t i = 0; i < size; ++i)
    {
        for (int32_t j = i + 1; j < size; ++j)
        {
            if (mtrx[1][i] <= mtrx[1][j])
            {
                std::swap(mtrx[1][i], mtrx[1][j]);
                std::swap(mtrx[0][i], mtrx[0][j]);
            }
        }
    }
}


template <typename T>
void inputFromFile(std::ifstream &fin, T* arr, uint32_t size) 
{
    for (uint32_t i = 0; i < size; i++) 
    {
        fin >> arr[i];
    }
}



template <typename T>
void outputInFile(std::ofstream &fout, T* arr, T** mtrx, uint32_t size, uint32_t position)
{
    sortFrequency(arr, mtrx, size, position);
    for (int32_t i = 0; i < position; ++i)
    {
        fout << mtrx[0][i] << ' ';
    }
    fout << '\n';
}

template <typename T>
void outputFromConsole(T* arr, T** mtrx, uint32_t size, uint32_t position)
{
    sortFrequency(arr, mtrx, size, position);
    for (int32_t i = 0; i < position; ++i)
    {
        std::cout << mtrx[0][i] << ' ';
    }
}

template <typename T>
void output(std::ofstream &fout, T* arr, T** mtrx, int32_t size, uint32_t& position, char way)
{
    switch (way)
    {
    case '1':
        std::cout << "Array in file 'output.txt' \n";
        outputInFile(fout, arr, mtrx, size, position);
        break;
    case '2':
        std::cout << "Array in file 'output.txt' \n";
        outputInFile(fout, arr, mtrx, size, position);
        break;
    case '3':
        outputFromConsole(arr, mtrx, size, position);
    }
}

template <typename T>
void inputRandom(T* arr, uint32_t size)
{
    srand(rand());
    for (int i = 0; i < size; i++) 
    {
        arr[i] = static_cast<T>((rand())%256);
    }
}

template <typename T>
void wayInputOutput(std::ifstream &fin, T* arr, uint32_t size, char& way)
{
    if (way == ' ')
    {
        std::cout << "Select the data input and output method:\n\t1.Direct input and writing to a text file\n\t2.Generating random numbers using a sensor and writing to a text filen\n\t3.Input from a text file, and output to the console.\n";
        std::cin >> way;
    }
    switch (way) {
    case '1':
        inputFromFile(fin, arr, size);
        break;
    case '2':
        inputRandom(arr, size);
        break;
    case '3':
        inputFromFile(fin, arr, size);
        break;
    default:
        throw "Incorrect choice of input method\n";
    }
}

template <typename T>
void deleteArrAndMtrx(T* arr,  T** mtrx)
{
    delete[] arr;
    for (size_t i = 0; i < 2; ++i)
    {
        delete[] mtrx[i];
    }
    delete[]mtrx;
}

int32_t main()
{
    uint32_t position;
    size_t size;
    double checksize;
    try
    {
        checkSize(checksize, size);
        char way = ' ';

        int32_t* intArr = new int32_t[size];
        double* doubleArr = new double[size];
        char* charArr = new char[size];

        int32_t** intMtrx = new int32_t * [2];
        for (int32_t i = 0; i < 2; i++)
        {
            intMtrx[i] = new int32_t[size];
        }

        double** doubleMtrx = new double* [2];
        for (int32_t i = 0; i < 2; i++)
        {
            doubleMtrx[i] = new double[size];
        }

        char** charMtrx = new char* [2];
        for (int32_t i = 0; i < 2; i++)
        {
            charMtrx[i] = new char[size];
        }

        std::ifstream fin("input.txt");
        checkInputFile(fin);
        wayInputOutput(fin, intArr, size, way);
        wayInputOutput(fin, doubleArr, size, way);
        wayInputOutput(fin, charArr, size, way);
        fin.close();

        std::cout << "\nInteger: ";
        printArray(intArr, size);
        std::cout << "\nDouble: ";
        printArray(doubleArr, size);
        std::cout << "\nChar: ";
        printArray(charArr, size);

        std::ofstream fout("output.txt");
        std::cout << "\nInteger: \n";
        output(fout, intArr, intMtrx, size, position, way);
        std::cout << "\nDouble: \n";
        output(fout, doubleArr, doubleMtrx, size, position, way);
        std::cout << "\nChar: \n";
        output(fout, charArr, charMtrx, size, position, way);
        
        deleteArrAndMtrx(intArr, intMtrx);
        deleteArrAndMtrx(doubleArr, doubleMtrx);
        deleteArrAndMtrx(charArr, charMtrx);
        fout.close();
    }
    catch (const char* msg)
    {
        std::cout << msg;
    }
    return 0;
}
