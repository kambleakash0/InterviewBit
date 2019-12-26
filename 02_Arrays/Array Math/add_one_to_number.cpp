/*
Asked in:  Google Microsoft

Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.

Example:
If the vector has [1, 2, 3]
the returned vector should be [1, 2, 4]
as 123 + 1 = 124.

*/

################################################################################

vector<int> Solution::plusOne(vector<int> &A) {
    // vector<int> v(A.size()+1);
    int carry=0;
    if(A.size() >1){
        reverse(A.begin(), A.end());
        auto it=A.rbegin();
        while(*it==0 && it!=A.rend()){
            A.pop_back();
             it++;
        }
        reverse(A.begin(), A.end());
    }
    for(auto it=A.rbegin(); it!=A.rend(); it++){
        if(it==A.rbegin()){
            if(*it + 1 > 9){
                *it = 0;
                // v.push_back(0);
                carry = 1;
            }
            else{
                *it += 1;
                // v.push_back(*it+1);
            }
        }
        else{
            if(*it + carry > 9){
                *it = 0;
                // v.push_back(0);
                carry = 1;
            }
            else{
                *it += carry;
                // v.push_back(*it + carry);
                carry = 0;
            }
        }
    }
    if(carry==1){
        reverse(A.begin(), A.end());
        A.push_back(1);
        // v.push_back(1);
        reverse(A.begin(), A.end());
        // reverse(v.begin(), v.end());
    }
    return A;
}
