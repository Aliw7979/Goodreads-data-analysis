#ifndef REVIEW_H
#define REVIEW_H "REVIEW_H"
#include<vector>
#include<string>

class review {
public:

void show_all_reviews_of_book(int const &id_of_book);


	double rating_calculator(int id_of_book);


	int best_reviewer(int &number_of_likes);



	int best_book_average_rating_id(float &rating);

	double credit_viewer(int id_of_user);

	void read_from_file(std::string reviews_address);
    
private:
	std::vector<int> id_of_reviews;
	std::vector<int> book_ids;
	std::vector<int> user_ids;
	std::vector<int>likes;
	std::vector<int> ratings;
	std::vector<std::string> date_of_reviews;
};

#endif