#include <regexp>
#define r(x) regexp(x)

if (regexp_search("hey", r("hey"))) {
    cout << "hey";
}