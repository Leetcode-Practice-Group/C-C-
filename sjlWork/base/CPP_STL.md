C++容器及使用
------
使用STL容器刷leetcode事半功倍，包括`vector`、`string`、`deque`、`list`、`stack`、`queue`、`priority_queue`、`set`、`map`等，本文内容根据《算法设计与分析》第一章及刷题经验整理。
<!-- more -->

## 常用STL容器及头文件
| 数据结构                           | 说明               | 头文件    |
| ---------------------------------- | ------------------ | --------- |
| vector向量                         | 支持快速随机访问   | \<vector> |
| string字符串                       | 处理字符串，可加   | \<string> |
| deque双端队列                      | 中间不能增删       | \<deque>  |
| list链表                           | 可快速增删结点     | \<list>   |
| stack堆栈                          | 后进先出的队列     | \<stack>  |
| queue队列                          | 先进先出的队列     | \<queue>  |
| priority_queue优先队列             | 某种顺序入队的队列 | \<queue>  |
| set/multiset集合/多重集合          | 集合               | \<set>    |
| map/multimap         映射/多重映射 | 映射               | \<map>    |
  
## vector向量
| 方法             | 描述                         |
| ---------------- | ---------------------------- |
| empty()          | 判断是否为空                 |
| size()           | 返回元素个数                 |
| []               | 返回指定下标的元素           |
| push_back(n)     | 向尾部添加                   |
| insert(pos,elem) | 在pos前插入elem，pos为迭代器 |
| front()          | 返回第一个元素               |
| back()           | 返回最后一个元素             |
| begin()          | 返回第一个位置               |
| end()            | 返回最后一个位置             |
| rbegin()         | 返回反向第一个位置           |
| rend()           | 返回反向最后一个位置         |
  
```cpp
//定义一个存放int型整数的vector容器
    vector<int> myv;
    myv.push_back(1);
    myv.push_back(2);
    myv.push_back(3);
    //使用正向迭代器
    cout << "正向迭代器输出" << endl;
    vector<int>::iterator it;
    for (it = myv.begin(); it != myv.end(); ++it) {
        // printf("%d",*it);
        *it *= 2;  //扩大两倍
        cout << *it << " ";
    }
    cout << endl;

    cout << "正向迭代器输出" << endl;
    vector<int>::reverse_iterator rit;
    for (rit = myv.rbegin(); rit != myv.rend(); ++rit) {
        // printf("%d",*it);
        cout << *rit << " ";
    }
    cout << endl;
```
```bash
正向迭代器输出
2 4 6 
正向迭代器输出
6 4 2 
```
```cpp
    //顺序容器
    cout << "创建顺序容器：" << endl;
    vector<int> v2(10);  // v2有10个int元素
    vector<int>::iterator it;
    int i = 0;
    for (it = v2.begin(); it != v2.end(); ++it) {
        *it = i++;
        cout << *it << "\t";
    }
    cout << endl;

    cout << "v2.front() = " << v2.front() << "\nv2.back() = " << v2.back()
         << "\nv2.size() = " << v2.size() << endl;

    //使用[]进行遍历
    cout << "使用[]进行遍历：" << endl;
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << "\t";
    }
    cout << endl;

    //插入元素
    // v2.insert(2,100); 直接输入2是错误的，应当传递迭代器
    it =
        v2.begin() +
        2;  // begin()返回引用第一个元素的位置，end()返回引用最后一个元素后面的位置
    v2.insert(it, 100);
    // cout << *(v2.begin() + 2) << " " << endl;
    cout << "在原先下标为2位置之前插入100：" << endl;
    for (it = v2.begin(); it != v2.end(); ++it) {
        cout << *it << "\t";
    }
    cout << endl;
    // 0 9 11  --插入元素后数量自动加一
    // cout << v2.front()<< " " << v2.back() << " " <<v2.size() << endl;

    //删除元素
    it = v2.begin() + 5;
    v2.erase(it);
    cout << "删除下表为5的元素：" << endl;
    for (it = v2.begin(); it != v2.end(); ++it) {
        cout << *it << "\t";
    }
    cout << endl;

    //调整容量
    v2.resize(5);
    cout << "调整容量为5：" << endl;
    for (it = v2.begin(); it != v2.end(); ++it) {
        cout << *it << "\t";
    }
    cout << endl;
    //全部清除
    cout << "全部清除：" << endl;
    v2.clear();
    cout << "v2.front() = " << v2.front() << "\nv2.back() = " << v2.back()
         << "\nv2.size() = " << v2.size() << endl;
```
```bash
创建顺序容器：
0       1       2       3       4       5       6       7       8       9
v2.front() = 0
v2.back() = 9
v2.size() = 10
使用[]进行遍历：
0       1       2       3       4       5       6       7       8       9
在原先下标为2位置之前插入100：
0       1       100     2       3       4       5       6       7       8       9
删除下表为5的元素：
0       1       100     2       3       5       6       7       8       9
调整容量为5：
0       1       100     2       3
全部清除：
v2.front() = 0
v2.back() = 0
v2.size() = 0
```
## string字符串
| 方法                                    | 描述                                                 |
| --------------------------------------- | ---------------------------------------------------- |
| empty()                                 | 判断是否为空                                         |
| size()                                  | 返回实际字符个数                                     |
| []                                      | 返回指定下标的字符，从0开始                          |
| compare(const string &str)              | 与str比较，大于返回1等于返回0小于返回-1              |
| append(const string &str)               | 末尾添加str，相当于+                                 |
| insert(size_type idx,const string &str) | 在idx前插入字符串str                                 |
| find(string &s,size_type pos)           | 查找从pos开始字符串s出现的第一个位置，不存在则返回-1 |
| replace(idx,len,str)                    | 从idx开始的len个字符被str替换                        |
| substr(idx)                             | 返回从idx开始的子串                                  |
| substr(idx,len)                         | 返回从idx开始长度为len的子串                         |
  
