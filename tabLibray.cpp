//
// Created by nicolas on 22/12/17.
//

#include "tabLibray.h"


/**
 * \brief procedure qui compare le contenu de 2 tableaux
 * \param 2 tableaux
 * \param 1 entier : la taille des tableaux
 */
bool compare_tabs(const std::unique_ptr<int[]> *pa, const std::unique_ptr<int[]> *pb, int size)
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