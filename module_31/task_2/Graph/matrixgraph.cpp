#include "matrixgraph.h"

MatrixGraph::MatrixGraph(){}

MatrixGraph::MatrixGraph(IGraph *oth)
{
    if(oth->getType() == "Matrix")
    {
        MatrixGraph *tmp = static_cast<MatrixGraph*>(oth);
        grph = tmp->grph;

    }else if(oth->getType() == "List")
    {
        ListGraph *tmp = static_cast<ListGraph*>(oth);
        int size = tmp->VerticesCount();

        grph.resize(size);
        for(int i = 0; i <= size; ++i)
        {
            grph[i].resize(size);
            std::vector<int> v;
            tmp->getLeaves(i, v);
            for(auto at : v)
            {
                grph[i][at] = 1;
            }
        }
    }
}

MatrixGraph &MatrixGraph::operator=(IGraph &oth)
{
    if(oth.getType() == "Matrix")
    {
        if(this != &oth)
        {
            grph.clear();
            MatrixGraph *tmp = static_cast<MatrixGraph*>(&oth);
            grph = tmp->grph;
        }

    }else if(oth.getType() == "List")
    {
        ListGraph *tmp = static_cast<ListGraph*>(&oth);
        int size = tmp->VerticesCount();
        grph.clear();
        grph.resize(size);
        for(int i = 0; i <= size; ++i)
        {
            grph[i].resize(size);
            std::vector<int> v;
            tmp->getLeaves(i, v);
            for(auto at : v)
            {
                grph[i][at] = 1;
            }
        }
    }

    return *this;
}

MatrixGraph::~MatrixGraph(){}

std::string MatrixGraph::getType(){ return TYPE;}

void MatrixGraph::getLeaves(int vertex, std::vector<int> &leaves)
{
    if(grph.size() >= vertex)
    {
        for(int i = 0; i < grph.size(); ++i)
        {
            if(grph[vertex][i] != 0)
                leaves.push_back(i);
        }
    }

}

void MatrixGraph::AddEdge(int from, int to)
{
    int max = from > to ? from : to;

    if(grph.size() <= max)
    {
        grph.resize(max+1);
        for(int i = 0; i <= max; ++i)
        {
            grph[i].resize(max+1);
        }
    }

    grph[from][to] = 1;

}

int MatrixGraph::VerticesCount() const { return grph.size();}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {}
