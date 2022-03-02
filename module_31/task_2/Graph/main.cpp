#include <iostream>
#include "igraph.h"
#include "listgraph.h"
#include "matrixgraph.h"

using std::cout;
using std::endl;

int main()
{
    ListGraph lst(new ListGraph);
    ListGraph lst1(new MatrixGraph);

    lst.AddEdge(0,1);
    lst.AddEdge(0,2);
    lst.AddEdge(1,2);
    std::vector<int> v;
    lst.GetNextVertices(5, v);

    std::cout << lst.VerticesCount() << std::endl;

    MatrixGraph mtrx(new ListGraph);
    MatrixGraph mtrx1(new MatrixGraph);

    return 0;
}
