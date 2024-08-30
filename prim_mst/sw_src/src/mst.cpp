#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>

#include "static_mst_mtx.hpp"
#include "size_def.h"

int main()
{
	int graph[V][V];

	std::string graph_filepath = GRAPHS_DIR + "graph" + std::to_string(V) + ".txt";
	std::string mst_filepath	 = GRAPHS_DIR + "mst" + std::to_string(V) + ".txt";

	if (readGraph(graph, GRAPHS_DIR + graph_filepath) != 0) {
		std::cout << "Error reading graph" << std::endl;
		return 1;
	}

	std::size_t parent[V];

	primMST(graph, parent);

	if (writeMSTtoFile(parent, graph, mst_filepath) != 0) {
		std::cout << "Error writing MST" << std::endl;
		return 1;
	}

	return 0;
}
