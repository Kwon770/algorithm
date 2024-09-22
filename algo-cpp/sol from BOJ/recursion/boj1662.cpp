#include <iostream>
#include <utility>
#define endl "\n"
using namespace std;

string str;

// {current length, current index}
pair<int, int> recursion(int idx) {
	int total = 0;
	int multiplier;
	while (idx < (int)str.length()) {
		if (str[idx] == '(') {
			multiplier= str[idx - 1] - '0';
			pair<int, int> tmp = recursion(++idx);
			total += multiplier * tmp.first;
			// Substract multiplier number length (1) from total
			total--;
			idx = tmp.second + 1;
		} else if (str[idx] == ')') {
			return {total, idx};
		} else {
			total++;
			idx++;
		}
	}

	return {total, 0};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	cout << recursion(0).first;
	return 0;
}
