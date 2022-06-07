#include "matrixgraph.h"

MatrixGraph::MatrixGraph(){}

MatrixGraph::MatrixGraph(IGraph *oth)
{
    MatrixGraph *tmpMatrix = dynamic_cast<MatrixGraph*>(oth);
    if(tmpMatrix)
    {        
        grph = tmpMatrix->grph;
    }

    ListGraph *tmpList = dynamic_cast<ListGraph*>(oth);
    if(tmpList)
    {
        int size = tmpList->VerticesCount();
        grph.resize(size);
        for(int i = 0; i <= size; ++i)
        {
            grph[i].resize(size);
            std::vector<int> v;
            tmpList->getLeaves(i, v);
            for(auto at : v)
            {
                grph[i][at] = 1;
            }
        }
    }
}

MatrixGraph &MatrixGraph::operator=(const MatrixGraph &oth)
{
    if(this != &oth)
    {
        grph.clear();
        grph = oth.grph;
    }
   return *this;
}

MatrixGraph &MatrixGraph::operator=(IGraph &oth)
{
    ListGraph *tmpList = dynamic_cast<ListGraph*>(&oth);
    if(tmpList)
    {
        if(tmpList->VerticesCount() != 0)
        {
            int size = tmpList->VerticesCount();
            grph.clear();
            grph.resize(size);
            for(int i = 0; i <= size; ++i)
            {
                grph[i].resize(size);
                std::vector<int> v;
                tmpList->getLeaves(i, v);
                for(auto at : v)
                {
                    grph[i][at] = 1;
                }
            }
        }
    }

    return *this;
}

MatrixGraph::~MatrixGraph(){}

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
