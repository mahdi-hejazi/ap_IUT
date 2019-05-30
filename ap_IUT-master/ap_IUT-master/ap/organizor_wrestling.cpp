#include "organizer_wrestling.h"
#include "ui_organizor_wrestling.h"

organizor_wrestling::organizor_wrestling(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::organizor_wrestling)
{
    ui->setupUi(this);
}

organizor_wrestling::~organizor_wrestling()
{
    delete ui;
}
void organizer_wrestling::show_participant(){}
void organizer_wrestling::show_tournament(){}//and show matches in every tournament
void organizor_wrestling::show_score_table(){}
bool organizor_wrestling::add_tournament(){return true;}
void organizor_wrestling::manage_matches(){}//define matches in a tournoment
void organizor_wrestling::update_results(){}
void organizor_wrestling::edit_match(){}
void organizor_wrestling::cancel_match(){}
