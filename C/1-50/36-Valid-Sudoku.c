/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'
 * Created by supercoderx on 2017/8/12.
 */

#include "../main.h"
#include <stdio.h>

bool isValidSudoku(char **board, int boardRowSize, int boardColSize) {
    // 行
    for (int k = 0; k < boardColSize; ++k) {
        for (int i = 0; i < boardRowSize - 1; i++) {
            if (board[k][i] == '.')
                continue;
            if (board[k][i] <= 0x30 || board[k][i] > 0x39)
                return false;
            for (int j = i + 1; j < boardRowSize; j++) {
                if (board[k][j] == '.')
                    continue;
                if (board[k][j] <= 0x30 || board[k][j] > 0x39)
                    return false;
                if (board[k][j] == board[k][i])
                    return false;
            }
        }
    }

    // 列
    for (int k = 0; k < boardRowSize; k++) {
        for (int i = 0; i < boardRowSize - 1; ++i) {
            if (board[i][k] == '.')
                continue;
            if (board[i][k] <= 0x30 || board[i][k] > 0x39)
                return false;
            for (int j = i + 1; j < boardRowSize; ++j) {
                if (board[j][k] == '.')
                    continue;
                if (board[j][k] <= 0x30 || board[j][k] > 0x39)
                    return false;
                if (board[i][k] == board[j][k])
                    return false;
            }
        }
    }

    // 格子
    int start = 0;
    for (int x = 0; x < boardRowSize; x += 3) {
        for (int y = 0; y < boardColSize; y += 3) {
            for (int i = 0; i < boardRowSize / 3; ++i) {
                for (int j = 0; j < boardColSize / 3; ++j) {
                    if (board[i + x][j + y] == '.')
                        continue;
                    for (int q = j + 1; q < boardRowSize / 3; q++)
                        if (board[i + x][q + y] == board[i + x][j + y])
                            return false;
                    for (int p = i + 1; p < boardRowSize / 3; p++)
                        for (int q = 0; q < boardColSize / 3; ++q) {
                            if (board[x + p][y + q] == board[i + x][j + y])
                                return false;
                        }
                }
            }
        }
    }
    return true;
}

void testIsValidSudoku() {
    char *sudoku[9] = {"....5..1.", ".4.3.....", ".....3..1", "8......2.", "..2.7....", ".15......", ".....2...",
                       ".2.9.....", "..4......"};
    printf("%d", isValidSudoku(sudoku, 9, 9));
}