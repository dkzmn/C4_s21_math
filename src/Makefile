FLAGS=-Wall -Wextra -Werror -std=c11# -fsanitize=address -pedantic
LIBS=-lcheck
OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
	FLAGS += -D MACOS
else
	LIBS += -lsubunit -lrt -lm -lpthread
endif

rebuild: clean all

all: test gcov_report

s21_math.a: s21_math.c
	gcc $(FLAGS) -c s21_math.c -o s21_math.o
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

test: test_s21_math.c s21_math.a
	gcc $(FLAGS) -c test_s21_math.c -o test_s21_math.o
	gcc $(FLAGS) test_s21_math.o s21_math.a $(LIBS) -o test
	./test

gcov_report: test
	gcc $(FLAGS) -c s21_math.c --coverage -o s21_math.o
	gcc $(FLAGS) -c test_s21_math.c --coverage -o test_s21_math.o
	gcc $(FLAGS) test_s21_math.o s21_math.o --coverage $(LIBS) -o test
	./test
	gcovr -r . --html --html-details -o s21_math.html
	rm -rf *.gcda *.gcno

clean:
	rm -rf *.o *.a *.css *.html *.gcda *.gcno test CPPLINT.cfg cpplint.py

clf:
	clang-format -n --style=Google *.[ch]

cpk:
	cppcheck *.[ch]

cpl:
	cp ../materials/linters/CPPLINT.cfg ../materials/linters/cpplint.py ./
	python3 cpplint.py --extensions=c *.[ch]
	rm -rf CPPLINT.cfg cpplint.py

style: clf cpk cpl