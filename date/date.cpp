#include "std_lib_facilities.h"
#include "date.h"

Date read(){
	cout << "Enter your date in format YYYY/MM/DD: ";
	int year, month, day;
	char a, b;
	cin >> year >> a >> month >> b >> day;
	Date d {year, Month(month), day};
	
	return d;
}

void add(Date d, string type){
	if (type == "day" || type =="days"){
		cout <<"Adding how many " << type << "?";
	    int n;
	    cin >> n;
		d.add_day(n);
		cout << "Adding " << n <<" " <<type <<"...\nThe new date is: ";
		d.print_long();
	}
	else if (type == "month" || type =="months"){
		cout <<"Adding how many " << type << "?";
	    int n;
	    cin >> n;
		d.add_month(n);
		cout << "Adding " << n <<" " <<type <<"...\nThe new date is: ";
		d.print_long();
	}
	else if (type == "year" || type =="years"){
		cout <<"Adding how many " << type << "?";
	    int n;
	    cin >> n;
		d.add_year(n);
		cout << "Adding " << n <<" " <<type <<"...\nThe new date is: ";
		d.print_long();
	}
	else{
		error("Invalid Input!");
	}
}

void add(Date d, string type, int n){
	if (type == "day" || type =="days"){
		d.add_day(n);
		cout << "Adding " << n <<" " <<type <<"...\nThe new date is: ";
		d.print_long();
	}
	else if (type == "month" || type =="months"){
		d.add_month(n);
		cout << "Adding " << n <<" " <<type <<"...\nThe new date is: ";
		d.print_long();
	}
	else if (type == "year" || type =="years"){
		d.add_year(n);
		cout << "Adding " << n <<" " <<type <<"...\nThe new date is: ";
		d.print_long();
	}
	else{
		error("Invalid Input!");
	}
}

bool is_leap( int y){
	if (((y%4==0) && (y%100!=0)) || (y%400==0)){
		return true;
	}
	else{
		return false;
	}
}

bool is_equal( Date a, Date b){
	if ((a.get_year()==b.get_year())&& 
		(a.get_month()== b.get_month())&& (a.get_day()==b.get_day())){
		return true;
	}
	else{
		return false;
	}
}

bool Date::is_valid(){
	if (get_year()<1){
		return false;
	}
	if (is_leap(get_year())){
		if(get_day()>leap_last_day[month()]){
			return false;
		}
	}
	else{
		if(get_day()>last_day[month()]){
			return false;
		}
	}
	return true;
	
}

Date::Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {
	try{
		if(!is_valid()){
		    throw Invalid{};
	    }
	}
	catch(exception& e){
		cout<<e.what()<<"\n";
	}

}

void Date::add_day(int n){
	d +=n;
	if (is_leap(get_year())){
		cout << "in leap year\n";
		while (d>leap_last_day[month()]){
		d -= leap_last_day[month()];
		add_month(1);
	    }
	}
	else{
		while (d>last_day[month()]){
		d -= last_day[month()];
		add_month(1);
	    }
	}
}

void Date::add_month(int n){
	int temp = int(m);
	temp +=n;
	while (temp>12){
		temp -= 12;
		add_year(1);
	}
    m=Month(temp);
}

void Date::add_year(int n){
	y +=n;
}

Month Date::get_month(){
	return m;
}

int Date::month(){
	return int(m);
}

int Date::get_day(){
	return d;
}

int Date::get_year(){
	return y;
}

void Date::print_long(){
	cout <<mons[month()-1]<<" "<<get_day()<<", "<<get_year()<<"\n";
}

ostream& operator << (ostream& os, const Date& d){
	return os<<'('<<d.get_year()<<'/'<<d.month()<<'/'<<d.get_day()<<')';
}

