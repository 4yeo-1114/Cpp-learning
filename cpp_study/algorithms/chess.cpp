/* C++ | algorithms: chess. */
#include <iostream>
using namespace std;

bool win(string& g, char u){
  // 检查三行、三列、两对角线是否出现棋手u的三连，返回true表示u获胜。
  // 三行
  if(g[0]==u&&g[1]==u&&g[2]==u) return true;
  if(g[3]==u&&g[4]==u&&g[5]==u) return true;
  if(g[6]==u&&g[7]==u&&g[8]==u) return true;
  // 三列（Bug修复：之前漏了列检查）
  if(g[0]==u&&g[3]==u&&g[6]==u) return true;
  if(g[1]==u&&g[4]==u&&g[7]==u) return true;
  if(g[2]==u&&g[5]==u&&g[8]==u) return true;
  // 两对角线
  if(g[0]==u&&g[4]==u&&g[8]==u) return true;
  if(g[2]==u&&g[4]==u&&g[6]==u) return true;
  return false;
}

int eval(string& g, char a, char b, int r){
  // 参数：局面、当前棋手、对方、剩余空格。
  if(win(g, a)){ return  (r + 1); }
  if(win(g, b)){ return -(r + 1); } // 当前局面如果b胜利，对a来说就是负分。
  int best = -9; // 初始化成不可能的分数（获胜时双方至少要下5子，剩4格空，不会-9分）
  for(int i = 0; i < 9; ++i){
    /* TODO:
    尝试每个空白
      按当前棋手a落子，
      交换角色，以对手角色评估棋局得分（递归调用eval）。
      那么该下法对手得分取负就是我方得分。
      如果得分更高，更新best。
      恢复空白
    */
   if(g[i]=='.'){
    g[i]=a;
    best = max(best,-eval(g,b,a,r-1));
    g[i] =' ';
   }
  }
  // 如果best没被修改，说明无空可下，平局。
  return best == -9 ? 0 : best;
}

int main(){
  for(string g; cin >> g;){
    // TODO: 统计X、O数量，确定当前棋手a、对手b所执的字符。
    int a1=0,b1=0,r=0;
    for(int i = 0;i<9;i++){
        if(g[i]=='X'){
            a1++;
        }
        else if(g[i]=='O'){
            b1++;
        }
        else{
            r++;
        }
    }
    char a,b;
    // Bug修复：X先手，数量相等时X走，X多一个时O走
    if(a1 == b1){
        a = 'X';
        b = 'O';
    }
    else{
        a = 'O';
        b = 'X';
    }
    cout << a << ' ' << eval(g, a, b, r) << endl;
  }
}