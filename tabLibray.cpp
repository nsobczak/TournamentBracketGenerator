//
// Created by nicolas on 22/12/17.
//

#include "tabLibray.h"


void tabLibrary::printArray(int *pTab, int arraySize)
{
    std::cout << "|";
    for (int i = 0; i < arraySize; ++i)
        std::cout << "|" << pTab[i];
    std::cout << "||" << std::endl;
}


/**
 * \brief compare 2 tab
 * \param 2 tab
 * \param 1 int : tab size
 */
bool tabLibrary::compare_tabs(int *pa, int *pb, int size)
{
    int i;
    bool result = true;

    for (i = 0; i < size; ++i)
    {
        if (pa[i] != pb[i])
            result = false;
    }
    return result;
}