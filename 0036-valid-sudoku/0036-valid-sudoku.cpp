class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int>row[9];
        set<int>col[9];
        set<int>boxes[9];
       int m=board.size();
       int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char c = board[i][j];
                if(c=='.'){
                   continue;
                }
                  int box = (i / 3) * 3 + (j / 3); 
                if(row[i].count(c)||col[j].count(c)||boxes[box].count(c)){
                    return false;
                }
                 row[i].insert(c);
                 col[j].insert(c);
                 boxes[box].insert(c);
            }
           
        }
        return true;
        
    }
};