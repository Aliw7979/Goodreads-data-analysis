#include"functions.hpp"
#include<algorithm>
using namespace std;

bool compare_by_alphabet(const Match_id_of_book_with_its_title &a, const Match_id_of_book_with_its_title &b)
{
	return a.titles < b.titles;
}
void sorter(vector<Match_id_of_book_with_its_title>&a) {
	sort(a.begin(), a.end(), compare_by_alphabet);

}