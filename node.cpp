#include"node.h"
node::node(int input_num,double load_X,double load_Y,double disp_x,double disp_y,double X,double Y)
{
    globle_num=input_num;
    load_x=load_X;
    load_y=load_Y;
    displacement_x=disp_x;
    displacement_y=disp_y;
    x=X;
    y=Y;
}

node::~node()
{
}