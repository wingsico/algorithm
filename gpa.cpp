//
//  main.cpp
//  acm_test
//
//  Created by 钟伟杰 on 2017/10/17.
//  Copyright © 2017年 钟伟杰. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    // insert code here...
    int count = 0, number;
    double credit, grades;
    double score = 0.0;
    double totalCredit = 0.0;
    cin >> number;
    while (number > count) {
        cin>>credit>>grades;
        totalCredit += credit;
        score += credit * grades;
        count++;
    }
    cout << fixed << setprecision(2) << score / totalCredit << endl;
    return 0;
}
