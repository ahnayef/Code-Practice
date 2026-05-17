#include <bits/stdc++.h>
using namespace std;

void vizualize(const string &text, const string &key)
{
     int numColumns = key.size();
     int numRows = (text.size() + numColumns - 1) / numColumns;

     string grid = text;
     while ((int)grid.size() < numRows * numColumns)
          grid += 'X';

     vector<int> order = getColumnOrder(key);
}

int main()
{
     string text = "ATTACKATDAWN", key = "CARGO";

     visualize(text, key);
}