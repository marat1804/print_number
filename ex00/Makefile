NAME = rush-02
SOURCE = dict_parse.c dict_queries.c dict_utils.c ft_split.c ft_strjoin.c get_nbr_list.c list_utils.c main.c memory_control.c print_nbr.c trim_leading_zeros.c utils.c validators.c
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
