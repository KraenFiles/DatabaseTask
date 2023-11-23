#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_updateButton_clicked();
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_peopleFiltrationComboBox_currentIndexChanged(int index);
    void on_allColumnsFiltrationEdit_textChanged(const QString &text);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
