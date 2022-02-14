#ifndef FUNCTIONS_H
#define FUNCTIONS_H "FUNCTIONS_H"

#include<string>
#include<vector>

struct Match_id_of_book_with_its_title {
	int ids;
	std::string titles;
};

bool compare_by_alphabet(const Match_id_of_book_with_its_title &a, const Match_id_of_book_with_its_title &b);
void sorter(std::vector<Match_id_of_book_with_its_title>&a);




#endif