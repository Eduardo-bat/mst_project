#ifndef STATIC_MST_MTX_HPP
#define STATIC_MST_MTX_HPP

#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>

#include "size_def.h"

#define GRAPHS_DIR std::string("../graphs/")

int minKey(int key[V], bool mstSet[V]);
void initmtx(int mtx[V][V]);
void fillMSTmtx(int mst[V][V], int parent[V], int graph[V][V]);
int writetoFile(int mtx[V][V]);
int writeMSTtoFile(int parent[V], int graph[V][V]);
void initKeysMSTset(int key[V], bool mstSet[V]);
bool isedge(int graph[V][V], int u, int v);
bool isInSet(bool mstSet[V], int v);
bool costsLess(int graph[V][V], int u, int v, int key[V]);
void buildMST(int graph[V][V], int parent[V]);
void primMST(int graph[V][V], int parent[V]);
int readGraph(int graph[V][V], std::string filename);

#endif
