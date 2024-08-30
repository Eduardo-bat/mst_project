from mst_checker.mst_checker import checkFiles
from make_and_run.make_and_run import *
from graph_creator.graph_creator import createGraphAdjMatrix
import sys
import os

def main(size=None):
	if size is None:
		print("Usage: python3 host.py <size>")
		return 1

	if(readSizeDef("./src/include/size_def.h") != size):
		changeSizeDef("./src/include/size_def.h", size)

	executable_name = f"./mst{size}"

	make(executable_name)

	graph_file_name = "./graphs/graph" + str(size) + ".txt"
	mst_file_name		= "./graphs/mst" + str(size) + ".txt"

	createGraphAdjMatrix(graph_file_name, size)
	computeMST(executable_name)

	return checkFiles(graph_file_name, mst_file_name)

if __name__ == "__main__":
	arg = int(sys.argv[1]) if len(sys.argv) > 1 else None
	main(arg)
