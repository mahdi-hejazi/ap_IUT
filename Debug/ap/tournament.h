#pragma once
#ifndef TOURNOMANT_H
#define TOURNOMANT_H
#include <iostream> 
#include "extra_function.h"
using namespace std;

class tournament
{
	int type; // if 1: footsal     if 2: resteling   if 3:box
	string tournament_name;
	string *team_name;
	int number; //max number of ourteam
public:
	time tournomentt;
	tournament(string tournament_name, int type, int number);
	~tournament();
	friend ostream& operator << (ostream &out, tournament &tour);
	friend istream& operator >> (istream &input, tournament &tour);
	void add_team_name(string team_name);
	int get_number();  // get max number of ourteam
	int get_type(); 
};

class match        //this class is for save in a file 
{
	string tournament_name;
	string teams_name[2];
	int score[2]; 
public:
	time tournomentt;
	friend ostream& operator << (ostream &out, match &tour);
	friend istream& operator >> (istream &input, match &tour);
};




#endif // !TOURNOMANT_H

