class Solution {
public:
    // 将s[j] 向上拨动一位
    string UP(string s,int j){
        int s_j = s[j] - '0';
        if(s_j  == 9){
            s[j] = '0';
        }else{
            s[j] += 1;
        }
        return s;
    }

    // 将s[j] 向下拨动一位
    string DOWN(string s,int j){
        int s_j = s[j] - '0';
        if(s_j  == 0){
            s[j] = '9';
        }else{
            s[j] -= 1;
        }
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        // 记录死亡密码
        set<string> deads;
        for(string s : deadends){
            deads.insert(s);
        }
            
        
        // 记录已经遍历过的密码
        set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                 string temp = q.front(); // 取出队首密码
                 q.pop();
                 if(temp == target) return step;
                 if(deads.find(temp) != deads.end()) continue; // 死亡密码，跳过
                 // 将该节点可能遍历的密码放入队列
                 for(int i=0;i<4;++i){
                     
                     string up = UP(temp,i);
                     if(visited.find(up) == visited.end()){
                         visited.insert(up);
                         q.push(up);
                     }
                     string down = DOWN(temp,i);
                     if(visited.find(down) == visited.end()){
                         visited.insert(down);
                         q.push(down);
                     }
                 }
                 
            }
            ++step;
        }
        
        
        return -1;
    }

};