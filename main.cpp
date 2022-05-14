#include <iostream>
#include <unordered_map>
#include <map>
#include <tuple>

#include "BFS.hpp"

int main() {
    std::unordered_map<int, std::vector<int>> graph;
    graph[1] = {2,3};
    graph[2] = {4};
    graph[3] = {5};
    graph[5] = {4};
    std::cout << BFS(1, 4, graph);
    std::multimap<int, std::vector<int>> m;
    std::vector<int> v{1,2,3};
    std::vector<int> v1{1,3,5};
    m.insert(std::pair<int, std::vector<int>>(1, v));
    m.insert(std::pair<int, std::vector<int>>(1, v1));
    return 0;
}
