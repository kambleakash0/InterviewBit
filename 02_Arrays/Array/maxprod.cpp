/*

You are given an array A containing N integers.
The special product of each i'th integer in this array is defined as the product of the following <ul>:
LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j).
    If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i).
    If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

Constraints:
    1 <= N <= 10^5
    1 <= A[i] <= 10^9
    
Note:
    If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.
*/

################################################################################

int Solution::maxSpecialProduct(vector<int> &A) {
    long n =A.size();
    int i;
    int rv = A[n - 1];
    i = n - 2;
    while ( i>0 && A[i]>=rv){
        rv = A[i];
        --i;
    }
    int end = i + 1;
    while (i > 0 && A[i] <= rv){
        rv = A[i];
        --i;
    }
    int start = i + 1;
    long max = 0;
    for (int j = start; j < end; ) {
        int mid = j;
        for (; (i>=0)&&(A[i]<=A[mid]); --i);
        if (i < 0) break;
        for (; (j <= end)&&(A[j] == A[mid]); ++j);
        if (j > end) break;
        int left =i;
        int right =j;
        long res = (long)left*(long)right;
        if(res>max) max =res;
    }
    return max%1000000007;
}
