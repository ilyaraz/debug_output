#define DEBUG_OUTPUT
#include "debug_output.h"

#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<int, std::vector<int> > a;
    a[0].push_back(1);
    a[0].push_back(2);
    a[1].push_back(3);
    a[1].pop_back();
    DEBUG(a);
    std::vector<char> aa;
    aa.push_back('a');
    aa.push_back('b');
    DEBUG(aa);
    DEBUG(2 * 2);
    DEBUG("blah blah");
    return 0;
}
