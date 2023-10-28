#include <iostream>
#include <fstream>

using namespace std; //so you don't have to keep typing std::

int readmatrix(float matrixA[100][100], float matrixB[100][100]) { //method that reads and formats input file
    ifstream inFile("matrix_input.txt");
    if (!inFile.is_open()) { //throws this message if the file isnt found
        cout << "File Does Not Exist/Incorrect File Name" << endl;
        return 1;
    }

    int size;
    inFile >> size;

    cout << "\nMatrix A" << endl; // prints matrix A in the correct format
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            inFile >> matrixA[x][y];
            cout << matrixA[x][y] << " ";
        }
        cout << endl;
    }
    cout << "\nMatrix B"<< endl; // prints matrix B in the correct format
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            inFile >> matrixB[x][y];
            cout << matrixB[x][y] << " ";
        }
        cout << endl;
    }

    inFile.close();
    return size;
}

void matrix_addition(float matrixA[100][100], float matrixB[100][100], int matrixSize) { //method to compute addition matrix
    cout << "\nMatrix Sum (A + B)" << endl;
    float addMatrix[100][100];
    for (int x = 0; x < matrixSize; x++) {
        for (int y = 0; y < matrixSize; y++) {
            addMatrix[x][y] = matrixA[x][y] + matrixB[x][y];
            cout << addMatrix[x][y] << " ";
        }
        cout << endl;
    }
}

void matrix_product(float matrixA[100][100], float matrixB[100][100], int matrixSize) { //method to compute procut matrix
    cout << "\nMatrix Product (A * B)" << endl;
    float productMatrix[100][100];
    for (int x = 0; x < matrixSize; x++) {
        for (int y = 0; y < matrixSize; y++) {
            productMatrix[x][y] = 0;
            for (int z = 0; z < matrixSize; z++) {
                productMatrix[x][y] += matrixA[x][z] * matrixB[z][y];
            }
        }
    }
    for (int x = 0; x < matrixSize; x++) {
        for (int y = 0; y < matrixSize; y++) {
            cout << productMatrix[x][y] << " ";
        }
        cout << endl;
    }
}

void matrix_difference(float matrixA[100][100], float matrixB[100][100], int matrixSize) { // method to compute differnece
    cout << "\natrix Difference (A - B)" << endl;
    float subMatrix[100][100];
    for (int x = 0; x < matrixSize; x++) {
        for (int y = 0; y < matrixSize; y++) {
            subMatrix[x][y] = matrixA[x][y] - matrixB[x][y];
            cout << subMatrix[x][y] << " ";
        }
        cout << endl;
    }
}

int main() { //main function that runs the code
    float matrixA[100][100];
    float matrixB[100][100];
    int size = readmatrix(matrixA, matrixB);
    matrix_addition(matrixA, matrixB, size);
    matrix_product(matrixA, matrixB, size);
    matrix_difference(matrixA, matrixB, size);
    return 0;
}
