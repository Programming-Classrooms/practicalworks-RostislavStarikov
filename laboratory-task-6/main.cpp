#include <iostream>
#include <fstream>
#include <ctime>


void CheckInputFile(std::ifstream& fin)
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

void CheckSize(double checksize, size_t &size)
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
void processArray(T* arr, uint32_t size) {
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
void InputFromFile(std::ifstream &fin, T* arr, uint32_t size) 
{
    CheckInputFile(fin);
    for (uint32_t i = 0; i < size; i++) 
    {
        fin >> arr[i];
    }
}



template <typename T>
void OutputInFile(std::ofstream &fout, T* arr, T** matr, uint32_t size, uint32_t pos)
{
    sortFrequency(arr, matr, size, pos);
    for (int32_t i = 0; i < pos; ++i)
    {
        fout << matr[0][i] << ' ';
    }
    fout << '\n';
}

template <typename T>
void OutputFromConsole(T* arr, T** matr, uint32_t size, uint32_t pos)
{
    sortFrequency(arr, matr, size, pos);
    for (int32_t i = 0; i < pos; ++i)
    {
        std::cout << matr[0][i] << ' ';
    }
}

template <typename T>
void Output(std::ofstream &fout, T* arr, T** matr, int32_t size, uint32_t& pos, char way)
{
    switch (way)
    {
    case '1':
        std::cout << "Array in file 'output.txt' \n";
        OutputInFile(fout, arr, matr, size, pos);
        break;
    case '2':
        std::cout << "Array in file 'output.txt' \n";
        OutputInFile(fout, arr, matr, size, pos);
        break;
    case '3':
        OutputFromConsole(arr, matr, size, pos);
    }
}

template <typename T>
void InputRandom(T* arr, uint32_t size)
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
        InputFromFile(fin, arr, size);
        break;
    case '2':
        InputRandom(arr, size);
        break;
    case '3':
        InputFromFile(fin, arr, size);
        break;
    default:
        std::cout << "Uncorrect valuable!!!\n";
        wayInputOutput(fin, arr, size, way);
    }
}

void deleteArr(int32_t* intArr, double* doubleArr, char* charArr, int32_t** intMatr, double** doubleMatr, char** charMatr)
{
    delete[] intArr;
    delete[] doubleArr;
    delete[] charArr;
    for (int32_t i = 0; i < 2; ++i)
    {
        delete[] intMatr[i];
    }
    delete[]intMatr;
    for (int32_t i = 0; i < 2; ++i)
    {
        delete[] doubleMatr[i];
    }
    delete[]doubleMatr;
    for (int32_t i = 0; i < 2; ++i)
    {
        delete[] charMatr[i];
    }
    delete[]charMatr;
}

int32_t main()
{
    uint32_t pos;
    size_t size;
    double checksize;
    try
    {
        CheckSize(checksize, size);
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
        processArray(intArr, size);
        std::cout << "\nDouble: ";
        processArray(doubleArr, size);
        std::cout << "\nChar: ";
        processArray(charArr, size);

        std::ofstream fout("output.txt");
        std::cout << "\nInteger: \n";
        Output(fout, intArr, intMatr, size, pos, way);
        std::cout << "\nDouble: \n";
        Output(fout, doubleArr, doubleMatr, size, pos, way);
        std::cout << "\nChar: \n";
        Output(fout, charArr, charMatr, size, pos, way);
        deleteArr(intArr, doubleArr, charArr, intMatr, doubleMatr, charMatr);
        fout.close();
    }
    catch (const char* msg)
    {
        std::cout << msg;
    }


    return 0;
}