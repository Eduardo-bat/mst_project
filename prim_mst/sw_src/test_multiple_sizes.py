import host

def test_size(size):
	return host.main(size)

if __name__ == "__main__":
	sizes = [10, 50, 100, 500, 1000]
	for size in sizes:
		print(f"Testing host.py with size {size}")
		if (not test_size(size)):
			print("Failed")
			break
