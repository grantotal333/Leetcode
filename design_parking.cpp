class ParkingSystem {
    public:
        vector<int> capacidad; //Se crea un vector vacio llamado capacidad
        ParkingSystem(int big, int medium, int small) {
            capacidad = {big, medium, small}; //Se inicializa el vector capacidad con los valores de big, medium y small dados por el usuario
        }
        
        bool addCar(int carType) {
            if (capacidad[carType - 1] > 0){ //Se verifica si el espacio para el tipo de coche es mayor a 0
                //Si es mayor a 0, se resta 1 al espacio disponible para ese tipo de coche
                //y se retorna true
                //Si no, se retorna false
                //El -1 es porque el vector empieza en 0 y los tipos de coches empiezan en 1
                //Ejemplo: si el coche es de tipo 1, se resta 1 al espacio de capacidad[0]
                //Ejemplo: si el coche es de tipo 2, se resta 1 al espacio de capacidad[1]
                capacidad[carType - 1] -= 1;
                return true;
            }
            else
                return false;
        }
    };
    
    /**
     * Your ParkingSystem object will be instantiated and called as such:
     * ParkingSystem* obj = new ParkingSystem(big, medium, small);
     * bool param_1 = obj->addCar(carType);
     */