NAME = push_swap

NAME_BONUS = checker

SRC = utils/ft_atoi.c \
		utils/ft_split.c \
		utils/ft_strdup.c \
		utils/ft_strjoin.c \
		utils/ft_strlcpy.c \
		utils/ft_strlen.c \
		push_swap.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		handle_errors.c \
		cleanup.c \
		sort.c \
		sort_small.c \
		sort_large.c \
		sort_large_utils.c \

Bonus_SRC = bonus/checker.c \
		bonus/cleanup_bonus.c \
		bonus/handle_errors_bonus.c \
		bonus/push_bonus.c \
		bonus/read_input_bonus.c \
		bonus/reverse_rotate_bonus.c \
		bonus/rotate_bonus.c \
		bonus/swap_bonus.c \
		bonus/utils/ft_atoi.c \
		bonus/utils/ft_split.c \
		bonus/utils/ft_strdup.c \
		bonus/utils/ft_strjoin.c \
		bonus/utils/ft_strlcpy.c \
		bonus/utils/ft_strlen.c \
		bonus/utils/ft_strcmp.c \
		bonus/GNL/get_next_line.c \
		bonus/GNL/get_next_line_utils.c \

OBJS = $(SRC:.c=.o)

Bonus_OBJS = $(Bonus_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

RM = rm -f

all: $(NAME)

bonus: $(Bonus_OBJS)
	$(CC) $(CFLAGS) $(Bonus_OBJS) -o $(NAME_BONUS)
      
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(Bonus_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re