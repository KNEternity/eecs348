#include <iostream> 
#include <fstream> 
#include <iomanip>


using namespace std; 

#define MAX_SIZE 100



void myFunction(){
    //code to be executed 
    cout << "I just got executed!"; 
}

void readMatrixFile(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size, const char *filename){
    std::ifstream MyReadFile(filename); // read from the text file 
    
    MyReadFile >> size; 

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            MyReadFile >> matrix1[i][j];
        }
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            MyReadFile >> matrix2[i][j];
        }
    }

    MyReadFile.close(); //close file
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size){
    for (int i = 0; i < size; i++){ //read per line
        for (int j = 0; j < size; j++){ //read per element
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrix(int matrix1[MAX_SIZE][MAX_SIZE],int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE],int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    //init variables 
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE]; 
    int matrixSum[MAX_SIZE][MAX_SIZE]; 
    int size = MAX_SIZE; // will be changed later 

    readMatrixFile(matrixA, matrixB, size, "matrix_input.txt");
    cout<<"Matrix A \n";
    printMatrix(matrixA, size);
    cout<<endl;
    cout<<"Matrix B \n";
    printMatrix(matrixB, size);

    cout<<endl;
    cout<<"Matrix sum \n";
    addMatrix(matrixA, matrixB, matrixSum, size);
    printMatrix(matrixSum, size);

    return 0;
}