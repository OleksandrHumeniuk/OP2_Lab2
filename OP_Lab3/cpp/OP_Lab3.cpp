#include <iostream>
#include "tetrahedron.h"
#include "functions.h"

int main()
{   
    int arrayLength = inputInt("Enter size of the tetrahedron array: ", NumInputMode :: POSITIVE_INT);
    Mode mode = chooseMode();

    Tetrahedron* tetrahendros = generateArray(arrayLength, mode);
    printTetrahendronsArray(tetrahendros, arrayLength);

    int maxIndex = findMaxVolumeIndex(tetrahendros, arrayLength);
    cout << "\nTetrahedron #" << maxIndex + 1 << " has max volume" << endl;
    tetrahendros[maxIndex].display();
}