```cpp
    //字符串
    char cstr[] = "China! Great Wall!";
    string s1(cstr);
    cout << "s1(cstr) = " << s1 << endl;
    string s2(s1);
    cout << "s2(s1) = " << s2 << endl;
    string s3(cstr, 7, 11);
    cout << "s3(cstr, 7, 11) = " << s3 << endl;
    string s4(cstr, 6);
    cout << "s4(cstr, 6) = " << s4 << endl;
    string s5(5, 'A');
    cout << "s5(5, 'A') = " << s5 << endl;

    cout << "s1.size = " << s1.size() << endl;
    cout << "s1.length = " << s1.length() << endl;
    for (int i = 0; i < s1.length(); i++) {
        cout << "s1[" << i << "] = " << s1[i] << " ";
        cout << "\ts1.at(" << i << ") = " << s1.at(i) << " ";
        cout << endl;
    }
    for (auto c: s1){
        cout << c << " ";
    }
    cout << endl;

    cout << "s1.compare(cstr) = " << s1.compare(cstr) << endl;
    cout << "s1.compare(s3) = " << s1.compare(s3) << endl;
    cout << "s1.compare(s4) = " << s1.compare(s4) << endl;
    cout << "s1.append(s4) = " << s1.append(s4) << endl;  //在末尾添加
    //等效于APPEND
    cout << "s1.insert(s1.length(),s5) = " << s1.insert(s1.length(), s5)
         << endl;

    // cout << "s1.insert(s1.length()-1,s5) = " << s1.insert(s1.length() - 1,
    // s5) << endl; //在最后一位之前插入串
    cout << "s1.find(\"a\",0) = " << s1.find("a", 0) << endl;
    cout << "s1.replace(0,9,\"123456789\") = " << s1.replace(0, 9, "123456789")
         << endl;
    cout << "s1.substr(5,11) = " << s1.substr(5, 11) << endl;
    cout << "s1.erase(5,11) = " << s1.erase(5, 11) << endl;

    //字符串连接，等同于append
    cout << "s1 + s2 = " << s1 + s2 << endl;
```
```bash
s1(cstr) = China! Great Wall!
s2(s1) = China! Great Wall!
s3(cstr, 7, 11) = Great Wall!
s4(cstr, 6) = China!
s5(5, 'A') = AAAAA
s1.size = 18
s1.length = 18
s1[0] = C       s1.at(0) = C 
s1[1] = h       s1.at(1) = h 
s1[2] = i       s1.at(2) = i 
s1[3] = n       s1.at(3) = n 
s1[4] = a       s1.at(4) = a 
s1[5] = !       s1.at(5) = ! 
s1[6] =         s1.at(6) =   
s1[7] = G       s1.at(7) = G 
s1[8] = r       s1.at(8) = r 
s1[9] = e       s1.at(9) = e 
s1[10] = a      s1.at(10) = a 
s1[11] = t      s1.at(11) = t 
s1[12] =        s1.at(12) =   
s1[13] = W      s1.at(13) = W 
s1[14] = a      s1.at(14) = a 
s1[15] = l      s1.at(15) = l 
s1[16] = l      s1.at(16) = l 
s1[17] = !      s1.at(17) = ! 
C h i n a !   G r e a t   W a l l ! 
s1.compare(cstr) = 0
s1.compare(s3) = -4
s1.compare(s4) = 12
s1.append(s4) = China! Great Wall!China!
s1.insert(s1.length(),s5) = China! Great Wall!China!AAAAA
s1.find("a",0) = 4
s1.replace(0,9,"123456789") = 123456789eat Wall!China!AAAAA
s1.substr(5,11) = 6789eat Wal
s1.erase(5,11) = 12345l!China!AAAAA
s1 + s2 = 12345l!China!AAAAAChina! Great Wall!
```
## deque双端队列
一个双端队列
```
元素：队头 --- elem --- ... --- 队尾 
索引： 0   ---  1   --- ... --- size()-1
动作： ↑                         ↓
含义：队头插入                队尾删除
动作： ↓                         ↑ 
含义：队头删除                队尾插入
```
| 方法             | 描述           |
| ---------------- | -------------- |
| empty()          | 判断是否为空队 |
| size()           | 返回元素个数   |
| push_front(elem) | 队头插入元素   |
| push_back(elem)  | 队尾插入元素   |
| pop_front()      | 删除队头元素   |
| pop_back()       | 删除队尾元素   |
  
