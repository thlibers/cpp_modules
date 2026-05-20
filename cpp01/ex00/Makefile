NAME = Zombie
SOURCES = sources/main.cpp sources/newZombie.cpp sources/randomChump.cpp sources/Zombie.cpp

OBJECTS = $(SOURCES:%.cpp=%.o)

CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98
RM = rm -f
CC = c++

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
 
all: $(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re