#pragma once
#include <string>
using namespace std;

class Symbol {
    string Literal;
    string Type;
    //
};
class Rule {

};
class Token {
    int line;
    int col;
    int offset;
    string type;
    string value;

    Token(int l, int c, int o, string t, string v) {
        line, col, offset, type, value = l, c, o, t, v;
    };
};


class Lexer {
    string buffer;
    int index;
    int line;
    int col;
    public:

        Lexer(string input) {
            buffer = input;
            index, line, col = 0, 1, 0;
        };

};

Lexer::next() {
    
}