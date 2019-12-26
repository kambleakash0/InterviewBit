/*
Asked in:  Google 

Given an index k, return the kth row of the Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:
    Input : k = 3
    Return : [1,3,3,1]
    
NOTES:
    k is 0 based. k = 0, corresponds to the row [1].
    Could you optimize your algorithm to use only O(k) extra space?
*/

################################################################################

vector<int> Solution::getRow(int A) {
    vector<int> p;
    p.resize(A+1);
    p[0]=1;
    if(A==0) return p;
    
    p[0]=1; p[1]=1;
    if(A==1) return p;
    
    vector<int> buff(A, 0);
    
    for(int i=1; i<A; i++){
        // buff.assign(p, p.size());
        buff = p;
        for(int j=0; j<=i; j++){
            if(j==0)
                p[j]=1;
            p[j] = buff[j]+buff[j-1];
        }
        p[i+1]=1;
    }
    return p;
}
