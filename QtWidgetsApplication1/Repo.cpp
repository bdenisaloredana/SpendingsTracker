#include "Repo.h"
#include "Expense.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

///Default constructor for the repository.
Repo::Repo() {

   
}

/// Copy constructor for the repository.
/// \param repo the repository whose contents will be copied.
Repo::Repo(const Repo &repo) {

    for (int i = 0; i < repo.expenses.size(); i++)
        this->expenses.push_back(repo.expenses[i]);

}

///Destructor for the repository.
Repo::~Repo() {

}

///Getter for the size of the repository.
int Repo::getSize() {
    return this->expenses.size();
}

///Getter for all of the expenses.
vector<Expense> Repo::getAll() {
    return this->expenses;
}

/// Searches for an expense in the repository.
/// \param expense the searched expense
/// \return the position of the expense in the repository, if it exists; -1 otherwise
int Repo::findElem(const Expense& expense) {
    for(int i = 0; i < expenses.size(); i++)
        if(this->expenses[i] == expense)
            return i;
    return -1;
}

/// Adds an expense to the repository.
/// \param expense the expense to be added
void Repo::add(const Expense& expense) {
    this->expenses.push_back(expense);
}

/// Updates an expense in the repository.
/// \param odlExpense the old expense
/// \param newExpense the new expense with updated contents
void Repo::update(Expense &oldExpense, Expense &newExpense) {
    int poz;
    poz = findElem(oldExpense);
    this->expenses[poz] = newExpense;


}

/// Deletes an expense from the repository.
/// \param expense the expense to be deleted.
void Repo::del(const Expense &expense) {

    vector<Expense>::iterator poz = find(expenses.begin(), expenses.end(), expense);
    this->expenses.erase(poz);
}

/// Overwrites the ostream << operator for an repository.
ostream &operator<<(ostream &os, Repo &repo) {
    for(int i = 0; i < repo.getSize(); i++)
        os <<"Day "<<repo.expenses[i].getDay()<<";"<<"Sum "<<repo.expenses[i].getSum()<<";"<<"Type "<<repo.expenses[i].getType()<<endl;

    return os;
}

/// Overwrites the assignment operator.
/// \param repo the repo whose values will be copied
/// \return an repository with the same contents as repo
Repo &Repo::operator=(const Repo &repo) {
    this->expenses.clear();
    for (int i = 0; i < repo.expenses.size(); i++)
        this->expenses.push_back(repo.expenses[i]);
    return *this;
}
