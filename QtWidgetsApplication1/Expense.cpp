#include "Expense.h"
#include <string.h>
#include <iostream>
using namespace std;

///Default constructor for an expense.
Expense::Expense() {
    this->day = 1;
    this->sum = 0;
    this->type = new char[1];
    strcpy_s(this->type, 1, "");
}

/// Constructor for an expense.
/// \param day the day of the expense
/// \param sum the cost of the expense
/// \param type the type of the expense
Expense::Expense(int day, float sum, const char* type) {
    this->day = day;
    this->sum = sum;
    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);

}

///Copy constructor.
/// \param expense the expense whose contents we will copy
Expense::Expense(const Expense &expense) {
    this->day = expense.day;
    this->sum = expense.sum;
    this->type = new char[strlen(expense.type) + 1];
    strcpy_s(this->type, strlen(expense.type) + 1, expense.type);
}

///Destructor for an expense.
Expense::~Expense() {
    if(this->type)
    {
        delete[] this->type;
        this->type = nullptr;
    }
}

/// Getter for the day of an expense.
/// \return the day of the expense
int Expense::getDay() {
    return this->day;
}

/// Getter for the cost of an expense.
/// \return the cost of the expense
float Expense::getSum() {
    return this->sum;
}

/// Getter for the type of an expense.
/// \return the type of the expense
char* Expense::getType() {
    return this->type;
}

/// Setter for the day of an expense.
/// \param dayValue the day of the expense
void Expense::setDay(int dayValue) {
    this->day = dayValue;
}

/// Setter for the cost of an expense.
/// \param sumValue the cost of the expense
void Expense::setSum(float sumValue) {
    this->sum = sumValue;
}

/// Setter for the type of an expense.
/// \param typeValue the type of the expense
void Expense::setType(const char* typeValue) {
    this->type = new char[strlen(typeValue) + 1];
    strcpy_s(this->type, strlen(typeValue) + 1, typeValue);
}

/// Overwrites the assignment operator.
/// \param expense the expense whose values will be copied
/// \return an expense with the same contents as expense
Expense& Expense::operator=(const Expense &expense) {
    if(this != &expense) {

        this->setDay(expense.day);
        this->setSum(expense.sum);
        this->setType(expense.type);
    }
    return *this;
}

/// Overwrites the equality operator.
/// \param expense1 the expense with which the comparison will take place
/// \return true if the two expenses are equal, false otherwise
bool Expense::operator==(const Expense &expense1) {
    if(strcmp(this->type, expense1.type) == 0)
        if(this->day == expense1.day)
            if(this->sum == expense1.sum)
                return true;
    return false;
}

/// Overwrites the ostream << operator for an expense.
ostream& operator<<(ostream& os, Expense& expense) {
    os <<"Day "<<expense.day<<";"<<"Sum "<<expense.sum<<";"<<"Type "<<expense.type<<endl;
    return os;
}
