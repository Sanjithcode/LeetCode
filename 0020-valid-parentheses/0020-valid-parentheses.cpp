class Solution {
public:
    bool isValid(string s) {
         stack<char> st;
    
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);  // Push open brackets onto the stack
        } else {
            if (st.empty()) return false; // If stack is empty and we get a closing bracket, it's invalid
            
            char top = st.top();
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')) {
                st.pop(); // Valid pair, remove from stack
            } else {
                return false; // Mismatched bracket
            }
        }
    }
    
    return st.empty(); // If stack is empty, it's valid
}

int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    if (isValid(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
    }
};