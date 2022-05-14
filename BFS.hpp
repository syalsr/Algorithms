#pragma once

#include <cstring>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

//ToDo Каким-то образом составить путь, но не понятно как
//Можно проходить по всем нодам и если у нее также есть соседи добавлять
//В потенциальный путь, т.е. допустим вот дерево
/*
 *          1
 *         / \
 *        2   3
 *        /
 *        4
 * Предполагаемые пути, 1-2, 1-3, т.к. у 3 нет соседей, то удаляем его из
 * возможных путей, движемся дальше, добавляем путь 1-2-4, который и оказывается
 * единственным
 * Но не понятно как хранить предполагаемые пути
 * 1. вектор векторов, но не понятно как находить один из многих путей которые нужно либо удалить
 * либо добавить новую ноду
 * 2. мультимапа кажется единственным выходом multimap<node, vector<node>>
 * но опять же как по ним осуществлять поиск, что будет ключом,
 * теоретически ключом может быть последняя добавленная нода в вектор,
 * к сожалению даже так, unordered_map не подойдет, т.к. нет уверенности
 * что все ноды уникальны
 */
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