#include <iostream>

char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};


void Draw() {
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            std::cout << matrix[i][j] << " "; 
            
            }
        std::cout << std::endl;
        }
    } 

char CheckWinner() {
    // Diagonal check
    if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
        return matrix[0][0];
    if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])
        return matrix[0][2];
    // Vertical and horizontal check
    for (int i = 0; i<3; i++) {
        // Vertical check
        if (matrix[i][i] == matrix[i][(i+1)%3] && matrix[i][i] == matrix[i][(i+2)%3])
            return matrix[i][i];
        // Horizontal clock
        if (matrix[i][i] == matrix[(i+1)%3][i] && matrix[i][i] == matrix[(i+2)%3][i])
            return matrix[i][i];
        }
    
    std::cout << "No winner" << std::endl;
    return 'N';
    
    }
    
bool PlayerInput(char PlayerSign) {
    char move {'0'};
    std::cout << "Enter your move: ";
    std::cin >> move;
    
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            if (matrix[i][j] == move) {
                std::cout << "Valid move" << std::endl;
                matrix[i][j] = PlayerSign;
                return true;
                }
        }
    }
        
    std::cout << "Invalid move";
    return false;
    }

int main() {
    std::cout << "My TicTacToe Game" << std::endl;
    char current_player {'X'};
    bool running {true};
    
    while (running) {
        Draw();
        PlayerInput(current_player);
        
        if (current_player == 'X')
            current_player = 'O';
        else
            current_player = 'X';
        
        
        char winner = CheckWinner();
        
        if (winner == 'X' or winner == 'O') {
            Draw();
            std::cout << "WINNER: " << winner << std::endl;
            running = false;
        }
    }
    
    
    
    return 0;
}
