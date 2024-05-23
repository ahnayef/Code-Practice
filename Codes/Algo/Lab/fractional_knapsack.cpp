#include <bits/stdc++.h>
using namespace std;

struct items
{
    double weight, price, unitprice;
};

double fractionalKnapsack(items item[], int n, double cap)
{
    double profit = 0.0;
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (item[j].unitprice < item[j + 1].unitprice)
            {
                swap(item[j], item[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    for (int i = 0; i < n; ++i)
    {
        if (item[i].weight <= cap)
        {
            profit += item[i].price;
            cap -= item[i].weight;
        }
        else
        {
            profit += cap * item[i].unitprice;
            cap = 0;
            break;
        }
    }
    return profit;
}

int main()
{
    int n, capacity;
    cout << "Enter the number of element: ";
    cin >> n;
    items item[n];
    cout << "Enter weight and profit: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> item[i].weight >> item[i].price;
        item[i].unitprice = item[i].price / item[i].weight;
    }
    cout << "Enter capacity: ";
    cin >> capacity;
    cout << "Maximum Profit: " << fractionalKnapsack(item, n, capacity) << endl;
}