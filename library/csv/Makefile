##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=	.

SRC_DIR		=	sources

TEST_DIR	=	tests

CC			=	gcc

NAME		=	libcsv.a

TEST		= tests_run

BUILD		=	$(ROOT)/build

SRC			:=	parse_csv.c	\
				operations.c	\
				str_to_word_array.c	\
				check_extension.c	\
				free_csv_data.c	\
				free_array.c	\

TEST_SRC	:=	test_parse_csv.c	\
				test_operations.c

CFLAGS		=	-I $(ROOT)/includes $(WARN)

WARN		=	-Wall -Wextra

LIB			?=	1

DEB			?=	0

G			=	-g -D DEBUG

V			?=	@

SRC_PREFIXED		:= $(addprefix $(SRC_DIR)/, $(SRC))
TEST_SRC_PREFIXED	:= $(addprefix $(TEST_DIR)/, $(TEST_SRC))

OBJS			:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC_PREFIXED))
TEST_OBJS		:=	$(patsubst $(TEST_DIR)/%.c, $(BUILD)/%.o, $(TEST_SRC_PREFIXED))

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

build_tests:	CFLAGS	+= --coverage
build_tests:	LDFLAGS += -lcriterion --coverage
build_tests:	OBJS	+=	$(TEST_OBJS)
build_tests:	fclean $(BUILD)/$(TEST)
				$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
				$(V)cp $(BUILD)/$(TEST) $(TEST)

$(TEST):	build_tests
			$(V)printf "$(GREEN)Execute tests for $(NAME):$(WHITE)\n"
			$(V)./tests_run -f


debug:			 echo_d $(NAME)

release:		 fclean echo_r $(NAME)

$(BUILD)/$(NAME):	$(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)ar rc $(BUILD)/$(NAME) $(OBJS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(SRC_DIR)/%.c
			$(V)mkdir -p $(dir $@)
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS)


$(BUILD)/$(TEST):	$(OBJS) $(TEST_OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)$(CC) -o $(BUILD)/$(TEST) $(OBJS) $(LDFLAGS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(TEST_DIR)/%.c
			$(V)mkdir -p $(dir $@)
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS)

clean:
			$(V)rm -f $(OBJS)
			$(V)rm -f $(TEST_OBJS)
			$(V)rm -rf $(BUILD)
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:		clean
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

.PHONY:		 clean fclean debug all re echo_debug buildrepo build_tests
