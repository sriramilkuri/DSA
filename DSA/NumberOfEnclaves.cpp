#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid, int i , int j, int& area, int& boundaryFound)
    {
       if(  (i < 0 || i > grid.size()-1 || j < 0 || j > grid[0].size()-1) || grid[i][j] == -1 || grid[i][j] == 0)
       {
        return ;
       }
       if(grid[i][j] == 1 and (i == 0 || i== grid.size()-1 || j == 0 || j == grid[0].size()-1))
       {
        boundaryFound = 1;
        return;
       }
       grid[i][j] = -1;
       area++;
       dfs(grid, i+1, j, area, boundaryFound);
       dfs(grid, i-1, j, area, boundaryFound);
       dfs(grid, i, j+1, area, boundaryFound);
       dfs(grid, i, j-1, area, boundaryFound);

       return;
    }
    int numEnclaves(vector<vector<int>>& grid) {      
        int n = grid.size();
        int ans = 0;
        for(int i =0; i< n;i++)
        {
            for(int j =0; j< grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = 0, boundaryFound = 0;
                    dfs(grid, i , j , area, boundaryFound);
                    if(!boundaryFound)ans += area;
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    Solution solution;
    int ans = solution.numEnclaves(grid);
    
    cout<<ans<<endl;
    return 0;
}