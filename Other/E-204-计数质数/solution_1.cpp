//随机数引擎
	mt19937 rng{ random_device{}() }; 
	//随机数分布
	uniform_real_distribution<double> uni{ -1, 1 };//生成-1 - 1序列
class Solution {
public:
    double radius;   //半径
    double x_center; //圆心x坐标
    double y_center; //圆心y坐标

    Solution(double radius, double x_center, double y_center) {
      this->radius = radius;
      this->x_center = x_center;
      this->y_center = y_center;
    }
    
    vector<double> randPoint() {
      //循环采样
      while(1){
        //在 [-R,R]上取值
        double x = uni(rng) * radius;
        double y = uni(rng) * radius;
        if (x*x + y*y > radius*radius)  //在圆外，重新取值
          continue;
        return {x_center + x,y_center+y}; 
      }
    }

};