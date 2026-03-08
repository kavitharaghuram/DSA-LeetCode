#include <bits/stdc++.h>
class Solution {
public:
    int parse(string& s, int i, long long num, int sign){
            if(i>s.length()|| !isdigit(s[i])){
                return num*sign;
            }
            int dig= s[i]-'0';
            num=num*10+dig;
            long long val=num*sign;
            if(val>INT_MAX)return INT_MAX;
            if(val<INT_MIN)return INT_MIN;
            return parse(s, i+1, num, sign);
        }
    int myAtoi(string s) {
        int i=0, n=s.length();
        while(i<n && s[i]==' ')i++;
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        return parse(s, i, 0, sign);
    }

};