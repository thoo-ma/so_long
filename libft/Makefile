NAME		=	libft.a

SRCS		=	ft_bzero.c		\
				ft_memcpy.c		\
				ft_memchr.c		\
				ft_strchr.c		\
				ft_strlen.c		\
				ft_strdup.c		\
				ft_strcmp.c		\
				ft_strcspn.c

OBJS		=	$(addsuffix .o, $(basename $(SRCS)))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

ARCHIVE		=	ar -rcs $(NAME)

all:			$(NAME)

%.o:			%.c
				@$(CC) $(FLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				@$(ARCHIVE) $^

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

#.PHONY:			all clean fclean re bonus
