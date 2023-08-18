//Approach-2 (O(logn) insertion using priority_queue) - Accepeted
class MedianFinder {
public:
    priority_queue<int> left_max_heap; //max heap
    priority_queue<int, vector<int>, greater<int>> right_min_heap; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }
        
        
        //always maintain left_max_heap size one greater than rigfht_min_heap size
        //ya fir, dono ka size equal ho
        
        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if(left_max_heap.size() < right_min_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()) {
            // matlab even number of elements hue honge
            
            return (double)(left_max_heap.top()+right_min_heap.top())/2;
        }
        
        //else hamare paas odd number of elemenes hue honge
        return left_max_heap.top();
    }
};