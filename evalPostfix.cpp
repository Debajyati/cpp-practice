#include <cctype>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
#include <string>

std::set<char> OPERATORS = {'+', '-', '*', '/', '%', '^', '&', '|'};

int eval_postfix(const std::string &expr);
int perform(int oprnd1, int oprnd2, char oprtor);

int main() {
  std::string expr;
  std::cout << "Enter the postfix expression to evaluate:\n";
  std::getline(std::cin, expr);

  try {
    int output = eval_postfix(expr);
    std::cout << "\nThe calculated output is: " << output << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error during evaluation: " << e.what() << std::endl;
  }
  return 0;
}

int eval_postfix(const std::string &expr) {
  std::stack<int> S;
  std::istringstream iss(expr);
  std::string token;

  while (iss >> token) {
    if (token.size() == 1 && OPERATORS.find(token[0]) != OPERATORS.end()) {
      if (S.size() < 2)
        throw std::runtime_error("Insufficient operands");

      int op2 = S.top();
      S.pop();
      int op1 = S.top();
      S.pop();
      int result = perform(op1, op2, token[0]);
      S.push(result);
    } else {
      try {
        int num = std::stoi(token);
        S.push(num);
      } catch (...) {
        throw std::runtime_error("Invalid token: " + token);
      }
    }
  }

  if (S.size() != 1)
    throw std::runtime_error("Malformed expression");

  return S.top();
}

int perform(int oprnd1, int oprnd2, char oprtor) {
  switch (oprtor) {
  case '+':
    return oprnd1 + oprnd2;
  case '-':
    return oprnd1 - oprnd2;
  case '*':
    return oprnd1 * oprnd2;
  case '/':
    if (oprnd2 == 0)
      throw std::runtime_error("Division by zero");
    return oprnd1 / oprnd2;
  case '%':
    if (oprnd2 == 0)
      throw std::runtime_error("Modulo by zero");
    return oprnd1 % oprnd2;
  case '^':
    return oprnd1 ^ oprnd2;
  case '&':
    return oprnd1 & oprnd2;
  case '|':
    return oprnd1 | oprnd2;
  default:
    throw std::runtime_error("Unknown operator");
  }
}
