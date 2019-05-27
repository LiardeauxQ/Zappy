##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=	.

V		?=	@

DIRS			:= $(ROOT)/Server	\
				   $(ROOT)/AI	\
				   $(ROOT)/Graphical

BINARIES_SRC	:=	$(ROOT)/Server/zappy_server	\
					$(ROOT)/AI/zappy_ai	\
					$(ROOT)/Graphical/zappy_graphical

BINARIES		:=	zappy_server	\
					zappy_ai	\
					zappy_graphical

TEST_DIRS		:=	$(ROOT)/Server/tests	\
					$(ROOT)/AI/tests	\
					$(ROOT)/Graphical/tests

#COLOR

GREEN		=	\e[1;32m

WHITE		=	\e[0m

ORANGE		=	\e[1;33m

RED		 =	\e[1;35m

BLUE		=	\e[1;34m


debug:			CFLAGS += $(G)

##
## Directives
##

all:
		$(V)$(foreach var, $(DIRS), make --no-print-directory -C $(var);)
		$(V)$(foreach var, $(BINARIES_SRC), cp $(var) .;)

debug:			 echo_d $(NAME)

release:		 fclean echo_r $(NAME)

tests_run:
		$(V)printf "$(ORANGE)Starting tests:\n\n$(WHITE)"
		$(V)$(foreach var, $(DIRS), make tests_run --no-print-directory -C $(var);)
		$(V)gcovr -r . --exclude Server/tests --exclude AI/tests --exclude Graphical/tests

clean:
		$(V)$(foreach var, $(DIRS), make clean --no-print-directory -C $(var);)
		$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:
		$(V)$(foreach var, $(DIRS), make fclean --no-print-directory -C $(var);)
		$(V)$(foreach var, $(BINARIES), rm -f $(var);)
		$(V)printf "$(ORANGE)Removing binary files.$(WHITE)\n"

re:			fclean all

echo_build:
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_d:
			$(V)printf "$(RED)DEBUG MODE initialized.$(WHITE)\n";

echo_r:
			$(V)printf "$(RED)RELEASE MODE initialized.$(WHITE)\n";

.PHONY:		 clean fclean debug all re echo_debug buildrepo 
