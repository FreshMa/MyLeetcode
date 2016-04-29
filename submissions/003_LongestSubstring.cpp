/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
c++ string类很强大
基本思路：
1.定义一个子串变量sub，它用来存储在发现重复字符前遍历过的子串，当发现push_back某个字符时使它出现了重复字符，那么将sub中发生重复的原字符
以及位于它之前的字符擦除（使用string的erase方法）。
2.定义一个变量len来存储在发现重复字符前的子串长度，并且在发现重复字符之后，将它的长度改变为“它原本长度减去子串中出现重复的位置”。
3.定义一个变量max通过与len比较来存储遍历过程中最长子串长度。
4.判断，如果它长度小于2，直接返回它的长度
5.该算法的时间复杂度为O(n)。
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		string sub = "";
		int len = 0;
		int max = 0;
		int i = 0;
		if (s.length()<2) {
			return s.length();
		}
		else {
			for (; i<s.length(); i++) {
				int pos = sub.find(s[i]);
				//将该字符加入子串中
				sub.push_back(s[i]);
				//如果该字符没有与子串中某字符重复，长度加一
				if (pos == sub.npos) {
					len++;
				}
				//如果重复了，将发生重复的原字符以及位于它之前的字符从子串中擦除
				//并将len的值重置为如今子串的长度(len-=pos相当于len = sub.length())
				else {
					sub.erase(0, pos + 1);
					len = len - pos;
				}
				max = len > max ? len : max;
			}
			return max;
		}
	}
};
