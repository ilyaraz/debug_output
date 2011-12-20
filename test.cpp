#define DEBUG_OUTPUT
#include "debug_output.h"

#include <iostream>
#include <map>
#include <vector>
int main() {
    std::map<int, std::vector<int> > a;
    a[0].push_back(1);
    a[0].push_back(2);
    a[42].assign(5, 0);
    a[1].push_back(3);
    a[1].pop_back();
    DEBUG(a);
    DEBUG(a, 100);
    DEBUG(a, 1);
    DEBUG(a, 3);
    std::vector<char> aa;
    aa.push_back('a');
    aa.push_back('b');
    DEBUG(aa);
    DEBUG(2 * 2);
    DEBUG("blah blah");
    int b[5]={2, 3, 7, 13, 42};
    DEBUG(b, 5);
    DEBUG(b, 3);
    return 0;
}
