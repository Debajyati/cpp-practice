#include <iostream>
#include <sstream>
using namespace std;

typedef unsigned long long int ulli;

class Bin {
private:
  static stringstream& getStream() {
    static stringstream bs;
    return bs;
  }
  static void toBinary(ulli num) {
    stringstream& bs = getStream();
    if (num > 1) {
      toBinary(num >> 1);
    }
    bs << (num & 1);
  }
public:
  static ulli getBinaryNumber(ulli num) {
    ulli result;
    stringstream& bs = getStream();
    bs.clear();
    toBinary(num);
    bs >> result;
    return result;
  }
  static string getBinaryString(ulli num) {
    string result;
    stringstream& bs = getStream();
    bs.clear();
    toBinary(num);
    bs >> result;
    return result;
  }
};

int main (int argc, char *argv[]) {
  ulli a = 1ULL << 5;

  ulli b = Bin::getBinaryNumber(a);
  cout << "Base 10 form is :- " << a << std::endl;
  cout << "Base 2 form is :- " << b << std::endl;
  return 0;
}
