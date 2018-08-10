#include "std_lib_facilities.h"

class vect{
	int sz;
	double* elem;
public:
	double get (int i){return elem[i];}
	void set (int i, double d){
		{elem[i]= d;}
	}
	vect (int s)
	   :sz{s}, elem{new double [s]} {}

    vect (const vect& arg)
       :sz{arg.sz}, elem{new double[arg.sz]} {
   	   copy(arg.elem, arg.elem + arg.sz, elem);  	
    }

    double& operator[](int n){return elem[n];}

    vect operator=(const vect& a){
       double* p = new double[a.sz];
       copy(a.elem, a.elem + a.sz, p);
       delete[] elem;
       elem = p;
       sz = a.sz;
       return *this;  
    }

	~vect(){
		delete[] elem;
	}
};

void f(int n){
	vect v(3);
	v[2]=2.2;
	vect v2 =v;
	v[1]=9.9;
	v2[0]= 8.8;
	cout << v[0] << " " <<v2[1]<<"\n";
}

int main(){
	int i=0;
	while(i<100){
		f(10);
		i++;
	}
}


