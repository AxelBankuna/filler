# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abukasa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 15:49:10 by abukasa           #+#    #+#              #
#    Updated: 2018/08/16 16:08:08 by abukasa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
ALLFILL =filler 

SRC = filler.c src/create.c src/piece.c src/map.c src/print.c src/checking.c src/checking2.c src/free.c \
	  src/init.c src/trim.c src/trim2.c src/trim3.c src/trim4.c src/algo.c 
	  
OBJ = filler.o create.o piece.o map.o print.o checking.o checking2.o free.o \
	  init.o trim.o trim2.o trim3.o trim4.o algo.o 


filler : $(OBJECTS)
all: $(ALLFILL)
$(ALLFILL):
	$(MAKE) -C libft	
	gcc $(SRC) -o $@ $(OBJECTS) libft/libft.a

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckForbiddenSourceHeader src/filler.h
	norminette -R CheckForbiddenSourceHeader filler.c

clean :
	rm -rf $(OBJ)
	$(MAKE) -C libft clean

fclean : clean
	rm -rf $(NAME) filler
	$(MAKE) -C libft fclean
re: fclean all
	$(MAKE) -C libft fclean all
