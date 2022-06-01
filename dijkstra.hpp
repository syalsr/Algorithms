std::string find_lowest_cost_node(const std::vector<std::string>& checked,
    std::unordered_map<std::string, size_t>& costs)
{
    std::size_t lowest_cost{ std::numeric_limits<size_t>::max() };
    std::string lowest_node{};
    for (auto&& node : costs)
    {
        std::size_t cost = node.second;
        auto check = find(checked.begin(), checked.end(), node.first);
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
			std::cout << "->";
        node = parents[node];
    }
}