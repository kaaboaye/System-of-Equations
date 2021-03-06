#include "InputOutput.h"
#include "Vector.h"
#include "Consts.h"
#include "SystemOfEquations.h"
#include <iostream>
#include <fstream>
#include <sstream>

template<typename T>
SystemOfEquations<T> OpenFile(char* filename)
{
    std::fstream file;
    Vector<T> v;
    SystemOfEquations<T> SoE;

    file.open(filename); //Open file

    if(file.is_open()) //Has file opened succesfully?
    {
        std::cout << "FILE IS OPEN" << std::endl << std::endl;

        for (int i = 0; i <= SIZE ; ++i)
        {
            file >> v; //From stream file to Vector

            if(i < SIZE)
            {
                SoE.SetVectorsA(i, v);
            } else //Last vector is B matrix
            {
                SoE.SetVectorB(v);
            }
        }
    }
    file.close(); //Close file

    return SoE;
}