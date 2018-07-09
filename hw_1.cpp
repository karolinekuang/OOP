#include "std_lib_facilities.h"

int main(){
    double a = 2.5;
    int b = 3;
    char c = 'a';
    
    int a1 = a;
    char a2 = a;
    bool a3 = a;
    
    double aa = a1;
    double ab = a2;
    double ac = a3;
    
    char b1 = b;
    bool b2 = b;
    
    int ba = b1;
    int bb = b2;
    
    bool c1 = c;
    
    char ca = c1;
    
    cout << "Original double value: " << a <<"\n -to int: " << a1 <<"\n -to char: "<< a2 << "\n -to bool: " << a3 ;
    cout << "\nConvert back to double: \n -from int: " << aa <<"\n -from char: "<< ab << "\n -from bool: " << ac ;
    cout << "\n\nOriginal int value: " << b <<"\n -to char: "<< b1 << "\n -to bool: " << b2 ;
    cout << "\nConvert back to int: \n -from char: " << ba << "\n -from bool: " << bb ;
    cout << "\n\nOriginal char value: " << c << "\n -to bool: " << c1 ;
    cout << "\nConvert back to char: \n -from bool: " << ca <<"\n\n" ;
    
    return 0;
}
