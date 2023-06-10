#include <QtWidgets>

double f(double x) {
    return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout layout(&window);

    QLabel aLabel("a:");
    QLineEdit aLineEdit;
    QLabel bLabel("b:");
    QLineEdit bLineEdit;
    QLabel dxLabel("dx:");
    QLineEdit dxLineEdit;

    QPushButton calculateButton("Calculate");
    QTextEdit resultTextEdit;

    layout.addWidget(&aLabel);
    layout.addWidget(&aLineEdit);
    layout.addWidget(&bLabel);
    layout.addWidget(&bLineEdit);
    layout.addWidget(&dxLabel);
    layout.addWidget(&dxLineEdit);
    layout.addWidget(&calculateButton);
    layout.addWidget(&resultTextEdit);

    QObject::connect(&calculateButton, &QPushButton::clicked, [&]() {
        double a = aLineEdit.text().toDouble();
        double b = bLineEdit.text().toDouble();
        double dx = dxLineEdit.text().toDouble();

        QString result;

        for (double x = a; x <= b; x += dx) {
            double fx = f(x);
            result += QString("x = %1, f(x) = %2\n").arg(x).arg(fx);
        }

        resultTextEdit.setText(result);
    });

    window.show();

    return app.exec();
}
