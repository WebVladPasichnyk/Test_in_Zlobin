#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <iostream>
#include <cmath>

double f(double x) {
    // Задайте функцію f(x) тут
    return x * x - 4;
}

double findRoot(double a, double b, double epsilon) {
    double x = (a + b) / 2.0;

    while (std::fabs(f(x)) > epsilon) {
        if (f(a) * f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
        x = (a + b) / 2.0;
    }

    return x;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout layout(&window);

    QLabel label("Введіть початок та кінець відрізка:");
    layout.addWidget(&label);

    QLineEdit startLineEdit;
    layout.addWidget(&startLineEdit);

    QLineEdit endLineEdit;
    layout.addWidget(&endLineEdit);

    QPushButton button("Знайти корінь");
    layout.addWidget(&button);

    QTextEdit resultTextEdit;
    resultTextEdit.setReadOnly(true);
    layout.addWidget(&resultTextEdit);

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        double a = startLineEdit.text().toDouble();
        double b = endLineEdit.text().toDouble();

        // Знайдемо корінь рівняння з точністю 0.0001
        double epsilon = 0.0001;
        double root = findRoot(a, b, epsilon);

        // Вікно перевірки знайденого розв'язку
        QString resultText = "Знайдений корінь рівняння: " + QString::number(root) + "\n";
        resultText += "Значення f(x) в точці x = " + QString::number(f(root)) + "\n";

        resultTextEdit.setText(resultText);
    });

    window.setLayout(&layout);
    window.show();

    return app.exec();
}
