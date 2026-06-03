class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1)return "";
        int n= palindrome.length();
        for(int i=0; i<n; i++){
            if(palindrome[i]!='a' && !(n%2==1 && i==n/2)){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};