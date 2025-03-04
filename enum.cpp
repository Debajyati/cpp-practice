#include <iostream>
#include <unordered_map>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
// Define specializations for the Traits class template here.
template <> struct Traits<Fruit> {
public:
    static string name(int index) {
        Fruit frray[] = {Fruit::apple, Fruit::orange, Fruit::pear};

        if (index < 0 || index >= 3) return "unknown";  // Fix: Handle out-of-bounds case
        
        switch (frray[index]) {
            case Fruit::apple:  return "apple";
            case Fruit::orange: return "orange";
            case Fruit::pear:   return "pear";
        }
        return "unknown";
    }
};

template <> struct Traits<Color> {
public:
    static string name(int index) {
        unordered_map<Color, string> color_string_map = {
            {Color::red, "red"},
            {Color::green, "green"},
            {Color::orange, "orange"}
        };
        
        Color clarray[] = {Color::red, Color::green, Color::orange};
        
        if (index < 0 || index >= 3) return "unknown";
        
        return color_string_map[clarray[index]];
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