```cpp
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_back(4);
    dq.push_front(5);
    dq.push_back(6);
    cout << "dq :" << endl;
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    cout << endl;
    cout << "dq.front()\t= " << dq.front() << endl;
    cout << "dq.back()\t= " << dq.back() << endl;
    dq.pop_back();
    dq.pop_front();
    cout << "after dq.pop_front() dq.front()\t= " << dq.front() << endl;
    cout << "after dq.pop_back() dq.back()\t= " << dq.back() << endl;
```
```bash
dq :
5 3 1 2 4 6 
dq.front()      = 5
dq.back()       = 6
after dq.pop_front() dq.front() = 3
after dq.pop_back() dq.back()   = 4
```
## list链表
一个链表，不能使用[]快速随机访问，支持迭代器顺序访问：`list<int>::iterator it`，`*it`表示具体值，begin()/end()不表述。
```
元素：表头 --- elem --- ... --- 表尾 
索引： 0   ---  1   --- ... --- size()-1
动作：                           ↓↑
含义：                  pop_back()/push_back
```

| 方法                        | 描述                          |
| --------------------------- | ----------------------------- |
| empty()                     | 判断是否为空表                |
| size()                      | 返回元素个数                  |
| push_back(elem)             | 表尾插入元素                  |
| pop_back()                  | 删除表尾元素                  |
| remove()                    | 删除指定值的元素              |
| unique                      | 删除相邻的重复元素，只保留1个 |
| insert(iterator pos,elem)   | pos前插入一个元素             |
| insert(iterator pos,n,elem) | pos前插入n个相同元素          |
| reverse()                   | 逆序反转                      |
| sort()                      | 排序                          |
  
