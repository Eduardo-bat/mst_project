from mst_checker.mst_checker import checkFiles
from make_and_run.make_and_run import *
from graph_creator.graph_creator import createGraphAdjMatrix
import sys

def main(size=None):
    if size is None:
        if len(sys.argv) > 1:
            size = int(sys.argv[1])
        else:
            print("Usage: python3 host.py <size>")
            return 1

    if(readSizeDef("./src/include/size_def.h") != size):
        changeSizeDef("./src/include/size_def.h", size)

    make()

    createGraphAdjMatrix("./graphs/graph.txt", size)
    computeMST("./mst")

    checkFiles("./graphs/graph.txt", "./graphs/mst.txt")

if __name__ == "__main__":
    arg = int(sys.argv[1]) if len(sys.argv) > 1 else None
    main(arg)
