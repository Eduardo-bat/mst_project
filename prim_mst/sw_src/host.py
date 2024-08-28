from mst_checker.mst_checker import checkFiles
from make_and_run.make_and_run import *
import sys

def main():
    size = -1

    if len(sys.argv) > 1:
        size = int(sys.argv[1])
    else:
        print("Usage: python3 host.py <size>")
        return 1

    if(readSizeDef("./src/include/size_def.h") != size):
        changeSizeDef("./src/include/size_def.h", size)

    make()

    createGraph("./create_graph.exe")
    computeMST("./prim_mst.exe")

    checkFiles("./graphs/graph.txt", "./graphs/mst.txt")

if __name__ == "__main__":
    main()