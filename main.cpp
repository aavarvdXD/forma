#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setApplicationName("Forma");
    QApplication::setOrganizationName("Qorym");

    MainWindow window;
    window.show();

    return app.exec();
}