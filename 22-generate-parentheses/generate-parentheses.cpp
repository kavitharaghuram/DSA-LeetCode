class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0, 0, n, res, stack);
        return res;
    }
    private:
    void backtrack(int open, int closed, int n, vector<string>&res, string& stack){
        if(open==closed && open==n){
            res.push_back(stack);
            return;
        }
        if(open<n){
            stack+='(';
            backtrack(open+1, closed, n, res, stack);
            stack.pop_back();
        }
        if(closed<open){
            stack+=')';
            backtrack(open, closed+1, n, res, stack);
            stack.pop_back();
        }
    }
};