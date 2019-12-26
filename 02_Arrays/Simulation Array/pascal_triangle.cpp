/*
Asked in:  Google Amazon 

Given numRows, generate the first numRows of Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:
Given numRows = 5, return,
[ [1],
  [1,1],
  [1,2,1],
  [1,3,3,1],
  [1,4,6,4,1] ]
*/

################################################################################

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > p;
    if(A==0) return p;
    p.resize(A);
    for(int i=0; i<A; i++)
        p[i].resize(i+1);
    p[0][0]=1;
    if(A==1) return p;
    p[1][0]=1; p[1][1]=1;
    if(A==2) return p;
    int i, j;
    for(i=2; i<A; i++){
        j=0;
        p[i][j]=1;
        for(j=1; j<i; j++){
            p[i][j] = p[i-1][j]+p[i-1][j-1];
        }
        p[i][j]=1;
    }
    return p;
}
