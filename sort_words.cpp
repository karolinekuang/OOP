#include "std_lib_facilities.h"

int main()
{
    cout << "Enter your sentence:\n";
    
    vector<string> words;
    for(string word; cin>>word; )
        words.push_back(word);
    sort(words);
    int count =1;
    for (int i=1; i<words.size(); i++){
    	if (words[i]==words[i-1]){
    		count++;
    	}
    	else {
    		cout<<words[i-1] <<": " << count <<"  ";
    		count = 1;
    	}
    }
    cout<<words[words.size()-1] <<": " << count <<"  ";
    return 0;
}