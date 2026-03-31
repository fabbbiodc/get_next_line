# Get Next Line Makefile
NAME_M = test_mandatory
NAME_B = test_bonus
SRC_M = test_mandatory.c get_next_line.c get_next_line_utils.c
SRC_B = test_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: $(NAME_M)
$(NAME_M): $(SRC_M)
	$(CC) $(CFLAGS) $(SRC_M) -o $(NAME_M)
$(NAME_B): $(SRC_B)
	$(CC) $(CFLAGS) $(SRC_B) -o $(NAME_B)
test_m: $(NAME_M)
	./$(NAME_M) test1.txt
test_b: $(NAME_B)
	./$(NAME_B) test1.txt test2.txt
test: test_m
	@echo "Mandatory tests passed!"
clean:
	rm -f $(NAME_M) $(NAME_B)
fclean: clean
re: clean all