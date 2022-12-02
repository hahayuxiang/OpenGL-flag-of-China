/*用来求五星红旗的点的坐标，每一次求出5个点，即每个五角星的外围五个顶点或内部五个顶点，
所以应该需要求十次，每一次该程序的相关参数需要修改*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

float PI = 3.1415926f;
int main()
{
    float center_x = -1.0f / 3, center_y = 0.8f;//每一次需要修改中心坐标
    float cnt = 3.0f / 5;//每一次修改中心的的正切值
    float thera = atan(cnt);
    for (int i = 0; i < 5; i++) {
        float tmp = thera + PI + 72.0f * PI / 180.0f * i;
        if (tmp >= 2 * PI) tmp -= 2 * PI;
        float x = 0.1f * cos(tmp) * 2.0f / 3 + center_x;
        float y = 0.1f * sin(tmp) + center_y;
        std::cout << x << " " << y << "\n";
    }
    std::cout << "\n";
    for (int i = 0; i < 5; i++) {
        float tmp = thera + PI + 36.0f * PI / 180.0f + 72.0f * PI / 180.0f * i;
        if (tmp >= 2 * PI) tmp -= 2 * PI;
        float x = 0.0382f * cos(tmp) * 2.0f / 3 + center_x;
        float y = 0.0382f * sin(tmp) + center_y;

        std::cout << x << " " << y << "\n";
    }

    return 0;
}