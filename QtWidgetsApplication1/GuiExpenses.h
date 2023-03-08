#pragma once
#include<vector>
using namespace std;
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include "Service.h"
#include "ExpenseModel.h"

class GuiExpenses : public QWidget {

private:
	Service& expensesService;
	QTableView* tableViewExpenses = new QTableView;
	ExpensesModel* expensesModel = new ExpensesModel;
	QPushButton* refreshBtn = new QPushButton("Refresh");

	QPushButton* insertExpenseBtn = new QPushButton("Add expense");
	QLineEdit* dayEdt = new QLineEdit();
	QLineEdit* typeEdt = new QLineEdit();
	QLineEdit* sumEdt = new QLineEdit();

	QPushButton* deleteExpenseByTypeBtn = new QPushButton("Delete type");
	QLineEdit* typeDelEdt = new QLineEdit();

	QPushButton* deleteFromDayXToDayYBtn = new QPushButton("Delete");
	QLineEdit* dayXDelEdt = new QLineEdit();
	QLineEdit* dayYDelEdt = new QLineEdit();

	QPushButton* deleteExpenseDayBtn = new QPushButton("Delete day");
	QLineEdit* dayDelEdt = new QLineEdit();

	QPushButton* sumForTypeBtn = new QPushButton("Total cost for type");
	QLabel* typeSumDisplayLbl = new QLabel(); 
	QLineEdit* typeSumEdt = new QLineEdit();

	QPushButton* maxDayBtn = new QPushButton("Max day");
	QLabel* maxDayDisplayLbl = new QLabel();	

	QPushButton* filterBySignSumBtn = new QPushButton("Filter");
	QLineEdit* signFilterEdt = new QLineEdit();
	QLineEdit* sumFilterEdt = new QLineEdit();

	QPushButton* filterByTypeBtn = new QPushButton("Filter by type");
	QLineEdit* typeFilterEdt = new QLineEdit();

	QPushButton* undoBtn = new QPushButton("Undo");


	void initGuiComponents();

	void connectSignalsSlots();

	void refreshTable(vector<Expense> expenses);

	void insertExpense();

	void deleteByType();

	void deleteFromDayXToDayY();

	void deleteExpenseDay();

	void sumForType();

	void maxDay();

	void filterBySignSum();

	void filterByType();

	void undo();

protected:
	void closeEvent(QCloseEvent* ev) override;

public:
	GuiExpenses(Service& service):expensesService(service){
		tableViewExpenses->setModel(expensesModel);
		initGuiComponents();
		connectSignalsSlots();
		refreshTable(expensesService.getAll());

	}


};
