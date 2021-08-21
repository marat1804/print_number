NAME = rush-02
SOURCE = main.c utils.c validators.c
OBJECT = ${SOURCE:.c=.o}
HEADER = header.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	gcc $(OBJECT) -o $(NAME) 

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
