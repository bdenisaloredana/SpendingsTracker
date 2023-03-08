#pragma once
#include<vector>
using namespace std;
#include <QWidget>
#include <QCoreApplication>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include<QHeaderView>
#include "Service.h"
#include "GuiExpenses.h"
#include "ExpenseModel.h"
#include <string.h>
#include<cstring>


/// Initializez the gui components for the window.
void GuiExpenses::initGuiComponents() {
	QHBoxLayout* mainLayout = new QHBoxLayout;
	this->setLayout(mainLayout);
	this->setWindowTitle("Expenses tracker");

	QWidget* finalForm = new QWidget;
	QVBoxLayout* finalFormVbox = new QVBoxLayout;
	finalForm->setLayout(finalFormVbox);

	QWidget* form = new QWidget;
	QFormLayout* formLayout = new QFormLayout;
	form->setLayout(formLayout);

	QLabel* dayLbl = new QLabel("Day");
	QLabel* typeLbl = new QLabel("Type");
	QLabel* sumLbl = new QLabel("Amount");
	formLayout->addRow(dayLbl, dayEdt);
	formLayout->addRow(typeLbl, typeEdt);
	formLayout->addRow(sumLbl, sumEdt);

	finalFormVbox->addWidget(form);

	QWidget* formHboxWidget = new QWidget;
	QHBoxLayout* formBtnHbox = new QHBoxLayout;
	formHboxWidget->setLayout(formBtnHbox);
	formBtnHbox->addWidget(insertExpenseBtn);
	formBtnHbox->addWidget(undoBtn);


	finalFormVbox->addWidget(formHboxWidget);

	//for delete operations
	QWidget* mainDeleteForm = new QWidget;
	QVBoxLayout* mainDeleteFormLayout = new QVBoxLayout;
	mainDeleteForm->setLayout(mainDeleteFormLayout);

	QWidget* deleteForm = new QWidget;
	QFormLayout* deleteFormLayout = new QFormLayout;
	deleteForm->setLayout(deleteFormLayout);

	QLabel* typeDelLbl = new QLabel("Type");
	QLabel* fromLbl = new QLabel("From");
	QLabel* toLbl = new QLabel("To");
	QLabel* dayDelLbl = new QLabel("Day");
	deleteFormLayout->addRow(typeDelLbl, typeDelEdt);
	deleteFormLayout->addRow(fromLbl, dayXDelEdt);
	deleteFormLayout->addRow(toLbl, dayYDelEdt);
	deleteFormLayout->addRow(dayDelLbl, dayDelEdt);

	//delete buttons
	QWidget* deleteBtns = new QWidget;
	QHBoxLayout* deleteHbox = new QHBoxLayout;
	deleteBtns->setLayout(deleteHbox);
	deleteHbox->addWidget(deleteExpenseByTypeBtn);
	deleteHbox->addWidget(deleteFromDayXToDayYBtn);
	deleteHbox->addWidget(deleteExpenseDayBtn);


	mainDeleteFormLayout->addWidget(deleteForm);
	mainDeleteFormLayout->addWidget(deleteBtns);


	//sum for type & max day 
	QWidget* mainSumForTypeAndMaxDay = new QWidget;
	QVBoxLayout* mainSumForTypeAndMaxDayVBox = new QVBoxLayout;
	mainSumForTypeAndMaxDay->setLayout(mainSumForTypeAndMaxDayVBox);

	QWidget* sumForTypeAndMaxDayForm = new QWidget;
	QFormLayout* sumForTypeAndMaxDayFormLayout = new QFormLayout;
	sumForTypeAndMaxDayForm->setLayout(sumForTypeAndMaxDayFormLayout);

	QLabel* typeSumLbl = new QLabel("Type:");
	QLabel* typeSumDisplay = new QLabel("Total cost for type:");
	QLabel* maxDayLbl = new QLabel("Day with biggest spendings:");
	sumForTypeAndMaxDayFormLayout->addRow(typeSumLbl, typeSumEdt);
	sumForTypeAndMaxDayFormLayout->addRow(typeSumDisplay, typeSumDisplayLbl);
	sumForTypeAndMaxDayFormLayout->addRow(maxDayLbl, maxDayDisplayLbl);

	QWidget* sumAndDayBtns = new QWidget;
	QHBoxLayout* sumAndDayBtnsBox = new QHBoxLayout;
	sumAndDayBtns->setLayout(sumAndDayBtnsBox);

	sumAndDayBtnsBox->addWidget(sumForTypeBtn);
	sumAndDayBtnsBox->addWidget(maxDayBtn);

	mainSumForTypeAndMaxDayVBox->addWidget(sumForTypeAndMaxDayForm);
	mainSumForTypeAndMaxDayVBox->addWidget(sumAndDayBtns);


	//filterbuttonsHbox

	QWidget* filterWidget = new QWidget;
	QVBoxLayout* filterVbox = new QVBoxLayout;
	filterWidget->setLayout(filterVbox);

	QWidget* filterForm = new QWidget;
	QFormLayout* filterFormLayout = new QFormLayout;
	filterForm->setLayout(filterFormLayout);

	QLabel* typeFilterLbl = new QLabel("Type:");
	QLabel* signFilterLbl = new QLabel("Sign:");
	QLabel* sumFilterLbl = new QLabel("Amount:");
	QLabel* filterByTypeLbl = new QLabel("Filter by type:");

	filterFormLayout->addRow(signFilterLbl, signFilterEdt);
	filterFormLayout->addRow(sumFilterLbl, sumFilterEdt);
	filterFormLayout->addRow(filterByTypeLbl, typeFilterEdt);

	QWidget* filterBtnsWidget = new QWidget;
	QHBoxLayout* filterBtnsLayout = new QHBoxLayout;
	filterBtnsWidget->setLayout(filterBtnsLayout);

	filterBtnsLayout->addWidget(filterBySignSumBtn);
	filterBtnsLayout->addWidget(filterByTypeBtn);

	filterVbox->addWidget(filterForm);
	filterVbox->addWidget(filterBtnsWidget);

	tableViewExpenses->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	QWidget* tableWidget = new QWidget;
	QVBoxLayout* tableVBox = new QVBoxLayout;
	tableWidget->setLayout(tableVBox);
	tableVBox->addWidget(tableViewExpenses);
	tableVBox->addWidget(refreshBtn);

	mainLayout->addWidget(tableWidget);
	mainLayout->addWidget(finalForm);
	mainLayout->addWidget(mainDeleteForm);
	mainLayout->addWidget(mainSumForTypeAndMaxDay);
	mainLayout->addWidget(filterWidget);

}

