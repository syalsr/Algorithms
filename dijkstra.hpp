#include <unordered_map>
#include <string>
#include <vector>

std::string find_lowest_cost_node(const std::vector<std::string>& checked,
    std::unordered_map<std::string, size_t>& costs)
{
    std::size_t lowest_cost{ std::numeric_limits<size_t>::max() };
    std::string lowest_node{};
    for (auto&& node : costs)
    {
        std::size_t cost = node.second;
        auto check = std::find(checked.begin(), checked.end(), node.first);
    	if (cost < lowest_cost && check == checked.end())
        {
            lowest_cost = cost;
            lowest_node = node.first;
        }
    }
    return lowest_node;
}

void dijkstra(const std::unordered_map<std::string, std::unordered_map<std::string, size_t>>& graph,
					std::unordered_map<std::string, size_t>& costs,
					std::unordered_map<std::string, std::string>& parents)
{
    std::vector<std::string> checked;

    auto node = find_lowest_cost_node(checked, costs);

    while (!node.empty())
    {
        auto cost = costs[node];
        auto neighbors = graph.at(node);
        for (auto&& neighbor : neighbors)
        {
            std::size_t new_cost = cost + neighbor.second;
            if (costs[neighbor.first] > new_cost)
            {
                costs[neighbor.first] = new_cost;
                parents[neighbor.first]= node;
            }
        }
        checked.push_back(node);
        node = find_lowest_cost_node(checked, costs);
    }
}

void print_path(std::unordered_map<std::string, std::string> parents)
{
    std::string node = "Finish";
    while(!node.empty())
    {
        std::cout << node;
        if (node != "Start")
			std::cout << "<-";
        node = parents[node];
    }
}

void test()
{
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
}
