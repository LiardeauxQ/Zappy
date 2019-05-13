##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=	.

V		?=	@

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
	$(V)make --no-print-directory -C AI
	$(V)make --no-print-directory -C Server
	$(V)cp Server/zappy_server .
	$(V)cp AI/zappy_ai .

debug:			 echo_d $(NAME)

release:		 fclean echo_r $(NAME)

clean:
		$(V)make clean --no-print-directory -C AI
		$(V)make clean --no-print-directory -C Server
		$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:
		$(V)make fclean --no-print-directory -C AI
		$(V)make fclean --no-print-directory -C Server
		$(V)rm -f zappy_server
		$(V)rm -f zappy_ai
		$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:			fclean all

echo_build:
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_d:
			$(V)printf "$(RED)DEBUG MODE initialized.$(WHITE)\n";

echo_r:
			$(V)printf "$(RED)RELEASE MODE initialized.$(WHITE)\n";

.PHONY:		 clean fclean debug all re echo_debug buildrepo 
