NAME = sugarray
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -g
INC = -I./include
LFLags = -lm
SRC = src/vec3.cpp src/main.cpp src/color.cpp src/sphere.cpp \
	  src/hitable_list.cpp
OBJS = $(SRC:.cpp=.o)
RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(INC) -o $(NAME) $(OBJS)

all: $(NAME)

test: all
	@./sugarray > test.ppm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) test.ppm

re: fclean all

.PHONY: fclean all re clean
