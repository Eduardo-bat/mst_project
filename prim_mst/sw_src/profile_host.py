import cProfile
import pstats
import host

def profile_host(size):
    profiler = cProfile.Profile(subcalls=False, builtins=False)
    profiler.enable()
    host.main(size)
    profiler.disable()
    stats = pstats.Stats(profiler).strip_dirs().sort_stats('cumtime')
    stats.print_stats('createGraphAdjMatrix')
    stats.print_stats('computeMST')
    stats.print_stats('checkFiles')

if __name__ == "__main__":
    sizes = [10, 50, 100, 500, 1000, 5000]
    for size in sizes:
        print(f"Profiling host.py with size {size}")
        profile_host(size)
        