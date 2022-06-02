#pragma once

#include <cstring>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>


template<typename T>
bool BFS(T const& start, T const& end, std::unordered_map<T, std::vector<T>>& graph)
{
    std::queue<T> nodes;
    std::unordered_set<T> searched;

    for(auto&& friend_ : graph.find(start)->second)
    {
        nodes.push(friend_);
    }

    while(!nodes.empty())
    {
        T& node = nodes.front();
        nodes.pop();

        if(searched.find(node) == searched.end())
        {
            if(node == end){return true;}
            for(auto&& friend_ : graph.find(node)->second)
            {
                nodes.push(friend_);
            }
            searched.insert(std::move(node));
        }
    }
    return false;
}