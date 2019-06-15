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

SERVER_BIN_NAME	=	zappy_server
CLIENT_BIN_NAME	=	zappy_ai
GRAPH_BIN_NAME	=	zappy_graphical

SERVER_BIN_SRC	= $(ROOT)/Server
CLIENT_BIN_SRC	= $(ROOT)/AI
GRAPH_BIN_SRC	= $(ROOT)/Graphical

BINARIES		:=	$(SERVER_BIN_NAME) $(CLIENT_BIN_NAME) $(GRAPH_BIN_NAME)

LIBS				:=	$(ROOT)/library/csv

TEST_DIRS		:=	$(ROOT)/Server/tests	\
					$(ROOT)/AI/tests	\
					$(ROOT)/Graphical/tests	\
					$(ROOT)/library/csv/tests

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

all: $(SERVER_BIN_NAME) $(CLIENT_BIN_NAME) $(GRAPH_BIN_NAME)
		$(V)$(foreach var, $(BINARIES_SRC), cp $(var) .;)

$(SERVER_BIN_NAME): libraries
		$(V)make --no-print-directory -C $(SERVER_BIN_SRC)
		$(V)cp $(SERVER_BIN_SRC)/$(SERVER_BIN_NAME) .

$(CLIENT_BIN_NAME):
		$(V)make --no-print-directory -C $(CLIENT_BIN_SRC)
		$(V)cp $(CLIENT_BIN_SRC)/$(CLIENT_BIN_NAME) .

$(GRAPH_BIN_NAME):
		$(V)make --no-print-directory -C $(GRAPH_BIN_SRC)
		$(V)cp $(GRAPH_BIN_SRC)/$(GRAPH_BIN_NAME) .

libraries:
		$(V)$(foreach var, $(LIBS), make --no-print-directory -C $(var);)

debug:			 echo_d $(NAME)

release:		 fclean echo_r $(NAME)

tests_run:
		$(V)printf "$(ORANGE)Starting tests:\n\n$(WHITE)"
		$(V)$(foreach var, $(LIBS), make tests_run --no-print-directory -C $(var);)
		$(V)$(foreach var, $(LIBS), make --no-print-directory -C $(var);)
		$(V)$(foreach var, $(DIRS), make tests_run --no-print-directory -C $(var);)
		$(V)printf "$(RED)\nCompute coverage for zappy project:\n\n$(WHITE)"
		$(V)gcovr -r . --exclude Server/tests --exclude AI/tests --exclude Graphical/tests --exclude library/csv/tests

clean:
		$(V)$(foreach var, $(LIBS), make clean --no-print-directory -C $(var);)
		$(V)$(foreach var, $(DIRS), make clean --no-print-directory -C $(var);)
		$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:
		$(V)$(foreach var, $(LIBS), make fclean --no-print-directory -C $(var);)
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

.PHONY:		 clean fclean debug all re echo_debug buildrepo libraries
