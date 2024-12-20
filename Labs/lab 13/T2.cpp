#include <iostream>
#include <vector>
using namespace std;

int hashFunction(vector <int>& a) {
	vector <int> b(2001, 0);
	for (int nums : a) {
		b[nums + 1000] += 1;
		
	}
	int outputs;
	for (int i = 1; i < 2001; i++) {
		if (b[i] == 1) {
			outputs = i;
			outputs = outputs - 1000;
			break;
		}
	}
	return outputs;
}


int main() {
	vector<int> v;
	v = { 1,2,3,5,7,1,2,7,3,5 };
	int x = hashFunction(v);
	cout << x;
	return 0;
}
