#include"author.hpp"
using namespace std;
author::author(int &id_of, string &name_of, string &gender_of, string &member_since_of, int &year_of_birth_of, string &place, string &genres_of)
	{
		id = id_of;
		name = name_of;
		gender = gender_of;
		member_since=member_since_of;

		year_of_birth = year_of_birth_of;

		place_of_birth = place;
		stringstream temp2(genres_of);
		while (getline(temp2, genres_of, '$')) {
			genres.push_back(genres_of);
			genres_of.clear();
		}

	}
	void author::show_author_info()
	{
		cout << "id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Year of Birth: " << year_of_birth << endl;
		cout << "Place of Birth: " << place_of_birth << endl;

		cout << "Member Since: " << member_since<< endl;

		cout << "Genres: ";
		for (int i = 0; i < genres.size(); i++) {
			cout << genres[i];
			if (i == genres.size())
				cout << ",";
		}
		cout << endl;
	}
	int author::get_id() {
		return id;
	}
	string author::get_name() {
		return name;
	}