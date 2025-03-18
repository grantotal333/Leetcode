class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> resultado; //Creamos un vector de enteros llamado resultado
            for (int i = 0; i < nums.size(); i++){ //Recorremos el vector nums para saber cada dato en cada una de las posiciones de los vectores
                for (int j = 0; j < nums.size(); j++){ //Recorremos el vector nums para saber cada dato en cada una de las posiciones para despuescompararla con i
                    if (i != j){ //Si i es diferente de j entonces ya sabemos que no estamos hablando de la misma posición en el vector
                        if (nums[i] + nums[j] == target){ //Si la suma de los datos en las posiciones i y j es igual al target entonces sacamos el resultado
                            resultado.push_back(i); //Que se guarde el valor de i en el vector resultado
                            resultado.push_back(j); //Que se guarde el valor de j en el vector resultado
                            return resultado; //Que regrese el vector resultado con las posiciones de los datos que sumados dan el target
                        }
                    }
                }
            }
            return{};
        }
    };