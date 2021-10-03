#include <iostream>
#include <string>

using namespace std;

class symbol {
public:
    symbol() {
        
    }

};

#define log(x) cout << x;
class Rule {
public:
    string name;
    symbol symbols[];
    Rule() {

    }
};
int main() {

    for (int i = 0; i < 10; i++) {
        log(i);
    }
    return 0;
}
