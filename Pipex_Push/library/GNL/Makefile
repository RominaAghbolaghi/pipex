# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 16:10:02 by rmohamma          #+#    #+#              #
#    Updated: 2023/02/14 16:10:49 by rmohamma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRCS = get_next_line.c get_next_line_utils.c
SRCS_BONUS = get_next_line_bonus.c

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -g

$(NAME): $(OBJS)
	@ ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@ gcc $(FLAGS) -c $(SRCS)

$(OBJS_BONUS): $(SRCS_BONUS) $(SRCS)
	@ gcc $(FLAGS) -c $(SRCS_BONUS) $(SRCS)

all:: $(NAME)

bonus: $(OBJS_BONUS) $(OBJS)
	@ ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

so:
	@ $(CC) -nostartfiles -fPIC $(FLAGS) $(SRCS)
	@ gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS)

clean:
	@ rm -f *.o

fclean: clean
	@ rm -f $(NAME)

re: fclean all
