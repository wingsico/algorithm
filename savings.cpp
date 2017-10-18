//
//  savings.cpp
//  acm_test
//
//  Created by 钟伟杰 on 2017/10/17.
//  Copyright © 2017年 钟伟杰. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int count = 0, budget = 0, cash = 0, savings = 0, status = true, month = 0;
    while ( count < 12) {
        count++;
        cin >> budget;
        cash += 300 - budget;
        if (cash >= 100) {
            savings += (cash / 100) * 100;
            cash -= (cash / 100) * 100;
        }
        if (cash < 0 && status) {
            month = count;
            status = false;
        }
    }
    if (!status) {
        cout << -month << endl;
    } else {
        cout<< cash + savings * 1.2 << endl;
    }
    return 0;
}
