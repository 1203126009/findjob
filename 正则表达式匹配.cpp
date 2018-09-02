////https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
bool match( char* str,  char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore( char* str,  char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            // 进入有限状态机的下一个状态
            return matchCore(str + 1, pattern + 2)
            // 继续留在有限状态机的当前状态 
            || matchCore(str + 1, pattern)
            // 略过一个'*' 
            || matchCore(str, pattern + 2);
        else
            // 略过一个'*'
            return matchCore(str, pattern + 2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}

};