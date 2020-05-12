### pat模板

### 1. 进制转化（基于r进行的转化）

代码

```
long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
```

```
说明: string  是原始的输出 
1. 使用 auto  rbegin 从末尾出发进行遍历操作 rend 进行停止处理
2. isdigit 判断 是否是 数字
3. pow(radix ,index)  乘底数的指数幂
4. 对结果进行返回操作
// to_string()   把一个数转化成string 


```



### 二分查找

```

long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}




```

```
1. *max_element(n.begin.n.end) 找出数组中的最大值
2. 

```

### 结构体排序

```
struct node {
    int id, best;
    int score[4], rank[4];
}stu[2005];
int exist[1000000], flag = -1;
bool cmp1(node a, node b) {return a.score[flag] > b.score[flag];}

for(flag = 0; flag <= 3; flag++) {
        sort(stu, stu + n, cmp1);
        stu[0].rank[flag] = 1;
        for(int i = 1; i < n; i++) {
            stu[i].rank[flag] = i + 1;
            if(stu[i].score[flag] == stu[i-1].score[flag])
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
            }
        }
    }
  //  进行实际的排序
  //int exist[1000000],   进行id的映射操作
```

###  图的dfs 搜索

```
void dfs(int node) {
    // 实际的搜索操作
    visit[node] = true;
    for(int i = 1; i <= n; i++) {
            //对没有进行标记过的节点进行搜索操作
        if(visit[i] == false && v[node][i] == 1)
            dfs(i);
    }
}


  for(int j = 1; j <= n; j++) {
                //  进行图的dfs搜索操作
            if(visit[j] == false) {
                dfs(j);
                   // 进行搜索了的次数
                cnt++;
            }
        }
        
        
```

### 队列的使用

```
1014 Waiting in Line 
struct node {
    int poptime, endtime;
    queue<int> q;
};
 window[j].q.push(time[index]);
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]);
        window[tempwindow].poptime +=  window[tempwindow].q.front
         //对队列的元素进行操作

```

### 判断一个数是素数

```
bool isprime(int n) {
    if(n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
```

###  一个数的简单进制转换

```
do{
            arr[len++] = n % d;
            n = n / d;
        }while(n != 0);
        for(int i = 0; i < len; i++)
            n = n * d + arr[i];
```

