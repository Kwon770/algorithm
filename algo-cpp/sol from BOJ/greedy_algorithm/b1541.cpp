// https://www.acmicpc.net/problem/1541
// Greedy Algorithm(4), 잃어버린 괄호
// NUMBER 1541

// Greedy Algorithm, https://www.notion.so/sckwon770/Greedy-Algorithm-5f306db9c09945caa986ddc5989e4414

// 추가할 괄호에는 제한이 없으며, 계산값의 최소를 구해야하므로
// 괄호를 이용해 숫자끼리 덧셈하여 숫자를 최대한 크게 만들고, 크게 만든 숫자를
// 뺄셈하면 식의 최소가 된다는 수학적인 원리를 통해 푸는 문제

// 식은 구별없이 문자열로 주어지므로, 식을 구별하기 위해 replace_all 과 split을 직접 구현함

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

void replace_all(string &str, string searchStr, string replaceStr) {
    size_t pos = str.find(searchStr);
    while (pos != string::npos) {
        str.replace(pos, searchStr.size(), replaceStr);
        pos = str.find(searchStr, pos + replaceStr.size());
    }
}

void split(vector<string> &vec, string str, char deli) {
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, deli)) {
        vec.push_back(temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> ele;
    vector<int> exp;
    string str;
    cin >> str;
    replace_all(str, "+", " + ");
    replace_all(str, "-", " - ");
    split(ele, str, ' ');

    int temp;
    for (int i = ele.size() - 1; i >= 0; i--) {
        if (ele[i] == "+") {
            temp += atoi(ele[i - 1].c_str());
            i--;
        } else if (ele[i] == "-") {
            exp.push_back(temp);
            temp = 0;
        } else {
            temp = atoi(ele[i].c_str());
        }
    }

    for (int i = 0; i < exp.size(); i++) {
        temp -= exp[i];
    }
    cout << temp << endl;
    return 0;
}