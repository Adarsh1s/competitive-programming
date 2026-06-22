class MyHashMap {
    static const int size = 20011;
    static const int empty = -1;
    static const int tb = -2; 
    int keys[size];
    int values[size];
public:
    MyHashMap() {
        fill(keys,keys+size,empty);
    }

    int hash(int key){
        return key%size;
    }
    
    void put(int key, int value) {
        int index = hash(key), first_tb = -1;
        while(keys[index] != empty){
            if(keys[index] == key){
                values[index] = value;
                return;
            }
            if(keys[index] == tb && first_tb == -1){
                first_tb = index;
            }
            index = (index + 1) % size;
        }
        if(first_tb != -1) index = first_tb;
        keys[index] = key;
        values[index] = value;
        
    }
    
    int get(int key) {
        int index = hash(key);
        while(keys[index] != empty){
            if(keys[index] == key) return values[index];
            index = (index+1) % size;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        while(keys[index] != empty){
            if(keys[index] == key){
                keys[index] = tb;
                return;
            }
            index = (index + 1) % size;
        }
        
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */