##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=	.

SRC_DIR		=	sources

TEST_DIR	=	tests

CC		=	gcc

NAME		=	zappy_server

TEST		=	tests_run

BUILD		=	$(ROOT)/build

MAIN		:=	$(SRC_DIR)/main.c	\

SRC			:=	$(SRC_DIR)/arguments/arguments.c	\
				$(SRC_DIR)/arguments/port.c	\
				$(SRC_DIR)/arguments/width.c	\
				$(SRC_DIR)/arguments/height.c	\
				$(SRC_DIR)/arguments/freq.c	\
				$(SRC_DIR)/arguments/client_nbr.c	\
				$(SRC_DIR)/arguments/names.c	\
				$(SRC_DIR)/arguments/int_argument.c	\
				$(SRC_DIR)/destroy_struct.c	\
				$(SRC_DIR)/error.c	\
				$(SRC_DIR)/init_connection.c	\
				$(SRC_DIR)/protocols.c	\

TEST_SRC	:=	$(TEST_DIR)/test_arguments.c


CFLAGS		=	-I $(ROOT)/includes $(WARN)

WARN		=	-Wall -Wextra

LIB			?=	1

DEB			?=	0

G			=	-g -D DEBUG

V			?=	@

MAIN_OBJ		:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(MAIN))
OBJS			:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))
TEST_OBJS		:=	$(patsubst $(TEST_DIR)/%.c, $(BUILD)/%.o, $(TEST_SRC))

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

$(NAME):	OBJS += $(MAIN_OBJ)
$(NAME):	$(BUILD)/$(NAME)
			$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
			$(V)cp $(BUILD)/$(NAME) $(NAME)

$(TEST):		CFLAGS += --coverage
$(TEST):		LDFLAGS	+= -lcriterion --coverage
$(TEST):		OBJS +=	$(TEST_OBJS)
$(TEST):		$(BUILD)/$(TEST)
				$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
				$(V)cp $(BUILD)/$(TEST) $(TEST)
				$(V)printf "$(GREEN)Execute tests for $(NAME):$(WHITE)\n"
				$(V)./tests_run
				$(V)gcovr --exclude $(TEST_DIR)

debug:			 echo_d $(NAME)

release:		 fclean echo_r $(NAME)

$(BUILD)/$(NAME):	$(MAIN_OBJ) $(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)$(CC) -o $(BUILD)/$(NAME) $(OBJS) $(LDFLAGS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BUILD)/$(TEST):	$(OBJS) $(TEST_OBJS)
					$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
					$(V)$(CC) -o $(BUILD)/$(TEST) $(OBJS) $(LDFLAGS)
					$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(SRC_DIR)/%.c
			$(V)mkdir -p $(dir $@)
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS)

$(BUILD)/%.o:		$(TEST_DIR)/%.c
			$(V)mkdir -p $(dir $@)
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS)

clean:
			$(V)rm -f $(OBJS)
			$(V)rm -f $(TEST_OBJS)
			$(V)rm -f $(MAIN_OBJ)
			$(V)rm -rf $(BUILD)
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:		 clean
			$(V)rm -f $(BUILD)/$(NAME)
			$(V)rm -f $(BUILD)/$(TEST)
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