```cpp
void show_list(list<int> &lst) {
    for (auto c : lst) {
        cout << c << " ";
    }
    cout << endl;
}

...

    list<int> lst;
    lst.push_back(5);
    lst.push_back(2);
    lst.push_back(4);
    lst.push_back(1);
    lst.push_back(3);

    show_list(lst);
    cout << "lst.front() = " << lst.front() << endl;
    cout << "lst.back() = " << lst.back() << endl;
    list<int>::iterator start;
    start = ++lst.begin();
    cout << "在第二个位置前插入30：" << endl;
    lst.insert(start, 30);
    show_list(lst);

    cout << "在第二个位置前插入5个99：" << endl;
    lst.insert(start, 5, 99);
    show_list(lst);
    cout << "反转：" << endl;
    lst.reverse();
    show_list(lst);
    cout << "删除30" << endl;
    lst.remove(30);
    show_list(lst);
    cout << "删除相邻相同的元素：" << endl;
    lst.unique();
    show_list(lst);
    cout << "排序：" << endl;
    lst.sort();
    show_list(lst);
```
```bash
5 2 4 1 3 
lst.front() = 5
lst.back() = 3
在第二个位置前插入30：
5 30 2 4 1 3 
在第二个位置前插入5个99：
5 30 99 99 99 99 99 2 4 1 3 
反转：
3 1 4 2 99 99 99 99 99 30 5 
删除30
3 1 4 2 99 99 99 99 99 5 
删除相邻相同的元素：
3 1 4 2 99 5 
排序：
1 2 3 4 5 99 
```
## stack堆栈
堆栈是后进先处，不支持随机访问和迭代器顺序访问，只能查看顶部元素。  
  
| 方法       | 描述           |
| ---------- | -------------- |
| empty()    | 判断是否为空栈 |
| size()     | 返回元素个数   |
| push(elem) | 进栈           |
| pop()      | 出栈，不返回   |
| top()      | 返回栈顶元素   |
  
```cpp
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    while(!st.empty()){
        cout << "st.top() = " << st.top() << endl;
        st.pop();
    }
```
```bash
st.top() = 3
st.top() = 2
st.top() = 1
```
## queue队列
队列是先进先出，不支持随机访问和迭代器顺序访问，只能查看队头和队尾元素。  
  
| 方法       | 描述           |
| ---------- | -------------- |
| empty()    | 判断是否为空队 |
| size()     | 返回元素个数   |
| push(elem) | 进队           |
| pop()      | 出队，不返回   |
| front()    | 队头           |
| back()     | 队尾           |
  
```cpp
    queue <int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    while(!qu.empty()){
        cout << "qu.front() = " << qu.front() << '\t';
        cout << "qu.back() = " << qu.back() <<endl;
        qu.pop();
    }
```
```bash
qu.front() = 1  qu.back() = 3
qu.front() = 2  qu.back() = 3
qu.front() = 3  qu.back() = 3
```
## priority_queue优先队列
默认从大到小排列的队列：  
  
| 方法       | 描述           |
| ---------- | -------------- |
| empty()    | 判断是否为空队 |
| size()     | 返回元素个数   |
| push(elem) | 进队           |
| pop()      | 出队，不返回   |
| top()      | 队头元素       |
  
