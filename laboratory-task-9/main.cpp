/*
    Строки текстового файла input.txt состоят из слов, разделенных одним  или несколькими пробелами.
    Перед первым, а также после последнего слова  строки пробелы могут отсутствовать. 
    Требуется найти слова максимальной и  минимальной длины и поменять их местами.
    Если таких слов несколько – брать первые.
*/


#include <fstream>
#include <string>
#include <iostream>


void checkFile(std::ifstream& fin)
{
    if (!fin.good())
    {
        throw "File is not founded!\n";
    }
    if (!fin)
    {
        throw "Error of open file!\n";
    }
    if (fin.peek() == EOF)
    {
        throw "file is empty!\n";
    }
}

void checkWordSize                  // Поиск минимального и максимального по длинне слова
    (
        size_t& maxLength, 
        size_t& minLength, 
        std::string word, 
        std::string& maxWord, 
        std::string& minWord
    )
{
    if (word.size() > maxLength)
    {
        maxLength = word.size();
        maxWord = word;
    }
    if (word.size() < minLength)
    {
        minLength = word.size();
        minWord = word;
    }
}

void replaceMinMaxWords                  // Меняем местами максимального и минимального слова
    (
        std::string& resultLine, 
        std::string& maxWord, 
        std::string& minWord, 
        size_t minLength, 
        size_t maxLength
    )
{
    size_t maxPos = resultLine.find(maxWord);
    size_t minPos = resultLine.find(minWord);
    if (minPos < maxPos)                // Если минимальное слово идет первым, а максимальное вторым
    {
        resultLine.replace(minPos, minWord.length(), maxWord);
        resultLine.replace(maxPos + (maxLength - minLength), maxWord.length(), minWord);
    }
    else                                // Если максимальное слово идет первым, а минимальное вторым
    {
        resultLine.replace(maxPos, maxWord.length(), minWord);
        resultLine.replace(minPos - (maxLength - minLength), minWord.length(), maxWord);
    }
}

std::string processFile(std::ifstream& fin,std::ofstream& fout, std::string delimiters)
{ 
    size_t maxLength = 0;
    size_t minLength = SIZE_MAX;
    std::string maxWord = {};
    std::string minWord = {};
    std::string line = {};
    std::string tempLine = {};
    std::string resultLine = {};

    while (getline(fin, line))
    {
        size_t begInd = 0;
        size_t endInd = 0;

        tempLine = line;
        line.push_back(' '); 

        while (line.size() != 0)
        {
            begInd = line.find_first_not_of(delimiters);
            if (begInd == std::string::npos)            // Если символ, не относящийся к разделителем не найден(строка закончилась)
            {
                line = {};
                break;
            }
            endInd = line.find_first_of(delimiters, begInd);

            std::string word = line.substr(begInd, endInd - begInd);
            checkWordSize(maxLength, minLength, word, maxWord, minWord);

            line = line.substr(endInd); 
        }
        resultLine += tempLine + '\n';
    }
    replaceMinMaxWords(resultLine, maxWord, minWord, minLength , maxLength);

    return resultLine;
} 

int main()
{
    try
    {
        std::string delimiters = "  ,.!?";
        std::ifstream fin("input.txt");
        checkFile(fin);

        std::ofstream fout("input.txt");
        
        fout << processFile(fin, fout, delimiters);;

        fin.close();
        fout.close();
    }
    catch (const char* msg)
    {
        std::cerr << msg;
        return 0;
    }
    return 0;
}
