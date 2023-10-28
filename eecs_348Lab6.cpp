#include <iostream>
#include <fstream>

using namespace std; // allows me to skip std::


int readmatrix(float matrixA[100][100], float matrixB[100][100]){ //reads and formats matrix from input file
    ifstream file("matrix_input.txt"); //opens the file called matrix_input.txt
    if(!file.is_open()){ //if the file can't open 
        cout<<"File Does Not Exist/Incorrect File Name"<<endl; //prints message if file can't be found
        return 1; 
    }
    int size; 
    file>>size;
    cout<<"Matrix A"<<endl;
    for (int x =0; x<size; x++){
        for(int y =0; y<size; y++){
            file >> matrixA[x][y];
            cout << matrixA [x][y]<< " ";
        }
        cout<<endl;
    }
    cout<<"Matrix A"<<endl;
    for (int x =0; x<size; x++){
        for(int y =0; y<size; y++){
            file >> matrixB[x][y];
            cout << matrixB [x][y]<< " ";
        }
        cout<<endl;
    }
    file.close(); //closes the file
    return size;
}

void matrix_addition(float matrixA[100][100], float matrixB[100][100],int matrixSize){
    cout<< "Matrix Sum (A+B)"<<endl;
    float addMatrix[100][100];
    for (int x =0; x<matrixSize; x++){
        for (int y = 0; y<matrixSize; y++){
            addMatrix[x][y] = matrixA[x][y]+matrixB[x][y];
            cout <<addMatrix[x][y] <<" "; 
        }
        cout<<endl;
    }
}

void matrix_product(float matrixA[100][100], float matrixB[100][100], int matrixSize){
    cout<<"Matrix Product (A*B)"<< endl;
    float productMatrix[100][100];
    for (int x=0; x<matrixSize; x++){
        for (int y = 0; y<matrixSize; y++){
            productMatrix[x][y] = 0;
            for (int z=0; z<matrixSize; z++){
                productMatrix[x][y] += matrixA[x][y] *matrixB[x][y];
            }
        cout<<productMatrix[x][y]<<" ";
        }
    cout<<endl;
    }
}

void matrix_difference (float matrixA[100][100], float matrixB[100][100], int matrixSize){
    cout <<"Matrix Difference (A-B)"<<endl;
    float subMatrix[100][100];
    for (int x =0; x<matrixSize; x++){
        for (int y = 0; y<matrixSize; y++){
            subMatrix[x][y] = matrixA[x][y]-matrixB[x][y];
            cout <<subMatrix[x][y] <<" "; 
        }
        cout<<endl;
    }
}


int main(){
    float matrixA[100][100];
    float matrixB [100][100];
    const int size = readmatrix(matrixA,matrixB);
    matrix_addition(matrixA,matrixB,size);
    matrix_product (matrixA, matrixB, size);
    matrix_difference(matrixA,matrixB,size);

}