class Solution {
public:

    void computeNext(string p,int next[]){
        int pLen = p.length();
        int k = -1;
        int j = 0;
        next[0]=-1;
        while(j<pLen){
//p[k]代表特征串前缀，p[j]代表特征串后缀
            if(k==-1||p[k]==p[j]){
                k++;
                j++;
                next[j] = k;
            }
            else{
                k = next[k];
            }
        }
    }
    int strStr(string haystack, string needle) {
        int next[100000];
        int hLen = haystack.length();
        int nLen = needle.length();
        int i = 0;
        int j = 0;
        int result;
        computeNext(needle,next);
        while(i<hLen&&j<nLen){
            if(j == -1||haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
        }
        result = j==nLen?i-j:-1;
        return result;
    }
};
