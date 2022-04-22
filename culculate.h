#pragma once
#include <Eigen/Dense>
#include <vector>
#include "triangle.h"
#include "node.h"
using namespace Eigen;
using namespace std;
#define t 0.01
#define deg 2   //自由度
#define miu 0.2 //泊松比
#define E 210E9 //弹性模量
class culculate
{
private:
    MatrixXd Globle_K; //总体刚度矩阵
    VectorXd Globle_L; //总体节点载荷列阵
    VectorXd Globle_D; //位移列阵
public:
    culculate(int node_num);
    ~culculate();
    void ThreeNodesTriangleSingle(triangle *tri);                //计算三角形单元单刚
    void ThreeNodeTriangleGlobleSingle(triangle *tri);           //合成总刚
    void ThreeNodeTriangleGlobleLoad(node *nod);                 //形成总体节点载荷
    void SoluteDisp();                                           //求解有限元方程，位移法
    void SetNodeDisp(node *nod);                                 //确定节点位移
    void SoluteStrain(triangle *tri);                            //求解应变
    void SoluteStress(triangle *tri);                            //求解应力
    void SetUnitNodes(triangle *tri, node *nod);                 //计算三角形单元对应总体坐标数组
    void SetUnitDisp(triangle *tri, node *nod); /*每个单元把节点上的位移储存在自己的数组里，用作展示*/
};
