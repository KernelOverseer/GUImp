# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make_config.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 09:47:18 by abiri             #+#    #+#              #
#    Updated: 2021/04/10 16:31:20 by abiri            ###   ########.fr        #
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
FLAGS = -g -Ofast

#directories and paths

INC_DIR = ./includes
SRC_DIR = ./sources
LIBS_DIR = ./libraries
OBJ_DIR = ./objects
TEST_DIR = ./tests

#system specific conditions

SYS_SPECIFIC_FLAGS = -lm
ifeq ($(shell uname -s), Darwin)
	SYS_SPECIFIC_FLAGS := -headerpad_max_install_names
endif
