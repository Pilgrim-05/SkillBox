#include "matrixgraph.h"

MatrixGraph::MatrixGraph(){}

MatrixGraph::MatrixGraph(IGraph *oth)
{
    copyGraph(oth);
}

MatrixGraph::~MatrixGraph(){}

std::string MatrixGraph::getType(){ return TYPE;}

void MatrixGraph::copyGraph(IGraph *oth)
{
    if(oth->getType() == "Matrix")
    {
        MatrixGraph *tmp;
        std::cout << "Matrix in List" <<std::endl;
        grph.clear();
        tmp = (MatrixGraph*)oth;
        grph = tmp->grph;

    }else if(oth->getType() == "List")
    {
        ListGraph *tmp;
        std::cout << "List in List" <<std::endl;
        grph.clear();
        tmp = (ListGraph*)oth;
    }
}

void MatrixGraph::AddEdge(int from, int to){}

int MatrixGraph::VerticesCount() const { return grph.size();}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {}
