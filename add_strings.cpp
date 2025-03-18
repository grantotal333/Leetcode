class Solution {
    public:
        string addStrings(string num1, string num2) { //La entrada de la función es un string num1 y un string num2
            string result = ""; // Creamos un string llamado result para al final llamarlo con el resultado
            int carry = 0;  // necesitamos un carrier ya que toca hacer la suma de cada uno de los intervalos de los strings
            int i = num1.size() - 1, j = num2.size() - 1; // con esto sabemos la longitud de los strings estas tienen valores de -1 ya que los vectores empiezan en 0
    
            while (i >= 0 || j >= 0 || carry > 0) { // Usamos el While ya que neesitamos que la suma se haga por todos los datos de los strings
                int digit1 = (i >= 0) ? num1[i] - '0' : 0;  //Si el valor de i es mayor o igual a 0 entonces el valor de digit1 es igual a num1[i] - '0' si no entonces digit1 es igual a 0
                int digit2 = (j >= 0) ? num2[j] - '0' : 0;  //Si el valor de j es mayor o igual a 0 entonces el valor de digit2 es igual a num2[j] - '0' si no entonces digit2 es igual a 0
                int sum = digit1 + digit2 + carry; //Lo anterior se hace porque usamos sistema ASCII y necesitamos que los valores sean enteros
                carry = sum / 10;  // Es para saber si hay carrier o no, si el valor el mayor a 10 entonces hay carrier de lo contrario se manda a 0
                result = char((sum % 10) + '0') + result;  // Se hace la suma de los valores de los strings y se guarda en result
                i--;  // Finaliza el while
                j--;  // Finaliza el while
            }
    
            return result; //Retorna el resultado
        }
    };