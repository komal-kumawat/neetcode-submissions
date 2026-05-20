class MedianFinder {
public:
    priority_queue<int>leftmax;
    priority_queue<int ,  vector<int> , greater<int> >rightmin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftmax.push(num);
        rightmin.push(leftmax.top());
        leftmax.pop();
        while(rightmin.size()>leftmax.size()){
            leftmax.push(rightmin.top());
            rightmin.pop();
        }
        
    }
    
    double findMedian() {
        if(leftmax.size()>rightmin.size()){
            return leftmax.top();
        }
        return (leftmax.top()+rightmin.top())/2.0;
        
    }
};
