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

CPP=c++
NAME=computorv2
CPPFLAGS=
CREATE_DIRECTORY=mkdir -p
HEADERS_DIR=include
SOURCES_DIR=sources
OBJECTS_DIR=objects
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Client.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Object.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Matrix.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Vector.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Complex.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/statment.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/computorv2.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/Polynomial.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/UsualFunction.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/VirtualMachine.hpp
COMPUTORV2_HEADERS := $(COMPUTORV2_HEADERS) $(HEADERS_DIR)/IndependentVariable.hpp

COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/main.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/Client.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/Vector.cpp
COMPUTORV2_SOURCES := $(COMPUTORV2_SOURCES) $(SOURCES_DIR)/Complex.cpp
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
	@echo $(COMPUTORV2_OBJECTS)

all: $(NAME)



# NAME=computor
# CFLAGS=-Wall -Wextra -Werror
# REMOVEFILE=rm -rf
# CREATEDIR=mkdir -p
# PYTHON=python3
# COPYFILE=cp -r
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_init.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_next.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_clear.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_parse.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_solve.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_isnull.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_release.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_acquire.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_isinteger.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_isvariable.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_parse_sign.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_skip_spaces.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_syntaxerror.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_reduced_form.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_print_number.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_fraction_part.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_parse_exponent.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_parse_coefficient.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_irreducible_fraction.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_equation.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_degree.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_copy_number.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_fini.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_usage.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_sqrt.c
# COMPUTORV1_SOURCES+=app/C/sources/computorv1_floor.c

# all: ${NAME} python
	

# ${NAME}:
# 	@cc ${CFLAGS} ${COMPUTORV1_SOURCES} app/C/sources/main.c -o ${NAME}

# test: all
# 	./computor "2 * X^0 = 55 * X^0"
# 	./computor "2 * X^0 = 2 * X^0"
# 	./computor "1 = 0"
# 	./computor "1 + X = 0"
# 	./computor "1 + X + X^2 = 0"
# 	./computor "1 + 2X + X^2 = 0"
# 	./computor "1 - 2X + X^2 = 0"
# 	./computor "1 - X + 2X^2 = 0"
# 	./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
# 	./computor "5 * X^0 + 4 * X^1 = 4 * X^0"
# 	./computor "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"

# clean:
# 	echo "clean..."

# fclean: clean
# 	${REMOVEFILE} ${NAME}
# 	${REMOVEFILE} "build"

# python:
# 	${PYTHON} "app/Python/setup.py" "build"
# 	${CREATEDIR} "lib/python/site-packages"
# 	${COPYFILE} "build/lib.macosx-10.9-x86_64-cpython-310/computorv1.cpython-310-darwin.so" "lib/python/site-packages/computorv1.so"

# push:
# 	git add . && git commit -m "update" && git push

# p: push

# re: fclean all
