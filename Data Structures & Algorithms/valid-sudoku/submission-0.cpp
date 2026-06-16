class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

    int32_t a = 1;
    int32_t b = 1;

    std::vector<std::unordered_set<int8_t> > rowDupilcate(board.size());
    std::vector<std::unordered_set<int8_t> > columnDupilcate(board[0].size());


    std::vector< std::vector<std::unordered_set<int8_t>> > boxDupilcate(board.size()/3, std::vector<std::unordered_set<int8_t>>(board[0].size()/3));



    for (int32_t i = 1; i <= board.size(); ++i)
    {
        

        for (int32_t j = 1; j <= board[i-1].size(); ++j)
        {
            if ((board[i - 1][j - 1] != '.') && rowDupilcate[i - 1].contains(board[i - 1][j - 1]))
                return false;
            else
                rowDupilcate[i - 1].insert(board[i - 1][j - 1]);



            if ((board[i - 1][j - 1] != '.') && columnDupilcate[j - 1].contains(board[i - 1][j - 1]))
                return false;
            else
                columnDupilcate[j - 1].insert(board[i - 1][j - 1]);



            if ((board[i - 1][j - 1] != '.') && boxDupilcate[a - 1][b -1].contains(board[i - 1][j - 1]))
                return false;
            else
                boxDupilcate[a - 1][b - 1].insert(board[i - 1][j - 1]);


           

            if (((j % 3) == 0) && (j != 9))
                ++b;




            //std::cout << board[i - 1][j - 1] << std::endl;

        }


        if (((i % 3) == 0) && (i != 9))
            ++a;


        b = 1;
    }

    a = 1;

    return true;
}
};
