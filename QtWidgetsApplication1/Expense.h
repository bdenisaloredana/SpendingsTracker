//
// Created by Denisa on 3/3/2023.
//

#ifndef EXPENSESMANAGEMENT_EXPENSE_H
#define EXPENSESMANAGEMENT_EXPENSE_H

#include <iostream>

using namespace std;

class Expense {
private:
    int day;
    float sum;
    char* type;
public:

    Expense();
    Expense(int day, float sum, const char* type);
    Expense(const Expense &expense);
    ~Expense();
    int getDay();
    float getSum();
    char* getType();
    void setDay(int day);
    void setSum(float sum);
    void setType(const char* type);
    Expense& operator=(const Expense& expense);
    bool operator==(const Expense &expense1);
    friend ostream& operator<<(ostream& os, Expense& expense);

};


#endif //EXPENSESMANAGEMENT_EXPENSE_H
