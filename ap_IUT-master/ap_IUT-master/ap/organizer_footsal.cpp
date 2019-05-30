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
void organizer_footsal::show_participant(){}
void organizer_footsal::show_tournament(){}//and show matches in every tournament
void organizer_footsal::show_score_table(){}
bool organizer_footsal::add_tournament(){return true;}
void organizer_footsal::manage_matches(){}//define matches in a tournoment
void organizer_footsal::update_results(){}
void organizer_footsal::edit_match(){}
void organizer_footsal::cancel_match() {}
