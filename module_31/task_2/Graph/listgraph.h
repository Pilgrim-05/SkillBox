#pragma once
#include <string>
#include <map>
#include "igraph.h"
#include "matrixgraph.h"

class ListGraph : public IGraph
{
private:
    const std::string TYPE = "List";
    std::map<int, std::vector<int>> grph;
    void copyGraph(IGraph *oth);
public:
    ListGraph();

    ListGraph(IGraph *oth);

    virtual ~ListGraph();

    std::string getType();

    void AddEdge(int from, int to); // Метод принимает вершины начала и конца ребра и добавляет ребро

    int VerticesCount() const; // Метод должен считать текущее количество вершин

    void GetNextVertices(int vertex, std::vector<int> &vertices) const; // Для конкретной вершины метод выводит в вектор “вершины”
                                                                                    // все вершины, в которые можно дойти по ребру из данной

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const; // Для конкретной вершины метод выводит в вектор “вершины”
                                                                                    // все вершины, из которых можно дойти по ребру в данную
};
