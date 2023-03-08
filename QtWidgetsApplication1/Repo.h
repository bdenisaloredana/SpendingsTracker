#ifndef EXPENSESMANAGEMENT_REPO_H
#define EXPENSESMANAGEMENT_REPO_H


#include "Expense.h"
#include <vector>

using namespace std;
class Repo {
private:
    vector<Expense> expenses;

public:
    Repo();
    Repo(const Repo& r);
    ~Repo();
    void add(const Expense& c);
    void update(Expense& oldC, Expense& newC);
    void del(const Expense& c);
    int getSize();
    int findElem(const Expense& c);
    vector<Expense> getAll();
    friend ostream& operator<<(ostream& os, Repo& r);
    Repo& operator=(const Repo& repo);

};


#endif //EXPENSESMANAGEMENT_REPO_H
