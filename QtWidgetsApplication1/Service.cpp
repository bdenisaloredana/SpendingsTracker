#include "Service.h"
#include "Expense.h"
#include <cstring>
#include <stack>
stack<Repo> repo_stack;

///Default constructor for the serivce.
Service::Service() {

}

/// Constructor for the service.
/// \param repo the repository of the service
Service::Service(Repo &repo) {

    this->repo = repo;
    addToStack(this->repo);
}

///Destructor for the service.
Service::~Service() {
}

/// Adds an expense.
/// \param day the day of the expense
/// \param sum the cost of the expense
/// \param type the type of the expense
void Service::addExpense(int day, float sum, const char *type) {

    Expense c(day, sum, type);
    this->repo.add(c);
    addToStack(this->repo);

}

/// Updates an expense.
/// \param oldDay the old day of the expense
/// \param oldSum the old sum of the expense
/// \param oldType the old type of the expense
/// \param newDay the new day of the expense
/// \param newSum the new sum of the expense
/// \param newType the new type of the expense
void Service::updateExpense(int oldDay, float oldSum, const char *oldType, int newDay, float newSum, const char *newType) {
    Expense oldC(oldDay, oldSum, oldType);
    Expense newC(newDay, newSum, newType);
    this->repo.update(oldC, newC);
    addToStack(this->repo);

}

/// Deletes an expense.
/// \param day the day of the expense
/// \param sum the cost of the expense
/// \param type the type of the expense
void Service::deleteExpense(int day, float sum,const char *type) {
    Expense c(day, sum, type);
    this->repo.del(c);
    addToStack(this->repo);

}

///Getter for the expenses from the repository.
vector<Expense> Service::getAll() {
    return this->repo.getAll();
}

/// Deletes all expenses from a given day.
/// \param day the given day
void Service::deleteAllByDay(int day) {
    vector<Expense> expenses_repo = this->repo.getAll();
    int i = 0;
    while(i < expenses_repo.size())
    {
        if (expenses_repo[i].getDay() == day)
        {
            this->repo.del(expenses_repo[i]);
            expenses_repo.erase(find(expenses_repo.begin(), expenses_repo.end(), expenses_repo[i]));
        }
            
        else i++;

    }

    addToStack(this->repo);
}

/// Delete all expenses from a period of time.
/// \param dayX the start/end of the given period
/// \param dayY the start/end of the given period
void Service::deleteAllFromDayXtoDayY(int dayX, int dayY) {
    vector<Expense> expenses_repo = this->repo.getAll();

    if(dayX > dayY){
        int aux = dayX;
        dayX = dayY;
        dayY = aux;
    }
    int i = 0;
    while(i < expenses_repo.size()){
        int day = expenses_repo[i].getDay();
        if (day >= dayX && day <= dayY)
        {
            this->repo.del(expenses_repo[i]);
            expenses_repo.erase(find(expenses_repo.begin(), expenses_repo.end(), expenses_repo[i]));
        }
        else
            i++;
    }

    addToStack(this->repo);
}

/// Deletes all the expenses of a given type.
/// \param type the given type
void Service::deleteAllByType(const char *type) {
    vector<Expense> expenses_repo = this->repo.getAll();

    int i = 0;
    while(i < expenses_repo.size()){
        if (strcmp(type, expenses_repo[i].getType()) == 0)
        {
            this->repo.del(expenses_repo[i]);
            expenses_repo.erase(find(expenses_repo.begin(), expenses_repo.end(), expenses_repo[i]));
        }
        else
            i++;
    }

    addToStack(this->repo);
}

