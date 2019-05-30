#include "organizer_wrestling.h"
#include "ui_organizer_wrestling.h"

organizer_wrestling::organizer_wrestling(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::organizer_wrestling)
{
    ui->setupUi(this);
}

organizer_wrestling::~organizer_wrestling()
{
    delete ui;
}
void organizer_wrestling::show_participant(){}
void organizer_wrestling::show_tournament(){}//and show matches in every tournament
void organizer_wrestling::show_score_table(){}
bool organizer_wrestling::add_tournament(){return true;}
void organizer_wrestling::manage_matches(){}//define matches in a tournoment
void organizer_wrestling::update_results(){}
void organizer_wrestling::edit_match(){}
void organizer_wrestling::cancel_match(){}
