#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int partition(vector<int>& R, int s, int t) {
	int i = s;
	int j = s + 1;
	int base = R[s];
	while (j <= t) {
		if (R[j] <= base) {
			i++;
			if (i != j)
				swap(R[i],R[j]);
		}
		j++;
	}
	swap(R[s], R[i]);
	return i;
}
void quicksort(vector<int>& R, int s, int t) {
	if (s < t) {
		int i = partition(R, s, t);
		quicksort(R, s, i - 1);
		quicksort(R, i + 1,t);
	}
}
void Quicksort(vector<int>& R, int n) {
	quicksort(R, 0, n - 1);
}
int main() {
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	vector<int>R;
	int a;
	while (ifs >> a)
		R.push_back(a);
	Quicksort(R, R.size());
	for (int i = R.size() - 1; i >= R.size() - 10; i--)
		ofs << R[i] << " ";
	return 0;
}