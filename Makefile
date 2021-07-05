# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 17:30:55 by abiri             #+#    #+#              #
#    Updated: 2021/07/06 00:50:05 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include make_config.mk

.PHONY: all
all: $(NAME)

# default config

SOURCE_FILES = $(shell find $(SRC_DIR) -type f | sed 's/$(SRC_DIR)\///g')

HEADER_FILES = $(shell find $(INC_DIR) -type f | sed 's/$(INC_DIR)\///g')

# this part is automatic
SOURCES = $(addprefix $(SRC_DIR)/, $(SOURCE_FILES))
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCE_FILES:.c=.o))
INCLUDES = $(addprefix $(INC_DIR)/, $(HEADER_FILES))
LINKS =
INCS = $(addprefix -I , $(shell find $(INC_DIR) -type d))
OBJECT_DIRS = $(sort $(dir $(OBJECTS)))
REQUIRED_RULES =
CLEAN_RULES =
FCLEAN_RULES =
ifeq ($(shell uname -s), Darwin)
	HEADER_PAD = -headerpad_max_install_names
endif

include $(LIBS_DIR)/libraries_linking.mk

$(NAME): $(REQUIRED_RULES) $(OBJECTS)
	$(AR) $(AR_FLAGS) $@ $(OBJECTS)
	$(RANLIB) $(RANLIB_FLAGS) $@

$(TEST_NAME): $(NAME)
	$(CC) $(HEADER_PAD) $(TEST_DIR)/$@.c $(INCS) -L. -lui $(LINKS) -o $@
ifeq ($(shell uname -s), Darwin)
	@-install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 @loader_path/$(SDL2) $@
	@-install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image @loader_path/$(SDL2_IMAGE) $@
	@-install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf @loader_path/$(SDL2_TTF) $@
	@-install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer @loader_path/$(SDL2_MIXER) $@
endif

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES) | $(OBJECT_DIRS)
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(OBJECT_DIRS):
	@echo "DIR "$(OBJECT_DIRS)
	@-mkdir -p $(OBJECT_DIRS)

.PHONY: clean
clean: $(CLEAN_RULES)
	@-rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: $(FCLEAN_RULES)
	@-rm -rf $(OBJ_DIR)
	@-rm -rf $(NAME)
	@-rm -rf $(TEST_NAME)

.PHONY: re
re: fclean all

.PHONY: testclean
testclean:
	@-rm -rf $(TEST_NAME)

.PHONY: retest
retest: testclean test
