SHELL := /bin/bash
FLAG =-Wall -Wextra -Werror
CHECK =valgrind --tool=memcheck --leak-check=yes
FILE=test.txt

all: clean s21_cat tests

s21_cat:
	gcc $(FLAG) s21_cat.c -o s21_cat

clean:
	rm -f s21_cat
	rm -f .clang-format

tests:
	-cp ../../materials/linters/.clang-format ../../src/cat/
	-clang-format -n s21_cat.c
	-diff <(./s21_cat $(FILE)) <(cat $(FILE))
	-diff <(./s21_cat -e $(FILE)) <(cat -e $(FILE))
	-diff <(./s21_cat -s $(FILE)) <(cat -s $(FILE))
	-diff <(./s21_cat -n $(FILE)) <(cat -n $(FILE))
	-diff <(./s21_cat -b $(FILE)) <(cat -b $(FILE))
	-diff <(./s21_cat --squeeze-blank $(FILE)) <(cat -s $(FILE))
	-diff <(./s21_cat --number $(FILE)) <(cat -n $(FILE))
	-diff <(./s21_cat --number-noblank $(FILE)) <(cat -b $(FILE))
	-diff <(./s21_cat -etsnb $(FILE)) <(cat -etsnb $(FILE))

	# $(CHECK) ./s21_cat $(FILE) 
	# $(CHECK) ./s21_cat -n $(FILE) 
	# $(CHECK) ./s21_cat -e $(FILE) 
	# $(CHECK) ./s21_cat -t $(FILE) 
	# $(CHECK) ./s21_cat -b $(FILE) 
	# $(CHECK) ./s21_cat -s $(FILE) 
	# $(CHECK) ./s21_cat -etsnb $(FILE)
	
	