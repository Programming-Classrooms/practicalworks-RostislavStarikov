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
void sortFrequency(T* arr, T** matr, int32_t size, uint32_t& pos)
{

    for (int32_t i = 0; i < 2; ++i)
    {
        for (int32_t j = 0; j < size; j++)
        {
            matr[i][j] = NULL;
        }
    }

    pos = 0;//current position in the matrix
    for (int32_t i = 0; i < size; ++i) // iterates through all the elements of the array
    {
        bool found = false; //was there an element in the array
        for (int32_t j = 0; j < pos; ++j) //iterates through the elements of the matrix to the current pos position
        {
            if (matr[0][j] == arr[i])
            {
                matr[1][j]++; //adding 1 to the counter
                found = true;
                break;
            }
        }
        if (!found)
        {
            matr[0][pos] = arr[i]; // adds a value
            matr[1][pos] = 1;
            pos++;
        }
    }
    // Sorted
    for (int32_t i = 0; i < size; ++i)
    {
        for (int32_t j = i + 1; j < size; ++j)
        {
            if (matr[1][i] <= matr[1][j])
            {
                std::swap(matr[1][i], matr[1][j]);
                std::swap(matr[0][i], matr[0][j]);
            }
        }
    }
}


template <typename T>
void inputFromFile(std::ifstream &fin, T* arr, uint32_t size) 
{
    checkInputFile(fin);
    for (uint32_t i = 0; i < size; i++) 
    {
        fin >> arr[i];
    }
}



template <typename T>
void outputInFile(std::ofstream &fout, T* arr, T** matr, uint32_t size, uint32_t pos)
{
    sortFrequency(arr, matr, size, pos);
    for (int32_t i = 0; i < pos; ++i)
    {
        fout << matr[0][i] << ' ';
    }
    fout << '\n';
}

template <typename T>
void outputFromConsole(T* arr, T** matr, uint32_t size, uint32_t pos)
{
    sortFrequency(arr, matr, size, pos);
    for (int32_t i = 0; i < pos; ++i)
    {
        std::cout << matr[0][i] << ' ';
    }
}

template <typename T>
void output(std::ofstream &fout, T* arr, T** matr, int32_t size, uint32_t& pos, char way)
{
    switch (way)
    {
    case '1':
        std::cout << "Array in file 'output.txt' \n";
        outputInFile(fout, arr, matr, size, pos);
        break;
    case '2':
        std::cout << "Array in file 'output.txt' \n";
        outputInFile(fout, arr, matr, size, pos);
        break;
    case '3':
        outputFromConsole(arr, matr, size, pos);
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
        std::cout << "Uncorrect valuable!!!\n";
        wayInputOutput(fin, arr, size, way);
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
    uint32_t pos;
    size_t size;
    double checksize;
    try
    {
        checkSize(checksize, size);
        char way = ' ';

        int32_t* intArr = new int32_t[size];
        double* doubleArr = new double[size];
        char* charArr = new char[size];

        int32_t** intMatr = new int32_t * [2];
        for (int32_t i = 0; i < 2; i++)
        {
            intMatr[i] = new int32_t[size];
        }

        double** doubleMatr = new double* [2];
        for (int32_t i = 0; i < 2; i++)
        {
            doubleMatr[i] = new double[size];
        }

        char** charMatr = new char* [2];
        for (int32_t i = 0; i < 2; i++)
        {
            charMatr[i] = new char[size];
        }

        std::ifstream fin("input.txt");
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
        output(fout, intArr, intMatr, size, pos, way);
        std::cout << "\nDouble: \n";
        output(fout, doubleArr, doubleMatr, size, pos, way);
        std::cout << "\nChar: \n";
        output(fout, charArr, charMatr, size, pos, way);
        
        deleteArrAndMtrx(intArr, intMatr);
        deleteArrAndMtrx(doubleArr, doubleMatr);
        deleteArrAndMtrx(charArr, charMatr);
        fout.close();
    }
    catch (const char* msg)
    {
        std::cout << msg;
    }


    return 0;
}
