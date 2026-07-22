// 数据流中的中位数 - 双优先队列
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> smallNum;
    priority_queue<int, vector<int>, greater<int>> largeNum;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (smallNum.empty() || num <= smallNum.top()) {
            smallNum.push(num);
        } else {
            largeNum.push(num);
        }

        if (smallNum.size() > largeNum.size() + 1) {
            largeNum.push(smallNum.top());
            smallNum.pop();
        } else if (smallNum.size() < largeNum.size()) {
            smallNum.push(largeNum.top());
            largeNum.pop();
        }
    }
    
    double findMedian() {
        if (smallNum.empty() && largeNum.empty()) {
            return 0.0;
        } else if ((smallNum.size() + largeNum.size()) % 2) {
            return smallNum.top(); 
        } else {
            return (smallNum.top() + largeNum.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */