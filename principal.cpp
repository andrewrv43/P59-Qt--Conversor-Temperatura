#include "principal.h"
#include "ui_principal.h"

#include <QDebug>
Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->inCent,SIGNAL(valueChanged(int)),this,SLOT(cent2fahr(int)));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fahr(int i)
{
    float fahrenheit=(i*(9/5)+32);
    ui->outFahr->display(fahrenheit);


}

