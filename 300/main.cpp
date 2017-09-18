/*
 * Peter Nguyen
 * UVa Online Judge Problem 300
 */

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

class Haab {
private:
    int day;
    string month;
    int year;

    map<string, int> months = {
            {"pop", 0}, {"no", 1}, {"zip", 2}, {"zotz", 3}, {"tzec", 4}, {"xul", 5},
            {"yoxkin", 6}, {"mol", 7}, {"chen", 8}, {"yax", 9}, {"zac", 10},
            {"ceh", 11}, {"mac", 12}, {"kankin", 13}, {"muan", 14}, {"pax", 15},
            {"koyab", 16}, {"cumhu", 17}, {"uayet", 18}
    };
public:
    Haab(int day, const string &month, int year) : day(day), month(month), year(year) {}

    int toDays() const {
        int total = year * 365; // Add days in previous years
        total += months.find(month)->second * 20; // Add days in previous months
        total += day; // Add days past in month

        return total;
    }
};

class Tzolkin {
private:
    int number;
    string name;
    int year;

    map<int, string> names = {
            {0, "imix"}, {1, "ik"}, {2, "akbal"}, {3, "kan"}, {4, "chicchan"},
            {5, "cimi"}, {6, "manik"}, {7, "lamat"}, {8, "muluk"}, {9, "ok"},
            {10, "chuen"}, {11, "eb"}, {12, "ben"}, {13, "ix"}, {14, "mem"},
            {15, "cib"}, {16, "caban"}, {17, "eznab"}, {18, "canac"}, {19, "ahau"}
    };

public:
    Tzolkin(const Haab &haab) {
        int days = haab.toDays();

        this->year = days / 260; // 260 days per year
        this->number = ((days % 260) % 13) + 1;
        this->name = names.find((days % 260) % 20)->second;
    }

    string toString() const {
        return to_string(number) + ' ' + name + ' ' + to_string(year);
    }
};

int main() {
    int count;
    cin >> count;
    cout << count << '\n';

    for (int i = 0; i < count; ++i) {
        string day, month;
        int year;

        cin >> day >> month >> year;
        day.pop_back(); // Remove period

        cout << Tzolkin(Haab(stoi(day), month, year)).toString() << '\n';
    }
}
