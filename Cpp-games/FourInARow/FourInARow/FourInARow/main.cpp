#include <iostream>

#define width_field 7
#define height_field 6

char matrix[height_field][width_field] {};

void Draw() {
    for (int i = 0; i<height_field; i++) {
        for (int j = 0; j<width_field; j++) {
            std::cout << matrix[i][j] << " ";
            
            }
        std::cout << std::endl;
        }
    
    for (int k = 1; k<width_field+1; k++) {
        std::cout << k << " ";
        }
    
    }
    
void InitializeMatrix() {
    for (int i = 0; i<height_field; i++) {
        for (int j = 0; j<width_field; j++) {
            matrix[i][j] = '|';
            }
        }
    }
    
bool PlayerInput(char current_player) {
    int move {0};
    std::cout << std::endl;
    std::cout << current_player << " enter your move: ";
    std::cin >> move;
    
    for (int i = height_field; i>=0; i--) {
        if (matrix[i][move-1] == '|') {
            matrix[i][move-1] = current_player;
            std::cout << "VALID MOVE" << std::endl;
            return true;
            }
        
        }
    
    std::cout << "INVALID MOVE";
    return false;
    }
    
char CheckWinner() {
    // Vertical check
    for (int j = 0; j<width_field; j++) {
        for (int i=0; i<height_field-4; i++) {
            if (matrix[i][j] == matrix[i+1][j] && matrix[i][j] == matrix[i+2][j] && matrix[i][j] == matrix[i+3][j] && matrix[i][j] != '|')
                return matrix[i][j];
            }
        }
    // Horizontal check
    for (int i = 0; i<height_field; i++) {
        for (int j=0; j<width_field-4; j++) {
            if (matrix[i][j] == matrix[i][j+1] && matrix[i][j] == matrix[i][j+2] && matrix[i][j] == matrix[i][j+3] && matrix[i][j] != '|')
                return matrix[i][j];
            }
        }
        
    //Descending Diagonal check
    for (int j=0; j<width_field-3; j++) {
        for (int i=0; i<height_field-3; i++) {
            if (matrix[i][j] == matrix[i+1][j+1] && matrix[i][j] == matrix[i+2][j+2] && matrix[i][j] == matrix[i+3][j+3] && matrix[i][j] != '|')
                return matrix[i][j];
            }
        }
    
    //Ascending Diagonal check
    for (int j=3; j<width_field; j++) {
        for (int i=0; i<height_field-3; i++) {
            if (matrix[i][j] == matrix[i+1][j-1] && matrix[i][j] == matrix[i+2][j-2] && matrix[i][j] == matrix[i+3][j-3] && matrix[i][j] != '|')
                return matrix[i][j];
            }
        }
    
    return 'N';
    }


int main() {
    std::cout << "My Four-in-a-Row Game" << std::endl;
    char current_player {'X'};
    bool running {true};
    
    InitializeMatrix();
    
    while (running) {
        // Draw the playing field
        Draw();
        
        // Loop until user inputs a valid move
        while (PlayerInput(current_player) != true)
            ;
        
        // Change player
        if (current_player == 'X')
            current_player = 'O';
        else
            current_player = 'X';
        
        // Determine if someone has won
        char winner = CheckWinner();
        
        if (winner == 'X' or winner == 'O') {
            Draw();
            std::cout << std::endl;
            std::cout << "WINNER: " << winner << std::endl;
            running = false;
        }
        
    }
    
    
    return 0;
}
