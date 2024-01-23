# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:43:59 by rmohamma          #+#    #+#              #
#    Updated: 2023/03/13 11:44:01 by rmohamma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME		=	pipex
CC		=	gcc -g3
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	pipex.h pipex_bonus.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	pipex.c pipex_utils.c error.c free.c fork.c
MPATH_DIR		=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=	pipex_bonus.c error_bonus.c pipex_utils_bonus.c\
				free_bonus.c fork_bonus.c
BPATH_DIR		=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

L_FT		= ./library/libft
L_GNL	= ./library/GNL

INC_L_FT	= -L ${L_FT} -lft
INC_L_GNL	= -L ${L_GNL} -lgnl


#COMMANDS
#This is a Makefile rule that describes how to generate an object file (.o) from
# a source file (.c) using the C compiler (CC).
#The rule specifies that for any file that matches the pattern %.o (i.e., any 
#file with the extension .o), this recipe can be used to create it. The recipe 
#itself consists of a single command that is executed when the rule is invoked.
#The command runs the C compiler (specified by the CC variable) with a set of 
#flags (specified by the FLAGS variable) and uses the -c option to compile the 
#source file specified by $< (the first dependency, which will be the .c file 
#corresponding to the .o file being created) and generates the output file 
#specified by $@ (the target file being created).
#The rule also specifies two dependencies, $(HEADER) and Makefile, which means 
#that the object file depends on both the header file and the Makefile itself. 
#If either the header file or the Makefile changes, the object file will be 
#rebuilt.
#The @ symbol at the beginning of the command tells Make to run the command 
#quietly, without echoing it to the terminal. This is a common convention in 
#Makefiles to keep the output clean and avoid cluttering the terminal with 
#unnecessary messages.
%.o: %.c $(HEADER) Makefile
	@${CC} ${FLAGS} -c $< -o $@


all:			$(NAME)

$(NAME):		$(OBJ_M)
			@ make  -C $(L_FT)
			@ $(CC) $(OBJ_M) -o $(NAME) ${INC_L_FT}
#This line of code is a command in a Makefile that uses the echo command to 
#print a message to the terminal.
#The message consists of a few variables wrapped in the $( ) syntax that are 
#evaluated by Make at runtime.
#The $(GREEN) and $(DEFAULT) variables likely contain ANSI escape codes that 
#change the color of the text printed to the terminal. The $(NAME) variable 
#likely contains the name of the file or target that was just created.
#So when this command is executed during the Make process, it will print a 
#message to the terminal that says something like "filename created!" in green 
#text.
			@echo -e "$(GREEN)Mandatory created!$(DEFAULT)"


bonus:		$(OBJ_B)
			@ make  -C $(L_FT)
			@ make  -C $(L_GNL)
			@ $(CC) $(OBJ_B) -o $(NAME) ${INC_L_FT} ${INC_L_GNL}
			@ echo -e "$(GREEN)Bonus created!$(DEFAULT)"

clean:
			@ $(RM) $(OBJ_M)
			@ $(RM) $(OBJ_B)
			@ cd $(L_FT) && $(MAKE) fclean
			@ cd $(L_GNL) && $(MAKE) fclean
			@ echo -e "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean:		clean
			@ $(RM) $(NAME)
			@ $(RM) $(OBJ_B)
			@ cd $(L_FT) && $(MAKE) fclean
			@ cd $(L_GNL) && $(MAKE) fclean
			@ echo -e "$(RED)all deleted!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
DEFAULT	= \033[0m
