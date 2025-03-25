#include <iostream>
using namespace std;

void Triangle(int n) 
{
    int t[35][35] = {0}; 


    for (int i = 0; i < n; i++) 
    {
        t[i][0] = 1; // 每行的第一个元素为 1
        t[i][i] = 1; // 每行的最后一个元素为 1

        for (int j = 1; j < i; j++) t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
    }


    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
                if (j > 0) cout << " ";
                cout << t[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    Triangle(n);

    return 0;
}
