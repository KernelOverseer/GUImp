# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libraries_linking.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 14:39:16 by abiri             #+#    #+#              #
#    Updated: 2021/04/10 16:45:54 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_ftsimplesdl_FILE = $(LIBS_DIR)/FT_SimpleSDL/libftsimplesdl.a
LIB_libcplus_FILE = $(LIBS_DIR)/libCplus/libC+.a

REQUIRED_RULES += $(LIB_ftsimplesdl_FILE)\
				  $(LIB_libcplus_FILE)

CLEAN_RULES += LIB_ftsimplesdl_CLEAN\
			   LIB_libcplus_CLEAN

FCLEAN_RULES += LIB_ftsimplesdl_FCLEAN\
				LIB_libcplus_FCLEAN

.PHONY: LIB_ftsimplesdl_CLEAN LIB_libcplus_CLEAN LIB_ftsimplesdl_FCLEAN LIB_libcplus_FCLEAN

# SDL LINKING RULES

OS_TYPE := $(shell uname -s)

SDL_INC = -I libraries/FT_SimpleSDL/sdl2_inc
SDL_DIR = $(LIBS_DIR)/FT_SimpleSDL/sdl2_frameworks
SDL2	= $(SDL_DIR)/SDL2.framework/Versions/A/SDL2
SDL2_IMAGE = $(SDL_DIR)/SDL2_image.framework/Versions/A/SDL2_image
SDL2_TTF = $(SDL_DIR)/SDL2_ttf.framework/Versions/A/SDL2_ttf
SDL2_MIXER = $(SDL_DIR)/SDL2_mixer.framework/Versions/A/SDL2_mixer
SDL_LINK = -F $(SDL_DIR) -framework SDL2 -framework SDL2_image\
	-framework SDL2_ttf -framework SDL2_MIXER
ifeq ($(OS_TYPE), Linux)
	SDL_LINK = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
endif

LINKS += -L $(LIBS_DIR)/FT_SimpleSDL -lftsimplesdl -L $(LIBS_DIR)/libCplus -lC+ $(SDL_LINK)
INCS += -I $(LIBS_DIR)/FT_SimpleSDL/inc -I $(LIBS_DIR)/libCplus/includes $(SDL_INC)

# MAIN RULES

$(LIB_ftsimplesdl_FILE):
	@make -C $(LIBS_DIR)/FT_SimpleSDL

$(LIB_libcplus_FILE):
	@make -C $(LIBS_DIR)/libCplus

LIB_ftsimplesdl_CLEAN:
	@make -C $(LIBS_DIR)/FT_SimpleSDL clean

LIB_ftsimplesdl_FCLEAN:
	@make -C $(LIBS_DIR)/FT_SimpleSDL fclean

LIB_libcplus_CLEAN:
	@make -C $(LIBS_DIR)/libCplus clean

LIB_libcplus_FCLEAN:
	@make -C $(LIBS_DIR)/libCplus fclean
