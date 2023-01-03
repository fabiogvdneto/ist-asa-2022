# Projeto de Análise e Síntese de Algoritmos 2022-2023

Este repositório alberta os projetos realizados por mim no âmbito da cadeira de Análise e Síntese
de Algoritmos (ASA) do Instituto Superior Técnico (IST) dirigida pelo professor Luís Guerra e Silva.

O repositório foi dividido em duas branches, uma para cada um dos projetos.

### Compilation

`g++ -std=c++11 -O3 -Wall file.cpp -lm`

### DGG

Dense Graph Generator.
Compilation: `gcc -O3 -Wall -o dgg dgg.c`
Usage: `./dgg <num_of_vertices> > <test>`

### delaunay2graph

Generates a graph using Delaunay triangulation with some random parameters
Compilation: `g++ -std=c++11 -O3 -o d2g delaunay2graph.cpp -lm`
Usage: `./d2g <num_of_vertices> <max_coord> <probability> <seed> > <test>`

### Hyperfine

`hyperfine --export-json graph.json --runs 20 --parameter-list TEST tests/d200.txt,tests/d400.txt,tests/d600.txt,tests/d800.txt,tests/d1000.txt,tests/d1200.txt,tests/d1400.txt,tests/d1600.txt,tests/d1800.txt,tests/d2000.txt './a.out < {TEST}'`