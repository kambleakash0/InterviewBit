/*
Asked in:  Google

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.
The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
Maximum sub-array is defined in terms of the sum of the elements in the sub-array.
Find and return the required subarray.

NOTES:
    1. If there is a tie, then compare with segment's length and return segment which has maximum length.
    2. If there is still a tie, then return the segment with minimum starting index.

Constraints:
    1 <= N <= 1e5
    1 <= A[i] <= 1e5
    
Examples:
    Input 1: A = [1, 2, 5, -7, 2, 3]
    Output 1: [1, 2, 5]
    Explanation 1:
        The two sub-arrays are [1, 2, 5] [2, 3].
        The answer is [1, 2, 5] as its sum is larger than [2, 3].

    Input 2: A = [10, -1, 2, 3, -4, 100]
    Output 2: [100]
    Explanation 2:
        The three sub-arrays are [10], [2, 3], [100].
        The answer is [100] as its sum is larger than the other two.
*/

################################################################################

vector<int> Solution::maxset(vector<int> &A) {
    vector<int> v;
    int n=A.size();
    long mSum=0, sum=0;
    int stidx=0, mStidx=0, len=0, mLen=0;
    for(int i=0; i<n; i++){
        if(A[i]<0){
            sum=0;
            stidx=i+1;
            len=0;
            continue;
        }
        sum += A[i];
        len++;
        if(mSum<sum){
            mSum=sum;
            mStidx=stidx;
            mLen=len;
        }
        else if(mSum==sum){
            if(mLen<len){
                mLen=len;
                mStidx=stidx;
            }
            else if(mLen==len){
                if(mStidx>stidx){
                    mStidx=stidx;
                }
            }
        }
    }
    for(int i=mStidx; i<mStidx+mLen; i++){
        v.push_back(A[i]);
    }
    return v;
}
