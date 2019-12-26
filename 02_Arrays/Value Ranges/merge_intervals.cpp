/*
Asked in:  Google 

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
    Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:
    Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
    This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Note:
    Make sure the returned intervals are also sorted.
*/

################################################################################

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> v;
    bool merged=false;
    if(intervals.empty()){
        v.push_back(newInterval);
        return v;
    }
    for(int i=0; i<intervals.size(); i++){
        if(merged){
            v.push_back(intervals[i]);
            continue;
        }
        if(max(intervals[i].start,newInterval.start) > min(intervals[i].end,newInterval.end)){
            if(intervals[i].start <= newInterval.start){
                v.push_back(intervals[i]);
            }
            else{
                v.push_back(newInterval);
                merged=true;
                i--;
            }
        }
        else{
            if(newInterval.start <= intervals[i].start && newInterval.end >= intervals[i].end){
                continue;
            }
            else if(newInterval.start <= intervals[i].start && newInterval.end <= intervals[i].end){
                newInterval.end = intervals[i].end;
            }
            else if(newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end){
                newInterval.start = intervals[i].start;
                newInterval.end = intervals[i].end;
            }
            else if(newInterval.start >= intervals[i].start && newInterval.end >= intervals[i].end){
                newInterval.start = intervals[i].start;
            }
        }
    }
    if(!merged) v.push_back(newInterval);
    return v;
}
