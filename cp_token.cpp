#include "std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;
};

void print_token(Token t){
     cout<< "Got token" << " of kind " << t.kind << " with vals " << t.value << "\n";
}

class Token_stream {
public:
    Token get();
    void putback(Token t);
private:
    Token buffer;
    bool full = {false};
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
        case ';': case 'q': case '(': case '+': case ')':
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

vector <Token> tokens;
Token_stream ts;
double primary ();
double term();
double expression ();


double term(){
    return primary();
}

double primary (){
    
    Token t=ts.get();
    //cout <<"pri: ";
    //print_token(t);
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
            default:
                //cout <<" in exp, putting back: ";
                //print_token(t);
                ts.putback(t);
                return left;
        }
    }
}

int main() {
    try{
        double val =0.0;
        while (cin){
            Token t = ts.get();
            //cout<< "Got token" << " of kind " << t.kind << " with val " << t.value << "\n";
            if (t.kind=='q'){
                break;
            }
            if (t.kind == ';'){
                cout << " = "<< val<< '\n';
            }
            else {
                ts.putback(t);
            }
            val = expression();
        }
    }
    catch(exception e){
        cout << "error";
    }
    return 0;
}

