#include <iostream>
using namespace std;

const int n = 1000;   
long long a[n + 1];  

int main() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)  a[i] = a[i - 1] + a[i - 2];
    

    return 0;
}
