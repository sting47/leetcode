class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        stack<char> stk;
        while( i < s.length() ) {
            switch( s[i] ) {
                case '(':
                    stk.push('(');
                    break;
                case '{':
                    stk.push('{');
                    break;
                case '[':
                    stk.push('[');
                    break;
                case ')':
                    if( stk.empty() != true ) {
                        if( stk.top() == '(' ) {
                            stk.pop();
                            break;
                        }
                        else
                            return false;
                    }
                    else
                        return false;
                case '}':
                    if( stk.empty() != true ) {
                        if( stk.top() == '{' ) {
                            stk.pop();
                            break;
                        }
                        else
                            return false;
                    }
                    else
                        return false;
                case ']':
                    if( stk.empty() != true ) {
                        if( stk.top() == '[' ) {
                            stk.pop();
                            break;
                        }
                        else
                            return false;
                    }
                    else
                        return false;
                default:
                    return false;
            }
            i++;
        }
        if( stk.empty() )
            return true;
        else
            return false;
    }
};
