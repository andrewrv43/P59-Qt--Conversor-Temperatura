#include "principal.h"
#include "ui_principal.h"

#include <QDebug>
Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //conectar el dial de cent a fahr
    connect(ui->inCent,SIGNAL(valueChanged(int)),this,SLOT(cent2fahr(int)));
    //conectar el dial de fahr a cent
    connect(ui->inFahr,SIGNAL(valueChanged(int)),this,SLOT(fahr2cent(int)));
    //conectar el dial de cent a kelv
    connect(ui->inCent,SIGNAL(valueChanged(int)),this,SLOT(cent2kelv(int)));
    //conectar el dial de kelv a cent
    connect(ui->inKelv,SIGNAL(valueChanged(int)),this,SLOT(kelv2cent(int)));
    //conectar el dial de fahr a kelv
    connect(ui->inFahr,SIGNAL(valueChanged(int)),this,SLOT(fahr2kelv(int)));
    //conectar el dial de KELV A FAHR
    connect(ui->inKelv,SIGNAL(valueChanged(int)),this,SLOT(kelv2fahr(int)));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fahr(int i)
{
   if(ui->inCent->hasFocus()){
        int fahr=(i*(9.0/5)+32);
        ui->inFahr->setValue(fahr);

}


}

void Principal::fahr2cent(int i)
{
    if(ui->inFahr->hasFocus()){
        int f=(i-32)*5/9;
        ui->inCent->setValue(f);
    }
}

void Principal::cent2kelv(int i)
{
    if(ui->inCent->hasFocus()){
        float k=i+273.15;
        ui->inKelv->setValue(k);
    }
}

void Principal::kelv2cent(int i)
{
    if(ui->inKelv->hasFocus()){
        float C=i-273.15;
        ui->inCent->setValue(C);
    }
}

void Principal::fahr2kelv(int i)
{
    if(ui->inFahr->hasFocus()){
        float f=((i-32)*5/9)+237.25;
        ui->inKelv->setValue(f);
    }
}

void Principal::kelv2fahr(int i)
{
    if(ui->inKelv->hasFocus()){
        float C=i-273.15;
        C=(C*(9.0/5)+32);
        ui->inFahr->setValue(C);
    }
}

