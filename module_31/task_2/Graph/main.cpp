#include <iostream>
#include "igraph.h"
#include "listgraph.h"
#include "matrixgraph.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    ListGraph lst;
    lst.AddEdge(0,1);
    lst.AddEdge(0,2);
    lst.AddEdge(1,2);
    lst.AddEdge(1,3);

    ListGraph lst1(lst);

    cout << lst.VerticesCount() << endl;
    cout << lst1.VerticesCount() << endl;

    std::vector<int> v;
    lst1.GetNextVertices(1, v);

//    lst1.GetPrevVertices(1, v);

    for(auto at : v)
        cout << at << " ";
    cout << endl;

//    MatrixGraph mtrx(new ListGraph);
//    MatrixGraph mtrx1(new MatrixGraph);

    return 0;
}
