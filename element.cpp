#include "element.h"
element::element()
{
}

element::~element()
{
}

void element::StartSolute()
{
    //创建节点(节点编号，横向载荷，纵向载荷，横向位移，纵向位移，横坐标，纵坐标)
    node *node1 = new node(1, 1000E3 * t, 0, 0, 0, 0, 1);
    node *node2 = new node(2, 0, 0, 0, 0, 0, 0.75);
    node *node3 = new node(3, 0, 0, 0, 0, 0, 0.5);
    node *node4 = new node(4, 0, 0, 0, 0, 0, 0.25);
    node *node5 = new node(5, 0, 0, 0, 0, 0, 0);
    node *node6 = new node(6, 0, 0, 0, 0, 0.25, 0);
    node *node7 = new node(7, 0, 0, 0, 0, 0.5, 0);
    node *node8 = new node(8, 0, 0, 0, 0, 0.75, 0);
    node *node9 = new node(9, 0, 0, 0, 0, 1, 0);
    node *node10 = new node(10, 0, 0, 0, 0, 1.25, 0);
    node *node11 = new node(11, 0, 0, 0, 0, 1.5, 0);
    node *node12 = new node(12, 0, 0, 0, 0, 1.75, 0);
    node *node13 = new node(13, 0, 0, 0, 0, 2, 0);
    node *node14 = new node(14, 0, 0, 0, 0, 1.75, 0.25);
    node *node15 = new node(15, 0, 0, 0, 0, 1.5, 0.5);
    node *node16 = new node(16, 0, 0, 0, 0, 1.25, 0.75);
    node *node17 = new node(17, 0, 0, 0, 0, 1, 1);
    node *node18 = new node(18, 0, 0, 0, 0, 0.75, 1);
    node *node19 = new node(19, 0, 0, 0, 0, 0.5, 1);
    node *node20 = new node(20, 0, 0, 0, 0, 0.25, 1);
    node *node21 = new node(21, 0, 0, 0, 0, 0.25, 0.75);
    node *node22 = new node(22, 0, 0, 0, 0, 0.25, 0.5);
    node *node23 = new node(23, 0, 0, 0, 0, 0.25, 0.25);
    node *node24 = new node(24, 0, 0, 0, 0, 0.5, 0.25);
    node *node25 = new node(25, 0, 0, 0, 0, 0.75, 0.25);
    node *node26 = new node(26, 0, 0, 0, 0, 1, 0.25);
    node *node27 = new node(27, 0, 0, 0, 0, 1.25, 0.25);
    node *node28 = new node(28, 0, 0, 0, 0, 1.5, 0.25);
    node *node29 = new node(29, 0, 0, 0, 0, 1.25, 0.5);
    node *node30 = new node(30, 0, 0, 0, 0, 1, 0.75);
    node *node31 = new node(31, 0, 0, 0, 0, 0.75, 0.75);
    node *node32 = new node(32, 0, 0, 0, 0, 0.5, 0.75);
    node *node33 = new node(33, 0, 0, 0, 0, 0.5, 0.5);
    node *node34 = new node(34, 0, 0, 0, 0, 0.75, 0.5);
    node *node35 = new node(35, 0, 0, 0, 0, 1, 0.5);
    //创建节点容器
    vector<node *> node_vector;
    vector<node *>::iterator node_iter = node_vector.begin();
    node_vector.insert(node_vector.end(), node1);
    node_vector.insert(node_vector.end(), node2);
    node_vector.insert(node_vector.end(), node3);
    node_vector.insert(node_vector.end(), node4);
    node_vector.insert(node_vector.end(), node5);
    node_vector.insert(node_vector.end(), node6);
    node_vector.insert(node_vector.end(), node7);
    node_vector.insert(node_vector.end(), node8);
    node_vector.insert(node_vector.end(), node9);
    node_vector.insert(node_vector.end(), node10);
    node_vector.insert(node_vector.end(), node11);
    node_vector.insert(node_vector.end(), node12);
    node_vector.insert(node_vector.end(), node13);
    node_vector.insert(node_vector.end(), node14);
    node_vector.insert(node_vector.end(), node15);
    node_vector.insert(node_vector.end(), node16);
    node_vector.insert(node_vector.end(), node17);
    node_vector.insert(node_vector.end(), node18);
    node_vector.insert(node_vector.end(), node19);
    node_vector.insert(node_vector.end(), node20);
    node_vector.insert(node_vector.end(), node21);
    node_vector.insert(node_vector.end(), node22);
    node_vector.insert(node_vector.end(), node23);
    node_vector.insert(node_vector.end(), node24);
    node_vector.insert(node_vector.end(), node25);
    node_vector.insert(node_vector.end(), node26);
    node_vector.insert(node_vector.end(), node27);
    node_vector.insert(node_vector.end(), node28);
    node_vector.insert(node_vector.end(), node29);
    node_vector.insert(node_vector.end(), node30);
    node_vector.insert(node_vector.end(), node31);
    node_vector.insert(node_vector.end(), node32);
    node_vector.insert(node_vector.end(), node33);
    node_vector.insert(node_vector.end(), node34);
    node_vector.insert(node_vector.end(), node35);
    //创建三节点三角形单元（局部1节点x，局部1节点y，局部2节点x，局部2节点y，局部3节点x，局部3节点y，）

    triangle *tri1 = new triangle(0, 0.75, 0.25, 0.75, 0, 1);
    triangle *tri2 = new triangle(0.25, 1, 0, 1, 0.25, 0.75);
    triangle *tri3 = new triangle(0, 0.75, 0, 0.5, 0.25, 0.75);
    triangle *tri4 = new triangle(0, 0.5, 0.25, 0.5, 0.25, 0.75);
    triangle *tri5 = new triangle(0, 0.25, 0.25, 0.25, 0, 0.5);
    triangle *tri6 = new triangle(0.25, 0.5, 0, 0.5, 0.25, 0.25);
    triangle *tri7 = new triangle(0, 0.25, 0, 0, 0.25, 0.25);
    triangle *tri8 = new triangle(0.25, 0, 0.25, 0.25, 0, 0);
    triangle *tri9 = new triangle(0.25, 1, 0.25, 0.75, 0.5, 1);
    triangle *tri10 = new triangle(0.5, 0.75, 0.5, 1, 0.25, 0.75);
    triangle *tri11 = new triangle(0.25, 0.5, 0.5, 0.5, 0.25, 0.75);
    triangle *tri12 = new triangle(0.5, 0.75, 0.25, 0.75, 0.5, 0.5);
    triangle *tri13 = new triangle(0.25, 0.5, 0.25, 0.25, 0.5, 0.5);
    triangle *tri14 = new triangle(0.5, 0.25, 0.5, 0.5, 0.25, 0.25);
    triangle *tri15 = new triangle(0.25, 0, 0.5, 0, 0.25, 0.25);
    triangle *tri16 = new triangle(0.5, 0.25, 0.25, 0.25, 0.5, 0);
    triangle *tri17 = new triangle(0.5, 0.75, 0.75, 0.75, 0.5, 1);
    triangle *tri18 = new triangle(0.75, 1, 0.5, 1, 0.75, 0.75);
    triangle *tri19 = new triangle(0.5, 0.75, 0.5, 0.5, 0.75, 0.75);
    triangle *tri20 = new triangle(0.75, 0.5, 0.75, 0.75, 0.5, 0.5);
    triangle *tri21 = new triangle(0.5, 0.25, 0.75, 0.25, 0.5, 0.5);
    triangle *tri22 = new triangle(0.75, 0.5, 0.5, 0.5, 0.75, 0.25);
    triangle *tri23 = new triangle(0.5, 0.25, 0.5, 0, 0.75, 0.25);
    triangle *tri24 = new triangle(0.75, 0, 0.75, 0.25, 0.5, 0);
    triangle *tri25 = new triangle(0.75, 1, 0.75, 0.75, 1, 1);
    triangle *tri26 = new triangle(1, 0.75, 1, 1, 0.75, 0.75);
    triangle *tri27 = new triangle(0.75, 0.5, 1, 0.5, 0.75, 0.75);
    triangle *tri28 = new triangle(1, 0.75, 0.75, 0.75, 1, 0.5);
    triangle *tri29 = new triangle(0.75, 0.5, 0.75, 0.25, 1, 0.5);
    triangle *tri30 = new triangle(1, 0.25, 1, 0.5, 0.75, 0.25);
    triangle *tri31 = new triangle(0.75, 0, 1, 0, 0.75, 0.25);
    triangle *tri32 = new triangle(1, 0.25, 0.75, 0.25, 1, 0);
    triangle *tri33 = new triangle(1, 0.25, 1, 0, 1.25, 0.25);
    triangle *tri34 = new triangle(1.25, 0, 1.25, 0.25, 1, 0);
    triangle *tri35 = new triangle(1, 0.25, 1.25, 0.25, 1, 0.5);
    triangle *tri36 = new triangle(1.25, 0.5, 1, 0.5, 1.25, 0.25);
    triangle *tri37 = new triangle(1.25, 0.5, 1.25, 0.75, 1, 0.5);
    triangle *tri38 = new triangle(1, 0.75, 1, 0.5, 1.25, 0.75);
    triangle *tri39 = new triangle(1, 0.75, 1.25, 0.75, 1, 1);
    triangle *tri40 = new triangle(1.25, 0.5, 1.5, 0.5, 1.25, 0.75);
    triangle *tri41 = new triangle(1.25, 0.5, 1.25, 0.25, 1.5, 0.5);
    triangle *tri42 = new triangle(1.5, 0.25, 1.5, 0.5, 1.25, 0.25);
    triangle *tri43 = new triangle(1.25, 0, 1.5, 0, 1.25, 0.25);
    triangle *tri44 = new triangle(1.5, 0.25, 1.25, 0.25, 1.5, 0);
    triangle *tri45 = new triangle(1.5, 0.25, 1.75, 0.25, 1.5, 0.5);
    triangle *tri46 = new triangle(1.5, 0.25, 1.5, 0, 1.75, 0.25);
    triangle *tri47 = new triangle(1.75, 0, 1.75, 0.25, 1.5, 0);
    triangle *tri48 = new triangle(1.75, 0, 2, 0, 1.75, 0.25);
    //创建单元容器
    vector<triangle *> TriangleUnit;
    TriangleUnit.insert(TriangleUnit.end(), tri1);
    TriangleUnit.insert(TriangleUnit.end(), tri2);
    TriangleUnit.insert(TriangleUnit.end(), tri3);
    TriangleUnit.insert(TriangleUnit.end(), tri4);
    TriangleUnit.insert(TriangleUnit.end(), tri5);
    TriangleUnit.insert(TriangleUnit.end(), tri6);
    TriangleUnit.insert(TriangleUnit.end(), tri7);
    TriangleUnit.insert(TriangleUnit.end(), tri8);
    TriangleUnit.insert(TriangleUnit.end(), tri9);
    TriangleUnit.insert(TriangleUnit.end(), tri10);
    TriangleUnit.insert(TriangleUnit.end(), tri11);
    TriangleUnit.insert(TriangleUnit.end(), tri12);
    TriangleUnit.insert(TriangleUnit.end(), tri13);
    TriangleUnit.insert(TriangleUnit.end(), tri14);
    TriangleUnit.insert(TriangleUnit.end(), tri15);
    TriangleUnit.insert(TriangleUnit.end(), tri16);
    TriangleUnit.insert(TriangleUnit.end(), tri17);
    TriangleUnit.insert(TriangleUnit.end(), tri18);
    TriangleUnit.insert(TriangleUnit.end(), tri19);
    TriangleUnit.insert(TriangleUnit.end(), tri20);
    TriangleUnit.insert(TriangleUnit.end(), tri21);
    TriangleUnit.insert(TriangleUnit.end(), tri22);
    TriangleUnit.insert(TriangleUnit.end(), tri23);
    TriangleUnit.insert(TriangleUnit.end(), tri24);
    TriangleUnit.insert(TriangleUnit.end(), tri25);
    TriangleUnit.insert(TriangleUnit.end(), tri26);
    TriangleUnit.insert(TriangleUnit.end(), tri27);
    TriangleUnit.insert(TriangleUnit.end(), tri28);
    TriangleUnit.insert(TriangleUnit.end(), tri29);
    TriangleUnit.insert(TriangleUnit.end(), tri30);
    TriangleUnit.insert(TriangleUnit.end(), tri31);
    TriangleUnit.insert(TriangleUnit.end(), tri32);
    TriangleUnit.insert(TriangleUnit.end(), tri33);
    TriangleUnit.insert(TriangleUnit.end(), tri34);
    TriangleUnit.insert(TriangleUnit.end(), tri35);
    TriangleUnit.insert(TriangleUnit.end(), tri36);
    TriangleUnit.insert(TriangleUnit.end(), tri37);
    TriangleUnit.insert(TriangleUnit.end(), tri38);
    TriangleUnit.insert(TriangleUnit.end(), tri39);
    TriangleUnit.insert(TriangleUnit.end(), tri40);
    TriangleUnit.insert(TriangleUnit.end(), tri41);
    TriangleUnit.insert(TriangleUnit.end(), tri42);
    TriangleUnit.insert(TriangleUnit.end(), tri43);
    TriangleUnit.insert(TriangleUnit.end(), tri44);
    TriangleUnit.insert(TriangleUnit.end(), tri45);
    TriangleUnit.insert(TriangleUnit.end(), tri46);
    TriangleUnit.insert(TriangleUnit.end(), tri47);
    TriangleUnit.insert(TriangleUnit.end(), tri48);
    //创建迭代器
    vector<triangle *>::iterator triangle_iter = TriangleUnit.begin();
    //创建计算对象
    culculate yxy_culculate = culculate(node_vector.size());
    //将三节点三角形单元放入节点，便于传递位移
    while (triangle_iter != TriangleUnit.end())
    {
        node_iter = node_vector.begin();
        while (node_iter != node_vector.end())
        {
            yxy_culculate.SetUnitNodes(*triangle_iter, *node_iter);
            node_iter++;
        }
        triangle_iter++;
    }
    triangle_iter = TriangleUnit.begin();
    node_iter = node_vector.begin();
    /*计算各个单元，对应节点，单元刚度矩阵,合成总纲*/
    while (triangle_iter != TriangleUnit.end())
    {
        yxy_culculate.ThreeNodesTriangleSingle(*triangle_iter);
        yxy_culculate.ThreeNodeTriangleGlobleSingle(*triangle_iter);
        triangle_iter++;
    }
    triangle_iter = TriangleUnit.begin();
    //计算节点载荷向量
    while (node_iter != node_vector.end())
    {
        yxy_culculate.ThreeNodeTriangleGlobleLoad(*node_iter);
        node_iter++;
    }
    node_iter = node_vector.begin();
    //计算代数方程，求出节点位移
    yxy_culculate.SoluteDisp();
    while (node_iter != node_vector.end())
    {
        yxy_culculate.SetNodeDisp(*node_iter);
        node_iter++;
    }
    node_iter = node_vector.begin();
    //计算单元顶点位移
    while (triangle_iter != TriangleUnit.end())
    {
        node_iter = node_vector.begin();
        while (node_iter != node_vector.end())
        {
            yxy_culculate.SetUnitDisp(*triangle_iter, *node_iter);
            node_iter++;
        }
        triangle_iter++;
    }
    triangle_iter = TriangleUnit.begin();
    node_iter = node_vector.begin();
    //计算单元应变,应力
    while (triangle_iter != TriangleUnit.end())
    {
        yxy_culculate.SoluteStrain(*triangle_iter);
        yxy_culculate.SoluteStress(*triangle_iter);
        triangle_iter++;
    }
    triangle_iter = TriangleUnit.begin();
    delete tri1, tri2, tri3, tri4, tri5, tri6, tri7, tri8, tri9, tri10, tri11, tri12,
        tri13, tri14, tri15, tri16, tri17, tri18, tri19, tri20, tri21, tri22,
        tri23, tri24, tri25, tri26, tri27, tri28, tri29, tri30, tri31, tri32,
        tri33, tri34, tri35, tri36, tri37, tri38, tri39, tri40, tri41, tri42,
        tri43, tri44, tri45, tri46, tri47, tri48;
    delete node1, node2, node3, node4, node5, node6, node7, node8, node9, node10, node11, node12,
        node13, node14, node15, node16, node17, node18, node19, node20,
        node21, node22, node23, node24, node25, node26, node27, node28, node29, node30,
        node31, node32, node33, node34, node35;
}
