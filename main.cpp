#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <tuple>
#include <limits>
#include <algorithm>

#include "BFS.hpp"
#include "dijkstra.hpp"
#include "Check_Brackets_Sequence.hpp"


int main() {
    std::stringstream ss;
    ss << "([[]])]]";
    auto d = check_brakets_sequence(ss);
    for(int i = 0; i < d->size(); ++i)
        std::cout << d->top(); d->pop();
    return 0;
}
