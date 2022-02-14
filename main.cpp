#include"goodreads.hpp"
#include<iostream>
using namespace std;


int main(int argc,char* argv[])
{
		string command, shelf_type, genre;
	int id;
	string dir=argv[1];
	string authors_file_name="/authors.csv";
	string books_address="/books.csv";
	string reviews_address="/reviews.csv";
	string users_address="/users.csv";

	goodreads goodread((dir+authors_file_name).c_str()
	,(dir+books_address).c_str()
	,(dir+reviews_address).c_str()
	,(dir+users_address).c_str());


	while (true)
	{
		cin >> command;
		if (command == "show_author_info") {
			cin >> id;
			goodread.show_info_of_author(id);
		}
		if (command == "show_sorted_shelf") {
			cin >> id;
			cin >> shelf_type;
			cin >> genre;
			goodread.show_sorted_shelf(id, shelf_type, genre);
		}


		if (command == "credit") {
			cin >> id;
			goodread.show_credit_of_user(id);
		}
		if (command == "best_book") {
			goodread.show_best_book();
		}
		if (command == "best_reviewer") {
			goodread.show_best_reviewer();
		}
		if (command == "recommend_first_approach") {
			cin >> id;
			goodread.recommended_book(id);
		}

	}


}