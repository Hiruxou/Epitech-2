##
## Makefile for Makefile in /home/paglia_f//WorkOffline/printf
##
## Made by floran pagliai
## Login   <paglia_f@epitech.net>
##
## Started on  Mon Nov 14 10:39:32 2011 floran pagliai
## Last update Fri Jan 23 17:21:52 2015 Nicolas Charvoz
##

NAME= 	moulinette/trade

SRC= 	src/main.cpp\
	src/Logger.cpp\
	src/Trader.cpp\
	src/Tools.cpp

OBJ=	$(SRC:.cpp=.o)

FLAG=	-g -Wall

all:	$(OBJ)
	g++ $(FLAG) -o $(NAME) $(OBJ)
	make clean
	php ./moulinette/trade_moulinette.php -f moulinette/amazon1.txt -p $(NAME) -m 2000000
	php ./moulinette/trade_moulinette.php -f moulinette/bac1.txt -p $(NAME) -m 200000
	php ./moulinette/trade_moulinette.php -f moulinette/cisco1.txt -p $(NAME) -m 300000
	php ./moulinette/trade_moulinette.php -f moulinette/boeing5.txt -p $(NAME) -m 1000000
	php ./moulinette/trade_moulinette.php -f moulinette/ibm5.txt -p $(NAME) -m 2000000
	php ./moulinette/trade_moulinette.php -f moulinette/nike5.txt -p $(NAME) -m 1000000

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
