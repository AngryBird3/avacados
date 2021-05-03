# avacados
Get those avacados

# Build
```
mkdir build
cd build
cmake ..
make -j12
```

# Unit test
Optionally running individual test binary:
```
../build/test/tests
```
unfortunately you need to run tests from test directory. I
didn't spend enough time to set resource dir for tests

# Implementation details
1. The first thing came to mind was to solve using BFS to walk to closest
neighbor till we collect all avacados. This is implemented in `shortest_path.cpp`.
2. Second thing I wanted to try to create highly connected graph
using important nodes (start and avacado nodes) and then narrow it down to variant of
Travelling Salesman Problem. I solved second part of this using modified Dijkstra and bitmask.
This is implemented in `shortest_path_astar.cpp` which uses `A*.cpp` to create graph
that I described before. I don't think this is efficient approach - it would be very slow as nodes
increased - as it has exponential complexity
3. I should have started out with namespace but I didn't and never got around
creating later on. So you might see some alias duplicated. :-/