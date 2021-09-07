CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

LIBFT_DIR		=	libft/

LIBFT			=	$(LIBFT_DIR)libft.a

SRCS			=	src/main.c \
					src/gnl.c \
					src/gfx.c \
					src/init.c \
					src/move.c \
					src/hook.c \
					src/utils.c \
					src/parse.c \
					src/array.c \
					src/check1.c \
					src/check2.c

INCLUDE			=	-I minilibx-linux \
					-I include \
					-I libft

OBJS			=	$(addsuffix .o, $(basename, $(SRCS)))

NAME			=	so_long

%.o:				%.c
					@$(CC) $(FLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(SRCS)
					@echo Compiling so_long...
					@$(CC) $(FLAGS) $(INCLUDE) $(SRCS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
					@echo Building libft...
					@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

clean:
					@echo Cleaning objects...
					@$(MAKE) --no-print-directory clean -C $(LIBFT_DIR)

fclean:				clean
					@echo Cleaning binaries...
					@rm -f $(NAME) 
					@$(MAKE) --no-print-directory fclean -C $(LIBFT_DIR)

re:					fclean all

norminette:
					@norminette $(SRCS) \
					include				\
					$(LIBFT_DIR)

.PHONY:				libft
