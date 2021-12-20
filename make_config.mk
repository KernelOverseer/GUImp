# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make_config.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 09:47:18 by abiri             #+#    #+#              #
#    Updated: 2021/07/10 20:55:01 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = ui
NAME = lib$(LIB_NAME).a
TEST_NAME = test
CC = gcc
AR = ar
AR_FLAGS = rc
RANLIB = ranlib
RANLIB_FLAGS =
FLAGS = -g -Wall -Werror -Wextra

#directories and paths

INC_DIR = includes
SRC_DIR = sources
LIBS_DIR = ./libraries
OBJ_DIR = ./objects
TEST_DIR = ./tests

#color presets

_lCYAN = \e[1;96m
_lYELLOW = \e[1;93m
_lGREEN = \e[1;92m
_lBLUE = \e[1;94m
_RED = \e[1;31m
_BOLD = \e[1;1m
_END = \e[1;0m

#system specific conditions

SYS_SPECIFIC_FLAGS = -lm
ifeq ($(shell uname -s), Darwin)
	SYS_SPECIFIC_FLAGS := -headerpad_max_install_names
endif
