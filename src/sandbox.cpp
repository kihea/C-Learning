#include <string>
#include "./Projects/projects.h"
#include "./Projects/classes.h"
using namespace std;
using namespace pr;
string get_cpp_version() {
  if(__cplusplus == 201402L) return "C++14";
  else if(__cplusplus == 201103L) return "C++11";
  else if(__cplusplus == 199711L) return "C++98";
  else return "pre-standard C++";
}

int main() {
    string testCases[][2] = {
        {"Hey", "rey"}
    };
    
    
    cout << strdist("eryt", "reyll") << endl;
    Lexer("test");
}