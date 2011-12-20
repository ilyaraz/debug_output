#define DEBUG_OUTPUT
#include "debug_output.h"

#include <iostream>
#include <map>
#include <set>
#include <vector>

void f(const int &x) {
    DEBUG(x);
}

void g(int *x) {
    DEBUG(x);
}

void h(char *x) {
    DEBUG(x);
}

void h(const char *x) {
    DEBUG(x);
}

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
    int test = 5;
    f(test);
    g(&test);
    int b[5] = {0, 1, 2, 3, 4};
    DEBUG(std::vector<int>(b, b + 5));
    h("blah blah");
    h((char*)"blah blah");
    std::set<int> ss;
    ss.insert(1);
    ss.insert(3);
    ss.insert(5);
    DEBUG(ss);
    return 0;
}
