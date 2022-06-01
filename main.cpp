#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <tuple>

#include "BFS.hpp"
#include "dijsktra.hpp"

int main() {
    std::unordered_map<std::string, std::unordered_map<std::string, size_t>> graph;
    graph.emplace("start", std::unordered_map<std::string, size_t>{{"A", 10}, { "B", 1 }});
    graph.emplace("B", std::unordered_map<std::string, size_t>{ {"C", 2}});
    graph.emplace("A", std::unordered_map<std::string, size_t>{ {"Finish", 3}, { "C", 1 }});
    graph.emplace("C", std::unordered_map<std::string, size_t>{ {"Finish", 2}});
    graph.emplace("Finish", std::unordered_map<std::string, size_t>{});

    std::unordered_map<std::string, size_t> costs;
    costs.emplace("A", 10);
    costs.emplace("B", 1);
    costs.emplace("C", std::numeric_limits<size_t>::max());
    costs.emplace("Finish", std::numeric_limits<size_t>::max());

    std::unordered_map<std::string, std::string> parents;
    parents.emplace("A","Start");
    parents.emplace("B", "Start");
    parents.emplace("Finish", "");

    dijkstra(graph, costs, parents);
    print_path(parents);
    return 0;
}
