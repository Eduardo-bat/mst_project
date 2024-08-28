#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>

#include "static_mst_mtx.hpp"
#include "size_def.h"

int main()
{
	int graph[V][V];

	if (readGraph(graph, GRAPHS_DIR + "graph.txt") != 0) {
		std::cout << "Error reading graph" << std::endl;
		return 1;
	}

	int parent[V];

	primMST(graph, parent);

	if (writeMSTtoFile(parent, graph) != 0) {
		std::cout << "Error writing MST" << std::endl;
		return 1;
	}

	return 0;
}
