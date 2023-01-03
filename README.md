# Projeto 2

Compilation: `g++ -std=c++11 -O3 -Wall main.cpp -lm -o main`

Usage: `./main`

Input:
- Line 1: number of vertices (V >= 1).
- Line 2: number of edges (E >= 0).
- Line 3..(E+2): two vertices and a weight (u, v and w), representing an edge.

Each vertice is represented by an integer between 1 and V.
The weight of an edge is also represented by an integer (w >= 0).

### Dense Graph Generator

The program dgg.c generates dense graphs given a number of vertices (useful for testing).

Compilation: `gcc -O3 -Wall -o dgg dgg.c`

Usage: `./dgg <num_of_vertices> > <test>`

### Delaunay Triangulation

The program delaunay2graph.cpp generates a graph using Delaunay Triangulation with some random parameters (useful for testing).

Compilation: `g++ -std=c++11 -O3 -o d2g delaunay2graph.cpp -lm`

Usage: `./d2g <num_of_vertices> <max_coord> <probability> <seed> > <test>`

### Graph

The provided performance graph was generated by following these steps:
1. Use dgg.c to generate some tests with dense graphs (you can find them inside tests.zip).
2. Install and run hyperfine to get some results and export them to a graph.json file.
3. Execute plot_whisker.py to convert the results from graph.json to a proper graph (int png format).

You can learn more about hyperfine and plot_whisker.py [here](https://github.com/sharkdp/hyperfine).
