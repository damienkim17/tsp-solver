# tsp-solver
Implements a solver in C++ to find the shortest cycle in a collection of n points on a plane that visits each vertext exactly once.

Solver uses smallest increase heuristic algorithm
- Input is a list of n >= 3 points
- Algorithm starts with the cycle consisting of first three points L[0], L[1], L[2]
- 1st iteration the algorithm takes L[3] and adds it to the current cycle in the location that minimizes the increase in length
- 2nd iteration the algorithm takes L[4] and adds it to the current cycle in the location that minimizes the increase in length
- And so on. When adding L[i], add it to the cycle between C[j] and C[j+1] so that dist(C[j],L[i]) + dist(L[i],C[j+1]) - dist(C[j+1],C[j]) is minimized
