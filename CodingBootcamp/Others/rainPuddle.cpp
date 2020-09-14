#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int puddle(vector<int> &ary);

int main(void) {
	vector<int> ary1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	vector<int> ary2 = { 0, 2, 0, 2, 0, 1, 1, 3, 1, 1, 2, 0 };
	cout << "���� array { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }�� �� : "<< puddle(ary1) << endl;
	cout << "���� array { 0, 2, 0, 2, 0, 1, 1, 3, 1, 1, 2, 0 }�� �� : " << puddle(ary2) << endl;
	return 0;
}

int puddle(vector<int> &ary) {
	int ans = 0;
	deque<int> arr1;
	deque<int> arr2;
	
	int max = ary.front();
	for (int i = 0; i < ary.size(); i++) {//���ʺ��� ����
		if (ary[i] > max)
			max = ary[i];
		arr1.push_back(max);
	}

	max = ary.back();
	for (int j = ary.size() - 1; j >= 0; j--) {//�����ʺ��� ����
		if (ary[j] > max)
			max = ary[j];
		arr2.push_front(max);
	}

	for (int i = 0; i < ary.size(); i++) {//���ʿ��� �� min�� ��
		(arr1[i] <= arr2[i]) ? ans += arr1[i] : ans += arr2[i];
		ans -= ary[i]; // �� ĭ�� ����.(���� �̷���� ĭ ������ ����)
	}

	return ans;
}