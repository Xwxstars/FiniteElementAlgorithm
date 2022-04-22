#pragma once
//节点类作用：传递位移
class node
{
private:
    int globle_num;                                    //整体编号
    double displacement_x , displacement_y; //位移
    double load_x, load_y;                             //节点载荷
    double x, y;                                       //坐标
public:
    friend class culculate;
    node(int globle_num, double load_X, double load_Y, double disp_x,double disp_y,double X, double Y);
    ~node();
};
