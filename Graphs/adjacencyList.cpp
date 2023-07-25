#include <iostream>
#include <list>

using namespace std;

/**
 * l[o] = [1]=>[2]=>[3];
 * l[1]=[2]=>[3];
 */

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            // every element of linked list;
            cout << i << "-->";
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.printAdjList();

        /* Graph g(6);
    g.addEdge(10, 11);
    g.addEdge(10, 14);
    g.addEdge(12, 11);
    g.addEdge(13, 14);
    g.addEdge(14, 15);
    g.addEdge(12, 13);
    g.addEdge(13, 15);
    g.printAdjList(); */
    return 0;
}