#include <iostream>
using namespace std;

/////////////////////////////////
/*
문제: 
크기가 2^N × 2^N인 2차원 배열을 Z모양으로 탐색하려고 함. (왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래)
N > 1 -> 2^(N-1) x 2^(N-1)로 4등분 후 재귀적으로 순서대로 방문함. (위의 순서와 동일)
N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램 작성 (1 <= N <= 15, 0 <= r, c < 2^N)

입력:
N r c

출력:
r행 c열을 몇 번째로 방문했는지

예시 입력:
2 3 1
3 7 7
1 0 0
4 7 7
10 511 511
10 512 512

예시 출력:
11
63
0
63
262143
786432

*/
/////////////////////////////////
// Global Variables

/////////////////////////////////
// Function Prototypes
int getNumVisited(int pow2n, int r, int c);

/////////////////////////////////
// Class

/////////////////////////////////
// Main

int main()
{
    int n, r, c, pow2n = 1;
    cin >> n >> r >> c;

    for (int i = 0; i < n; i++)
        pow2n *= 2;

    cout << getNumVisited(pow2n, r, c);

    return 0;
}

/////////////////////////////////
// Function

int getNumVisited(int pow2n, int r, int c)
{
    if (pow2n == 1) return 0;

    int isRBiggerMid = 0, isCBiggerMid = 0;
    int mid = pow2n / 2;

    if (r >= mid) isRBiggerMid = 2;
    if (c >= mid) isCBiggerMid = 1;

    return getNumVisited(mid, r - mid*((isRBiggerMid == 2)?1:0), c - mid*isCBiggerMid) + mid*mid * (isRBiggerMid + isCBiggerMid);
}

/////////////////////////////////