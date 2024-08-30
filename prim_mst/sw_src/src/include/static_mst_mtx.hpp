#ifndef STATIC_MST_MTX_HPP
#define STATIC_MST_MTX_HPP

#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>

#include "size_def.h"

#define GRAPHS_DIR std::string("../graphs/")

std::size_t minKey(int key[V], bool mstSet[V]);
void initmtx(int mtx[V][V]);
void fillMSTmtx(int mst[V][V], std::size_t parent[V], int graph[V][V]);
int writetoFile(int mtx[V][V], std::string filepath);
int writeMSTtoFile(std::size_t parent[V], int graph[V][V], std::string filepath);
void initKeysMSTset(int key[V], bool mstSet[V]);
bool isedge(int graph[V][V], std::size_t u, std::size_t v);
bool isInSet(bool mstSet[V], std::size_t v);
bool costsLess(int graph[V][V], std::size_t u, std::size_t v, int key[V]);
void buildMST(int graph[V][V], std::size_t parent[V]);
void primMST(int graph[V][V], std::size_t parent[V]);
int readGraph(int graph[V][V], std::string filepath);

#endif
