#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main() {
	string keyChar[] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> vKeyChar(keyChar, keyChar + 8);
	string digit = "23345";

	int digitLen = digit.length();
	int digit_it = 0;
	vector<string> v1;
	vector<string> v2;

	//提交前需判断digit的长度是否为零以及其中是否含有01
	//首先需要初始值
	string init_s = vKeyChar[digit[0] - '2'];
	cout << init_s << endl;

	for (int i = 0; i < init_s.length(); i++) {
		string temp = "";
		temp.push_back(init_s[i]);
		v1.push_back(temp);

	}
	digit_it++;

	//已经用第一个数字初始化了v1，索性采用一个变量来控制，指向digit字符串当前遍历的位置
	for (; digit_it < digitLen; digit_it++) {
		//temp_s1代表键盘上数字对应的字符串，如2代表abc
		string temp_s1 = vKeyChar[digit[digit_it] - '2'];
		int s1_len = temp_s1.length();
		//此处循环需要v1，但v1是不断更新的，所以我们下面使用了v2来保存新产生的vector，并将其复制给v1
		for (int j = 0; j < v1.size(); j++) {
			for (int k = 0; k < s1_len; k++) {
				string ts1 = v1[j];
				ts1.push_back(temp_s1[k]);
				v2.push_back(ts1);
			}
		}
		//新产生的vector是v2，正是下一次循环所要使用的v1，所以，在这儿将v2的值赋给v1，并将v2清空来存储下次循环新产生的vecotr
		vector<string> temp_v = v2;
		v1.clear();
		v2.clear();
		v1 = temp_v;
	}
	for (int i = 0; i < v1.size(); i++) {
		string s = v1[i];
		cout << s << endl;
	}
	//system("pause");
	return 0;

}
