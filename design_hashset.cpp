class MyHashSet {
    public:
        unordered_set<int> us; //se crea un vectror de enteros 
        MyHashSet() { //se crea un constructor para inicializar el vector, este constructor ejecuta el parrafo que esta abajo
        }
        
        void add(int key) { // se crea una funcion para agregar un entero, si el entero ya existe no se agrega
            us.insert(key);
        }
        
        void remove(int key) { // se crea una funcion para eliminar un entero, si el entero no existe no se elimina
            us.erase(key);
        }
        
        bool contains(int key) { // se crea una funcion para verificar si un entero existe, si existe devuelve true, si no existe devuelve false
            if (us.count(key))
                return true;
            else
                return false;
        }
    };
    
    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */