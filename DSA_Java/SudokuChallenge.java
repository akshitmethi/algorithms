class SudokuChallenge {
    
    private char[] chars = new char[]{'1','2','3','4','5','6','7','8','9'};
    
    public boolean checkValidity(char[][] board, char value, int i, int j){
        //check rows
        for(int idx=0; idx<9;idx++){
            if(board[idx][j] == value || board[i][idx]==value)
                return false;
        }
        //check block
        int blockx = (i/3)*3;
        int blocky = (j/3)*3;
        
        for(int idx=0; idx<3; idx++){
            for(int idy=0;idy<3;idy++){
                if(board[blockx + idx][blocky+idy] == value)
                    return false;
            }
        }
        
        //after all checks return true
        return true;
    }
    
    public void solveSudoku(char[][] board) {
        solveSudoku(board,0,0);
    }
    
    private boolean solveSudoku(char[][] board, int posx, int posy){
        int i=posx,j=posy;
        while(i<9){
            while(j<9){
                if(board[i][j] == '.'){
                    for(char c : this.chars){
                        if(checkValidity(board,c,i,j)){
                            board[i][j] = c;
                            //backtracking if solution not found
                            if(solveSudoku(board,i,j))
                                return true;
                            else
                                board[i][j] ='.';
                        }
                    }
                    return false;
                }
                if(i == 8 && j==8)
                    return true;
                if(j==8){
                    i++;
                    j=0;
                    continue;
                }
                j++;
            }
        }
        return false;
    }
}