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
    return x - 5;
}

double rectangleMethod(double a, double b, int N) {
    double h = (b - a) / N;
    double sum = 0.0;

    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }

    return h * sum;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout layout(&window);

    QLabel labelN("Введіть кількість прямокутників N:");
    layout.addWidget(&labelN);

    QLineEdit NLineEdit;
    layout.addWidget(&NLineEdit);

    QLabel labelA("Введіть початок відрізка a:");
    layout.addWidget(&labelA);

    QLineEdit aLineEdit;
    layout.addWidget(&aLineEdit);

    QLabel labelB("Введіть кінець відрізка b:");
    layout.addWidget(&labelB);

    QLineEdit bLineEdit;
    layout.addWidget(&bLineEdit);

    QPushButton button("Обчислити інтеграл");
    layout.addWidget(&button);

    QTextEdit resultTextEdit;
    resultTextEdit.setReadOnly(true);
    layout.addWidget(&resultTextEdit);

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        int N = NLineEdit.text().toInt();
        double a = aLineEdit.text().toDouble();
        double b = bLineEdit.text().toDouble();

        // Обчислення інтеграла методом прямокутників
        double integral = rectangleMethod(a, b, N);

        // Вікно виводу обчисленого інтеграла
        QString resultText = "Значення обчисленого інтеграла: " + QString::number(integral) + "\n";
                                                                                                  resultTextEdit.setText(resultText);
    });

    window.setLayout(&layout);
    window.show();

    return app.exec();
}
