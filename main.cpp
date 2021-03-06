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
    double sumAll = 0;
    multimap<int, string> reverseAns;
    for (pair<string, int> r : ans) {
        sumAll += r.second;
        reverseAns.insert(pair< int, string >(r.second, r.first));
    }

    ofstream out("output.csv");
    if (out.is_open()) {
        auto it = reverseAns.rbegin();
        while (it != reverseAns.rend()) {
            out << it->second << ";" << it->first << ";" << it->first/sumAll*100 << '%' << '\n';
            it++;
        }
    }
    out.close();
    // У меня огромный вопрос насчёт csv:
    // из названия следует, что разделять значения стоит именно запятыми,
    // в интернете тоже пишут, что запятыми.
    // Но почему, когда я разделяю запятыми Excel не видит разделения?!
    // На каком-то сайте прочитал, что разделять нужно "именно ',', а не ';' -
    // - решил попробовать точку с запятой и в Excel таблица всё-таки стала таблицей.
    // Почему так?
    ////////////

    return 0;
}
