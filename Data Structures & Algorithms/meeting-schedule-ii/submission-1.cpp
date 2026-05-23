/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n<=1) return n;
        sort(intervals.begin() , intervals.end() , [](auto &a , auto &b){
            return a.start <b.start;
        });

        priority_queue<int , vector<int> , greater<int>>q;
        q.push(intervals[0].end);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start>=q.top()){
                q.pop();
            }
            q.push(intervals[i].end);

        }
        return q.size();
        
    }
};
