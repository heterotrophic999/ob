#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

using namespace std;

int main() {
    string line;
    char *buf;

    ifstream in("input.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            //cout << line << endl;
            buf = strtok(line, " .,!?\n");
        }
    }
    in.close();     // закрываем файл

    return 0;
}
