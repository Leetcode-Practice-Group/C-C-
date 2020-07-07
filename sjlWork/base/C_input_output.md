刷题时经常遇到C语言的输入问题，包括一行读入数字、字符串、十六进制数等等，本文将对此进行一一分类编写。  
<!-- more -->   
```C
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_data(int *nums);
long StrToHex(char *data);
int judgeHexStr(char *data);
unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base);

int main() {
/*
    1 . 常规输入整行，$ My name is shenjianliang
    My name is shenjianliang
*/
#if 0
    char strline[100] = {'\0'};
    gets(strline);
    printf("input : %s\n", strline);

    return 0;
#endif
/*
    2 . 按空格隔开输入，使用scanf和二维数组,假设单词长度不超过20，总数不超过100
    My name is shenjianliang
*/
#if 0
    //按 Enter 后程序输出并退出
    char input[100][20];
    int i = 0;
    int count = 0;
    while (scanf("%s", &input[count++]) > 0) {
        if (getchar() == '\n')  //判断是否检测到 Enter
            break;
    }
    for (i = 0; i < count; i++) {
        printf("input[%d] = \t %s\n", i, input[i]);
    }
    return 0;
#endif

/*
    3 . 按行输入，使用双指针，假设单词长度不超过20，总数不超过100
    My
    name
    is
    shenjianliang
*/
#if 0
    //按 Enter
    //退出循环无法实现，此类题目一般靠有多少个输入或者最后一行等于end判断结束
    char strline[100][20];
    int i = 0;
    //	int N;
    //	scanf ("%d\n",&N);
    //	for (i = 0;i< N;i++){
    //		gets(strline[i]);
    //		printf ("strline[%d] = \t%s\n",i,strline[i]);
    //	}
    int count = 0;
    while (gets(strline[count++]) != NULL) {
        if (!strcmp(strline[count - 1], "end")) {
            break;
        }
    }
    for (i = 0; i < count; i++) {
        printf("strline[%d] = \t %s\n", i, strline[i]);
    }
    return 0;
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
    char input[20][100];  //使用二维数组
    char str[1000];
    char *ptr;
    int count = 0;
    gets(str);
    int i = 0;
    ptr = strtok(str, ",");
    while (ptr != NULL) {
        // count ++;
        strcpy(input[count++], ptr);
        ptr = strtok(NULL, ",");
    }
    printf("count  = %d\n", count);
    for (i = 0; i < count; i++) {
        printf("input[%d] = \t %s\n", i, input[i]);
    }
    return 0;
#endif
#if 0
    char **input, **temp;  //使用双指针 ,效果不好，不便于输出
    input = (char **)malloc(sizeof(char **) * 100);  //声明100个字符串组成的数组
    temp = input;                                    //存放开始的地址
    char str[1000];

    gets(str);

    //*input  = (char *) malloc (sizeof(char *)*20 );//第一个字符串数组分配空间
    //不分配也可以
    *input = strtok(str, ",");
    int count = 0;
    while (*input != NULL) {
        count++;
        *input++;
        //*input = (char *) malloc (sizeof(char *)*20 );	 // 不分配也可以
        *input = strtok(NULL, ",");
    }
    input = temp;  //恢复指针初始位置
    for (int i = 0; i < count; i++) {
        printf("input[%d] = \t %s\n", i, input[i]);  //以二维数组的形式打印输出
    }

    return 0;
#endif

/*
    5 . 数字输入，空格隔开
    12 23 445 345 12342435
*/
#if 0
    //按 Enter 后程序输出并退出
    int input[100];
    int count = 0;
    while (scanf("%d", &input[count++]) != EOF) {
        if (getchar() == '\n')  //判断是否检测到 Enter
            break;
    }
    printf("count  = %d \n", count);
    for (int i = 0; i < count; i++) {
        printf("input[%d] = \t %d\n", i, input[i]);
    }
    return 0;
#endif

/*
    6 . 数字输入，逗号隔开
    Example 1:
        452345,  645 6345,63776 ,37657, 214545          ,526
        count  = 6
        input[0] =       452345
        input[1] =       645
        input[2] =       63776
        input[3] =       37657
        input[4] =       214545
        input[5] =       526
    Example 2:
        2344,  ,  ,3545,,365
        count  = 5
        input[0] =       2344
        input[1] =       0
        input[2] =       0
        input[3] =       3545
        input[4] =       365
*/
#if 0

    int num_input[20];
    char str[1000];
    char *ptr;
    int count = 0;
    gets(str);
    ptr = strtok(str, ",");
    while (ptr != NULL) {
        num_input[count++] = atoi(ptr);
        ptr = strtok(NULL, ",");
    }
    printf("count  = %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("input[%d] = \t %d\n", i, num_input[i]);
    }
    return 0;
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
    int N = 0;
    int *damage, *health, *arrow_count;
    scanf("%d\n", &N);
    int damage_length = 0, health_length = 0, arrow_count_length = 0;
    for (int i = 0; i < N; i++) {
        damage = (int *)malloc(sizeof(int) * 20);
        health = (int *)malloc(sizeof(int) * 20);
        arrow_count = (int *)malloc(sizeof(int) * 20);

        damage_length = get_data(damage);
        health_length = get_data(health);
        arrow_count_length = get_data(arrow_count);

        printf("=============== start print =================\n");
        for (int j = 0; j < damage_length; j++) {
            printf("damage[%d] = %d\n", j, damage[j]);
        }
        for (int j = 0; j < health_length; j++) {
            printf("health[%d] = %d\n", j, health[j]);
        }
        for (int j = 0; j < arrow_count_length; j++) {
            printf("arrow_count[%d] = %d\n", j, arrow_count[j]);
        }
        printf("================ end print =================\n");

        free(damage);
        free(health);
        free(arrow_count);
    }
#endif
#if 1
    int N = 0;
    int damage[20], health[20], arrow_count[20];
    scanf("%d\n", &N);
    int damage_length = 0, health_length = 0, arrow_count_length = 0;
    for (int i = 0; i < N; i++) {
        damage_length = get_data(damage);
        health_length = get_data(health);
        arrow_count_length = get_data(arrow_count);

        printf("=============== start print =================\n");
        for (int j = 0; j < damage_length; j++) {
            printf("damage[%d] = %d\n", j, damage[j]);
        }
        for (int j = 0; j < health_length; j++) {
            printf("health[%d] = %d\n", j, health[j]);
        }
        for (int j = 0; j < arrow_count_length; j++) {
            printf("arrow_count[%d] = %d\n", j, arrow_count[j]);
        }
        printf("================ end print =================\n");
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
#if 0
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
    char a[20][100];  //使用二维数组
    char str[1000];
    char *ptr;
    int count = 0;
    gets(str);
    int i = 0;
    ptr = strtok(str, ",");
    while (ptr != NULL) {
        if (judgeHexStr(ptr) == 0) {  //判断格式
            strcpy(a[count++], ptr);
        } else {
            ptr = strtok(NULL, ",");
            continue;
        }

        ptr = strtok(NULL, ",");
    }
    for (i = 0; i < count; i++) {
        printf("a[%d] = \t %s\n", i, a[i]);
    }
    return 0;
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
    char str[1000];
    long output[20];
    char *ptr;
    int count = 0;
    gets(str);
    int i = 0;
    ptr = strtok(str, ",");
    while (ptr != NULL) {
        output[count] = StrToHex(ptr);
        ptr = strtok(NULL, ",");
        if (output[count] == -1) {
            continue;  //不是标准十六进制字符串则舍弃
        }
        count++;
    }
    for (i = 0; i < count; i++) {
        printf("output[%d]\t\tH: 0x%lx\t\tO: %ld\n", i, output[i], output[i]);
    }
    return 0;
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
    // char *a;
    // a = (char *)malloc (sizeof(char) * 20);
    char a[20];
    char **endp;
    while (scanf("%s", a) != EOF) {
        printf("(16)\t a = %ld\t", simple_strtoul(a, NULL, 16));
        printf("(10)\t a = %ld\t", simple_strtoul(a, NULL, 10));
        printf("(8)\t a = %ld\n", simple_strtoul(a, NULL, 8));
    }
    return 0;
#endif
}

int get_data(int *nums) {
    int count = 0, data = 0;
    char str[1000];
    gets(str);
    char *ptr;
    ptr = strtok(str, ",");
    while (ptr != NULL) {
        nums[count++] = atoi(ptr);
        ptr = strtok(NULL, ",");
    }
    return count;
}

//将十六进制字符串转换为整数（long）
long StrToHex(char *data) {
    //使用自己写的函数00x不可以识别
    if (judgeHexStr(data) != 0) {
        return -1;
    }
    long ret = 0, s = 1;
    int length = strlen(data);
    for (int i = length - 1; i >= 0; i--) {
        if (('0' <= data[i]) && (data[i] <= '9')) {
            s = 1;
            for (int j = 0; j < length - i - 1; j++) {
                s = s * 16;
            }
            ret += ((int)(data[i] - '0')) * s;
        } else if (('a' <= data[i]) && (data[i] <= 'f')) {
            s = 1;
            for (int j = 0; j < length - i - 1; j++) {
                s = s * 16;
            }
            ret += ((int)(data[i] - 'a' + 10)) * s;
        } else if (('A' <= data[i]) && (data[i] <= 'F')) {
            s = 1;
            for (int j = 0; j < length - i - 1; j++) {
                s = s * 16;
            }
            ret += ((int)(data[i] - 'A' + 10)) * s;
        } else {
            continue;
        }
    }
    return ret;
}
//判断是否为标准 0xaA12 或者 0XaA12 或者 aA12 格式
int judgeHexStr(char *data) {
    if (data == NULL) {
        return -1;
    }
    int length = strlen(data);
    if (length == 0) {
        return -1;
    } else if (length >= 1) {
        for (int i = 0; i < length; i++) {
            if ((data[i] == 'x') || (data[i] == 'X')) {
                // if (i == 0)
                // {
                // 	return -1;
                // }
                if (i != 1)  //改为判断第二位是否为x
                {
                    return -1;
                }
                for (int j = 0; j < i; j++) {
                    if (data[j] != '0') {
                        return -1;
                    }
                }
            } else {
                // if ((('a' <= data[i]) && (data[i] <= 'f')) ||
                //     (('A' <= data[i]) && (data[i] <= 'F')) ||
                //     (('0' <= data[i]) && (data[i] <= '9'))) {
                //等同于isxdigit(data[i]
                if (isxdigit(data[i])) {
                    continue;
                } else {
                    return -1;
                }
            }
        }
    }
    return 0;
}

//进制转换
//如果输入为 0xff 或者 0Xff 格式，则默认转化为16进制
//如果输入有 8~9，则转化为十进制和十六进制
//如果输入为 a~f，则只能转为十六进制
//输入遇到非法字符则自动截断
unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base) {
    unsigned long result = 0;
    unsigned long value;

    if (*cp == '0') {
        cp++;
        if ((*cp == 'x' || *cp == 'X') &&
            isxdigit(cp[1])) {  //判断是否 0x 开头，0x 开头则为十六进制数
            base = 16;
            cp++;
        }
        if (!base) {  //如果不是 0x 开头，base = 8
            base = 8;
        }
    }
    if (!base) {
        base = 10;
    }
    while (isxdigit(*cp) &&  // cp在的值0~f范围内，否则跳出循环
           (value = isdigit(*cp) ? *cp - '0'  //如果cp的值在0~9
                                 : (islower(*cp) ? toupper(*cp) : *cp) - 'A' +
                                       10) < base) {  //或者变为大写-'A'+10
        result = result * base + value;  //从左往右，数值 x base +最低位的值
        cp++;
    }
    if (endp) {
        *endp = (char *)cp;  //捕获最低位地址
    }
    return result;
}
```