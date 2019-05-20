#pragma once
#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <iostream> 

using namespace std;


class participant {
	string username;
	string password;
	string team_name;
	int tournament[10];//we can have at most 10 tournament
public:

	void get_team_name(string &taem_name);
	bool login();
	virtual void edit();
	//virtual void show_competitor() = 0;//for see our competitor and theire results
	virtual bool sign_in() = 0;
	virtual void observe_login_tournoments() = 0;
	virtual void show_score_table() = 0;//we can see our competitor and they informations
	virtual void show_our_tournament() = 0;//show how much time we have untill tournoment
	virtual void shw_over_matches() = 0;
};

class footsal_participant : public participant
{
	string players[10];//we have at most ten players
	int nationality_code[10];
public:
	virtual bool sign_in();
	virtual void edit();
	//virtual void show_competitor() = 0;//for see our competitor and theire results
	virtual void observe_login_tournoments();
	virtual void show_score_table();//we can see our competitor and they informations
	virtual void show_our_tournament();//show how much time we have untill tournoment
	virtual void shw_over_matches();
	friend ostream& operator << (ostream &out, footsal_participant &tour);
	friend istream& operator >> (istream &input, footsal_participant &tour);

};

class resteling_participant : public participant
{
	string player;
	string nationality_code;
public:
	virtual bool sign_in();
	virtual void edit();
	//virtual void show_competitor() = 0;//for see our competitor and theire results
	virtual void observe_login_tournoments();
	virtual void show_score_table();//we can see our competitor and they informations
	virtual void show_our_tournament();//show how much time we have untill tournoment
	virtual void shw_over_matches();
	friend ostream& operator << (ostream &out, resteling_participant &tour);
	friend istream& operator >> (istream &input, resteling_participant &tour);

};

class boxing_participant : public participant
{
	string player;
	string nationality_code;
public:
	virtual bool sign_in();
	virtual void edit();
	//virtual void show_competitor() = 0;//for see our competitor and theire results
	virtual void observe_login_tournoments();
	virtual void show_score_table();//we can see our competitor and they informations
	virtual void show_our_tournament();//show how much time we have untill tournoment
	virtual void shw_over_matches();
	friend ostream& operator << (ostream &out, boxing_participant &tour);
	friend istream& operator >> (istream &input, boxing_participant &tour);
};








#endif
