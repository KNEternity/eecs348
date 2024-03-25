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

void addMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE],int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

void subtractMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            result[i][j] = matrix2[i][j] - matrix1[i][j];
        }
    }
}

void updateMatrix(int matrix[MAX_SIZE][MAX_SIZE]){
    int row, column, number;
    cout <<"Row: ";
    cin >> row;
    while (row > 3 or row < 1){
        cout <<"Row: ";
        cin >> row;
    }
    cout <<"Column: ";
    cin >> column; 
    while (column > 3 or column < 1){
        cout <<"Column: ";
        cin >> column;
    }
    cout <<"New value: ";
    cin >> number; 

    matrix[row-1][column-1] = number; 
}

int findMaxMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size){
    int maxNumber = matrix[0][0]; 

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (matrix[i][j] > maxNumber){
                maxNumber = matrix[i][j];
            }
        }
    }
    return maxNumber;
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size){
    int dummyMatrix[size][size]; 

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            dummyMatrix[j][i] = matrix[i][j];
        }
    }
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j] = dummyMatrix[i][j];
        }
    }

}

int main() {
    //init variables 
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE]; 
    int matrixSum[MAX_SIZE][MAX_SIZE]; 
    int matrixMultiplication[MAX_SIZE][MAX_SIZE];
    int matrixSubtract[MAX_SIZE][MAX_SIZE]; 
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
    
    cout<<endl;
    cout<<"Matrix Multiplication \n";
    multiplyMatrix(matrixA, matrixB, matrixMultiplication, size);
    printMatrix(matrixMultiplication, size);

    cout<<endl;
    cout<<"Matrix Subtract \n";
    subtractMatrix(matrixA, matrixB, matrixSubtract, size);
    printMatrix(matrixSubtract, size);

    cout<<endl;
    cout<<"Matrix Update \n";
    updateMatrix(matrixA);
    cout<<"New Matrix \n";
    printMatrix(matrixA, size);

    int maxNumber = findMaxMatrix(matrixA, size);
    cout << "Max Number of the first matrix is: " <<maxNumber<< endl; 

    cout<<"Matrix Transposition \n";
    transposeMatrix(matrixA, size);
    printMatrix(matrixA, size);
    return 0;
}