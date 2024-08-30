import subprocess

def readSizeDef(file):
  with open(file, "r") as f:
    for line in f:
      if "#define V" in line:
        return int(line.split()[2])

def changeSizeDef(file, size):
  with open(file, "r") as f:
    lines = f.readlines()
  with open(file, "w") as f:
    for line in lines:
      if "#define V" in line:
        f.write(f"#define V {size}\n")
      else:
        f.write(line)

def make(name):
	subprocess.run(["make", f"BIN_NAME={name}"], cwd=".")

def computeMST(file):
  subprocess.run([file], cwd="./bin")
  