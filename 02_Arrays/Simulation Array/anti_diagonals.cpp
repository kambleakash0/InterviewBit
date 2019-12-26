/*
Asked in:  Microsoft Adobe 

Give a N*N square matrix, return an array of its anti-diagonals.

Examples:

    Input 1 : 	
    1 2 3
    4 5 6
    7 8 9
    
    Output 1 :
    [ [1],
      [2, 4],
      [3, 5, 7],
      [6, 8],
      [9] ]


    Input 2 : 
    1 2
    3 4

    Output 2 : 
    [ [1],
      [2, 3],
      [4] ]

*/

################################################################################

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > v(A.size()+A.size()-1);
    int x=A[0].size();
    int m, n;
    int idx=0;
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            m=i; n=j;
            if(i==0){
                for(int k=0; k<=j; k++){
                    v[idx].push_back(A[m][n]);
                    m=m+1;
                    n=n-1;
                }
                idx++;
            }else if(j==x-1){
                for(int k=0; k<v.size()-(i+j); k++){
                    v[idx].push_back(A[m][n]);
                    m=m+1;
                    n=n-1;
                }
                idx++;
            }
        }
    }
    return v;
}
