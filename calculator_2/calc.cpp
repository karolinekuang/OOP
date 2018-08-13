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

char drv(Token_stream& ts){
    vector <Token> tokens;
    int coef=1;
    string body= "";
    double d=1;
    char op;
    
    for (Token t = ts.get(); t.kind!='='; t=ts.get()){
        //op=t.kind;
        tokens.push_back(t);
        //cout<<"hi\n";
    }
    int i=0;
    for(Token tok: tokens){
        if(tok.kind== number){
           coef=tok.value;
           if(tokens.size()==(i+1)){
              d=0;
              coef=0;
           }
        }
       
        else if (tok.kind == name){
            body= tok.name;
            if(tokens.size()==(i+1)){
                d=d-1;
            }
        }
        else if (tok.kind == power){
            d=tokens[i+1].value;
            tokens[i+1].kind='0';
            coef *=d;
            d -=1;
        }
        i++;
    }
    if (d==0){
        cout <<coef;
    }
    else if(d==1){
        if (coef==1){
            cout<<body;
        }
        else {
            cout<<coef<<body;
        }
    }
    else{
        if (coef==1){
            cout<<body<<power<<d;
        }
        else {
            cout<<coef<<body<<power<<d;
        }
    }
    cout<<"\n";
    return op;
}

int main() {
    
    Token_stream ts;
    set_value("pi", 3.1415926535);
    set_value("e", 2.7182818284);
    //set_value("x", 7.3);
    double val =0.0;
    cout << "drv? yes/no";
    string s;
    cin>>s;
    if (s=="yes"){
        drv(ts);
    }
    try {
        calculate(ts);
        return 0;
    }
    catch (exception& e){
        cerr << "unknown exception\n";
        return 2;
    }
}

