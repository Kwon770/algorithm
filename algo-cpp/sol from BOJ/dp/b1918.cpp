// https://www.acmicpc.net/problem/1918
// 1918 후위 표기식
//
// 풀이, https://www.notion.so/sckwon770/1918-24fe9e7e8b2d4f889542ad58e9baf3e6
//
#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string ans;
	stack<char> s;
	for (int i = 0; i < (int)str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z')
			ans += str[i];
		else {
			switch (str[i]) {
				case '(':
					s.push(str[i]);
					break;
				case '*':
				case '/':
					while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
						ans += s.top();
						s.pop();
					}
					s.push(str[i]);
					break;
				case '+':
				case '-':
					while (!s.empty() && s.top() != '(') {
						ans += s.top();
						s.pop();
					}
					s.push(str[i]);
					break;	
				case ')':
					while (!s.empty() && s.top() != '(') {
						ans += s.top();
						s.pop();
					}
					s.pop();
					break;
			}
		}
	}

	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}

	cout << ans;
	return 0;
}
