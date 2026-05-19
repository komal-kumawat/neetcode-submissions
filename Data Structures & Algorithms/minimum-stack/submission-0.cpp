class MinStack {
public: 
    vector<int>stack;
    vector<int>minst;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if(minst.size()==0 || val<=minst.back()){
            minst.push_back(val);
        }
        
    }
    
    void pop() {
        if(minst.back()==stack.back()){
            minst.pop_back();
        }
        stack.pop_back();
        
    }
    
    int top() {
        return stack.back();
        
    }
    
    int getMin() {
        return minst.back();
        
    }
};
