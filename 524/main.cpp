/*
 * Peter Nguyen
 * UVa Online Judge Problem 524
 */

#include <iostream>
#include <set>
#include <vector>

const char isPairPrime[17][17] = {
    {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0}
};

void printRing(const std::vector<int> &ring) {
  for (int i = 0; i < ring.size(); ++i) {
    if (i != 0)
      std::cout << ' ';

    std::cout << ring[i];
  }

  std::cout << std::endl;
}

void findRings(
    int &ringLength,
    std::vector<int> &ring,
    std::set<int> available
) {
  if (ring.size() == ringLength) {
    if (isPairPrime[ring.back()][ring.front()])
      printRing(ring);
  } else {
    for (int number : available) {
      if (isPairPrime[ring.back()][number]) {
        std::set<int> newAvailable(available);
        newAvailable.erase(number);

        ring.push_back(number);
        findRings(ringLength, ring, newAvailable);
        ring.pop_back();
      }
    }
  }
}

void findRings(int ringLength) {
  std::vector<int> ring;
  std::set<int> available;

  ring.push_back(1);
  for (int i = 2; i <= ringLength; ++i)
    available.insert(i);

  findRings(ringLength, ring, available);
}

int main() {
  for (int ringLength, caseNum = 1; std::cin >> ringLength; ++caseNum) {
    if (caseNum != 1)
      std::cout << std::endl;

    std::cout << "Case " << caseNum << ":" << std::endl;

    if (ringLength != 1 && ringLength % 2 != 0) {
      // Odd ring length has two adjacent odd numbers (odd + odd = even)
    } else {
      findRings(ringLength);
    }
  }

  return 0;
}
