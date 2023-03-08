#include "tests.h"
#include "Repo.h"
#include "Service.h"
#include "GuiExpenses.h"
#include<QApplication>

void runGui(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Repo repo;
    Service service(repo);
    GuiExpenses gui(service);
    gui.show();
    app.exec();

}

int main(int argc, char* argv[]) {
    testAll();
    runGui(argc, argv);

    return 0;
}
