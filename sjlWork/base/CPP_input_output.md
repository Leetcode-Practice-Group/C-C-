刷题时经常遇到C++语言的输入问题，包括一行读入数字、字符串、十六进制数等等，本文将对此进行一一分类编写。  
<!-- more -->   
```cpp
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
/*
    1 . 常规输入整行，$ My name is shenjianliang
    My name is shenjianliang
*/
#if 0
    string s;
    cin >> s;
    cout << s << endl;
#endif
/*
    2 . 按空格隔开输入，输入enter结束
    My name is shenjianliang
*/
#if 0
    //使用切割函数
    string inputString;
    vector<string> outStrs;
    char str[128];
    char *tmp;

    getline(cin, inputString);  //读入整行的内容
    strcpy(str, inputString.c_str());

    // strtok参数为char*因此要将指针指向的内容赋值给str
    tmp = strtok(str, " -,.");  // 空格，'-'，',','.'都是分隔符
    while (tmp != NULL) {
        outStrs.push_back(tmp);
        tmp = strtok(NULL, " -,.");  // 注意这里是NULL
    }
    for (auto s :outStrs) {
        cout << s << endl;
    }
#endif
#if 0
    //更简单的方法
    string inputString;
    vector<string> outStrs;
    while (cin >> inputString && getchar() != '\n') {
        outStrs.push_back(inputString);
    }
    outStrs.push_back(inputString);         //读入最后一个串
    for (auto s : outStrs) {
        cout << s << endl;
    }

#endif

/*
    3 . 按行输入，已知总个数
    4
    My
    name
    is
    shenjianliang
*/
#if 0
    string inputString;
    vector<string> outStrs;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inputString;
        outStrs.push_back(inputString);
    }
    for (auto s : outStrs) {
        cout << s << endl;
    }
#endif

/*
    4 . 按逗号隔开输入（最难），使用双指针，条件同上
    etgerwty,,,rtyer,,,rteyerty,
    count  = 3
    input[0] =       etgerwty
    input[1] =       rtyer
    input[2] =       rteyerty
*/
#if 0
    //使用切割函数
    string inputString;
    vector<string> outStrs;
    char str[128];
    char *tmp;

    getline(cin, inputString);  //读入整行的内容
    strcpy(str, inputString.c_str());

    // strtok参数为char*因此要将指针指向的内容赋值给str
    tmp = strtok(str, " -,.");  // 空格，'-'，',','.'都是分隔符
    while (tmp != NULL) {
        outStrs.push_back(tmp);
        tmp = strtok(NULL, " -,.");  // 注意这里是NULL
    }
    for (auto s : outStrs) {
        cout << s << endl;
    }
#endif

/*
    5 . 数字输入，空格隔开
    12 23 445 345 12342435
*/
#if 0
    int num;
    vector<int> outNum;
    
    while (cin >> num && getchar() != '\n') {
        outNum.push_back(num);
    }
    outNum.push_back(num);

    for (int i = 0; i < outNum.size() ; i++) {
        cout << outNum[i] << endl;
    }
    for (auto s : outNum) {
        cout << s << endl;
    }
#endif

/*
    6 . 数字输入，逗号隔开
    Example 1:
    -23,-96,34,   ,45,456,-6,   -867,345
    -23
    -96
    34
    0   //遇到空格后停止
    -23,34,-98,-0012,24,26,235,2134,,234,,,,235
    -23
    34
    -98
    -12
    24
    26
    235
    2134
    0  //遇到,,停止

*/
#if 0
    //代码不变，遇到逗号、空格均会隔开
    int num;
    vector<int> outNum;
    
    while (cin >> num && getchar() != '\n') {
        outNum.push_back(num);
    }
    outNum.push_back(num);
    
    for (auto s : outNum) {
        cout << s << endl;
    }
#endif

/*
    7 . 多组输入，数据总量不相同
        N 组数据
        1,2,3,4				//伤害值数组，不定长
        20,30,15			//怪物生命值，不定长
        5,6,7,8				//不同箭的数量，与伤害值种类对应
        // 下面是第二组数据
        4,2,3,4,7,8,9		//伤害值数组，不定长
        50,30,15,234,44		//怪物生命值，不定长
        5,6,7,8,66,77,88	//不同箭的数量，与伤害值种类对应
        // 下面是第三组数据
        1,2,3,4,45			//伤害值数组，不定长
        20,60,11			//怪物生命值，不定长
        5,6,7,8,34			//不同箭的数量，与伤害值种类对应
*/
#if 0
    int num;
    int N;
    vector<int> damage, health, arrow_count;
    cin >> N;
    for (int i = 0; i < N; i++) {
        while (cin >> num && getchar() != '\n') {
            damage.push_back(num);
        }
        damage.push_back(num);
        while (cin >> num && getchar() != '\n') {
            health.push_back(num);
        }
        health.push_back(num);
        while (cin >> num && getchar() != '\n') {
            arrow_count.push_back(num);
        }
        arrow_count.push_back(num);
        for (int i = 0; i < damage.size(); i++) {
            cout << "damage[" << i << "] = " << damage[i] << endl;
        }
        for (int i = 0; i < health.size(); i++) {
            cout << "health[" << i << "] = " << health[i] << endl;
        }
        for (int i = 0; i < arrow_count.size(); i++) {
            cout << "arrow_count[" << i << "] = " << arrow_count[i] << endl;
        }
        damage.clear();
        health.clear();
        arrow_count.clear();
    }

#endif

/*
    8 . 读入十六进制字符串，空格隔开
    0x123 0xaaaa 100 0x01111 00x10 0x101 101 x xx 10ac      x01
    a[0]            H: 0x123                O: 291
    a[1]            H: 0xaaaa               O: 43690
    a[2]            H: 0x100                O: 256
    a[3]            H: 0x1111               O: 4369
    a[4]            H: 0x0                  O: 0     //00x101为0 和   0x10 = 16
    a[5]            H: 0x10                 O: 16
    a[6]            H: 0x101                O: 257
    a[7]            H: 0x101                O: 257  //x 和 xx不计入
    a[8]            H: 0x0                  O: 0
    //由于有x和xx,10ac和x01无法输入
*/
#if 1
    long a[20];
    int count = 0;
    while (scanf("%lx", &a[count++])) {
        if (getchar() == '\n') break;
    }
    for (int i = 0; i < count; i++) {
        printf("a[%d]\t\tH: 0x%lx\t\tO: %ld\n", i, a[i], a[i]);
    }
    return 0;
#endif

/*
    9 . 读入十六进制字符串，逗号隔开，判断后使用字符串格式输出
    0xaabb,0x1234,0xffff,0x10000000
    a[0] =   0xaabb
    a[1] =   0x1234
    a[2] =   0xffff
    a[3] =   0x10000000
*/
#if 0

#endif

/*
    10 . 读入十六进制字符串，逗号隔开，使用十六进制和十进制格式输出
    0x123,0xaaaa,100,0x01111,00x10,0x101,101,x,xx,10ac,    ,x01
    output[0]               H: 0x123                O: 291
    output[1]               H: 0xaaaa               O: 43690
    output[2]               H: 0x100                O: 256
    output[3]               H: 0x1111               O: 4369
    output[4]               H: 0x101                O: 257
    output[5]               H: 0x101                O: 257
    output[6]               H: 0x10ac               O: 4268
*/
#if 0

#endif

/*
        11 . 进制转换
        0xaa 111 98 aa 64 0Xaa 100fg   //非法字符自动截断
        (16)     a = 170        (10)     a = 170        (8)      a = 170
        (16)     a = 273        (10)     a = 111        (8)      a = 73
        (16)     a = 152        (10)     a = 98 		(8)      a = 0
        (16)     a = 170        (10)     a = 0  		(8)      a = 0
        (16)     a = 100        (10)     a = 64 		(8)      a = 52
        (16)     a = 170        (10)     a = 170        (8)      a = 170
        (16)     a = 4111       (10)     a = 100        (8)      a = 64
*/
#if 0

#endif

    return 0;
}
```