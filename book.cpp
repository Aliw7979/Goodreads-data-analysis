#include"book.hpp"
#include"functions.hpp"
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

int book::id_of_all() {
		return id.size();
	}

	int book::id_of_author_book(int const &id_of_book)
	{
		for (int i = 0; i < id.size(); i++) {
			if (id[i] == id_of_book) {
				return author_id[i];
			}
		}
	}

	string book::title_finder(int const &id_of_book)
	{
		for (int i = 0; i < id.size(); i++) {
			if (id[i] == id_of_book) {
				return title[i];
			}
		}

	}

	int book::show_shelf_ids(int const &requested_id)
	{
		for (int i = 0; i < id.size(); i++) {
			if (requested_id == id[i]) {
				cout << "id: " << id[i] << endl <<
					"Title: " << title[i] << endl <<
					"Genre: " << genre[i] << endl;
				return author_id[i];
			}
		}
	}

	vector<int>book::sort_by_title(vector<int>id_of_books)
	{
		vector<int>sorted;
		vector<Match_id_of_book_with_its_title> match;
		for (int i = 0; i < id_of_books.size(); i++) {
			for (int j = 0; j < id.size(); j++) {
				if (id_of_books[i] == id[j]) {
					match.push_back(Match_id_of_book_with_its_title());
					match[i].ids = id[j];
					match[i].titles = title[j];
				}
			}
		}
		sorter(match);
		for (int i = 0; i < match.size(); i++) {
			sorted.push_back(match[i].ids);
		}
		return sorted;
	}

	string book::book_genre_finder(int const &specific_id)
	{
		for (int i = 0; i < id.size(); i++) {
			if (id[i] == specific_id)
				return genre[i];
		}
		return "NULL";
	}

	void book::read_from_file(string books_address)
	{
		string oneline, temp, genre_temp;
		ifstream books_file(books_address);
		books_file.ignore(1000, '\n');
		while (getline(books_file, oneline)) {

			stringstream line(oneline);
			getline(line, temp, ',');
			id.push_back(stoi(temp));
			temp.clear();


			getline(line, temp, ',');
			title.push_back(temp);
			temp.clear();

			getline(line, temp, ',');
			author_id.push_back(stoi(temp));
			temp.clear();


			getline(line, temp);
			genre.push_back(temp);
			temp.clear();



		}
	}
	void book::show_details(int id_of_author)
	{
		cout << "Books:" << endl;
		for (int i = 0; i < author_id.size(); i++) {
			if (author_id[i] == id_of_author) {
				cout << "id: " << id[i] << " Title: " << title[i] << endl;
			}
		}

	}