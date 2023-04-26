#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

vector<pair<string, string>> diction(istream& is)
{
    vector<pair<string, string>> rule;
    string key;
    string val;
    while (is >> key && getline(is, val))
    {
        rule.push_back({ key,  val.substr(1) });
    }
    return rule;
}

void Rule(istream& map, istream& is, ostream& os)
{
    auto rule = diction(map);
    string str1;
    while (getline(is, str1))
    {
        auto it = rule.begin();
        do {
            string find = it->first;
            size_t sub = str1.find(find);
            if (sub != string::npos)
            {
                str1.replace(sub, find.size(), it->second);
                continue;
            }
            ++it;
        } while (it != rule.end());
        os << str1;
    }
}