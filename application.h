#ifndef APPLICATION_H
#define APPLICATION_H

#include "matrix.h"

class Application
{
public:
    Application();

    Matrix matrix;
    void showMenu();
    void inputMatrix();
    void calculateDeterminant();
    void transposeMatrix();
    void calculateRank();
    void printMatrix();

protected:
private:
};

#endif
