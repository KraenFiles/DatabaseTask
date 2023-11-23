#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_updateButton_clicked()
{

}


void MainWindow::on_addButton_clicked()
{

}


void MainWindow::on_deleteButton_clicked()
{

}


void MainWindow::on_peopleFiltrationComboBox_currentIndexChanged(int index)
{
}


void MainWindow::on_allColumnsFiltrationEdit_textChanged(const QString &text)
{

}

