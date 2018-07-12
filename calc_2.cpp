#include "std_lib_facilities.h"

int main (){
	cout << "Enter your calculations. . .\n";
	int lval= 0, rval, res;
	char op;
	cin >> lval >> op >> rval;
	switch (op) {
		case '+': res = lval + rval;
		break;
		case '-': res = lval - rval;
		break;
		case '*': res = lval * rval;
		break;
		case '/': res = lval / rval;
		break;
	}
	cout <<lval <<" "<< op <<" "<<rval << " = " <<res <<"\n";
}