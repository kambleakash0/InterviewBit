/*
Asked in:  Google Amazon

Given a collection of intervals, merge all overlapping intervals.

For example:
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Note:
    Make sure the returned intervals are sorted.
*/

################################################################################

int comp(Interval I1, Interval I2){
    return (I1.start < I2.start);
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> v;
    int n = A.size();
    if(A.empty()) return v;
    if(A.size()==1) return A;
    sort(A.begin() , A.begin()+A.size() , comp);
    v.push_back(A[0]);
    for(int i=1; i<n; i++){
        if(A[i].start <= v[v.size()-1].end){
            v[v.size()-1].end = max(v[v.size()-1].end, A[i].end);
        }
        else
            v.push_back(A[i]);
    }
    return v;
}
