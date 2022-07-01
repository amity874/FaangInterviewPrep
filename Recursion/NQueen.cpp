class Solution {
public:
    vector<vector<string>> res; 
bool isSafe(vector<string> &chess, int row, int col)
{
    for(int i=row-1, j=col; i>=0; i--)
    {
        if(chess[i][j]=='Q')
            return false;
    }
    
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
    {
        if(chess[i][j]=='Q')
            return false;
    }
    
    for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--, j++)
    {
        if(chess[i][j]=='Q')
            return false;
    }
    return true;
}

void NQueen(vector<string> &chess, int row)
{
    if(row==chess.size())
    {
        res.push_back(chess);
        return;
    }
    
    for(int col=0; col<chess.size(); col++)
    {
        if(isSafe(chess, row, col))
        {
            chess[row][col] = 'Q';
            NQueen(chess, row+1);
            chess[row][col] = '.';
        }
    }
}


vector<vector<string>> solveNQueens(int n) {
    if(n<=0)
        return{{}};
    vector<string> chess(n,string(n,'.'));
    NQueen(chess,0);
    return res;
}
};