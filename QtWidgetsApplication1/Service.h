#ifndef EXPENSESMANAGEMENT_SERVICE_H
#define EXPENSESMANAGEMENT_SERVICE_H

#include "Repo.h"
#include <vector>
class Service {
private:
    Repo repo;
public:
    Service();
    Service(Repo& repo);
    ~Service();

    void addExpense(int day, float sum, const char* type);
    void updateExpense(int oldDay, float oldSum,const char* oldType, int newDay, float newSum, const char* newType);
    void deleteExpense(int day, float sum, const char* type);
    void deleteAllByDay(int day);
    void deleteAllFromDayXtoDayY(int dayX, int dayY);
    void deleteAllByType(const char* type);
    float sumForType(const char* type);
    float sumForDayAndType(int day, const char* type);
    int dayWithTheBiggestExpenses();
    vector<Expense> filterByType(const char *type);
    vector<Expense> filterBySignAndTypeAndSum(const char *type, const char *sign, float sum);
    vector<Expense> getAll();
    void addToStack(Repo& repo1);
    void undo();
    vector<Expense> filterBySignAndCost(int cost, const char* sign);
};



#endif //EXPENSESMANAGEMENT_SERVICE_H
