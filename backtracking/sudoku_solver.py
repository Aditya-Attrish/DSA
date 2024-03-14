def isSafe(row, col, num):
    global sudoku
    # check columns
    for i in range(9):
        if sudoku[row][i] == num:
            return False
        
    # check rows
    for i in range(9):
        if sudoku[i][col] == num:
            return False
    
    # check grid
    gr = (row//3)*3
    gc = (col//3)*3
    for i in range(gr, gr+3):
        for j in range(gc, gc+3):
            if sudoku[i][j] == num:
                return False
    
    return True

def helper(row, col):
    global sudoku
    if row == 8 and col == 9:
        return True
    
    if col == 9:
        row += 1
        col = 0
        
    if sudoku[row][col] != 0:
        return helper(row, col + 1)
    
    for num in range(1, 10):
        if isSafe(row, col, num):
            sudoku[row][col] = num
            if helper(row, col + 1):
                return True
            sudoku[row][col] = 0
    
    return False

if __name__ == "__main__":
    sudoku = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]
    if helper(0, 0):
        for row in sudoku:
            print(*row)
    else:
        print("Wrong Sudoku")
