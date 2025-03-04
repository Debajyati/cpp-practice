#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<int, int> input(string s) {
  int v1 = 0;
  int i = 0;

  while (s[i] != '+') {
    v1 = v1 * 10 + s[i] - '0';
    i++;
  }

  while (s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
    i++;
  }

  int v2 = 0;

  while (i < s.length()) {
    v2 = v2 * 10 + s[i] - '0';
    i++;
  }

  return make_pair(v1, v2);
}

int main (int argc, char *argv[]) {
  string s;
  getline(cin, s);
  pair<int, int> c = input(s);

  cout << "Real Part: " << c.first << endl;
  cout << "Imaginary Part: " << c.second << endl;
  return 0;
}
