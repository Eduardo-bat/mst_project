import subprocess

def readSizeDef(file):
    with open(file, "r") as f:
        for line in f:
            if "#define V" in line:
                return int(line.split()[2])

def changeSizeDef(file, size):
    with open(file, "w") as f:
        f.write(f"#define V {size}\r\n")

def make():
    subprocess.run(["make"], cwd=".")

def createGraph(file):
    subprocess.run([file], cwd="./app")

def computeMST(file):
    subprocess.run([file], cwd="./app")
    