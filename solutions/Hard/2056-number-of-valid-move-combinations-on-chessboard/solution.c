// ──────────────────────────────────────────────────
// Problem  : 2056. Number of Valid Move Combinations On Chessboard
// Difficulty: Hard
// Tags     : Array, String, Backtracking, Simulation
// Link     : https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8584000 (beats 0%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <string.h>

int directions[8][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

typedef struct {
    int r, c;
    int dr, dc;
    int steps;
} PieceMove;

PieceMove pieceMoves[4][64];
int pieceMovesCount[4];
PieceMove currentCombo[4];
int totalPieces;

bool isValidCombination() {
    int maxSteps = 0;
    for (int i = 0; i < totalPieces; i++) {
        if (currentCombo[i].steps > maxSteps) {
            maxSteps = currentCombo[i].steps;
        }
    }

    for (int t = 0; t <= maxSteps; t++) {
        for (int i = 0; i < totalPieces; i++) {
            int stepI = (t < currentCombo[i].steps) ? t : currentCombo[i].steps;
            int rI = currentCombo[i].r + stepI * currentCombo[i].dr;
            int cI = currentCombo[i].c + stepI * currentCombo[i].dc;

            for (int j = i + 1; j < totalPieces; j++) {
                int stepJ = (t < currentCombo[j].steps) ? t : currentCombo[j].steps;
                int rJ = currentCombo[j].r + stepJ * currentCombo[j].dr;
                int cJ = currentCombo[j].c + stepJ * currentCombo[j].dc;

                if (rI == rJ && cI == cJ) {
                    return false;
                }
            }
        }
    }
    return true;
}

int generateAndCheck(int idx) {
    if (idx == totalPieces) {
        return isValidCombination() ? 1 : 0;
    }

    int count = 0;
    for (int i = 0; i < pieceMovesCount[idx]; i++) {
        currentCombo[idx] = pieceMoves[idx][i];
        count += generateAndCheck(idx + 1);
    }
    return count;
}

int countCombinations(char** pieces, int piecesSize, int** positions, int positionsSize, int* positionsColSize) {
    totalPieces = piecesSize;

    for (int i = 0; i < piecesSize; i++) {
        pieceMovesCount[i] = 0;
        int r = positions[i][0];
        int c = positions[i][1];

        pieceMoves[i][pieceMovesCount[i]++] = (PieceMove){r, c, 0, 0, 0};

        int startDir = 0, endDir = 8;
        if (strcmp(pieces[i], "rook") == 0) {
            endDir = 4;
        } else if (strcmp(pieces[i], "bishop") == 0) {
            startDir = 4;
        }

        for (int d = startDir; d < endDir; d++) {
            int dr = directions[d][0];
            int dc = directions[d][1];
            int step = 1;

            while (1) {
                int nr = r + dr * step;
                int nc = c + dc * step;

                if (nr < 1 || nr > 8 || nc < 1 || nc > 8) {
                    break;
                }

                pieceMoves[i][pieceMovesCount[i]++] = (PieceMove){r, c, dr, dc, step};
                step++;
            }
        }
    }

    return generateAndCheck(0);
}