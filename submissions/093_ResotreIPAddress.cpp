/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

/*
必须一直搜索到结尾才能确定结果，使用深搜。
使用一个vector<string> 来保存当前所获得的ip地址，到搜索完成时，
如果产生了合法的ip，将其拼接成合法的ip地址返回。
*/

class Solution{
public:
  vector<string> resotreIpAddresses(string s){
    vector<string> res;
    vector<string> ip;
    dfs(res,ip,s,0);
    return res;
  }

  void dfs(vector<string> &res,vector<string> &ip, string s,int pos){
    if(pos==s.length()&&ip.size()==4){
      string s;
      for(auto str:ip){
        s.append(str).push_back('.');
      }
      s.pop_back();
      res.push_back(s);
      return;
    }

    //剪枝
    if(s.length()-k > (4-ip.size())*3) return; //剩余字符太多，即使每段ip三个字符都有剩
    if(s.length()-k <  4-ip.size()) return; //剩余字符数目小于ip地址剩余段数

    //取接下来三个字符
    int num = 0;
    for(int i = pos;i<pos+3;i++){
      //转为数字，看是否合法
      num = num*10+s[i]-'0';
      if(num<0||num>255) break;

      //如果合法，将该字符串放到ip中，并继续搜索
      ip.push_back(s.substr(pos,i-pos+1));
      dfs(res,ip,string,i+1);
      //同一个pos可以产生三个ip，要保证它们互不影响。
      ip.pop_back();
    }
  }
};
