#include "std_lib_facilities.h"
#include "token.h"
#include "parser.h"
#include "vars.h"


void clean_up_mess(Token_stream& ts){
    while (true){
        Token t = ts.get();
        if (t.kind == print){
            return;
        }
    }
}

void calculate(Token_stream& ts){
    while (cin){
        try{
            cout << promt;
            Token t = ts.get();
            while (t.kind == print)
                t=ts.get();
            if (t.kind == quit)
                return;
            ts.putback(t);
            cout << result<< statement(ts) <<"\n";
        }
        catch(exception& e){
            cerr << e.what() <<"\n";
            clean_up_mess(ts);
        }
    }
}

int main() {
    
    Token_stream ts;
    set_value("pi", 3.1415926535);
    set_value("e", 2.7182818284);
    //set_value("x", 7.3);

    double val =0.0;
    try {
        calculate(ts);
        return 0;
    }
    catch (exception& e){
        cerr << "unknown exception\n";
        return 2;
    }
}

