#include <iostream>
#include <cmath>
#include <QtWidgets>
using namespace std;
// Функція, що обчислює значення f(x) для заданого x
double f(double x)

{

    return 0.1 * x * x - 5 * x * log(x) - 1;
}
// Функція, що обчислює значення похідної f'(x) для заданого x
double fprime(double x)
{
    return 1 / 5 * x - 5 * log(x) - 5;

}

// Функція, що знаходить корінь рівняння методом дотичних з точністю eps
double solve(double x0, double eps)
{
    double x = x0; // Початкове наближення
    // Ітераційний процеси
    while (abs(f(x)) > eps)
    {
        x = x - f(x) / fprime(x);
    }

    return x;

}

int main(int argc, char *argv[])

{

    QApplication a(argc, argv);

    // Створення вікна
    QWidget window;

    window.setWindowTitle("Розв'язання нелінійного рівняння методом дотичних");

    // Створення лейблів та текстових полів для вводу значень
    QLabel *label1 = new QLabel("Початкове наближення:");
    QLineEdit *lineEdit1 = new QLineEdit;
    QLabel *label2 = new QLabel("Точність (eps):");
    QLineEdit *lineEdit2 = new QLineEdit;

    // Створення кнопки для запуску обчислень
    QPushButton *button = new QPushButton("Розв'язати");

    // Створення лейблів для відображення результатів
    QLabel *resultLabel = new QLabel;
    QLabel *checkLabel = new QLabel;

    // Створення грідбокса та додавання в нього всіх елементів

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label1, 0, 0);
    layout->addWidget(lineEdit1, 0, 1);
    layout->addWidget(label2, 1, 0);
    layout->addWidget(lineEdit2, 1, 1);
    layout->addWidget(button, 2, 0, 1, 2);
    layout->addWidget(resultLabel, 3, 0, 1, 2);
    layout->addWidget(checkLabel, 4, 0, 1, 2);
    window.setLayout(layout);

    // Підключення слоту для кнопки
    QObject::connect(button, &QPushButton::clicked, [&](){

        double x0 = lineEdit1->text().toDouble(); // Отримання значення x0 з текстового поля
        double eps = lineEdit2->text().toDouble(); // Отримання значення eps з текстового поля

        double x = solve(x0, eps); //

        // Відображення результату в лейблі
        resultLabel->setText(QString("Корінь рівняння: %1").arg(x));

        // Перевірка результату і відображення відповідного повідомлення

        if (abs(f(x)) < eps)
        {

            checkLabel->setText("Результат перевірки: 0");

        }
        else
        {

            checkLabel->setText("Результат перевірки: невдало");

        }
    });

    window.show();
    return a.exec();
}
