/*���������Ǻ���ĵ�����꣬ÿһ�����5���㣬��ÿ������ǵ���Χ���������ڲ�������㣬
����Ӧ����Ҫ��ʮ�Σ�ÿһ�θó������ز�����Ҫ�޸�*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

float PI = 3.1415926f;
int main()
{
    float center_x = -1.0f / 3, center_y = 0.8f;//ÿһ����Ҫ�޸���������
    float cnt = 3.0f / 5;//ÿһ���޸����ĵĵ�����ֵ
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