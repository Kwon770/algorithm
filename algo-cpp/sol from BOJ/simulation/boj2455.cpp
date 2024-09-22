#include <iostream>
#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int station, maxPeople = -1, people = 0;
	for (int i = 1; i <= 4; i++) {
		int gettingOn, gettingOff;
		cin >> gettingOff >> gettingOn;
		people = people - gettingOff + gettingOn;
		if (maxPeople < people) {
			maxPeople = people;
			station = i;
		}

	}
	cout << maxPeople;
	return 0;
}
