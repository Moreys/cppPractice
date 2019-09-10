/*************************************************************************
  @FileName: dm01_函数返回值是一个引用.cc
  @Author:   morey
  @Email:    zymorey@gmail.com
  @Time:     2019年09月10日 星期二 22时50分09秒
 ************************************************************************/
#include <iostream>
using namespace std;

int getAA1()
{
    int a;
    a = 10;
    return a;
}

//返回a的本身 返回a的一个副本  10
int & getAA2()
{
    int a; //如果返回栈上的引用，有可能会有问题
    a = 10;
    return a;
}

int * getAA3() //返回一个int类型的地址
{
    int a;
    a = 10;
    return & a; 
}

int main11()
{
    int a1 = 0;
    int a2 = 0;
    a1 = getAA1();//10 返回一个int类型，其实就是赋值给a1
    
    //a2 = getAA2(); //   error   访问的还是栈的内容，

    //int & a3 = getAA2(); //若返回栈变量  不能成为其他引用的初始值。err
        //返回的是栈上的内容，不能用于其他引用的初始化
    printf("a1:%d\n", a1);
    printf("a2:%d\n", a2);
    //printf("a3:%d\n", a3); 

    std::cout << "Hello world" << std::endl;
    return 0;
}

int j1()
{
    static int a = 10;
    a++;
    return a;
}

int & j2()
{
    static int a = 10;
    a++;
    return a;
}

//若返回静态变量或全局变量
//可以成为其他引用的初始值
//即可作为右值使用，也可以作为左值使用
//
int main2()
{
    int a1 = 10;
    int a2 = 20;
    a1 = j1();
    a2 = j2();
    int &a3 = j2();

    printf("a1:%d\n", a1);
    printf("a2:%d\n", a2);
    printf("a3:%d\n", a3);
}

int g1()
{
    static int a = 10;
    a ++;
    return a;
}
int & g2()
{
    static int a = 10;
    a++;
    printf("a:%d\n", a);
    return a;
}

int main()
{
   g2() = 100;  //函数返回值是一个引用，并且当左值
   g2();
   int c1 = g1(); //函数返回值是一个引用，并且当右值
   int c2 = g2();//函数返回值是一个引用，并且当右值
   cout << c1 << endl;
   cout << c2 << endl;
}


