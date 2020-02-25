class Solution {
private:
    int islCnt;
    void processIsland(vector<vector<char>>& grid, int i, int j) {
        if( grid[i][j] == '0' ) return;
        else grid[i][j] = '0';

        if( j != 0 )
            processIsland( grid, i, j-1 );
        if( j != grid[i].size()-1 )
            processIsland( grid, i, j+1 );
        if( i != 0)
            processIsland( grid, i-1, j );
        if( i != grid.size()-1 )
            processIsland( grid, i+1, j );
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int i = 0, j = 0;
        islCnt = 0;
        for( i=0; i<grid.size(); i++ ) {
            for( j=0; j<grid[i].size(); j++ ) {
                if( grid[i][j] == '1' ) {
                    islCnt++;
                    processIsland( grid, i, j );
                }
                else continue;
            }
        }
        return islCnt;
    }
};
