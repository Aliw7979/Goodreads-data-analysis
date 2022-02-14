#include"review.hpp"
#include<iostream>
#include<set>
#include<fstream>
#include<sstream>
using namespace std;

void review::show_all_reviews_of_book(int const &id_of_book)
{
	cout<<"Reviews:"<<endl;
for(int i=0;i<book_ids.size();i++){
	if(id_of_book==book_ids[i]){
		cout<<"id: "<<id_of_reviews[i]<<
		" Rating: "<<ratings[i]<<
		" Likes: "<<likes[i]<<
		" Date: "<<date_of_reviews[i]<<endl;
	}
}
}


	double review::rating_calculator(int id_of_book)
	 {
		long int number_of_reviews_of_book = 0;
		double temp=0;
		for (int i = 0; i < book_ids.size(); i++) {
			if (book_ids[i] == id_of_book) {
				number_of_reviews_of_book += 1;
				temp += (double)ratings[i] * credit_viewer(user_ids[i]);
			}
		}

		if (number_of_reviews_of_book == 0)
			return 0;

		else
			return temp / number_of_reviews_of_book;

	}


	int review::best_reviewer(int &number_of_likes)
	{
		number_of_likes = 0;
		int most_hit_like = 0, id_of_best_reviewer;
		vector<int>id_of_users_without_dublicate;
		set<int> temp_of_unique(user_ids.begin(), user_ids.end());
		id_of_users_without_dublicate.assign(temp_of_unique.begin(), temp_of_unique.end());

		for (long int i = 0; i < id_of_users_without_dublicate.size(); i++) {

			for (long int sum = 0; sum < user_ids.size(); sum++) {
				if (user_ids[sum] == id_of_users_without_dublicate[i]) {
					number_of_likes += likes[sum];

				}
			}

			if (most_hit_like < number_of_likes) {
				most_hit_like = number_of_likes;
				id_of_best_reviewer = id_of_users_without_dublicate[i];
			}
			number_of_likes = 0;
		}
		number_of_likes = most_hit_like;
		return id_of_best_reviewer;
	}



	int review::best_book_average_rating_id(float &rating)
	{
		vector<int>just_id_of_books_without_dublicate;
		double best_rating = 0, sum_of_ratings = 0, temp;
		int id_of_best, count_of_ratings = 0;

		set<int> temp2(book_ids.begin(), book_ids.end());
		just_id_of_books_without_dublicate.assign(temp2.begin(), temp2.end());
		
		for (int i = 0; i < just_id_of_books_without_dublicate.size(); i++) {



			for (long int sum_ratings = 0; sum_ratings < book_ids.size(); sum_ratings++) {
				if (book_ids[sum_ratings] == just_id_of_books_without_dublicate[i]) {
					sum_of_ratings += ratings[sum_ratings];
					count_of_ratings += 1;
				}
			}

			temp = (double)(sum_of_ratings / count_of_ratings);
			if (best_rating < temp) {
				best_rating = temp;
				id_of_best = just_id_of_books_without_dublicate[i];
			}
			sum_of_ratings = 0;
			count_of_ratings = 0;
		}
		rating = best_rating;
		return id_of_best;
	}

	double review::credit_viewer(int id_of_user)
	{
		int number_of_user_reviews_likes = 0, number_of_likes = 0, number_of_user_reviews = 0, number_of_reviews = id_of_reviews.size();
		for (int i = 0; i < user_ids.size(); i++) {
			if (user_ids[i] == id_of_user) {
				number_of_user_reviews_likes += likes[i];
				number_of_user_reviews += 1;
			}
			number_of_likes += likes[i];
		}
		double user_credit = 0.5 * (((double)number_of_user_reviews_likes / (double)number_of_likes) + ((double)number_of_user_reviews / (double)number_of_reviews));
		
		return user_credit;

	}
	void review::read_from_file(string reviews_address)
	{
		string oneline, temp;
		ifstream review_file(reviews_address);
		review_file.ignore(1000, '\n');
		while (getline(review_file, oneline)) {

			stringstream line(oneline);
			getline(line, temp, ',');
			id_of_reviews.push_back(stoi(temp));
			temp.clear();

			getline(line, temp, ',');
			book_ids.push_back(stoi(temp));
			temp.clear();

			getline(line, temp, ',');
			user_ids.push_back(stoi(temp));
			temp.clear();

			getline(line, temp, ',');
			ratings.push_back(stoi(temp));
			temp.clear();

			getline(line, temp, ',');
			date_of_reviews.push_back(temp);
			temp.clear();

			getline(line, temp, ',');
			likes.push_back(stoi(temp));
			temp.clear();
		}
	}