/// Connects the signals to the slots.
void GuiExpenses::connectSignalsSlots() {
	QObject::connect(insertExpenseBtn, &QPushButton::clicked, this, &GuiExpenses::insertExpense);
	QObject::connect(undoBtn, &QPushButton::clicked, this, &GuiExpenses::undo);
	QObject::connect(sumForTypeBtn, &QPushButton::clicked, this, &GuiExpenses::sumForType);
	QObject::connect(maxDayBtn, &QPushButton::clicked, this, &GuiExpenses::maxDay);
	QObject::connect(filterByTypeBtn, &QPushButton::clicked, this, &GuiExpenses::filterByType);
	QObject::connect(filterBySignSumBtn, &QPushButton::clicked, this, &GuiExpenses::filterBySignSum);
	QObject::connect(deleteFromDayXToDayYBtn, &QPushButton::clicked, this, &GuiExpenses::deleteFromDayXToDayY);
	QObject::connect(deleteExpenseDayBtn, &QPushButton::clicked, this, &GuiExpenses::deleteExpenseDay);
	QObject::connect(deleteExpenseByTypeBtn, &QPushButton::clicked, this, &GuiExpenses::deleteByType);
	QObject::connect(refreshBtn, &QPushButton::clicked, [&]() {
		refreshTable(expensesService.getAll());
		});


}

/// Refreshes the tableview with new information.
/// expenses the vector that contains the new information
void GuiExpenses::refreshTable(vector<Expense> expenses) {
	
	expensesModel->setExpenses(expenses);

}

/// Handles the insertion of an expense
void GuiExpenses::insertExpense() {
	bool ok;
	int day = dayEdt->text().trimmed().toInt(&ok);
	if (ok) {
		string type(typeEdt->text().trimmed().toStdString());
		float amount = sumEdt->text().trimmed().toFloat(&ok);
		const char* expenseType = type.c_str();
		if (ok)
			expensesService.addExpense(day, amount, expenseType);
		refreshTable(expensesService.getAll());
		typeEdt->clear();
		dayEdt->clear();
		sumEdt->clear();


	}

}

/// Handles the removal of expenses of a certain type
void GuiExpenses::deleteByType() {
	string type(string(typeDelEdt->text().trimmed().toStdString()));
	const char* expenseType = type.c_str();
	expensesService.deleteAllByType(expenseType);
	refreshTable(expensesService.getAll());
	typeDelEdt->clear();

}


/// Handles the removal of expenses from a given period of time
void GuiExpenses::deleteFromDayXToDayY() {
	bool ok;
	int dayx = dayXDelEdt->text().trimmed().toInt(&ok);
	if (ok) {
		int dayy = dayYDelEdt->text().trimmed().toInt(&ok);
		if (ok)
		{
			expensesService.deleteAllFromDayXtoDayY(dayx, dayy);
			refreshTable(expensesService.getAll());

		}
		dayXDelEdt->clear();
		dayYDelEdt->clear();

	}


}

/// Handles the removal of expenses for a given day
void GuiExpenses::deleteExpenseDay() {
	bool ok;
	int day = dayDelEdt->text().trimmed().toInt(&ok);

	if (ok)
	{
		expensesService.deleteAllByDay(day);
		refreshTable(expensesService.getAll());
	}


}

/// Handles the total cost for a given type of expenses
void GuiExpenses::sumForType() {
	string type = typeSumEdt->text().trimmed().toStdString();
	const char* expenseType = type.c_str();
	float sum = expensesService.sumForType(expenseType);
	typeSumEdt->clear();
	typeSumDisplayLbl->setText(QString::number(sum));

}


/// Handles the day with the biggest expenses interogation
void GuiExpenses::maxDay() {
	int day = expensesService.dayWithTheBiggestExpenses();
	maxDayDisplayLbl->setText(QString::number(day));


}

/// Handles the filtration by a given type of the expenses
void GuiExpenses::filterByType() {
	string type = typeFilterEdt->text().trimmed().toStdString();
	const char* expenseType = type.c_str();
	typeFilterEdt->clear();
	refreshTable(expensesService.filterByType(expenseType));


}

///Handles the filtration of the expenses by a given sum and arithmetic sign 
void GuiExpenses::filterBySignSum() {
	bool ok;
	string sign = signFilterEdt->text().trimmed().toStdString();
	const char* expenseSign = sign.c_str();
	float sum = sumFilterEdt->text().trimmed().toFloat(&ok);
	signFilterEdt->clear();
	sumFilterEdt->clear();
	if (ok)
		refreshTable(expensesService.filterBySignAndCost( sum, expenseSign));


}

///Handles the undo operation 
void GuiExpenses::undo() {

	expensesService.undo();
	refreshTable(expensesService.getAll());

}

void GuiExpenses::closeEvent(QCloseEvent* ev) {
	
	QCoreApplication::quit();
}