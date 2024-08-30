#include "static_mst_mtx.hpp"
#include "size_def.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>

std::size_t minKey(int key[V], bool mstSet[V])
{
	int min;
	std::size_t min_index;

	min = std::numeric_limits<int>::max();
	min_index = -1;

	for (std::size_t v = 0; v < V; v++) {
		if (mstSet[v] == false && key[v] < min) {
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}

void initmtx(int mtx[V][V])
{
	for (std::size_t i = 0; i < V; i++) {
		for (std::size_t j = 0; j < V; j++) {
			mtx[i][j] = 0;
		}
	}
}

void fillMSTmtx(int mst[V][V], std::size_t parent[V], int graph[V][V])
{
	for (std::size_t i = 1; i < V; i++) {
		mst[parent[i]][i] = graph[i][parent[i]];
		mst[i][parent[i]] = graph[i][parent[i]];
	}
}

int writetoFile(int mtx[V][V], std::string filepath)
{
	std::ofstream outputFile(filepath);

	if (!outputFile.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	for (std::size_t i = 0; i < V; i++) {
		for (std::size_t j = 0; j < V; j++) {
			outputFile << mtx[i][j] << " ";
		}
		outputFile << "\r\n";
	}

	outputFile.close();
	return 0;
}

int writeMSTtoFile(std::size_t parent[V], int graph[V][V], std::string filepath)
{
	int mst[V][V];
	int writeok;

	initmtx(mst);
	fillMSTmtx(mst, parent, graph);
	writeok = writetoFile(mst, filepath);

	return writeok;
}

void initKeysandMSTset(int key[V], bool mstSet[V])
{
	for (std::size_t i = 0; i < V; i++) {
		key[i] = std::numeric_limits<int>::max();
		mstSet[i] = false;
	}
}

bool isedge(int graph[V][V], std::size_t u, std::size_t v)
{
	return graph[u][v] != 0;
}

bool isInSet(bool mstSet[V], std::size_t v)
{
	return mstSet[v];
}

bool costsLess(int graph[V][V], std::size_t u, std::size_t v, int key[V])
{
	return graph[u][v] < key[v];
}

void buildMST(int graph[V][V], int key[V], bool mstSet[V], std::size_t parent[V])
{
	for (std::size_t count = 0; count < V - 1; count++) {
		std::size_t u = minKey(key, mstSet);
		mstSet[u] = true;

		for (std::size_t v = 0; v < V; v++) {
			if (isedge(graph, u, v) && not isInSet(mstSet, v) && costsLess(graph, u, v, key)) {
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
}

void primMST(int graph[V][V], std::size_t parent[V])
{
	int key[V];
	bool mstSet[V];

	initKeysandMSTset(key, mstSet);

	key[0] = 0;
	parent[0] = -1;

	buildMST(graph, key, mstSet, parent);
}

int readGraph(int graph[V][V], std::string filepath)
{
	std::ifstream inputFile(filepath);

	if (!inputFile.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	for (std::size_t i = 0; i < V; i++) {
		for (std::size_t j = 0; j < V; j++) {
			inputFile >> graph[i][j];
		}
	}

	inputFile.close();
	return 0;
}
