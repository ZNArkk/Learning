//
​#include #include <stdio.h><stdio.h> <stdio.h>#include<stdio.h>#include
#include
常量
整数[
void交换整数
整数 t = a;
a=b；
    b = t;
}
无效下移值 voidvoid down(int i,int x) {down i，( x
    int s = i;
    int l = 2 * i + 1, r = 2 * i + 2;int l = 2 * i + 1, r = 2 * i + 2;2 * i + 1, r = 2 * i + 
    if (l <= x && a[s] < a[l]) s = l;ifs(l <= x && a[s] < a[l]]​​​l[l <= x && a) < a]​​ s = l;
    if (r <= x && a[s] < a[r]) s = r;ifs(r <= x && a[s]x && a​s=r；x < a[
如果（s！= 如果（） ​if    if(s != i) {if） 
        swap(a[i],a[s]);swapa[i[s]​​,)i]​s[,a[​a(​​)]​​
        down(s,x);downi]，x）；(,x​
    }}}
}
​ buildheap（voidvoid buildheap(int x) {buildheap ​ int x）如果（​​​buildheapx x） {​x​ ​
    for (int i = (x + 1) / 2 - 1; i >= 0; i--)for） / int0 i = (x + 1; i--）) / 2​ i = int - 
i, x);
}
​ heapsort x） int(​​(​ ​） ​​int x)​​
正在…tot    while (tot) {while）whilewhile​(​ ​
        swap(a[tot],a[0]);])​​​​总计)​总计(a]​​​​​a]​tot​;)0​​​,a
        down(0,--tot);down0，--总数）；0;
    }}}
}
​在 main（） 整数（）intint main() {(
    std::cin >> n;
    tot = n - 1;1;1;
    for (int i = 0; i < n; i++)for​​ i = ​​( ​取整 i = int i = 
        std::cin >> a[i];cin a[i]；​irr
    buildheap(tot);buildheap总计​​;
heapsort    heapsort(tot);totheapsort​void​void​heapsort(int heapsort(总计
    for (int i = 0; i < n; i++)for​取整 
        std::cout << a[i] << ' ';[i] << ' ';；[i] << ' ';];
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/13.

//
