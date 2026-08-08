#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adjList(n); // {node,cost}
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adjList[u].push_back({v, cost});
        }
        vector<int> visited(n, INT_MAX);
        queue<pair<int, pair<int, int>>> pq; // {cost,{k,node}}
        pq.push({-1, {0, src}});
        visited[src] = 0;
        while (!pq.empty())
        {
            int cost = pq.front().second.first;
            int kk = pq.front().first;
            int node = pq.front().second.second;
            pq.pop();
            for (auto it : adjList[node])
            {
                if (cost + it.second < visited[it.first])
                {
                    if (kk < k)
                    {
                        visited[it.first] = cost + it.second;
                        pq.push({kk + 1, {cost + it.second, it.first}});
                    }
                }
            }
        }
        return visited[dst] == INT_MAX ? -1 : visited[dst];
    }
};
