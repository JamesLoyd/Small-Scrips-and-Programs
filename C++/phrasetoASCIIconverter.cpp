#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
    char phrase[40];
    cout << "Enter a phrase: ";
    cin.get (phrase, 40);
    int k;
    for (int i =0;phrase[i];i++)
    {
        k = static_cast<int>(phrase[i]);
        cout << k << " ";

    }
}
