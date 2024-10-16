#  **************************************************************************   #
#                                                                               #
#                                                          :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+       #
#    By: ahabachi <abdelmathinhabachi@gmail.com>    +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+             #
#    Created: 2024/08/19 17:40:12 by ahabachi          #+#    #+#               #
#    Updated: 2024/09/24 06:34:37 by ahabachi         ###   ########.fr         #
#                                                                               #
#  **************************************************************************   #
#                                                                               #
#                                                                               #
#                                                                               #
#     ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗ ██████╗ ██████╗     #
#    ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔══██╗    #
#    ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   ██║   ██║██████╔╝    #
#    ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██║   ██║██╔══██╗    #
#    ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ╚██████╔╝██║  ██║    #
#     ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═╝    #
#                                                                               #
#                                                                               #
#                                                                               #
#                                                                               #
#  **************************************************************************   #
#                                                                               #
#   █████████            ██████████         ██████████         ██████████       #
#   ██     ██                    ██                 ██         ██      ██       #
#          ██                    ██                 ██         ██      ██       #
#          ██                    ██                 ██                 ██       #
#          ██            ██████████         ██████████                 ██       #
#          ██                    ██                 ██                 ██       #
#          ██                    ██                 ██                 ██       #
#          ██                    ██                 ██                 ██       #
#       ████████         ██████████         ██████████                 ██       #
#                                                                               #
#  **************************************************************************   #

.PHONY: clean fclean re push p docker-container

CPP=c++
NAME=computorv2
CPPFLAGS=-Wall -Wextra -Wshadow -Werror
CREATE_DIRECTORY=mkdir -p
REMOVE_FILE=rm -rf
HEADERS_DIR=include
SOURCES_DIR=sources
OBJECTS_DIR=objects
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Client.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Object.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Matrix.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/OStream.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Complex.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/statment.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/computorv2.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Polynomial.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/UsualFunction.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/VirtualMachine.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/IndependentVariable.hpp

COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/main.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/Client.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/Complex.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/OStream.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/Matrix.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/statment.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/computorv2.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/Polynomial.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/UsualFunction.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/VirtualMachine.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/IndependentVariable.cpp

COMPUTORV2_OBJECTS := $(patsubst $(SOURCES_DIR)/%.cpp, $(OBJECTS_DIR)/%.o, $(COMPUTORV2_SOURCES))

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp $(COMPUTORV2_HEADERS)
	$(CREATE_DIRECTORY) "$(dir $@)"
	$(CPP) $(CPPFLAGS) -c $< -o $@


$(NAME): $(COMPUTORV2_OBJECTS) $(COMPUTORV2_HEADERS)
	$(CPP) -o $(NAME) $(COMPUTORV2_OBJECTS)

all: $(NAME)

clean:
	$(REMOVE_FILE) $(OBJECTS_DIR)

fclean: clean
	$(REMOVE_FILE) $(NAME)

push:
	git add . && git commit -m "update" && git push

p: push

docker-container:
	${sudo} docker run -it -v ${PWD}:/home/computorv2 gcc:latest bash -c "cd '/home/computorv2' && exec bash"

re: fclean all
