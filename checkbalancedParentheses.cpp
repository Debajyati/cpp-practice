#include <iostream>
#include <stack>
using namespace std;

bool is_matching(char c1, char c2) {
  bool cond1 = (c1 == '{' && c2 == '}');
  bool cond2 = (c1 == '[' && c2 == ']');
  bool cond3 = (c1 == '(' && c2 == ')');
  bool cond4 = (c1 == '<' && c2 == '>');

  if (cond4 || cond1 || cond2 || cond3) return true;
  return false;
}

bool checkbalancedParentheses(string expression) {
  stack<char> S;

  for (char c: expression) {
    if (c == '(' || c == '{' || c == '[' || c == '<') S.push(c);

    else if (c == ')' || c == ']' || c == '}' || c == '>') {
      if (S.empty() || !is_matching(S.top(), c)) return false;
      else S.pop();
    }
  }
  return (S.empty() ? true : false);
}

int main (int argc, char *argv[]) {
  cout << "Enter the expression to check validity" << endl;
  string expr;
  cin >> expr;

  bool isValid = checkbalancedParentheses(expr);
  cout << "The expression is " << (isValid ? "Valid" : "NOT Valid") << '!' << endl;
  return 0;
}
