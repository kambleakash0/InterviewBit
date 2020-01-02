/*
Asked in:  Hunan Asset

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.

Example :
    Input : [1, 10, 5]
    Output : 5 
    
Notes:
    1. Return 0 if the array contains less than 2 elements.
    2. You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    3. You may also assume that the difference will not overflow.
*/

################################################################################

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2) return 0;
    int n=A.size();
    vector<int> v=A;
    int gap=0;
    sort(v.begin(), v.end());
    for(int i=0; i<n-1; i++){
        gap = max(gap, v[i+1]-v[i]);
    }
    return gap;
}
