#include "std_lib_facilities.h"
#include <iostream>

int main (){
    cout<< "Which year were you born?";
    int year;
    cin >> year;
    int remainder = year%12;
    switch (remainder) {
    case 4:
        cout << "You are a Rat in the Chinese zodiac!";
        break;
    case 5:
        cout << "You are an Ox in the Chinese zodiac!";
        break;
    case 6:
        cout << "You are a Tiger in the Chinese zodiac!";
        break;
    case 7:
        cout << "You are a Rabbit in the Chinese zodiac!";
        break;
    case 8:
        cout << "You are a Dragon in the Chinese zodiac!";
        break;
    case 9:
        cout << "You are a Snake in the Chinese zodiac!";
        break;
    case 10:
        cout << "You are a Horse in the Chinese zodiac!";
        break;
    case 11:
        cout << "You are a Goat in the Chinese zodiac!";
        break;
    case 0:
        cout << "You are a Monkey in the Chinese zodiac!";
        break;
    case 1:
        cout << "You are a Rooster in the Chinese zodiac!";
        break;
    case 2:
        cout << "You are a Dog in the Chinese zodiac!";
        break;
    case 3:
        cout << "You are a Pig in the Chinese zodiac!";
        break;
        }
    cout <<"\n";
}
