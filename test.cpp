#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
    string x,y;
    cout << "x,y : ";
    cin >> x >> y;
    string out = "echo ";
    out += "\"";
    out += x;
    out += "\n";
    out += y;
    out += "\" | ";
    out += "python test.py";

    system(out.c_str());
    return 0;
}