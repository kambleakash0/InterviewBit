/*
Asked in:  Amazon Goldman Sachs Microsoft

Given a list of non negative integers, arrange them such that they form the largest number.

For example:
    Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note:
    The result may be very large, so you need to return a string instead of an integer.
*/

################################################################################

bool comp(int x, int y){
    long int xx, yy;
    int digits = log10(y)+1;
    long int shifted = (long int)x * pow(10, digits);
    xx = shifted + y;
    digits = log10(x)+1;
    shifted = (long int)y * pow(10, digits);
    yy = shifted + x;
    return (xx>yy);
}
string Solution::largestNumber(const vector<int> &A) {
    int n=A.size();
    vector<int> v;
    v=A;
    string st;
    stringstream ss;
    sort(v.begin(), v.end(), comp);
    for(int i=0; i<n; i++){
        if(v[0]==0){
            ss<<0;
            break;
        }
        ss << v[i];
    }
    st = ss.str();
    return st;
}
