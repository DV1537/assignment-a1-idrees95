#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    double sum = 0.0;
    double total = 0.0;
    double average = 0.0;
    int arraySize = 1;

    double *numbers = new double[arraySize];

    std::ifstream inputToFile;

    inputToFile.open("numbers.txt");

    if(inputToFile.is_open())
    {
        while(inputToFile >> numbers[arraySize])
        {
            total++; 
            if(total >= arraySize)
            {
                double *tempNumbers = new double[arraySize + 1];
                for(int count = 0; count < arraySize; count++)
                {
                    tempNumbers[count] = numbers[count];
                }
                delete[] numbers;
                numbers = tempNumbers;
                tempNumbers = nullptr; 
                arraySize += 1;
            }
            for(int count = 0; count < total; count++)
            {
                sum += numbers[count];
            }
            average = sum / total;

            for(int count = 0; count < total; count++)
            {
                if(numbers[count] > average)
                {
                    std::cout << std::setprecision(3.0) << numbers[count] << " ";
                }
                else 
                {
                    std::cout << " ";
                }

            }
        }
    }
    else 
    {
        std::cout << " Error file couldn't be red !" << std::endl;
    }
    inputToFile.close();

    delete[] numbers;
    system("pause");
    return 0;
}
