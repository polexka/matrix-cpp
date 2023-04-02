#include<iostream>
#include "application.h"

using namespace std;

Application::Application() //ctor
{
    Matrix initialMatrix;
    matrix = initialMatrix;
}

void Application::showMenu()
{
    int choice = 0;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Input matrix\n";
        cout << "2. Calculate determinant\n";
        cout << "3. Transpose matrix\n";
        cout << "4. Calculate rank\n";
        cout << "5. Print matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            inputMatrix();
            break;
        case 2:
            system("cls");
            calculateDeterminant();
            break;
        case 3:
            system("cls");
            transposeMatrix();
            break;
        case 4:
            system("cls");
            calculateRank();
            break;
        case 5:
            system("cls");
            printMatrix();
            break;
        case 6:
            system("cls");
            cout << "Exiting...\n";
            break;
        default:
            system("cls");
            cout << "Invalid choice, try again.\n";
        }
    }
    while (choice != 6);
}

void Application::inputMatrix()
{
    int n;
    cout << "Enter matrix size: ";
    cin >> n;
    Matrix newMatrix(n);
    newMatrix.input();
    matrix = newMatrix;
}

void Application::calculateDeterminant()
{
    cout << "Determinant = " << matrix.determinant() << "\n";
}

void Application::transposeMatrix()
{
    cout << "Transposed matrix:\n";
    Matrix transpose = matrix.transpose();
    transpose.print();
}

void Application::calculateRank()
{
    cout << "Rank = " << matrix.rank() << "\n";
}

void Application::printMatrix()
{
    matrix.print();
}
