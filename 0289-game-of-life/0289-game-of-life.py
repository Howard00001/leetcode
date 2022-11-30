class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        for i in range(len(board)):
            for j in range(len(board[0])):
                transform(board,i,j)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]==2:
                    board[i][j]=0
                if board[i][j]==3:
                    board[i][j]=1

def transform(board, i, j):
    dir = [-1,0,1,0,-1,-1,1,1,-1]
    count = 0
    for d in range(8):
        x = i+dir[d]
        y = j+dir[d+1]
        if x>=0 and y>=0 and x<len(board) and y<len(board[0]):
            if board[x][y]==1 or board[x][y]==2:
                count+=1
    if board[i][j]==0 and count==3:
        board[i][j] = 3
    if board[i][j]==1 and (count<2 or count>3):
        board[i][j] = 2