class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closetoopen={
            {'}', '{'},
            {']','['},
            {')', '('}
        };
        stack<int> stack;
        for(char c: s){
            if(closetoopen.count(c)){
                if(!stack.empty()&& stack.top()==closetoopen[c])stack.pop();
                else return false;
            }
            else stack.push(c);
        }
        return stack.empty();
    }
};