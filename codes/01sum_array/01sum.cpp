/*
 * @Description: 给一个2^28长度的vector做赋值跟求和，计算一下时间
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-01-31 00:05:38
 * @LastEditTime: 2022-01-31 00:51:13
 * @FilePath: /HPC/codes/01sum_array/01sum.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //sort,reverse
//
#include <cmath> //   pow(a,b);//a必须是double类型的，b是a的多少次方 ! !
using namespace std;
#include <chrono>       // 时间must
using namespace chrono; // 时间must

int sum_array(vector<double>& arr, int len)
{
    int sum = 0;
    for (int i = 0; i < len; ++i)
    {
        arr[i] = i;    // 赋值
        sum += arr[i]; // 求和
    }
    return sum;
}

int main()
{
    std::cout << "## Starting caculate ...  "<< std::endl;
    auto t1 = std::chrono::steady_clock::now();
    // ======================================2^28长度的vector做赋值跟求和，计算一下时间
    // 输入给一个2^28长度的vector做赋值跟求和，计算一下时间
    int sum = 0;
    const int len = pow(2.0, 28);
    vector<double> a(len); // 定义ector
    sum = sum_array(a, len);
    // =====================================
    auto t2 = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(t2 - t1).count(); //这一帧处理时间  毫秒ms
    std::cout << "## Extract  time: " << dr_ms << " ms， result: " << sum << std::endl;
    // 处理

    //输出
    cout << "time" << endl;

    return 0;
}