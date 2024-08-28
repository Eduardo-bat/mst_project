import numpy as np

def createGraphAdjMatrix(file, vertices):
	adjacency_matrix = np.random.randint(0, 100, size=(vertices, vertices))
	adjacency_matrix = np.triu(adjacency_matrix) + np.triu(adjacency_matrix, 1).T

	np.savetxt(file, adjacency_matrix, fmt='%d', delimiter=' ')
