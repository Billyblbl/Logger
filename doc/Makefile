##
## EPITECH PROJECT, 2019
## Logger
## File description:
## Documentation build
##

DOXY	=	./Doxyfile

FORMAT	=	html
			# man\
			# latex


all: $(FORMAT)

build:
	doxygen $(DOXY)

$(FORMAT): build
	ln -s ./build/$@/index.$@ ./doc.$@

clean:
	$(RM) -r ./build

fclean: clean
	$(RM) $(addprefix ./doc., $(FORMAT))

re: fclean all

.PHONY:	all build clean fclean re
