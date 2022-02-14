#ifndef AUTHOR_H
#define AUTHOR_H "AUTHOR_H"

#include<string>
#include<vector>
#include<sstream>
#include<iostream>


class author {
public:
	author(int &id_of, std::string &name_of, std::string &gender_of, std::string &member_since_of, int &year_of_birth_of, std::string &place, std::string &genres_of);
	void show_author_info();
	int get_id();
	std::string get_name();
private:
	int id;
	std::string name;
	std::string gender;
	std::string member_since;
	int year_of_birth;
	std::string place_of_birth;
	std::vector <std::string> genres;
};

#endif