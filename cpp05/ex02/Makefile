NAME = Bureaucrat
SOURCES = sources/main.cpp sources/Bureaucrat.cpp sources/AForm.cpp sources/PresidentialPardonForm.cpp sources/RobotomyRequestForm.cpp sources/ShrubberyCreationForm.cpp

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