class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        std::unordered_set<int32_t> hsRow[9];
        std::unordered_set<int32_t> hsColumn[9];
        std::unordered_set<int32_t> hsBox[3][3];

        int32_t rowBox = 0;
        int32_t columnBox = 0;
        
        for(int32_t r = 0; r < board.size() ; ++r )
        {
            

            for(int32_t c = 0; c < board[r].size() ; ++c)
            {
                


                 if(hsRow[r].count(board[r][c]))
                     return false;
                 
                 if(board[r][c] != '.')
                    hsRow[r].insert(board[r][c]);

                  if(hsColumn[c].count(board[r][c]))
                  {
                    return false;
                  }
                      
                  if(board[r][c] != '.')
                    hsColumn[c].insert(board[r][c]);


                 if(hsBox[rowBox][columnBox].count(board[r][c]))
                     return false;

                if(board[r][c] != '.')
                    hsBox[rowBox][columnBox].insert(board[r][c]);

                 

                 if(!((c + 1 )% 3))
                     ++columnBox;




            }

            columnBox = 0;
            if(!((r + 1 )% 3))
                     ++rowBox;
        }

        return true;
    }
};
