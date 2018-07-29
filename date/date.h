#include "std_lib_facilities.h"

enum class Month{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day{
	Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday 
};

class Date{

public:
	Date (int y, Month m, int d);
	vector <string> mons ={"January", "February", "March", "April", "May", "June", "July", 
    "August", "September", "October", "November", "December"};
    vector <int> last_day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector <int> leap_last_day = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	void add_day (int n);
	void add_month(int n);
	void add_year(int n);
	Month get_month();
	int month();
	int get_day();
	int get_year();
	class Invalid {};

	int get_year() const {return y;}
    int month() const{return int(m);}
    int get_day() const{return d;}

    void print_long();

private:
	int y, d;
	Month m;
	bool is_valid();
};


bool is_leap( int y);
bool is_equal(Date a, Date b);
ostream& operator << (ostream& os, const Date& d);
Date read();
void add(Date d, string type);
void add(Date d, string type, int n);
