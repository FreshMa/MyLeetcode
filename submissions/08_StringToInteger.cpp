class Solution {
public:
    int myAtoi(string str) {
		//用一个新字符串用来存储数字
        string numstr = "";
        double sum = 0;
		//这个数是否是负数，即是否找到-号
        int isNeg = 0;
		//找到+号
        int findAdd = 0;
		//找到数字
        int findInt = 0;
		//找到字符
        int findChar = 0;
		//数字是否连续
        int isCon = 1;
		//存储结果
        double result;
        if (str.length() == 0){
            return 0;
        }
        else{
		//遍历，如果发现数字不连续，直接退出
            for(int i = 0;i<str.length()&&isCon;i++){
			//如果没有找到数字并且找到了负号，标记
                if(!findInt && (str[i]=='-')){
                    isNeg ++;
                }
				//如果没有找到数字，并且没有找到负号和＋，但是发现了空格，略过
                else if(!findInt&&(!isNeg)&&(!findAdd)&&(str[i] == ' ')){
                    continue;
                }
				//如果找到了＋，标记
                else if(str[i] == '+'){
                    findAdd ++;
                }
				//此外如果找到了非数字，标记，如果此前找到了数字，说明不连续
                else if((str[i]<'0')||(str[i]>'9')){
                    findChar = 1;
                    if(findInt){
                        isCon = 0;
                    }
                }
				//最后再次确定没有找到字符，说明找到了数字，那么将这个数字放到新字符串中
                else if(!findChar){
                    findInt = 1;
                    numstr.push_back(str[i]);
                }
            }
        }
		//判断是否出现多个+-号
        if(isNeg&&findAdd||(isNeg>1)||(findAdd)>1){
            return 0;
        }
		//计算新字符串中的值
        for(int i = 0,j=numstr.length()-1;i<numstr.length(),j>=0;i++,j--){
            double charToNum = numstr[i]-48;
            double tenNum = 1;
            for (int ini = 0; ini<j; ini++){
	            tenNum *= 10;
	        }
            sum+=charToNum*tenNum;
        }
		//判断是否超过了int的表示范围
        if(!isNeg&&(sum>2147483647)){
            result = 2147483647;
        }
		//直接写result = -2147483648 会出现C4146错误
        else if(isNeg&&(sum>=2147483648)){
            result = -2147483647-1;
        }
        else{
            result = isNeg?-sum:sum;    
        }
        
        return result;
    }
};
