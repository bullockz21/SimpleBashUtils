SHELL := /bin/bash
FLAG =-Wall -Wextra -Werror
CHECK =valgrind --tool=memcheck --leak-check=yes
FILE=test.txt

all: clean s21_grep tests

s21_grep:
	gcc $(FLAG) s21_grep.c -o s21_grep

clean:
	rm -f s21_grep
	rm -f .clang-format

tests:
	-cp ../../materials/linters/.clang-format ../../src/grep/
	-clang-format -n s21_grep.c
	-clang-format -n grep.h 
	-diff <(./s21_grep He $(FILE)) <(grep He $(FILE))
	-diff <(./s21_grep -v He $(FILE)) <(grep -v He $(FILE))
	-diff <(./s21_grep -i He $(FILE)) <(grep -i He $(FILE))
	-diff <(./s21_grep -iv He $(FILE)) <(grep -iv He $(FILE))
	-diff <(./s21_grep -in He $(FILE)) <(grep -in He $(FILE))
	-diff <(./s21_grep -ie "^he" $(FILE)) <(grep -ie "^he" $(FILE))
	-diff <(./s21_grep -ince "^he" $(FILE)) <(grep -ince "^he" $(FILE))
	-diff <(./s21_grep -lh se $(FILE)) <(grep -lh se $(FILE))
	-diff <(./s21_grep -hc e $(FILE)) <(grep -hc e $(FILE))
	
	-diff <(./s21_grep -e he $(FILE)) <(grep -e he $(FILE))
	-diff <(./s21_grep -s badfile $(FILE)) <(grep -s badfile $(FILE))
	-diff <(./s21_grep -f test.reg $(FILE)) <(grep -f test.reg $(FILE))
	-diff <(./s21_grep -oi he $(FILE)) <(grep -oi he $(FILE))
	-diff <(./s21_grep -ohf test.reg $(FILE)) <(grep -ohf test.reg $(FILE))
	-diff <(./s21_grep -oinc he $(FILE)) <(grep -oinc he $(FILE))
	-diff <(./s21_grep -oihlnc -e he -e Se -f test.reg $(FILE)) <(grep -oihlnc -e he -e Se -f test.reg $(FILE))

	# $(CHECK) ./s21_grep He $(FILE)
	# $(CHECK) ./s21_grep -v He $(FILE)
	# $(CHECK) ./s21_grep -i He $(FILE)
	# $(CHECK) ./s21_grep -iv He $(FILE)
	# $(CHECK) ./s21_grep -ie "^he" $(FILE)
	# $(CHECK) ./s21_grep -ince "^he" $(FILE)
	# $(CHECK) ./s21_grep -lh se $(FILE)
	# $(CHECK) ./s21_grep -hc e $(FILE)

	# $(CHECK) ./s21_grep -e he $(FILE)
	# $(CHECK) ./s21_grep -s badfile $(FILE)
	# $(CHECK) ./s21_grep -f test.reg $(FILE)
	# $(CHECK) ./s21_grep -oi he $(FILE)
	# $(CHECK) ./s21_grep -ohf test.reg $(FILE)
	# $(CHECK) ./s21_grep -oinc he $(FILE)
	# $(CHECK) ./s21_grep -oihlnc -e he -e Se -f test.reg $(FILE)
	