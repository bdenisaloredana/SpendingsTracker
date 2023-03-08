#include "tests.h"
#include "tests.h"
#include "Expense.h"
#include <cassert>
#include <cstring>
#include "Repo.h"
#include "Service.h"
#include <vector>

void testConstructors(){
    Expense expense;
    assert(expense.getDay() == 1);
    assert(expense.getSum() == 0);
    assert(strcmp(expense.getType(), "") == 0);

    Expense expense1(expense);
    assert(expense1.getDay() == 1);
    assert(expense1.getSum() == 0);
    assert(strcmp(expense1.getType(), "") == 0);
}

void testSetDay(){
    Expense expense;
    expense.setDay(10);
    assert(expense.getDay() == 10);
}

void testSetSum(){
    Expense expense;
    expense.setSum(40.5);
    assert(expense.getSum() == 40.5);
}

void testSetType(){
    Expense expense;
    expense.setType("transport");
    assert(strcmp(expense.getType(), "transport") == 0);
}

void testGetDay(){
    Expense expense(3, 15, "transport");
    assert(expense.getDay() == 3);
}

void testGetSum(){
    Expense expense(3, 15, "transport");
    assert(expense.getSum() == 15);
}

void testGetType(){
    Expense expense(3, 15, "transport");
    assert(strcmp(expense.getType(), "transport") == 0);
}

void testConstructors2(){
    Repo repo;
    Expense expense1(1, 14, "altele");
    Expense expense2(30, 140, "altele");
    assert(repo.getSize() == 0);

    //copy constructor
    repo.add(expense1);
    repo.add(expense2);
    assert(repo.getSize() == 2);


}

void testGetSizeRepo(){
    Repo repo;
    Expense expense1(1, 2, "altele");
    repo.add(expense1);
    assert(repo.getSize() == 1);
}

void testGetAllRepo(){
    Repo repo;
    Expense expense1(1, 2, "altele");
    Expense expense2(2, 3, "altele");
    repo.add(expense1);
    repo.add(expense2);
    assert(repo.getAll()[0] == expense1);
    assert(repo.getAll()[1] == expense2);


}

void testAddRepo(){
    Repo repo;
    Expense expense(20, 200, "transport");
    repo.add(expense);
    assert(repo.getAll()[0] == expense);
}

void testUpdateRepo(){
    Repo repo;
    Expense cOld(10, 15, "altele");
    Expense cNew(10, 150, "altele");
    repo.add(cOld);
    repo.update(cOld, cNew);
    assert(repo.getAll()[0].getSum() == 150);
}

void testDelRepo(){
    Repo repo;
    Expense expense1(12, 30, "altele");
    Expense expense2(15, 45, "altele");
    Expense expense3(12, 200, " altele");
    repo.add(expense1);
    repo.add(expense2);
    repo.add(expense3);
    repo.del(Expense(15, 45, "altele"));
    assert(repo.getSize() == 2);
}

void testConstructorsService(){
    Repo repo;
    Service service(repo);
    assert(service.getAll().size() == 0);
}

void testAddService(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    assert(service.getAll().size() == 1);
}

void testDeleteService(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 550, "transport");
    assert(service.getAll().size() == 2);
    service.deleteExpense(10, 150, "altele");
    assert(service.getAll().size() == 1);
    assert(service.getAll()[0] == Expense(7, 550, "transport"));
}

void testUpdateService(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 550, "transport");
    service.updateExpense(10, 150, "altele", 10, 200, "altele");
    assert(service.getAll()[0].getSum() == 200);
}

void testDeleteAllByDayService(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 550, "transport");
    service.addExpense(10, 200, "mancare");
    service.deleteAllByDay(10);
    assert(service.getAll().size() == 1);
}

void testDeleteAllFromDayXtoDayY(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 550, "transport");
    service.addExpense(8, 550, "transport");
    service.addExpense(10, 200, "mancare");
    service.deleteAllFromDayXtoDayY(7, 8);
    assert(service.getAll().size() == 2);

}

void testDeleteAllByType(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 550, "transport");
    service.addExpense(8, 550, "transport");
    service.addExpense(10, 200, "mancare");
    service.deleteAllByType("transport");
    assert(service.getAll().size() == 2);
}

void testSumForType(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 550, "transport");
    service.addExpense(8, 200, "transport");
    service.addExpense(10, 200, "mancare");
    float sum = service.sumForType("transport");
    assert(sum == 750);
}



void testSumForDayAndType(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 550, "transport");
    service.addExpense(8, 200, "transport");
    service.addExpense(10, 200, "mancare");
    float sum = service.sumForDayAndType(10,"altele");
    assert(sum == 300);
}

void testDayWithTheMostExpenses(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 50, "transport");
    service.addExpense(8, 200, "transport");
    service.addExpense(10, 200, "mancare");
    int day = service.dayWithTheBiggestExpenses();
    assert(day == 10);
}

void testFilterByType(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 50, "transport");
    service.addExpense(8, 200, "transport");
    service.addExpense(10, 200, "mancare");
    vector<Expense> expense;
    expense = service.filterByType("transport");
    assert(expense.size() == 2);
    assert(expense[0] == Expense(7, 50, "transport"));
    assert(expense[1] == Expense(8, 200, "transport"));
}


void testFilterBySign(){
    Repo repo;
    Service service(repo);
    service.addExpense(10, 150, "altele");
    service.addExpense(10, 150, "altele");
    service.addExpense(7, 50, "transport");
    service.addExpense(8, 200, "transport");
    service.addExpense(10, 200, "mancare");
    vector<Expense> expense;
    expense  = service.filterBySignAndTypeAndSum("transport", "=", 50);
    assert(expense[0] == Expense(7, 50, "transport"));

}

void testOpEqual(){
    Expense expense;
    Expense expense1(12, 500, "altele");
    expense = expense1;
    assert(expense == expense1);
}

void testUndo(){
    Service service;
    service.addExpense(12, 30, "altele");
    service.addExpense(12, 10, "altele");
    assert(service.getAll().size() == 2);
    service.undo();
    assert(service.getAll().size() == 1);
}



void testService(){
    testOpEqual();
    testAddService();
    testDeleteService();
    testUpdateService();
    testConstructorsService();
    testDeleteAllByDayService();
    testDeleteAllFromDayXtoDayY();
    testDeleteAllByType();
    testSumForType();
    testSumForDayAndType();
    testDayWithTheMostExpenses();
    testFilterByType();
    testFilterBySign();
    testUndo();
}

void testExpense(){
    testGetType();
    testGetSum();
    testGetDay();
    testSetType();
    testSetSum();
    testSetDay();
    testConstructors();
}

void testRepo(){
    testConstructors2();
    testGetSizeRepo();
    testGetAllRepo();
    testAddRepo();
    testUpdateRepo();
    testDelRepo();
};


void testAll() {
    testExpense();
    testRepo();
    testService();
}
