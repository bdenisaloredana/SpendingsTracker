#pragma once
#pragma once
#include<vector>
#include<QVariant>
#include "Expense.h"
#include <QAbstractTableModel>
using namespace std;

class ExpensesModel : public QAbstractTableModel {
private:
	vector<Expense> expenses;

public:
	ExpensesModel(QObject* parent = nullptr) :QAbstractTableModel(parent) {}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return static_cast<int>(expenses.size());


	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 3;

	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override {
		if (role == Qt::DisplayRole) {
			int row, col;
			row = index.row();
			col = index.column();
			Expense expense = this->expenses[row];

			if (col == 0)
				return QString::number(expense.getDay());
			if (col == 1)
				return QString::fromStdString(string(expense.getType()));
			if (col == 2)
				return QString::number(expense.getSum());

		}
		return QVariant{};
	}


	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {

		if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {

			if (section == 0)
				return QString("Day");
			if (section == 1)
				return QString("Type");
			if (section == 2)
				return QString("Amount");


		}
		return QVariant{};

	}

	void setExpenses(const vector<Expense>& expenses) {
		this->expenses = expenses;
		QModelIndex topLeft = createIndex(0, 0);
		QModelIndex bottomRight = createIndex(rowCount() - 1, columnCount() - 1);
		emit layoutChanged();
		emit dataChanged(topLeft, bottomRight);
	}
};

