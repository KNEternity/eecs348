//notes 
#include <iostream> 
using namespace std; 

void callMomma(){
    cout <<"call ur momma"<<endl;
}
int main() {
    cout << "Welcome to c++!\n";

    //cin 
    int number1 = 0; 
    int number2 = 0;
    cout <<"Please insert 2 numbers: "; 
    cin >> number1 >> number2;  //inserts 2 numbers into variables

    //if
    if (number1 == number2){
        cout << number1 << " == " << number2 << endl;
    }
    else if (number1 > number2){
        cout<<"your mom" <<endl;
    }
    else {
        cout<<"your dad" <<endl;
    }
    //
    int product = 3; 

    while (product <= 100){
        cout<<product<<endl;
        product *= 3;
    }
    callMomma();
    
    static int yourmomma = 32; 
    return 0; 
}
