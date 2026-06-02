class MyHashSet {
    HashMap<Integer , Boolean>hash;

    public MyHashSet() {
        hash= new HashMap<>();
        
    }
    
    public void add(int key) {
        if(!hash.containsKey(key)){
            hash.put(key , true);
        }
        
    }
    
    public void remove(int key) {
        hash.remove(key);
        
    }
    
    public boolean contains(int key) {
        return hash.containsKey(key);
        
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */