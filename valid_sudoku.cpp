class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            for (int i = 0; i < board.size(); i++){ //se crea un ciclo para recorrer el tablero pero solo se recorre los vectores externos
                unordered_set<char> fila, columna, cuadrado; //se crean 3 unordered_set para guardar los valores de las filas, columnas y cuadrados
                for (int j = 0; j < board[i].size(); j++){ // se crea un ciclo para recorrer los vectores internos
                    for (int c = 1; c <= 3; c++){ // se crea un ciclo para recorrer los 3 casos posibles
                        switch(c) {
                            case 1: //caso 1: se recorre la fila
                                if (board[i][j] != '.') { //se verifica si el valor en la posicion i,j es diferente de '.'
                                    if (fila.count(board[i][j])) //se verifica si el valor en la fila ya se encuentra en el unordered_set, si es asi se retorna false y el sudoku no es valido
                                        return false;
                                    else {
                                        fila.insert(board[i][j]); //si no se encuentra el valor en el unordered_set se inserta en la fila
                                        break;
                                    }
                                }
                                else {
                                    break; //si el valor es '.' se rompe el ciclo
                                }
                            case 2:
                                if (board[j][i] != '.') { //se verifica si el valor en la posicion j,i es diferente de '.'
                                    if (columna.count(board[j][i])) //se verifica si el valor en la columna ya se encuentra en el unordered_set, si es asi se retorna false y el sudoku no es valido
                                        return false;
                                    else {
                                        columna.insert(board[j][i]); //si no se encuentra el valor en el unordered_set se inserta el la columna
                                        break;
                                    }
                                }
                                else {
                                    break; //si el valor es '.' se rompe el ciclo
                                }
                            case 3:
                                int row = 3 * (i / 3) + j / 3; //se calcula la fila del cuadrado
                                int col = 3 * (i % 3) + j % 3; //se calcula la columna del cuadrado
                                if (board[row][col] != '.') { //se verifica si el valor en la posicion row,col es diferente de '.'
                                    if (cuadrado.count(board[row][col])) //se verifica si el valor en el cuadrado ya se encuentra en el unordered_set, si es asi se retorna false y el sudoku no es valido
                                        return false;
                                    else {
                                        cuadrado.insert(board[row][col]); //si no se encuentra el valor en el unordered_set se inserta en el cuadrado
                                        break;
                                    }
                                }
                                else {
                                    break; //si el valor es '.' se rompe el ciclo
                                }
                            }
                        }
                    }
                }
            return true; //si no se encuentra ningun error en el sudoku se retorna true
        }
    };