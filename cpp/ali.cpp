//
// Created by bowen on 2020/9/4.
//
// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N,a, b, c, d;
    vector<int> v;
//    while(cin >> N >> a >> b >> c >> d)
//    {
//        // 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
//        // cout << a+b << endl;
//    }
    cin >> N;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    int ret = 1;
    // int cur = 0;
    // int count = 0;
    int cur = N*N;
    for (auto i : v) {
        if (i == 0) {
            continue;
        }
        if (i == 1 && cur > 0) {
            // cout << cur << " " << ret << " ";
            ret *= cur;
            cur--;
            // cout << ret << " ";
            continue;
        }
        // int cnt = i;
        int cnt2 = 1;
        int mu = 1;
        int zi = 1;
        while (cnt2 <= i){
            mu *= cur;
            cur--;
            zi *= cnt2;
            cnt2++;
        }
//        cout << (mu/zi) << "\n";

        if (cnt2 != 1) ret += (mu / zi);

    }
    cout << ret % 998244353;
    return 0;

}
