##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=	..

CURRENT_DIR	=	GraphicalAPI

SRC_DIR		=	sources

CXX	    	=	g++

NAME		=	libGraphicalAPI.a

TEST		=	tests_run

BUILD		=	build

MAIN		:=

SRC			:=	Core/Window.cpp \
				Entity.cpp \
				Tile.cpp \

INCLUDES	=	-I includes

CXXFLAGS	=	$(INCLUDES) $(WARN) -pipe -march=native -std=c++17 -fPIC

LDFLAGS		=	-lsfml-graphics -lsfml-system -lsfml-window

TESTFLAGS	=	$(CXXFLAGS)

WARN		=	-Wall -Wextra

LIB		?=	1

DEB		?=	0

G		=	-g -D DEBUG

V		?=	@


MAIN_PREFIXED		:=	$(addprefix $(SRC_DIR)/, $(MAIN))
SRC_PREFIXED		:=	$(addprefix $(SRC_DIR)/, $(SRC))

MAIN_OBJ		:=	$(patsubst $(SRC_DIR)/%.cpp, $(BUILD)/%.o, $(MAIN_PREFIXED))
OBJS			:=	$(patsubst $(SRC_DIR)/%.cpp, $(BUILD)/%.o, $(SRC_PREFIXED))

#COLOR

GREEN		=	\e[1;32m

WHITE		=	\e[0m

ORANGE		=	\e[1;33m

RED		 	=	\e[1;35m

BLUE		=	\e[1;34m


debug:			CXXFLAGS += $(G)

##
## Directives
##

all:			$(NAME)

$(NAME):	OBJS += $(MAIN_OBJ)
$(NAME):	$(BUILD)/$(NAME)
			$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
			$(V)cp $(BUILD)/$(NAME) $(NAME)

debug:			 echo_d $(NAME)

release:		 fclean echo_r $(NAME)

$(BUILD)/$(NAME):	$(MAIN_OBJ) $(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)ar rc $(BUILD)/$(NAME) $(OBJS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(SRC_DIR)/%.cpp
			$(V)mkdir -p $(dir $@)
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
			$(V)rm -f $(OBJS)
			$(V)rm -f $(MAIN_OBJ)
			$(V)rm -rf $(BUILD)
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:		 clean
			$(V)rm -f $(BUILD)/$(NAME)
			$(V)rm -f $(NAME)
			$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:			fclean all

echo_build:
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_d:
			$(V)printf "$(RED)DEBUG MODE initialized.$(WHITE)\n";

echo_r:
			$(V)printf "$(RED)RELEASE MODE initialized.$(WHITE)\n";

.PHONY:		 clean fclean debug all re echo_debug buildrepo
