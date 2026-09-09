/* C++ | exams: ipv6. */
#include<string>
using namespace std;
string binaryToIPv6(const string& binaryStr){
    string s = binaryStr;
    int len =s.length();
    if(len<128) s.append(128-len,'0');
    else if(len>128) s.erase(128,len-128);
    string ans ;
    const char hexMap[] = "0123456789abcdef";
    for(int i = 0;i<8;i++){
        string bin = s.substr(i*16,16);
        string block = "";
       for(int j = 0 ;j<4;j++){
           string sub = bin.substr(j*4,4);
           int sum = 0;
           for(auto c:sub){
               sum = sum *2 + (c-'0');
           }
           block += hexMap[sum];
       }
        while(block.length()>1&&block[0]=='0'){
                block.erase(0,1);
            
        }
        ans += block;
        if(i!=7) ans+=':';
            
        }
      return ans;
}
