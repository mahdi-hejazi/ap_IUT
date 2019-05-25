#include "organizer_footsal.h"
#include "ui_organizer_footsal.h"

organizer_footsal::organizer_footsal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::organizer_footsal)
{
    ui->setupUi(this);
}

organizer_footsal::~organizer_footsal()
{
    delete ui;
}
