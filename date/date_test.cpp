#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today {2014, Month::jul, 4};
	cout << "\nThe defaul date is: ";
	today.print_long();
	cout << "\n";

	add(today, "days", 200);
	add(today, "months", 13);
	add(today, "years", 3);

	Date tomorrow {2014, Month::jul, 5};
	cout << "\nNew date for comparison: ";
	tomorrow.print_long();
	if (is_equal(today, tomorrow)){
		cout << "It's the same as the default 12!\n\n";
	}
	if (!is_equal(today, tomorrow)){
		cout << "It's not the same as the default date!\n\n";
	}


	cout <<"\nNow it's your turn!\n";
	Date new_day = read();
	cout << "The date you entered is: ";
	new_day.print_long();

	cout <<"\nWhat kind of adding? (days, months or years)";
	string type;
	cin >> type;
	add(new_day, type);

	cout <<"\nEnter another date for comparison - ";
	Date day2 = read();
	cout << "Your two dates are: " << new_day << " and " << day2<< ". ";
	if (is_equal(new_day, day2)){
		cout << "They are the same!\n\n";
	}
	else{
		cout << "They are not the same!\n\n";
	}
	return 0;
}