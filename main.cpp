//
//  main.cpp
//  HW1
//
//  Created by Karoline Kuang on 7/5/18.
//  Copyright © 2018 Karoline Kuang. All rights reserved.
//
#include "std_lib_facilities.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    cout << "Please enter your name:\n";
    string first_name;
    int age;
    cin >> first_name;
    cout << "Please enter your age:\n";
    cin >> age;
    cout<< first_name <<"\n" << age<<"\n";
    //keep_window_open();
    return 0;
}
