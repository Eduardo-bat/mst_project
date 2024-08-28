#include <bits/stdc++.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <climits>
#include <string>

#include "include/size_def.h"

#define graphs_dir std::string("../graphs/")

int minKey(int key[V], bool mstSet[V])
{
	int min;
	int min_index;

	min = INT_MAX;
	min_index = -1;

	for (int v = 0; v < V; v++) {
		if (mstSet[v] == false && key[v] < min) {
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}

int writeMSTtoFile(int parent[V], int graph[V][V])
{
	int mst[V][V];

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			mst[i][j] = 0;
		}
	}

	for (int i = 1; i < V; i++) {
		mst[parent[i]][i] = graph[i][parent[i]];
		mst[i][parent[i]] = graph[i][parent[i]];
	}

	std::ofstream outputFile(graphs_dir + "mst.txt");

	if (!outputFile.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			outputFile << mst[i][j] << " ";
		}
		outputFile << "\r\n";
	}

	outputFile.close();
	return 0;
}

void primMST(int graph[V][V], int parent[V])
{
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < V; v++) {
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}

}

int main()
{
	int graph[V][V];

	std::string filename = "../graphs/graph.txt";
	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			inputFile >> graph[i][j];
		}
	}

	inputFile.close();

	int parent[V];

	primMST(graph, parent);

	writeMSTtoFile(parent, graph);

	return 0;
}
