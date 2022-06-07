#pragma once
#include <string>
#include <map>
#include "igraph.h"
#include "matrixgraph.h"

class ListGraph : public IGraph
{
private:
    std::map<int, std::vector<int>> grph;

public:
    ListGraph();

    ListGraph(IGraph *oth);

    ListGraph& operator=(const ListGraph &oth);

    ListGraph& operator=(IGraph &oth);

    virtual ~ListGraph();

    void getLeaves(int vertex, std::vector<int> &leaves);

    void AddEdge(int from, int to); // Метод принимает вершины начала и конца ребра и добавляет ребро

    int VerticesCount() const; // Метод должен считать текущее количество вершин

    void GetNextVertices(int vertex, std::vector<int> &vertices) const; // Для конкретной вершины метод выводит в вектор “вершины”
                                                                                    // все вершины, в которые можно дойти по ребру из данной

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const; // Для конкретной вершины метод выводит в вектор “вершины”
                                                                                    // все вершины, из которых можно дойти по ребру в данную
};
