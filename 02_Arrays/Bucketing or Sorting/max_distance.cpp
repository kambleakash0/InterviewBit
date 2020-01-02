/*
Asked in:  Google Amazon Microsoft 

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
If there is no solution possible, return -1.

Example :
    Input : [3 5 4 2]
    Output : 2 
    for the pair (3, 4)

*/

################################################################################

int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a>b?b:a;
}

int Solution::maximumGap(const vector<int> &A) {
    vector<int> L;
    int i,j,R[A.size()];
    L.push_back(A[0]);
    for(i=1;i<A.size();i++)
        L.push_back(min(L[i-1],A[i]));
    R[A.size()-1]=A[A.size()-1];
    for(i=A.size()-2;i>=0;i--)
        R[i]=max(R[i+1],A[i]);
    i=0;j=0;int dif=-1;
    while(i<A.size() && j<A.size())
    {
        if(L[i]<=R[j])
        {
            dif=max(dif,j-i);
            j++;
        }
        else
            i++;
    }
    return dif;
}
