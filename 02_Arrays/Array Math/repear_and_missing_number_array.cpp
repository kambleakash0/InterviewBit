/*
Asked in:  Amazon

You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.

Note:
  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
  Note that in your output A should precede B.

Example:
    Input:[3 1 2 5 3] 
    Output:[3, 4] 
    Here, A = 3, B = 4
*/

################################################################################

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> res;
    
    long n = A.size();
    long long int nSum = n*(n+1)/2, nSqSum = n*(n+1)*(2*n+1)/6;
    for(int i=0; i<n; i++){
        nSum -= (long long int)A[i];
        nSqSum -= (long long int)A[i]*(long long int)A[i];
    }
    long long int diff=0, rep=0, missing=0;
    missing = (nSum+nSqSum/nSum)/2;
    rep = missing - nSum;
    
    res.push_back((int)rep);
    res.push_back((int)missing);
    return res;
}
