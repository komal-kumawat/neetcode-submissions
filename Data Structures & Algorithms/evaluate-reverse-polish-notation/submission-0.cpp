class Solution {
public:

    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {

            string op = tokens[i];

            if(op == "+" || op == "-" ||
               op == "*" || op == "/") {

                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                if(op == "+") {
                    st.push(first + second);
                }
                else if(op == "-") {
                    st.push(first - second);
                }
                else if(op == "*") {
                    st.push(first * second);
                }
                else {
                    st.push(first / second);
                }
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};