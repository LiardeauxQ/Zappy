##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=	.

SRC_DIR		=	sources

CC			=	gcc

NAME		=	libcsv.a

BUILD		=	$(ROOT)/build

SRC			:=	parse_csv.c	\
				str_to_word_array.c	\
				free_array.c	\

CFLAGS		=	-I $(ROOT)/includes $(WARN)

WARN		=	-Wall -Wextra

LIB			?=	1

DEB			?=	0

G			=	-g -D DEBUG

V			?=	@

SRC_PREFIXED		:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJS			:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC_PREFIXED))

#COLOR

GREEN		=	\e[1;32m

WHITE		=	\e[0m

ORANGE		=	\e[1;33m

RED		 	=	\e[1;35m

BLUE		=	\e[1;34m


debug:			CFLAGS += $(G)

##
## Directives
##

all:			$(NAME)

$(NAME):	$(BUILD)/$(NAME)
			$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
			$(V)cp $(BUILD)/$(NAME) $(NAME)

debug:			 echo_d $(NAME)

release:		 fclean echo_r $(NAME)

$(BUILD)/$(NAME):	$(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)ar rc $(BUILD)/$(NAME) $(OBJS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(SRC_DIR)/%.c
			$(V)mkdir -p $(dir $@)
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
			$(V)rm -f $(OBJS)
			$(V)rm -rf $(BUILD)
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:		clean
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
