//https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		vec.push_back(ch);
		mapdata[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		vector<char>::iterator it;
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if (mapdata[*it] == 1)
				return *it;
		}
		return '#';
	}
private:
	map<char, int> mapdata;
	vector<char> vec;
};
