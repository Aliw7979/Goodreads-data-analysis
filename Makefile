CC=g++ -std=c++11

all: a.out

a.out:main.o goodreads.o user.o book.o review.o author.o functions.o
	${CC} main.o goodreads.o user.o book.o review.o author.o functions.o


main.o: main.cpp goodreads.hpp
	${CC} -c main.cpp

goodreads.o: goodreads.cpp goodreads.hpp book.hpp user.hpp review.hpp author.hpp
	${CC} -c goodreads.cpp

user.o: user.cpp user.hpp
	${CC} -c user.cpp

functions.o: functions.cpp functions.hpp
	${CC} -c functions.cpp

book.o: book.cpp book.hpp functions.hpp
	${CC} -c book.cpp

review.o: review.cpp review.hpp
	${CC} -c review.cpp

author.o: author.cpp author.hpp
	${CC} -c author.cpp

clean:
	rm *.o
	rm a.out