#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

enum class RunType {
  Up,
  Down,
  Neither
};

int main() {
  while (cin.peek() != char_traits<char>::eof()) {
    int prev = 0, curr, nrValues = 1, runLength = 0;
    RunType runType = RunType::Neither;
    vector<int> upLengths, downLengths;

    cin >> prev;
    if (prev != 0) {
      while (!(cin >> curr).fail()) {
        RunType prevRunType = runType;

        if (curr == 0) { // Sequence end
          if (runType == RunType::Up) {
            upLengths.push_back(runLength);
          } else if (runType == RunType::Down) {
            downLengths.push_back(runLength);
          }

          break;
        } else {
          nrValues++;
        }

        if (curr > prev)
          runType = RunType::Up;
        else if (curr < prev)
          runType = RunType::Down;

        if (prevRunType != RunType::Neither && prevRunType != runType) {
          if (prevRunType == RunType::Up) {
            upLengths.push_back(runLength);
          } else {
            downLengths.push_back(runLength);
          }

          runLength = 1;
        } else {
          runLength++;
        }

        prev = curr;
      }

      if (nrValues != 0) {
        double averageUpLength = 0.0, averageDownLength = 0.0;

        if (!upLengths.empty())
          averageUpLength = accumulate(upLengths.begin(), upLengths.end(), 0.0) / upLengths.size();

        if (!downLengths.empty())
          averageDownLength = accumulate(downLengths.begin(), downLengths.end(), 0.0) / downLengths.size();

        cout << setprecision(6) << fixed << "Nr values = " << nrValues << ":  " << averageUpLength << " "
             << averageDownLength << endl;
      }
    }
  }

  return 0;
}
