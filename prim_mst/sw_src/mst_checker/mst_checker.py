class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def is_valid_spanning_tree(graph, spanning_tree, n):
    if len(spanning_tree) != n - 1:
        return False

    uf = UnionFind(n)
    for u, v, w in spanning_tree:
        if uf.find(u) == uf.find(v):
            return False
        uf.union(u, v)

    return True

def is_mst(graph, spanning_tree, n):
    if not is_valid_spanning_tree(graph, spanning_tree, n):
        return False

    for u, v, w in spanning_tree:
        uf = UnionFind(n)
        for x, y, z in spanning_tree:
            if (x, y) != (u, v) and (y, x) != (u, v):
                uf.union(x, y)

        min_edge = float('inf')
        for x, y, z in graph:
            if uf.find(x) != uf.find(y):
                min_edge = min(min_edge, z)

        if min_edge < w:
            return False

    return True

def validateChecker():
    examples = [
        {
            "graph": [
                (0, 1, 1),
                (0, 2, 2),
                (1, 2, 3),
                (1, 3, 4),
                (2, 3, 5)
            ],
            "spanning_tree": [
                (0, 1, 1),
                (0, 2, 2),
                (1, 3, 4)
            ],
            "expected": True
        },
        {
            "graph": [
                (0, 1, 1),
                (0, 3, 4),
                (1, 2, 2),
                (2, 3, 3),
                (1, 3, 5)
            ],
            "spanning_tree": [
                (0, 1, 1),
                (1, 2, 2),
                (2, 3, 3)
            ],
            "expected": True
        },
        {
            "graph": [
                (0, 1, 1),
                (0, 2, 2),
                (1, 2, 3),
                (1, 3, 4),
                (2, 3, 5)
            ],
            "spanning_tree": [
                (0, 1, 1),
                (1, 2, 3),
                (1, 3, 4)
            ],
            "expected": False
        },
        {
            "graph": [
                (0, 1, 1),
                (0, 3, 4),
                (1, 2, 2),
                (2, 3, 3),
                (1, 3, 5)
            ],
            "spanning_tree": [
                (0, 1, 1),
                (1, 3, 5),
                (2, 3, 3)
            ],
            "expected": False
        }
    ]

    print("Validate checker")
    for example in examples:
        graph = example["graph"]
        spanning_tree = example["spanning_tree"]
        expected = example["expected"]
        n = 4  # Number of vertices
        result = is_mst(graph, spanning_tree, n)
        print(f"Expected: {expected}, Got: {result}")
    print()

def checkFiles(graph_file, mst_file):
    # Read the graph adjacency matrix from graph.txt
    with open(graph_file, "r") as file:
        graph = []
        for line in file:
            row = list(map(int, line.strip().split()))
            graph.append(row)

    # Read the spanning tree adjacency matrix from mst.txt
    with open(mst_file, "r") as file:
        spanning_tree = []
        for line in file:
            row = list(map(int, line.strip().split()))
            spanning_tree.append(row)

    # Get the number of vertices
    n = len(graph)

    # Convert the adjacency matrix to edge list format
    graph_edges = []
    for i in range(n):
        for j in range(i+1, n):
            if graph[i][j] != 0:
                graph_edges.append((i, j, graph[i][j]))

    # Convert the spanning tree adjacency matrix to edge list format
    spanning_tree_edges = []
    for i in range(n):
        for j in range(i+1, n):
            if spanning_tree[i][j] != 0:
                spanning_tree_edges.append((i, j, spanning_tree[i][j]))

    # Check if the spanning tree is a minimum spanning tree
    result = is_mst(graph_edges, spanning_tree_edges, n)
    print(f"Is minimum spanning tree: {result}")
