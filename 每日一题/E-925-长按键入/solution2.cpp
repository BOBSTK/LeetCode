
/*
实现上，我们使用两个下标 i,j 追踪 name 和 typed 的位置。

当 name[i]=typed[j] 时，说明两个字符串存在一对匹配的字符，此时将 i,j都加 1。

否则，如果 typed[j]=typed[j-1]，说明存在一次长按键入，此时只将 j 加 1。

最后，如果 i=name.length，说明 name 的每个字符都被「匹配」了。
*/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.length()) {
            if (i < name.length() && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.length();
    }
};
