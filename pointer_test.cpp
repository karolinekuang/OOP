#include "std_lib_facilities.h"

int main(){
	char c ='a';
	int i  =4092;
	double d =3.14;
	char* cp = &c;
	int* ip = &i;
	double* dp = &d;
	cout <<"\ncp = "<<cp<<" and its value is " <<*cp <<"\n";
	cout <<"ip = "<<ip<<" and its value is " <<*ip <<"\n";
	cout <<"dp = "<<dp<<" and its value is " <<*dp <<"\n\n";
	
	cout << "size of cp is "<<sizeof(cp)<<"\n";
	cout << "size of ip is "<<sizeof(ip)<<"\n";
	cout << "size of dp is "<<sizeof(dp)<<"\n\n";

	cout << "size of c is "<<sizeof(c)<<"\n";
	cout << "size of i is "<<sizeof(i)<<"\n";
	cout << "size of d is "<<sizeof(d)<<"\n\n";

}