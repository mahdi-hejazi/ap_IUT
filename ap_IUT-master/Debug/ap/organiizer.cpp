#include "organiizer.h"
#include "ui_organiizer.h"

organiizer::organiizer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::organiizer)
{
    ui->setupUi(this);
}

organiizer::~organiizer()
{
    delete ui;
}
