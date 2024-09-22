// https://www.acmicpc.net/problem/2580
// Backtracking (6) 스도쿠
// NUMBER 2580

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 스도쿠의 규칙 상하좌우줄 그리고 3x3 사각형안에 모든 경우에서 1~9 의 숫자가 겹치면 안된다는 것을
// 백트랙킹으로 검사하여 구하면 됨.

// 단순히 백트랙킹만 하여 순서대로 숫자를 구하기만 하면 오류가 발생함 => 칸끼리 영향을 미침
// => 이는 DFS 를 사용하여 가능한 경우의 수를 모두 확인하여야 함.

// Vector 혹은 Deque를 통하여 풀었지만, 시간 초과때문에 배열만 사용하도록 바꿈.
// 내 풀이
//////////////////////////////////////////////////////////////////
// int arr[9][9];

// int GetUnitValue(int idx)
// {
//     switch (idx)
//     {
//     case 0:
//     case 1:
//     case 2:
//         return 0;
//     case 3:
//     case 4:
//     case 5:
//         return 3;
//     case 6:
//     case 7:
//     case 8:
//         return 6;
//     }
//     return 0;
// }

// void Solve(int cnt)
// {
//     if (cnt == 81)
//     {
//         for (int i = 0; i < 9; i++)
//         {
//             for (int o = 0; o < 9; o++)
//             {
//                 std::cout << arr[i][o] << " ";
//             }
//             std::cout << endl;
//         }

//         exit(0);
//     }

//     int y = cnt / 9;
//     int x = cnt % 9;

//     if (arr[x][y])
//     {
//         Solve(cnt + 1);
//     }
//     else
//     {
//         std::deque<int> deq;
//         for (int i = 1; i <= 9; i++)
//             deq.push_back(i);

//         for (int i = 0; i < 9; i++)
//         {
//             deq.erase(std::remove(deq.begin(), deq.end(), arr[i][y]), deq.end());
//             deq.erase(std::remove(deq.begin(), deq.end(), arr[x][i]), deq.end());
//         }

//         int xOff = GetUnitValue(x);
//         int yOff = GetUnitValue(y);
//         for (int i = xOff; i < xOff + 3; i++)
//         {
//             for (int o = yOff; o < yOff + 3; o++)
//             {
//                 deq.erase(std::remove(deq.begin(), deq.end(), arr[i][o]), deq.end());
//             }
//         }

//         for (std::deque<int>::iterator i = deq.begin(); i != deq.end(); i++)
//         {
//             arr[x][y] = *i;
//             Solve(cnt + 1);
//             arr[x][y] = 0;
//         }
//     }
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);

//     for (int i = 0; i < 9; i++)
//     {
//         for (int o = 0; o < 9; o++)
//         {
//             std::cin >> arr[i][o];
//         }
//     }

//     Solve(0);

//     return 0;
// }
//////////////////////////////////////////////////////////////////
//
//
// 정답 풀이
//
#include <iostream>

#define endl "\n"

int arr[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

int squareIdx(int y, int x)
{
    return (y / 3) * 3 + x / 3;
}

void Solve(int cnt)
{
    if (cnt == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int o = 0; o < 9; o++)
            {
                std::cout << arr[i][o] << " ";
            }
            std::cout << endl;
        }

        exit(0);
    }

    int y = cnt / 9;
    int x = cnt % 9;

    if (arr[y][x])
    {
        Solve(cnt + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!col[x][i] && !row[y][i] && !square[squareIdx(y, x)][i])
            {
                arr[y][x] = i;
                col[x][i] = true;
                row[y][i] = true;
                square[squareIdx(y, x)][i] = true;
                Solve(cnt + 1);
                arr[y][x] = 0;
                col[x][i] = false;
                row[y][i] = false;
                square[squareIdx(y, x)][i] = false;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            std::cin >> arr[i][o];
            if (arr[i][o])
            {
                col[o][arr[i][o]] = true;
                row[i][arr[i][o]] = true;
                square[squareIdx(i, o)][arr[i][o]] = true;
            }
        }
    }

    Solve(0);

    return 0;
}