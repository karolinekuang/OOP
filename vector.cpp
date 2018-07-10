#include "std_lib_facilities.h"
int main(){
	int i;
	vector<int> v;
	while (cin>>i){
		v.push_back(i);
	}
	cout<< "\n";
	for (int j=0; j<v.size();j++){
		cout << v[j] <<" ";
	}
}