#include "std_lib_facilities.h"
int main() {
    int number_of_words = 0;
    string previous = " ";
    string current;
    string word [100];
    while (cin >> current) {
        word [number_of_words] = current;
        ++number_of_words;
        int count=0;
        for (int i = 0; i<number_of_words-1; i++){
            if (word [i] == current){
                count++;
            }
        }
        if (count != 0){
            cout << current << " is repeated " << count <<" times. \n"<< current <<" word count: " << count+1;
        }
        previous = current;
    }
}