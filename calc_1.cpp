#include "std_lib_facilities.h"

int main(){
	cout << "Enter your calculations. . .(use space between numbers and operations)\n";
	int lval= 0, rval, res;
	char op;
	cin >> lval >> op >> rval;
	if (op == '+'){
		res = lval + rval;
	}
	else if (op == '-'){
		res = lval - rval;
	}
	cout <<lval <<" "<< op <<" "<<rval << " = " <<res <<"\n";
}