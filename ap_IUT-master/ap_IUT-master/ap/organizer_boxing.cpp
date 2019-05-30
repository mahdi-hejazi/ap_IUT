#include "organizer_boxing.h"
#include "ui_organizer_boxing.h"

organizer_boxing::organizer_boxing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::organizer_boxing)
{
    ui->setupUi(this);
}

organizer_boxing::~organizer_boxing()
{
    delete ui;
}
void organizer_boxing::show_participant(){}
void organizer_boxing::show_tournament(){}//and show matches in every tournament
void organizer_boxing::show_score_table(){}
bool organizer_boxing::add_tournament(){return true;}
void organizer_boxing::manage_matches(){}//define matches in a tournoment
void organizer_boxing::update_results(){}
void organizer_boxing::edit_match(){}
void organizer_boxing::cancel_match(){}
