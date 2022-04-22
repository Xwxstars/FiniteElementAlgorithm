#include "culculate.h"
culculate::culculate(int node_num)
{
    //总刚初始化
    Globle_K.resize(node_num * deg, node_num * deg);
    Globle_K.fill(0);
    //载荷列阵初始化
    Globle_L.resize(node_num * deg);
    Globle_L.fill(0);
    //位移列阵初始化
    Globle_D.resize(node_num * deg);
    Globle_D.fill(0);
}

culculate::~culculate()
{
}

void culculate::ThreeNodesTriangleSingle(triangle *tri)
{
    Matrix<double, 3, 6> B;
    B << tri->bi / (2 * tri->area), 0, tri->bj / (2 * tri->area), 0, tri->bm / (2 * tri->area), 0,
        0, tri->ci / (2 * tri->area), 0, tri->cj / (2 * tri->area), 0, tri->cm / (2 * tri->area),
        tri->ci / (2 * tri->area), tri->bi / (2 * tri->area), tri->cj / (2 * tri->area), tri->bj / (2 * tri->area), tri->cm / (2 * tri->area), tri->bm / (2 * tri->area);
    Matrix<double, 3, 3> D;
    D << E / (1 - miu * miu), E * miu / (1 - miu * miu), 0,
        E * miu / (1 - miu * miu), E / (1 - miu * miu), 0,
        0, 0, E / (2 + 2 * miu);
    /*计算单刚 Ke=Bt*D*B*t*area */
    tri->single_K = B.transpose() * D * B * t * tri->area;
}

void culculate::SetUnitNodes(triangle *tri, node *nod)
{
    if (tri->x1 == nod->x && tri->y1 == nod->y)
    {
        tri->unit_node[0] = nod->globle_num; //单元编号1对应的整体编号
    }
    if (tri->x2 == nod->x && tri->y2 == nod->y)
    {
        tri->unit_node[1] = nod->globle_num; //单元编号1对应的整体编号
    }
    if (tri->x3 == nod->x && tri->y3 == nod->y)
    {
        tri->unit_node[2] = nod->globle_num; //单元编号1对应的整体编号
    }
}

void culculate::ThreeNodeTriangleGlobleSingle(triangle *tri)
{
    /*
     利用原坐标与总纲坐标关系将总纲对应元素赋值：
     row_new=deg*(tri_node[row/deg]-1)+row%deg
     column_new=deg*(tri_node[column/deg]-1)+column%deg;
     每次循环将指针指向的单元对象中的单刚元素加到空矩阵中
        */
    int row = 0, column = 0;
    while (row < 3 * deg)
    {
        column = 0;
        while (column < 3 * deg)
        {
            Globle_K(deg * (tri->unit_node[row / deg] - 1) + row % deg, deg * (tri->unit_node[column / deg] - 1) + column % deg) += tri->single_K(row, column);
            column++;
        }
        row++;
    }
}

void culculate::ThreeNodeTriangleGlobleLoad(node *nod)
{
    Globle_L((nod->globle_num - 1) * deg) = nod->load_x;
    Globle_L((nod->globle_num - 1) * deg + 1) = nod->load_y;
}

void culculate::SoluteDisp()
{
    /*边界乘大数处理*/
    Globle_K(8, 8) = 10000000000 * Globle_K(8, 8);
    Globle_K(9, 9) = 10000000000 * Globle_K(9, 9);
    Globle_K(16, 16) = 10000000000 * Globle_K(16, 16);
    Globle_K(17, 17) = 10000000000 * Globle_K(17, 17);
    Globle_K(24, 24) = 10000000000 * Globle_K(24, 24);
    Globle_K(25, 25) = 10000000000 * Globle_K(25, 25);
    Globle_L(8) = 10000000000 *Globle_K(8, 8) * 0;
    Globle_L(9) = 10000000000 * Globle_K(9, 9) * 0;
    Globle_L(16) = 10000000000 * Globle_K(16, 16) * 0;
    Globle_L(17) = 10000000000 *  Globle_K(17, 17) * 0;
    Globle_L(24) = 10000000000 *Globle_K(24, 24) * 0;
    Globle_L(25) = 10000000000 * Globle_K(25, 25) * 0;
    //LU求解代数方程
    Globle_D = Globle_K.lu().solve(Globle_L); //位移
}

void culculate::SetNodeDisp(node *nod)
{
    nod->displacement_x = Globle_D((nod->globle_num - 1) * deg);
    nod->displacement_y = Globle_D((nod->globle_num - 1) * deg + 1);
}

void culculate::SetUnitDisp(triangle *tri, node *nod)
{
    int i = 0;
    while (i < 3)
    {
        tri->displayment[i][0] = Globle_D((tri->unit_node[i] - 1) * deg);
        tri->displayment[i][1] = Globle_D((tri->unit_node[i] - 1) * deg + 1);
        i++;
    }
}
//平面问题应变
void culculate::SoluteStrain(triangle *tri)
{
    VectorXd x(6);
    x << tri->displayment[0][0], tri->displayment[0][1], tri->displayment[1][0], tri->displayment[1][1], tri->displayment[2][0], tri->displayment[2][1];
    Matrix<double, 3, 6> B;
    B << tri->bi / (2 * tri->area), 0, tri->bj / (2 * tri->area), 0, tri->bm / (2 * tri->area), 0,
        0, tri->ci / (2 * tri->area), 0, tri->cj / (2 * tri->area), 0, tri->cm / (2 * tri->area),
        tri->ci / (2 * tri->area), tri->bi / (2 * tri->area), tri->cj / (2 * tri->area), tri->bj / (2 * tri->area), tri->cm / (2 * tri->area), tri->bm / (2 * tri->area);
    tri->strain = 1 / (2 * tri->area) * B * x;
}
//平面问题应力
void culculate::SoluteStress(triangle *tri)
{
    VectorXd x(6);
    x << tri->displayment[0][0], tri->displayment[0][1], tri->displayment[1][0], tri->displayment[1][1], tri->displayment[2][0], tri->displayment[2][1];
    Matrix<double, 3, 6> B;
    Matrix<double, 3, 3> D;
    B << tri->bi / (2 * tri->area), 0, tri->bj / (2 * tri->area), 0, tri->bm / (2 * tri->area), 0,
        0, tri->ci / (2 * tri->area), 0, tri->cj / (2 * tri->area), 0, tri->cm / (2 * tri->area),
        tri->ci / (2 * tri->area), tri->bi / (2 * tri->area), tri->cj / (2 * tri->area), tri->bj / (2 * tri->area), tri->cm / (2 * tri->area), tri->bm / (2 * tri->area);
    D << E / (1 - miu * miu), E * miu / (1 - miu * miu), 0,
        E * miu / (1 - miu * miu), E / (1 - miu * miu), 0,
        0, 0, E / (2 + 2 * miu);
    tri->stress = D * B * x;
}