/*
 * @Description: 给一个2^28长度的vector做赋值跟求和，计算一下时间
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-01-31 00:05:38
 * @LastEditTime: 2022-01-31 02:03:30
 * @FilePath: /HPC/codes/01sum_array/01sum.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //sort,reverse
//
#include <omp.h> //OpenMP—for指令法求和

#include <cmath> //   pow(a,b);//a必须是double类型的，b是a的多少次方 ! !
using namespace std;
// 时间
#include <time.h> // 	clock_t t1 = clock();
#include <chrono>       // 时间must
using namespace chrono; // 时间must

int sum_array_normal(vector<double>& arr, int len)
{
    int sum = 0;
    for (int i = 0; i < len; ++i)
    {
        arr[i] = i;    // 赋值
        sum += arr[i]; // 求和
    }
    return sum;
}
// 
int sum_array_openmp(vector<double>& arr, int len)
{
    int sum = 0;
    
    #pragma omp parallel
	{
        #pragma omp for reduction(+:sum) // 每个线程拷贝一份sum变量，退出并行块时再把各个线程的sum相加
        // #pragma omp for
        for (int i = 0; i < len; ++i){
            // #pragma omp critical //   critical制导语句标识的下一行代码，也可以是跟着一个大括号括起来的代码段做了同步处理
            arr[i] = i;    // 赋值
            sum += arr[i]; // 求和
        }
    }
    return sum;
}

int main()
{
    std::cout << "## Starting caculate ...  "<< std::endl;
    auto t1 = std::chrono::steady_clock::now();
    //  clock_t t1,t2;
    // ======================================2^28长度的vector做赋值跟求和，计算一下时间
    // 输入: 给一个2^28长度的vector做赋值跟求和，计算一下时间
    int sum = 0;
    const int len = pow(2.0, 28);
    vector<double> a(len); // 定义ector

    // 处理1 
    sum = sum_array_normal(a, len);
    // =====================================
    auto t2 = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(t2 - t1).count(); //这一帧处理时间  毫秒ms
    std::cout << "##【normal】Extract  time: " << dr_ms << " ms， Result: " << sum << std::endl;

    // 处理2: OpenMP//设置线程数，一般设置的线程数不超过CPU核心数，这里开4个线程执行并行代码段
	omp_set_num_threads(10); // 线程数量
    // #pragma omp parallel
	// {
	// 	cout << "Hello" << ", I am Thread " << omp_get_thread_num() << endl;
	// }
    sum = 0;
    sum = sum_array_openmp(a, len);

    auto t3 = std::chrono::steady_clock::now();
    double dr_ms1 = std::chrono::duration<double, std::milli>(t3 - t2).count(); //这一帧处理时间  毫秒ms
    std::cout << "##【OpenMP】Extract  time: " << dr_ms1 << " ms， Result: " << sum << std::endl;
    return 0;
}