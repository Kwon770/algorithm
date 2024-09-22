#include <iostream>
#include <vector>
#include <utility>
#define endl "\n"
using namespace std;

int n, counting = 0;
vector<pair<int, int>> ans;

void move(int from, int to) {
	counting++;
	ans.push_back(make_pair(from, to));
}

void hanoi(int n, int from, int to, int via) {
	if (n == 1) move (from, to);
	else {
		hanoi(n - 1, from, via, to);
		move(from, to);
		hanoi(n - 1, via, to, from);
	}
}


int main() {
	cin >> n;
	hanoi(n, 1, 3, 2); 
	cout << counting << endl;
	auto iter = ans.begin();
	while(iter != ans.end()){
		cout << (*iter).first << " " << (*iter).second << endl;
		iter++;
	}	
	return 0;
}