/// Filters an initial array of expenses and keeps the expenses with a cost equal to, greater than or less than a given cost.
/// param cost the cost with which we will compare the cost of the expenses
/// param sign one of the arithmetic signs: greater that, less than, equal to
/// returns: a vector containing the result
vector<Expense> Service::filterBySignAndCost(int cost, const char* sign){

    vector<Expense> result_expenses;
    vector<Expense> initial_expenses = this->repo.getAll();
    if(strcmp(sign, ">") == 0) {
        for (int i = 0; i < initial_expenses.size(); i++)
            if (initial_expenses[i].getSum() > cost)
            {
                result_expenses.push_back(initial_expenses[i]);
            }
    }

    if(strcmp(sign, "=") == 0){
        for (int i = 0; i < initial_expenses.size(); i++)
            if (initial_expenses[i].getSum() == cost)
            {
                result_expenses.push_back(initial_expenses[i]);
            }
    }

    if(strcmp(sign, "<") == 0){
        for (int i = 0; i < initial_expenses.size(); i++)
            if (initial_expenses[i].getSum() < cost)
            {
                result_expenses.push_back(initial_expenses[i]);
            }
    }
    return result_expenses;

}

/// Calculates the total cost of the expenses for a given type.
/// \param type the given type
/// \return the total cost
float Service::sumForType(const char *type) {
    vector<Expense> expenses_repo = this->repo.getAll();
    float sum = 0;
    for(int i = 0; i< expenses_repo.size(); i++)
        if(strcmp(expenses_repo[i].getType(), type) == 0)
            sum = sum + expenses_repo[i].getSum();
    return sum;
}



/// Calculates the total cost of the expenses for a given day and given type.
/// \param day the given day
/// \param type the given type
/// \return the total cost
float Service::sumForDayAndType(int day, const char *type) {
    vector<Expense> expenses_repo = this->repo.getAll();
    float sum = 0;
    for(int i = 0; i< expenses_repo.size(); i++)
        if(expenses_repo[i].getDay() == day && (strcmp(expenses_repo[i].getType(), type)== 0))
            sum = sum + expenses_repo[i].getSum();
    return sum;
}

/// Determines the day with the biggest total cost.
/// \return the day with the biggest total cost.
int Service::dayWithTheBiggestExpenses() {

    vector<Expense> expenses_repo = this->repo.getAll();
    float biggestSum = 0;
    int maxDay = 0;
    for(int i = 0; i < expenses_repo.size(); i++)
    {
        int day = expenses_repo[i].getDay();
        float s = 0;
        for(int j = 0; j < this->repo.getSize(); j++)
            if(expenses_repo[j].getDay() == day)
                s = s + expenses_repo[j].getSum();

        if(s > biggestSum) {
            biggestSum = s;
            maxDay = day;
        }

    }

    return maxDay;
}

/// Filters the expenses by a given type.
/// \param type the type of expense by which the filtering is done
/// \returns: a vector containing the expenses of the given type 
vector<Expense> Service::filterByType(const char *type) {
    vector<Expense> expenses_repo = this->repo.getAll();
    vector<Expense> expenses;
    for(int i = 0; i < expenses_repo.size(); i++)
        if(strcmp(expenses_repo[i].getType(), type) == 0) {
            expenses.push_back(expenses_repo[i]);
        }
    return expenses;


}

/// Filters the expenses by a given type which have a cost greater than, equal to or less that a given cost.
/// \param type the type of expense by which the filtering is done
/// \param sign one of the arithmetic signs: <, >, =
/// \param sum the given cost
/// with the cost greater than, equal to or less than the given cost
/// \returns: a vector that contains the result of the function: only the expenses that are of the given type
vector<Expense> Service::filterBySignAndTypeAndSum(const char *type, const char *sign, float sum) {
    vector<Expense> expenses_repo = this->repo.getAll();
    vector<Expense> expenses_filtered_by_type;


    for(int i = 0; i < expenses_repo.size(); i++)
        if(strcmp(expenses_repo[i].getType(), type) == 0)
        {
            expenses_filtered_by_type.push_back(expenses_repo[i]);
        }

    //return filterBySignAndCost(expenses_filtered_by_type, sum, sign);
    return expenses_filtered_by_type;


}

/// Adds the repository to the stack.
/// \param repo the repository to be added
void Service::addToStack(Repo& repo1) {

    repo_stack.push(repo1);
}

///Performs the undo operation.
void Service::undo() {

    if(!repo_stack.empty())
    {repo_stack.pop();
        this->repo = repo_stack.top();
    }

}



