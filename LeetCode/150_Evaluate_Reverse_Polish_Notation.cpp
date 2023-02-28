class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> nums;
        int res = stoi(tokens[0]);

        for (const string& s : tokens) {
            if ((s[0] == '-' && s.size() != 1) || isdigit(s[0])) {
                nums.push(s);
            } else {
                int second = stoi(nums.top());
                nums.pop();
                int first = stoi(nums.top());
                nums.pop();

                if (s == "+") res = first + second;
                else if (s == "-") res = first - second;
                else if (s == "*") res = first * second;
                else res = first / second;
                
                nums.push(to_string(res));
            }
        }

        return res;
    }
};