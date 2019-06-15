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

MAIN		:=	main.c	\

SRC			:=	arguments/arguments.c	\
				arguments/port.c	\
				arguments/width.c	\
				arguments/height.c	\
				arguments/freq.c	\
				arguments/client_nbr.c	\
				arguments/names.c	\
				arguments/resources.c	\
				arguments/int_argument.c	\
				connection/destroy_server_info.c	\
				error.c	\
				connection/init_connection.c	\
				connection/protocols/graphical/protocols.c	\
				connection/protocols/graphical/init_packets.c	\
				connection/protocols/graphical/packet_handler.c	\
				connection/protocols/ai/init_action_handlers.c	\
				connection/handle_clients.c	\
				game/create_map.c	\
				game/resources/default_resources.c	\
				game/resources/handle_resources.c	\
				game/world_generation.c	\
				game/player/create_player.c	\

TEST_SRC	:=	arguments/test_arguments.c	\
				arguments/test_freq_argument.c	\
				arguments/test_names_argument.c	\
				arguments/test_width_argument.c	\
				arguments/test_port_argument.c	\
				arguments/test_client_nbr_argument.c	\
				arguments/test_height_argument.c	\
				test_init_connection.c	\
				test_init_packets.c	\
				test_packet_handler.c	\
				game/test_map.c	\
				game/test_world_generation.c		\
				game/resources/test_resources.c	\
				game/resources/test_default_resources.c	\
				game/player/test_player_creation.c	\


CFLAGS		=	-I $(ROOT)/includes -I ../library/csv/includes $(WARN)

TESTCFLAGS	=	-I $(ROOT)/includes -I ../library/csv/includes $(WARN)

LDFLAGS		=	-lcsv -L ../library/csv

WARN		=	-Wall -Wextra

LIB			?=	1

DEB			?=	0

G			=	-g -D DEBUG

V			?=	@

MAIN_PREFIXED		:= $(addprefix $(SRC_DIR)/, $(MAIN))
SRC_PREFIXED		:= $(addprefix $(SRC_DIR)/, $(SRC))
TEST_SRC_PREFIXED	:= $(addprefix $(TEST_DIR)/, $(TEST_SRC))

MAIN_OBJ		:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(MAIN_PREFIXED))
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

$(NAME):	OBJS += $(MAIN_OBJ)
$(NAME):	$(BUILD)/$(NAME)
			$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
			$(V)cp $(BUILD)/$(NAME) $(NAME)

$(TEST):		CFLAGS += --coverage
$(TEST):		LDFLAGS	+= -lcriterion --coverage
$(TEST):		OBJS +=	$(TEST_OBJS)
$(TEST):		fclean $(BUILD)/$(TEST) #TODO: Find a solution to remove fclean rule
				$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
				$(V)cp $(BUILD)/$(TEST) $(TEST)
				$(V)printf "$(GREEN)Execute tests for $(NAME):$(WHITE)\n"
				$(V)./tests_run -f

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
			$(V)$(CC) -o $@ -c $< $(TESTCFLAGS) $(WARN)

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
