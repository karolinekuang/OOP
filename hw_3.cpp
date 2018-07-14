#include "std_lib_facilities.h"
class Token {
public:
    char kind;
    double value;
};

Token get_token (){
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
    return Token{ch};
}

vector <Token> tokens;


int main() {
    Token t=get_token();
    for (Token tok= t; tok.kind != 'q'; tok= get_token()){
        tokens.push_back(tok);
    }
    for (Token tok: tokens){
        if (tok.kind=='8')
            cout<< "A number token with val = " << tok.value << "\n";
        else if (tok.kind ==';'|| tok.kind =='q'|| tok.kind =='('|| tok.kind=='+'|| tok.kind == ')'||tok.kind=='-'||tok.kind =='*' || tok.kind == '/' || tok.kind == '%'){
            cout << "A token of kind " << tok.kind << "\n";
        }
        else {
            cout <<"We received an invalid token of value " << tok.kind << "\n";
        }
    }
    return 0;
}

