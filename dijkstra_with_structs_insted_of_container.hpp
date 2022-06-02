#include <vector>
#include <map>
#include <algorithms>

struct Edge
{
	size_t weight;
	size_t to;
};

struct Vertice
{
	size_t id;
	std::vector<Edge> edges;
	size_t weight;
	size_t from;
	bool visited;
};

struct Graph
{
	std::vector<Vertice> vertices;
	void clear()
	{
		vertices.clear();
	}
	void Init()
	{
		for(auto&& node : vertices)
		{
			node.weight = std::numeric_limits<size_t>::max();
			node.visited = false;
			node.from = std::numeric_limits<size_t>::max();
		}
	}
};

void dijkstra(Graph& graph, size_t start)
{
	std::multimap<size_t, size_t> weights;
	weights.insert({ start, 0 });
	graph.vertices[start].weight = 0;

	while(!weights.empty())
	{
		auto [first_id, first_weight] = *(weights.begin());
		weights.erase(weights.begin());
		if (graph.vertices[first_id].visited)
			continue;
		graph.vertices[first_id].visited = true;

		for(size_t i{}; i < graph.vertices[first_id].edges.size(); ++i)
		{
			size_t to = graph.vertices[first_id].edges[i].to;
			size_t weight = graph.vertices[first_id].edges[i].weight;
			if(!graph.vertices[to].visited)
			{
				if(first_weight + weight < graph.vertices[to].weight)
				{
					graph.vertices[to].weight = first_weight + weight;
					graph.vertices[to].from = first_id;
					weights.insert({ to, graph.vertices[to].weight });
				}
			}
		}
	}

}

std::vector<size_t> create_path(const Graph& graph, size_t start, size_t finish)
{
	std::vector<size_t> path;
	path.push_back(graph.vertices[finish].id);
	size_t index = finish;
	while(index != start)
	{
		path.push_back(graph.vertices[index].from);
		index = graph.vertices[index].from;
	}
	std::reverse(path.begin(), path.end());
	return path;
}

void print_path(std::vector<size_t> path)
{
	for (auto&& node : path)
	{
		if (!(node == 3))
			std::cout << node << "->";
		else
			std::cout << node;

	}
}

void test_dijkstra()
{
	Vertice zero{ 0,
	{
			 {7, 1},
			 {9, 2},
			 {14, 5}
			}
	};
	Vertice one{ 1,
		{
				 {10, 2},
				 {15, 3}
				}
	};
	Vertice two{ 2,
		{
				 {2, 5},
				 {11, 3}
				}
	};
	Vertice three{ 3 };
	Vertice four{ 4,
		{{6, 3}}
	};
	Vertice five{ 5,
		{{9, 4}}
	};
	Graph graph{ {zero,one, two, three, four, five} };
	graph.Init();

	dijkstra(graph, 0);
	auto path = create_path(graph, 0, 3);
	print_path(path);
}