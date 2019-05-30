#pragma once
#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <iostream> 
#include "QTextStream"
using namespace std;


class participant {
protected:
    QString username;
    QString password;
    QString team_name;
    QString team_email;
	int tournament[10];//we can have at most 10 tournament
public:

	void get_team_name(string &taem_name);
	virtual void edit();
	//virtual void show_competitor() = 0;//for see our competitor and theire results

	virtual void observe_login_tournoments() = 0;
	virtual void show_score_table() = 0;//we can see our competitor and they informations
	virtual void show_our_tournament() = 0;//show how much time we have untill tournoment
	virtual void shw_over_matches() = 0;
};






#endif
