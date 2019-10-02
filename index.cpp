#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include<algorithm>

using namespace std;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }

    return elems;
}

int main() {
    ifstream ifs("beatmania.txt");
    vector<string> enable_rows;

    if (ifs.fail()) {
        cerr << "opening failed\n";
        return EXIT_FAILURE;
    }

    for (string str; getline(ifs, str);) {
        bool is_invalid = false;
        vector<string> vec = split(str, ',');

        if (vec.size() != 4)  {
            continue;
        }

        for_each(vec.begin(), vec.end(), [&is_invalid](string& v) {
            if (v.compare("※") == 0) {
                is_invalid = true;
            }
        });

        if (is_invalid) {
            continue;
        }

        enable_rows.push_back(str);
    }

    for_each(enable_rows.begin(), enable_rows.end(), [](string& enable_row) {
        cout << enable_row;
    });
}
