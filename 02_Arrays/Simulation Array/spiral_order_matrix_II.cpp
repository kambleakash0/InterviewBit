/*
Asked in: Microsoft JP Morgan Amazon 

Given an integer A, generate a square matrix filled with elements from 1 to A^2 in spiral order.

Constraints:
    1 <= A <= 1000

Examples:
    Input 1: A = 3
    Output 1:[ [ 1, 2, 3 ],
               [ 8, 9, 4 ],
               [ 7, 6, 5 ] ]

    Input 2: 4
    Output 2: [ [1, 2, 3, 4],
               [12, 13, 14, 5],
               [11, 16, 15, 6],
               [10, 9, 8, 7] ]
               
*/

################################################################################

vector<vector<int> > Solution::generateMatrix(int A) {
    int dir=0, T=0, B=A-1, L=0, R=A-1, num=1, i, j;
    vector<vector<int> > v(A, vector<int>(A));
    while(T<=B && L<=R){
        if(dir==0){
            i=T;
            for(j=L; j<=R; j++){
                v[i][j] = num;
                num++;
            }
            dir=1;
            T++;
        }
        else if(dir==1){
            j=R;
            for(i=T; i<=B; i++){
                v[i][j] = num;
                num++;
            }
            dir = 2;
            R--;
        }
        else if(dir==2){
            i=B;
            for(j=R; j>=L; j--){
                v[i][j] = num;
                num++;
            }
            dir = 3;
            B--;
        }
        else if(dir==3){
            j=L;
            for(i=B; i>=T; i--){
                v[i][j] = num;
                num++;
            }
            dir = 0;
            L++;
        }
    }
    return v;
}
