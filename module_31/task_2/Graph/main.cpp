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
    lst.AddEdge(3,0);

    ListGraph lst1(&lst);


    MatrixGraph mg;

    mg.AddEdge(0,1);
    mg.AddEdge(0,2);
    mg.AddEdge(5,1);
    mg.AddEdge(3,2);
    mg.AddEdge(2,4);

    ListGraph lst2;//(&mg);
    lst2 = lst;
    lst2 = mg;

    MatrixGraph mg1;//(&lst);
    mg1 = mg;
    mg1 = lst;



    cout << lst.VerticesCount() << endl;
    cout << lst1.VerticesCount() << endl;
    cout << mg.VerticesCount() << endl;

    std::vector<int> v;
//    lst1.GetNextVertices(2, v);
    lst1.GetPrevVertices(3, v);

    for(auto at : v)
        cout << at << " ";
    cout << endl;

    return 0;
}
