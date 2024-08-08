class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        // 0 -> right, 1 -> down, 2 -> left, 3 -> up
        int cnt = 0, dir = 0, reqSteps = 1, curSteps = 0, useless = 0;
        pair<int,int>curCell = {rStart, cStart};
        vector<vector<int>>ans;
        ans.push_back({rStart, cStart});

        while( true )
        {
            if( dir == 0 )
                curCell = {curCell.first, curCell.second + 1};

            if( dir == 1 )
                curCell = {curCell.first + 1, curCell.second};

            if( dir == 2 )
                curCell = {curCell.first, curCell.second - 1};

            if( dir == 3 )
                curCell = {curCell.first - 1, curCell.second};

            cout << curCell.first << ' ' << curCell.second << endl;
            curSteps++;

            if( curSteps == reqSteps )
                cnt++, curSteps = 0, dir++;

            if( dir == 4 )
                dir = 0;

            if( cnt == 2 )
                cnt = 0, reqSteps++;

            if( curCell.first < rows && curCell.first >= 0 && curCell.second >= 0 && curCell.second < cols )
                useless = 0, ans.push_back({curCell.first, curCell.second});
            else
                useless++;

            if( useless == 8e2 )
                break;
        }

        return ans;
}
};