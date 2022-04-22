#pragma once
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;
class triangle
{
private:
    double x1, y1, x2, y2, x3, y3;             //顶点坐标
    double displayment[3][2];                  //坐标位移
    Vector3d strain;                           //平面问题应变
    Vector3d stress;                           //平面问题应变
    double area;                               //单元面积
    double ai, aj, am, bi, bj, bm, ci, cj, cm; //参数
    int unit_node[3];                          //存储单元节点
    Matrix<double, 6, 6> single_K;             //单元刚度矩阵
public:
    triangle(double X1, double Y1, double X2, double Y2, double X3, double Y3); //构造函数，获得参数
    ~triangle();
    friend class culculate;
};
