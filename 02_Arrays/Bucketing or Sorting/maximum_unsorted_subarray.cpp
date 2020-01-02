/*
Asked in:  Amazon 

You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Examples :
    Input 1: A = [1, 3, 2, 4, 5]
    Return: [1, 2]

    Input 2: A = [1, 2, 3, 4, 5]
    Return: [-1]

Explanation:
    In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
*/

################################################################################

vector<int> Solution::subUnsort(vector<int> &A) {
    int i, j, n=A.size();
    vector<int> v(1);
    v[0]= -1;
    if(n==1) return v;
    for(i=0; i<n-1; i++){
        if(A[i]>A[i+1])
            v.clear();
    }
    
    if(!v.empty()) return v;
    v.resize(2);
    for(i=0; i<n-1; i++){
        if(A[i] <= A[i+1]) continue;
        else break;
    }
    for(j=n-1; j>0; j--){
        if(A[j] >= A[j-1]) continue;
        else break;
    }
    int mn=A[i], mx=A[i];
//     min(Al, …, Ar) >= max(A0, …, Al-1)
// and max(Al, …, Ar) <= min(Ar+1, …, AN-1)
    
    for(int y=i+1; y<=j; y++){
        if(A[y]<mn) mn=A[y];
        if(A[y]>mx) mx=A[y];
    }
    for(int x=0; x<i; x++){
        if(A[x]>mn){
            i=x;
            break;
        }
    }
    for(int z=n-1; z>j; z--){
        if(A[z]<mx){
            j=z;
            break;
        }
    }
    // while(A[i] == A[i-1]) i--;
    // while(A[j] == A[j+1]) j++;
    // while(A[i] > A[j]) i--;
    // while(A[j] < A[i]) j++;
    
    v[0]=i;
    v[1]=j;
    return v;
}
