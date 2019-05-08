#pragma once
#ifndef ORGANIZER_H
#define ORGENIZER_H
#include <iostream> 

using namespace std;

class organizer
{
	int type; // 1:footsal    2:resteling        3:box
public:
	int get_type();
	virtual void show_participant() = 0;
	virtual void show_tournament() = 0;//and show matches in every tournament
	virtual void show_score_table() = 0;
	virtual bool add_tournament() = 0;
	virtual void manage_matches()=0;//define matches in a tournoment
	virtual void update_results()=0;
	virtual void edit_match()=0;
	virtual void cansel_match()=0;
	//friend ostream& operator << (ostream &out, organizer &tour);
	//friend istream& operator >> (istream &input, organizer &tour);
};
class footsal_organizer : public organizer
{
public:
	virtual void show_participant();
	virtual void show_tournament();//and show matches in every tournament
	virtual void show_score_table();
	virtual bool add_tournament();
	virtual void manage_matches();//define matches in a tournoment
	virtual void update_results();
	virtual void edit_match();
	virtual void cansel_match();
};
class resteling_organizer : public organizer
{
public:
	virtual void show_participant();
	virtual void show_tournament();//and show matches in every tournament
	virtual void show_score_table();
	virtual bool add_tournament();
	virtual void manage_matches();//define matches in a tournoment
	virtual void update_results();
	virtual void edit_match();
	virtual void cansel_match();
};
class boxing_organizer : public organizer
{
public:
	virtual void show_participant();
	virtual void show_tournament();//and show matches in every tournament
	virtual void show_score_table();
	virtual bool add_tournament();
	virtual void manage_matches();//define matches in a tournoment
	virtual void update_results();
	virtual void edit_match();
	virtual void cansel_match();
};


#endif
