#include "std_lib_facilities.h"
int main() {
    cout << "Enter the name of the person you want to write to:\n";
    string first_name;
    cin >> first_name;
    cout << "Enter your friend's name: \n";
    string friend_name;
    cin >> friend_name;
    cout << "How old is " << first_name <<"?";
    int age;
    cin >> age;
    cout << "Dear " << first_name << ",\n" << "Have you seen " <<friend_name <<" lately? I hear you had a birthday and you are now " <<age<<" years old! ";
    if (age<0 || age >110){
        simple_error("Are you sure this is the right age?\n");
    }
    else if (age < 17){
        cout << "You are young to be at NYU!\n";
    }
    else if (age > 65){
        cout << "It's great to see senior students around campus!\n";
    }
}