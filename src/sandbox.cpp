#include <string>
#include "./Projects/projects.h"
using namespace std;
using namespace pr;


int main() {
    string testCases[][2] = {
        {"Hey", "rey"}
    };
    cout << strdist("Hey", "rey") << endl;
}