#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    void dfs(unordered_map<int, vector<int>>& mp,
             int start,
             unordered_set<int>& visited)
    {
        visited.insert(start);

        for(int i = 0; i < mp[start].size(); i++)
        {
            if(visited.find(mp[start][i]) == visited.end())
            {
                dfs(mp, mp[start][i], visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();

        unordered_set<int> visited;
        unordered_map<int, vector<int>> mp;

        int ans = 0;

        // Create adjacency list
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    mp[i].push_back(j);
                }
            }
        }

        // Count provinces
        for(auto i : mp)
        {
            int start = i.first;

            if(visited.find(start) == visited.end())
            {
                dfs(mp, start, visited);
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> isConnected =
    {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution solution;

    int answer = solution.findCircleNum(isConnected);

    cout << "Number of provinces: " << answer << endl;

    return 0;
}