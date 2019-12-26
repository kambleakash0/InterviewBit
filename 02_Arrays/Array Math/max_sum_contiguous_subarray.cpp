/*
Asked in:  Facebook Paypal Yahoo Microsoft LinkedIn Amazon Goldman Sachs

Find the contiguous subarray within an array, A of length N which has the largest sum.

Constraints:
    1 <= N <= 1e6
    -1000 <= A[i] <= 1000
    
For example:
    Input 1: A = [1, 2, 3, 4, -10]
    Output 1: 10
    Explanation 1:
        The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

    Input 2: A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    Output 2: 6
    Explanation 2:
        The subarray [4,-1,2,1] has the maximum possible sum of 6.
*/

################################################################################

int Solution::maxSubArray(const vector<int> &A) {
    int mSum=INT_MIN, sum=0, n=A.size();
    for(int i=0; i<n; i++){
        sum += A[i];
        if(mSum<sum)
            mSum=sum;
        if(sum<0)
            sum=0;
    }
    return mSum;
}
