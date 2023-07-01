#include <stdio.h>

#define BOARD_SIZE 15
#define MAX_PLAYERS 4
#define SCORE_LIMIT 100

#define EMPTY ' '
#define DOUBLE_LETTER '2'
#define TRIPLE_LETTER '3'
#define DOUBLE_WORD 'D'
#define TRIPLE_WORD 'T'

// Function to initialize the board with the starting configuration
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize all cells to empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Set the multipliers for specific cells
    // (you can define your own configuration here)
    board[3][0] = DOUBLE_WORD;
    board[11][0] = DOUBLE_WORD;
    board[6][2] = DOUBLE_LETTER;
    board[8][2] = DOUBLE_LETTER;
    // ... Add more multipliers as needed
}

// Function to place a tile on the board at the given coordinates
void placeTile(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char tile) {
    // Check if the coordinates are within the board's dimensions
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        // Check if the cell is empty
        if (board[row][col] == EMPTY) {
            // Place the tile on the board
            board[row][col] = tile;
        } else {
            printf("Invalid move: Cell is already occupied.\n");
        }
    } else {
        printf("Invalid move: Coordinates are out of bounds.\n");
    }
}

// Function to calculate the score for a given word
int calculateScore(const char* word) {
    int score = 0;
    // Assign point values to each letter based on Scrabble rules
    // (you can define your own point values here)
    for (int i = 0; word[i] != '\0'; i++) {
        switch (word[i]) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'L':
            case 'N':
            case 'R':
            case 'S':
            case 'T':
                score += 1;
                break;
            case 'D':
            case 'G':
                score += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
                break;
            // ... Assign scores for other letters
        }
    }
    return score;
}

// Function to determine the next player's turn
int getNextPlayer(int currentPlayer) {
    return (currentPlayer + 1) % MAX_PLAYERS;
}

// Function to check if the game has ended
int isGameEnd(int* playerScores) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (playerScores[i] >= SCORE_LIMIT) {
            return 1; // Game has ended
        }
    }
    return 0; // Game is not yet ended
}

// Function to print the board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create the empty board
    char board[BOARD_SIZE][BOARD_SIZE];

    // Initialize the board with the starting configuration
    initializeBoard(board);

    // Player scores
    int playerScores[MAX_PLAYERS] = {0};

    // Current player turn
    int currentPlayer = 0;

    // Game loop
    while (!isGameEnd(playerScores)) {
        // Print the board
        printf("Current Board:\n");
        printBoard(board);

        // Prompt the current player for a move
        int row, col;
        char tile;
        printf("Player %d, enter the row and column to place your tile: ", currentPlayer + 1);
        scanf("%d %d", &row, &col);
        printf("Enter the tile to place: ");
        scanf(" %c", &tile);

        // Place the tile on the board
        placeTile(board, row, col, tile);

        // Calculate the score for the placed word
        int wordScore = calculateScore(&tile);

        // Update the player's score
        playerScores[currentPlayer] += wordScore;

        // Switch to the next player's turn
        currentPlayer = getNextPlayer(currentPlayer);
    }

    // Game has ended, determine the winner
    int maxScore = playerScores[0];
    int winner = 0;
    for (int i = 1; i < MAX_PLAYERS; i++) {
        if (playerScores[i] > maxScore) {
            maxScore = playerScores[i];
            winner = i;
        }
    }

    // Print the final scores and declare the winner
    printf("Final Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: %d\n", i + 1, playerScores[i]);
    }
    printf("The winner is Player %d!\n", winner + 1);

    return 0;
}
