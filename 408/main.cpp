/*
 * Peter Nguyen
 * UVa Online Judge Problem 408
 */

#include <iostream>
#include <iomanip>

using namespace std;

class RNG {
 public:
  RNG(int step, int mod) : step(step), mod(mod) {}

  unsigned long long getnext() {
    unsigned long long value = seed;

    seed = (seed + step) % mod;
    return value;
  }
 private:
  int step = 0;
  int mod = 0;
  unsigned long long seed = 0;
};

int main() {
  int step = 0, mod = 0;

  while (cin >> step >> mod) {
    unsigned long long results[mod];
    bool isgood = true;
    fill(results, results + mod, 0);

    RNG random(step, mod);
    for (int i = 0; i < mod; ++i) {
      unsigned long long value = random.getnext();

      if (++results[value] > 1) {
        isgood = false;
        break;
      }

    }

    cout << setw(10) << right << step
         << setw(10) << right << mod;
    if (isgood)
      cout << "    " << "Good Choice";
    else
      cout << "    " << "Bad Choice";

    cout << endl << endl;
  }

  return 0;
}
