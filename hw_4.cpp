#include "std_lib_facilities.h"

const char invalid = 'i';
const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';

const string promt =">> ";
const string result = " = ";


class Token {
public:
    char kind;
    double value;
};

class Token_stream {
public:
    Token get();
    void putback(Token t);
    void ignore (char c);
private:
    Token buffer;
    bool full {false};
};

void Token_stream::putback(Token t){
    buffer = t;
    full = true;
}

Token Token_stream::get(){
    if (full){
        full = false;
        return buffer;
    }
    char ch;
    cin >>ch;
    switch (ch){
        case print: case quit: case '(': case '+': case ')':
        case '-': case '*': case '/': case '%':
            return Token {ch};
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
        {cin.putback(ch);
            double val;
            cin >> val;
            return Token {'8',val};}
    }
    return Token{'q'};
}

void Token_stream::ignore(char c){
    if (full && c == buffer.kind){
        full =false;
        return;
    }
    full = false;
    char ch =0;
    while (cin >> ch){
        if (ch==c){
            return;
        }
    }
}

vector <Token> tokens;
Token_stream ts;
double primary ();
double term();
double expression ();


double term(){
    double left = primary();
    Token t = ts.get();        

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("Error: divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {
                double d = primary();
                if (d == 0) error("Error: divide by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);    
            return left;
        }
    }

}

double primary (){
    
    Token t=ts.get();
    switch (t.kind) {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            error("Error: primary expected");
    }
    return t.value;
}

double expression (){
    double left = term();
    Token t = ts.get();
    while (true){
        switch (t.kind){
            case '+':
                left +=term();
                t=ts.get();
                break;
            case '-':
                left -=term();
                t=ts.get();
                break;
            case '*':
                left *=term();
                t=ts.get();
                break;
            case '/':
            {double c = primary();
                if (c==0){
                    error ("Error: division by zero\n");
                }
                left /=c;
                t=ts.get();
                break;
            }
            case '%':
            {double d = primary();
                if (d==0) error("Error: division by zero\n");
                left = fmod(left, d);
                t=ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

void clean_up_mess(){
    while (true){
        Token t = ts.get();
        if (t.kind == print){
            return;
        }
    }
}

void calculate(){
    while (cin){
        try{
            cout << promt;
            Token t = ts.get();
            while (t.kind == print)
                t=ts.get();
            if (t.kind == quit)
                return;
            ts.putback(t);
            cout << result<< expression() <<"\n";
        }
        catch(exception& e){
            cerr << e.what() <<"\n";
            clean_up_mess();
        }
    }
}

int main() {
    double val =0.0;
    calculate();
    return 0;
}
