#include<iostream>
#include <cmath>
using namespace std;
const static int Open_Open = 0;  //初始状态，给水管开 排水管开
const static int Open_Close = 1;   //给水管开 排水管关
const static int Close_Open = 2;   //给水管关 排水管开
const static int Close_Close = 3;  //给水管关 排水管关


int main(){
    int T; //T 组数据
    cin>>T;
   while(T--){
       int m,t,m1,t1,m2,t2;
       cin>>m>>t>>m1>>t1>>m2>>t2;
       int state = Open_Open; //初始状态
       int in_timer = t1; //给水管计时器
       int out_timer = t2; //排水管计时器
       int current = 0; //当前容量
       for(int i=0;i<t;i++){ //每分钟判定一次
           switch(state){
               case Open_Open:
                   //计时器
                   --in_timer;
                   --out_timer;
                   //计算在当前状态一分钟后游泳池的容量
                   current += (m1-m2);
                   current = max(0,current);
                   current = min(m,current);
                   //是否需要切换状态
                   if(in_timer==0 && out_timer==0){
                       //重置计时器
                       in_timer = t1;
                       out_timer = t2;
                       state = Close_Close;
                   }else if(in_timer==0 && out_timer>0){
                       //重置计时器
                       in_timer = t1;
                       state = Close_Open;
                   }else if(in_timer > 0 && out_timer == 0){
                       //重置计时器
                       out_timer = t2;
                       state = Open_Close;
                   }
                   break;
                   
               case Open_Close:
                   //计时器
                   --in_timer;
                   --out_timer;
                   //计算在当前状态一分钟后游泳池的容量
                   current += m1;
                   //current = max(0,current);
                   current = min(m,current);
                   //是否需要切换状态
                   if(in_timer==0 && out_timer==0){
                       //重置计时器
                       in_timer = t1;
                       out_timer = t2;
                       state = Close_Open;
                   }else if(in_timer==0 && out_timer>0){
                       //重置计时器
                       in_timer = t1;
                       state = Close_Close;
                   }else if(in_timer > 0 && out_timer == 0){
                       //重置计时器
                       out_timer = t2;
                       state = Open_Open;
                   }
                   break;
                   
                   
                   case Close_Open:
                   //计时器
                   --in_timer;
                   --out_timer;
                   //计算在当前状态一分钟后游泳池的容量
                   current -= m2;
                   current = max(0,current);
                   //current = min(m,current);
                   //是否需要切换状态
                   if(in_timer==0 && out_timer==0){
                       //重置计时器
                       in_timer = t1;
                       out_timer = t2;
                       state = Open_Close;
                   }else if(in_timer==0 && out_timer>0){
                       //重置计时器
                       in_timer = t1;
                       state = Open_Open;
                   }else if(in_timer > 0 && out_timer == 0){
                       //重置计时器
                       out_timer = t2;
                       state = Close_Close;
                   }
                   break;
                   
                   case Close_Close:
                   //计时器
                   --in_timer;
                   --out_timer;
                   //计算在当前状态一分钟后游泳池的容量
                   //current += 0;
                   //current = max(0,current);
                   //current = min(m,current);
                   //是否需要切换状态
                   if(in_timer==0 && out_timer==0){
                       //重置计时器
                       in_timer = t1;
                       out_timer = t2;
                       state = Open_Open;
                   }else if(in_timer==0 && out_timer>0){
                       //重置计时器
                       in_timer = t1;
                       state = Open_Close;
                   }else if(in_timer > 0 && out_timer == 0){
                       //重置计时器
                       out_timer = t2;
                       state = Close_Open;
                   }
                   break;
                   default:
                   break;
           }
       }
       cout<<current<<endl;
   }

}