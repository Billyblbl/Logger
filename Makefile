##
## EPITECH PROJECT, 2019
## Logger
## File description:
## Makefile
##

CXXFLAGS +=	-std=c++17
CXXFLAGS +=	-I./include
CXXFLAGS +=	-W\
			-Wall\
            -Wextra\
            -Wshadow\
            -Wold-style-cast\
            -Wcast-align\
            -Wunused\
            -Woverloaded-virtual\
            -Wpedantic\
            -Wsign-conversion\
            -Wlogical-op\
            -Wuseless-cast\
            -Wno-non-virtual-dtor

LIB	=	liblog.so

SRC	=	./src/LogLevel.cpp\
		./src/StdLogTarget.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-I./include -fPIC
#LDFLAGS		+=

all:	$(LIB) doc

obj:	$(OBJ)

doc:
	$(MAKE) -C ./doc

$(LIB): obj
	$(CXX) -shared -o $(LIB) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	$(MAKE) -C ./doc $@

re:	fclean all

debug:	CXXFLAGS	+=	-g3
debug:	re

.PHONY:	all obj doc clean fclean re debug