```cpp
    //大根堆，即大值在队头
    priority_queue <int> p_qu;
    p_qu.push(3);
    p_qu.push(1);
    p_qu.push(2);
    p_qu.push(4);
    p_qu.push(5);
    while(!p_qu.empty()){
        cout << "p_qu.front() = " << p_qu.top() << endl;
        p_qu.pop();
    }
```
```bash
p_qu.front() = 5
p_qu.front() = 4
p_qu.front() = 3
p_qu.front() = 2
p_qu.front() = 1
```
## set/multiset集合/多重集合
* 关联容器中的每个元素有一个key（关键字），multiset允许集合中的元素重复；
* 可以使用迭代器遍历集合中的元素；
* 集合没有顺序容器的push/pop等操作；
* 集合中默认次序是按照递增次序排序
* 判断元素是否在集合中：`s.find(key) != s.end()`表示在集合中，或者`s.count(key) > 0`
  
| 方法             | 描述                                                   |
| ---------------- | ------------------------------------------------------ |
| empty()          | 判断是否为空集合                                       |
| size()           | 返回集合中元素个数                                     |
| insert()         | 插入元素                                               |
| erase()          | 删除一个元素，对于multiset删除多个元素                 |
| find(key)        | 寻找关键字为key的元素，返回其迭代器，若没有返回s.end() |
| count(key)       | 返回关键字key出现的次数                                |
| upper_bound      | 返回关键字不大于k的第一个元素的迭代器                  |
| lower_bound      | 返回关键字不小于k的第一个元素的迭代器                  |
| begin()/rbegin() | 迭代器第一个位置                                       |
| end()/rend()     | 迭代器最后一个位置                                     |
  
```cpp
    set<int> s;
    set<int>::iterator it;
    s.insert(1);
    s.insert(2);
    s.insert(14);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    if (s.find(13) == s.end()) {
        cout << "cannot find 13 in s" <<endl;
    }
    if (s.count(15) == 0) {
        cout << "cannot find 15 in s" <<endl;
    }
    multiset<int> ms;
    multiset<int>::iterator mit;
    ms.insert(1);
    ms.insert(2);
    ms.insert(14);
    ms.insert(3);
    ms.insert(4);
    ms.insert(4);
    for (mit = ms.begin(); mit != ms.end(); mit++) {
        cout << *mit << " ";
    }
    cout << endl;
```
对于set s，4只能插入一次，对于multiset ms，4可以插入多次：
```bash
1 2 3 4 14 
cannot find 13 in s
cannot find 15 in s
1 2 3 4 4 14 
```
## map/multimap
* map的底层是红黑树，使用pair对进行插入，亦可以直接`map[key] = value`插入，默认按照key的升序进行存放；
* map不允许key多次出现，而multimap是允许的，但不支持[]快速访问
* 查找可以用count也可以用find；
  
| 方法     | 描述                                       |
| -------- | ------------------------------------------ |
| empty()  | 判断是否为空映射                           |
| size()   | 返回映射中元素个数                         |
| insert() | 参考下面代码                               |
| map[key] | 既可以返回key的value，也可以插入key和value |
| find()   | 与set类似，不存在则返回end()的迭代器       |
| count()  | 返回key的元素个数，map为0/1                |
  
```cpp
    // map[key , value], key = map->first, value = map->second
    map<char, int> mymap;
    mymap.insert(pair<char, int>('a', 1));             //插入方式1
    mymap.insert(map<char, int>::value_type('b', 2));  //插入方式2
    mymap['c'] = 3;                                    //插入方式3
    map<char, int>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++) {
        cout << "[" << it->first << "," << it->second << "]" << endl;
    }
    for (it = mymap.begin(); it != mymap.end(); it++) {
        cout << mymap[it->first] << endl;
    }
    if (mymap.find('d') == mymap.end()) {
        cout << "cannod find d in mymap" << endl;
    }
    if (mymap.count('e') == 0){
        cout << "cannod find e in mymap" << endl;
    }
```
```bash
[a,1]
[b,2]
[c,3]
1
2
3
cannod find d in mymap
cannod find e in mymap
```

## unordered_map/unordered_set