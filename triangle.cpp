#include "triangle.h"
triangle::triangle(double X1, double Y1, double X2, double Y2, double X3, double Y3)
{
   x1 = X1;x2 = X2;x3 = X3;y1 = Y1;y2 = Y2;y3 = Y3;
   /*计算面积，ai,bi,ci,aj,bj,cj,am,bm,cm*/
   Matrix<double, 3, 3> m_local; //广义坐标矩阵
   m_local << 1, x1, y1, 1, x2, y2, 1, x3, y3;
   area = 0.5 * m_local.determinant(); //面积公式
   ai = x2 * y3 - x3 * y2;
   aj = x3 * y1 - x1 * y3;
   am = x1 * y2 - x2 * y1;
   bi = y2 - y3;
   bj = y3 - y1;
   bm = y1 - y2;
   ci = x3 - x2;
   cj = x1 - x3;
   cm = x2 - x1;
}

triangle::~triangle()
{
}



