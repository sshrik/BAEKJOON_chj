#include <vector>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

/*
    m*n ũ���� island.
    m�� n, island �迭�� ���ڷ� �޴´ٰ� ������.
*/

int solution(int m, int n, vector<vector<string>> island) {
    int number_of_area = 0;
    stack<pair<int, int>>s;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (island[i][j] == "1") {//��ĥ�� ĭ�� �߰��Ѵٸ� ���� ũ�� ���� ����.
                ++number_of_area;
                s.push(make_pair(i, j));
                island[i][j] = "0";
            }
            else
                continue;
            while (!s.empty()) {//��ĥ �� �ִ� ĭ�� stack�� �ְ� �ϳ��� �����鼭 �����¿� �˻��ϱ�.
                int fir = s.top().first;
                int sec = s.top().second;
                s.pop();
                for (int k = 0; k < 4; k++) {//�����¿� �˻�
                    if ((fir + dx[k] >= m) || (fir + dx[k] < 0) || (sec + dy[k] >= n) || (sec + dy[k] < 0))//�� ���� ������� �˻�
                        continue;
                    else if (island[fir + dx[k]][sec + dy[k]] == "1") {
                        s.push(make_pair(fir + dx[k], sec + dy[k]));
                        island[fir + dx[k]][sec + dy[k]] = "0";
                    }
                }

            }
        }
    }
    return number_of_area;
}

int main(void) {
    vector<vector<string>> island1 { {"1", "1", "1", "1", "0"} ,
        {"1", "1", "0", "1", "0"},
        {"1", "1", "0", "0", "0"},
        {"0", "0", "0", "0", "0"} };
    cout << "���� �� " << solution(island1.size(), island1[0].size(), island1) << "�� �Դϴ�." << endl;

    vector<vector<string>> island2{ {"1", "1", "0", "0", "0"} ,
        {"1", "1", "0", "0", "0"},
        {"0", "0", "1", "0", "0"},
        {"0", "0", "0", "1", "1"} };
    cout << "���� �� " << solution(island2.size(), island2[0].size(), island2) << "�� �Դϴ�." << endl;

    vector<vector<string>> island3{ {"1", "1", "0", "1", "0"} ,
        {"1", "1", "0", "0", "1"},
        {"0", "0", "1", "0", "0"},
        {"1", "1", "0", "1", "1"} };
    cout << "���� �� " << solution(island3.size(), island3[0].size(), island3) << "�� �Դϴ�." << endl;

}