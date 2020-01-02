/*
Asked in:  Amazon VMWare Riverbed

Given a read only array of n + 1 integers between 1 and n,
find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input: [3 4 1 4 1]

Sample Output: 1

Notes:
    If there are multiple possible answers ( like in the sample case above ), output any one.
    If there is no duplicate, output -1.
*/

################################################################################

int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(visited[A[i]-1]==false){
            visited[A[i]-1]=true;
        }
        else{
            return A[i];
        }
    }
    return -1;
}
