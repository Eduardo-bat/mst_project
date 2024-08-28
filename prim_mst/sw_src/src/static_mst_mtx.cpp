#include "static_mst_mtx.hpp"
#include "size_def.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>

int minKey(int key[V], bool mstSet[V])
{
	int min;
	int min_index;

	min = std::numeric_limits<int>::max();
	min_index = -1;

	for (int v = 0; v < V; v++) {
		if (mstSet[v] == false && key[v] < min) {
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}

void initmtx(int mtx[V][V])
{
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			mtx[i][j] = 0;
		}
	}
}

void fillMSTmtx(int mst[V][V], int parent[V], int graph[V][V])
{
	for (int i = 1; i < V; i++) {
		mst[parent[i]][i] = graph[i][parent[i]];
		mst[i][parent[i]] = graph[i][parent[i]];
	}
}

int writetoFile(int mtx[V][V])
{
	std::ofstream outputFile(GRAPHS_DIR + "mst.txt");

	if (!outputFile.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			outputFile << mtx[i][j] << " ";
		}
		outputFile << "\r\n";
	}

	outputFile.close();
	return 0;
}

int writeMSTtoFile(int parent[V], int graph[V][V])
{
	int mst[V][V];
	int writeok;

	initmtx(mst);
	fillMSTmtx(mst, parent, graph);
	writeok = writetoFile(mst);

	return writeok;
}

void initKeysandMSTset(int key[V], bool mstSet[V])
{
	for (int i = 0; i < V; i++) {
		key[i] = std::numeric_limits<int>::max();
		mstSet[i] = false;
	}
}

bool isedge(int graph[V][V], int u, int v)
{
	return graph[u][v] != 0;
}

bool isInSet(bool mstSet[V], int v)
{
	return mstSet[v];
}

bool costsLess(int graph[V][V], int u, int v, int key[V])
{
	return graph[u][v] < key[v];
}

void buildMST(int graph[V][V], int key[V], bool mstSet[V], int parent[V])
{
	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < V; v++) {
			if (isedge(graph, u, v) && not isInSet(mstSet, v) && costsLess(graph, u, v, key)) {
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
}

void primMST(int graph[V][V], int parent[V])
{
	int key[V];
	bool mstSet[V];

	initKeysandMSTset(key, mstSet);

	key[0] = 0;
	parent[0] = -1;

	buildMST(graph, key, mstSet, parent);
}

int readGraph(int graph[V][V], std::string filename)
{
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
	return 0;
}
