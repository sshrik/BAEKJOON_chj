#include <stack>
#include <string>
#include <iostream>

using namespace std;

string strDecode(string str);

int main() {
	string a1 = strDecode("3[a]2[bc]");
	string a2 = strDecode("3[a2[c]]");
	string a3 = strDecode("2[abc]3[cd]ef");
	string a4 = strDecode("abc3[cd]xyz");
	cout << "3[a]2[bc] �� ���ڵ� ��� : "<<a1 << endl;
	cout << "3[a2[c]] �� ���ڵ� ��� : " << a2 << endl;
	cout << "2[abc]3[cd]ef �� ���ڵ� ��� : " << a3 << endl;
	cout << "abc3[cd]xyz �� ���ڵ� ��� : " << a4 << endl;
	return 0;
}


string strDecode(string str) {
	string ans;
	stack<string> s;

	for(int i = 0;i<str.length();i++){
		if (str[i] == ']') {
			string temp;
			while (s.top() != "[") {
				temp = s.top() + temp;
				s.pop();
			}
			s.pop();// '[' ����
			int num = stoi(s.top());
			s.pop(); // ���� ����
			for (int i = 0; i < num; i++)
				s.push(temp);
		}
		else {// ']'���� ������ stack �� push
			string ss;
			ss += str[i];
			s.push(ss);
		}
	}

	while (!s.empty()) {//��ȣ�� �� Ǭ stack�� string�� �־���
		ans = s.top() + ans;
		s.pop();
	}
		
	return ans;
}