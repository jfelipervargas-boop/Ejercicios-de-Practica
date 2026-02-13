class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0) return false;

    std:string y = std::to_string(x);
    int n = y.size();
    
    for (int i = 0; i <= n/2; ++i){
        if (y[i] != y[n-1-i]){
            return false;
            }
        }
    return true;
    };
};