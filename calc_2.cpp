#include "std_lib_facilities.h"

int main (){
    cout << "Enter your calculations. . .\n";
    int lval= 0, rval, res=0;
    cin >> lval;
    if (!cin)
        error ("Invalid operation!");
    for (char op= 'x'; op != '='; cin >> op){
        if (op =='x'){
            cin >> op;
        }
        cin >> rval;
        switch (op) {
            case '+': res = lval + rval;
                break;
            case '-': res = lval - rval;
                break;
            case '*': res = lval * rval;
                break;
            case '/': res = lval / rval;
                break;
            default : res=lval;
        }
        if(res!= lval){
            lval = res;
        }
    }
    cout <<res <<"\n";
}
