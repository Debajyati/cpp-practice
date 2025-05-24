#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <set>
#include <vector>
#include <cctype>

std::set<char> OPERATORS = {'+', '-', '*', '/', '%', '^', '&', '|'};

int perform(int oprnd1, int oprnd2, char oprtor) {
  switch (oprtor) {
  case '+': return oprnd1 + oprnd2;
  case '-': return oprnd1 - oprnd2;
  case '*': return oprnd1 * oprnd2;
  case '/':
    if (oprnd2 == 0) throw std::runtime_error("Division by zero");
    return oprnd1 / oprnd2;
  case '%':
    if (oprnd2 == 0) throw std::runtime_error("Modulo by zero");
    return oprnd1 % oprnd2;
  case '^': return oprnd1 ^ oprnd2;
  case '&': return oprnd1 & oprnd2;
  case '|': return oprnd1 | oprnd2;
  default: throw std::runtime_error("Unknown operator");
  }
}

int eval_prefix(const std::string &expr) {
  std::stack<int> S;
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream iss(expr);

  while (iss >> token) {
    tokens.push_back(token);
  }

  for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
    token = *it;
    if (token.size() == 1 && OPERATORS.count(token[0])) {
      if (S.size() < 2)
        throw std::runtime_error("Insufficient operands for operator " + token);
      int op1 = S.top(); S.pop();
      int op2 = S.top(); S.pop();
      S.push(perform(op1, op2, token[0]));
    } else {
      S.push(std::stoi(token));
    }
  }

  if (S.size() != 1)
    throw std::runtime_error("Invalid prefix expression");

  return S.top();
}

int main() {
  std::string expr;
  std::cout << "Enter the prefix expression to evaluate (space-separated):\n";
  std::getline(std::cin, expr);

  try {
    int output = eval_prefix(expr);
    std::cout << "\nThe calculated output is: " << output << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error during evaluation: " << e.what() << std::endl;
  }
  return 0;
}