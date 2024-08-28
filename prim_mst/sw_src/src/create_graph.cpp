#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>

#include "include/size_def.h"

#define graphs_dir std::string("../graphs/")

int main() {
	int numNodes = V;

	// Create a random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	// Create a vector to store the graph matrix
	std::vector<std::vector<int>> graph(numNodes, std::vector<int>(numNodes));

	// Generate random edge weights and populate the graph matrix
	for (int i = 0; i < numNodes; ++i) {
		for (int j = i + 1; j < numNodes; ++j) {
			graph[i][j] = dist(gen);
			graph[j][i] = graph[i][j];
		}
	}

	// Write the graph matrix to a file
	std::ofstream outputFile(graphs_dir + "graph.txt");
	if (outputFile.is_open()) {
		for (int i = 0; i < numNodes; ++i) {
			for (int j = 0; j < numNodes; ++j) {
				outputFile << graph[i][j] << " ";
			}
			outputFile << "\r\n";
		}
		outputFile.close();
		std::cout << "Graph matrix has been written to the file." << std::endl;
	} else {
		std::cerr << "Unable to open the file for writing." << std::endl;
	}

	return 0;
}