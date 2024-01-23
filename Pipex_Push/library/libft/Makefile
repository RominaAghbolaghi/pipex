# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:35:02 by rmohamma          #+#    #+#              #
#    Updated: 2022/11/29 16:35:05 by rmohamma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = pf_base.c pf_char.c pf_nbr.c pf_str.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c


SRCS_BONUS = ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstadd_back.c ft_lstadd_front.c ft_lstsize.c ft_lstiter.c ft_lstmap.c ft_lstlast.c

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS) $(OBJS_BONUS)
	@ ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

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
