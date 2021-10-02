#include <iostream>
#include <fstream>
#include <list>
#include <cctype>
#include <sstream>
#include <map>

using namespace std;

string normalization(string row){
    for(int i = 0; i != '\n'; i++){
        if (!isalpha(row[i]) && !isdigit(row[i])){
            row[i] = ' ';
        }
    }
    return row;
}

map<string, int> strParse(list <string> rows){
    list <string>::iterator itr;
    map <string, int> ans;

    for(itr = rows.begin(); itr != rows.end(); itr++){
        stringstream str(*itr);
        string word;
        map<string, int>::iterator it;
        while (str >> word){
            if (ans.find(word) == ans.end()){
                ans[word] = 1;
            } else {
                ans[word] += 1;
            }
        }
    }
    return ans;
}

int main() {
    string line;
    list <string> rows;
    map <string, int> ans;

    ifstream in("input.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            line = normalization(line);
            rows.push_back(line);
        }
    }
    in.close();

    ans = strParse(rows);
    multimap<int, string> reverseAns;
    for (pair<string, int> r : ans) {
        reverseAns.insert(pair< int, string >(r.second, r.first));
    }

    ofstream out("output.csv");
    if (out.is_open()) {
        auto it = reverseAns.rbegin();
        while (it != reverseAns.rend()) {
            out << it->first << ";" << it->second << ";" << '\n';
            it++;
        }
    }
    out.close();

    return 0;
}
