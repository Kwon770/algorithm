// https://www.acmicpc.net/problem/10845
// NUMBER 10845, 큐

#include <iostream>
using namespace std;
#define endl '\n'

class Queue {
  int frontIdx;
  int backIdx;
  int size;
  int queueSize;
  int *arr;

public:
  Queue() {
    frontIdx = 0;
    backIdx = -1;
    size = 0;
    queueSize = 10;
    arr = new int[10];
  }
  ~Queue() { delete arr; }

  void Check_Size() {
    if (queueSize == backIdx + 1) {
      queueSize *= 2;
      int *temp = new int[queueSize];
      copy(arr, arr + (queueSize / 2), temp);
      delete arr;
      arr = temp;
    }
  }
  void Push(int n) {
    Check_Size();
    arr[backIdx + 1] = n;
    size++;
    backIdx++;
  }
  void Pop() {
    if (size == 0)
      cout << -1 << endl;
    else {
      cout << arr[frontIdx] << endl;
      frontIdx++;
      size--;
    }
  }
  void Size() { cout << size << endl; }
  void Empty() {
    if (size == 0)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  void Front() {
    if (size == 0)
      cout << -1 << endl;
    else
      cout << arr[frontIdx] << endl;
  }
  void Back() {
    if (size == 0)
      cout << -1 << endl;
    else
      cout << arr[backIdx] << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Queue queue = Queue();
  int n;
  cin >> n;
  string cmd;
  for (int i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd == "push") {
      int temp;
      cin >> temp;
      queue.Push(temp);
    } else if (cmd == "pop")
      queue.Pop();
    else if (cmd == "size")
      queue.Size();
    else if (cmd == "empty")
      queue.Empty();
    else if (cmd == "front")
      queue.Front();
    else if (cmd == "back")
      queue.Back();
  }
  return 0;
}
