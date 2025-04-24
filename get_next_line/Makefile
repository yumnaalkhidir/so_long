CC:= cc
CCFLAGS:= -Wall -Werror -Wextra
FILES:= get_next_line.c get_next_line_utils.c 

BONUS:= get_next_line_bonus.c get_next_line_utils_bonus.c 

HEADER:= get_next_line.h get_next_line_bonus.h
NAME:= gnl.a

OFILES:= $(FILES:.c=.o)
OBONUS:= $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	ar -crs $(NAME) $(OFILES) 

bonus: $(OBONUS) 
	ar -crs $(NAME) $(OBONUS)
	
clean:
	@rm -f $(OFILES) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re