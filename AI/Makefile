##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=	.

SRC_DIR		=	sources

TEST_DIR	=	tests

NAME		=	zappy_ai

TEST		=	tests_run

MAIN		:=	$(SRC_DIR)/main.py	\

SRC			:=	

TEST_SRC	:=


LIB		?=	1

DEB		?=	0

G		=	-g -D DEBUG

V		?=	@

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

$(NAME):
			$(V)printf "$(GREEN)Creating binary.$(WHITE)\n"
			$(V)touch $(NAME)
			$(V)echo "#!/usr/bin/env python3" >> $(NAME)
			$(V)cat $(MAIN) >> $(NAME)
			$(V)chmod +x $(NAME)

$(TEST):
				$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
				$(V)printf "$(GREEN)Executing tests for $(NAME):$(WHITE)\n"

debug:			 echo_d $(NAME)

release:		 fclean echo_r $(NAME)

clean:
			$(V)printf "$(ORANGE)Nothing to do for clean rule.$(WHITE)\n"

fclean:		 clean
			$(V)rm -f $(NAME)
			$(V)rm -f $(TEST)
			$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:			fclean all

echo_build:
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_d:
			$(V)printf "$(RED)DEBUG MODE initialized.$(WHITE)\n";

echo_r:
			$(V)printf "$(RED)RELEASE MODE initialized.$(WHITE)\n";

.PHONY:		 clean fclean debug all re echo_debug buildrepo
