#include <iostream>
#include<sstream>
#include<string>
using namespace std;
const int MAX_SIZE = 200;
int a[MAX_SIZE];
int b[MAX_SIZE];


int main()
{
	int cnt1 = 0;
	int cnt2 = 0;
	int number;
	string line;
    getline(cin,line);
    istringstream iss(line);
	while (iss >> number) {
		if (number % 2 == 0) {
			a[cnt1] = number;
			cnt1++;
		}
		else{
			b[cnt2] = number;
			cnt2++;
		}
		
	}

	for (int i = 0;i < cnt1;i++)
	{
		cout << a[i] << " ";
	}
	for (int i = 0;i < cnt2;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}