#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    string city;
    vector<string> nbrs;

    Node(string city)
    {
        this->city = city;
    }
};

class Graphs
{

public:
    unordered_map<string, Node *> mp;

    Graphs(vector<string> cities)
    {
        for (int i = 0; i < cities.size(); i++)
        {
            mp[cities[i]] = new Node(cities[i]);
        }
    }

    void addEdge(string x, string y, bool undir = true)
    {
        mp[x]->nbrs.push_back(y);
        if (undir)
        {
            mp[y]->nbrs.push_back(x);
        }
    }

    void printEdges()
    {
        for (auto city : mp)
        {
            string mainCity = city.first;
            Node *neighbours = city.second;
            cout << " " << neighbours->city << "-->";
            for (auto nbr : neighbours->nbrs)
            {
                cout << " " << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<string> cities = {"Banglore", "Dehli", "Patna", "Lucknow", "Aurangabad"};
    Graphs g(cities);
    g.addEdge("Banglore", "Dehli");
    g.addEdge("Aurangabad", "Dehli");
    g.addEdge("Dehli", "Patna");
    g.addEdge("Lucknow", "Dehli");
    g.addEdge("Patna", "Aurangabad");
    g.printEdges();
}