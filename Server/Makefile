##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=	.

SRC_DIR		=	$(ROOT)/sources

TEST_DIR	=	$(ROOT)/tests

BUILD		=	$(ROOT)/build

COMPILER_COMMAND	=	compile_commands.json

TMP_FILES	:=	.tmp tmp

CC		=	gcc

INCLUDES	=	-I includes -I ../library/csv/includes -I ../library/linked_list/includes

NAME		=	zappy_server

TEST		=	tests_run

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
				connection/init_info.c	\
				error.c	\
				connection/init_connection.c	\
				protocols/graphical/protocols.c	\
				protocols/graphical/init_packets.c	\
				protocols/graphical/packet_handler.c	\
				protocols/ai/init_action_handlers.c	\
				protocols/ai/read_ai_client.c	\
				protocols/graphical/commands/broadcast.c	\
				protocols/graphical/commands/eggs.c	\
				protocols/graphical/commands/end_game.c	\
				protocols/graphical/commands/expulsion.c	\
				protocols/graphical/commands/incantation.c	\
				protocols/graphical/commands/map_content.c	\
				protocols/graphical/commands/map_size.c	\
				protocols/graphical/commands/name_teams.c	\
				protocols/graphical/commands/player_connection.c	\
				protocols/graphical/commands/player_death.c	\
				protocols/graphical/commands/player_inventory.c	\
				protocols/graphical/commands/player_level.c	\
				protocols/graphical/commands/player_position.c	\
				protocols/graphical/commands/resources.c	\
				protocols/graphical/commands/server_message.c	\
				protocols/graphical/commands/tile_content.c	\
				protocols/graphical/commands/time.c	\
				protocols/graphical/commands/close_connection.c	\
				protocols/graphical/sender.c	\
				protocols/graphical/read_graph_client.c	\
				handle_clients.c	\
				game/resources/default_resources.c	\
				game/resources/handle_resources.c	\
				game/world_generation.c	\
				game/player/create_player.c	\
				game/player/destroy_player.c	\
				utils/get_next_line.c	\
				commands/wrap_protocols_commands.c	\

TEST_SRC	:=	arguments/test_arguments.c	\
				arguments/test_freq_argument.c	\
				arguments/test_names_argument.c	\
				arguments/test_width_argument.c	\
				arguments/test_port_argument.c	\
				arguments/test_client_nbr_argument.c	\
				arguments/test_height_argument.c	\
				test_init_connection.c	\
				test_init_info.c	\
				test_packet_handler.c	\
				test_init_packets.c	\
				game/test_world_generation.c		\
				game/resources/test_resources.c	\
				game/resources/test_default_resources.c	\
				game/player/test_player_creation.c	\
				commands/test_sender.c	\
				commands/test_map_size.c	\
				commands/test_tile_content.c	\
				commands/test_eggs.c	\
				commands/test_player.c	\
				commands/test_expulsion.c	\
				commands/test_incantation.c	\
				commands/test_player_inventory.c	\
				commands/test_end_game.c	\
				commands/test_broadcast.c	\


CFLAGS		=	$(INCLUDES) $(WARN)

TESTCFLAGS	=	$(INCLUDES) $(WARN)

LDFLAGS		=	-lcsv -L ../library/csv -llinkedlist -L ../library/linked_list

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

MAIN_JSONS	:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o.json, $(MAIN_PREFIXED))
JSONS		:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o.json, $(SRC_PREFIXED))
TEST_JSONS	:=	$(patsubst $(TEST_DIR)/%.c, $(BUILD)/%.o.json, $(TEST_SRC_PREFIXED))


#COLOR

GREEN		=	\e[1;32m

WHITE		=	\e[0m

ORANGE		=	\e[1;33m

RED		 	=	\e[1;35m

BLUE		=	\e[1;34m


debug:			CFLAGS += $(G) -D LOG_LEVEL=5

$(NAME):	OBJS += $(MAIN_OBJ)

build_tests:	CFLAGS += --coverage
build_tests:	LDFLAGS	+= -lcriterion --coverage
build_tests:	OBJS +=	$(TEST_OBJS)

##
## Directives
##

all:			$(ROOT)/$(NAME)

$(ROOT)/$(NAME):	$(BUILD)/$(NAME)
					$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
					$(V)cp $(BUILD)/$(NAME) $(NAME)

build_tests:	fclean $(BUILD)/$(TEST) #TODO: Find a solution to remove fclean rule
				$(V)printf "$(GREEN)Duping binary.$(WHITE)\n"
				$(V)cp $(BUILD)/$(TEST) $(TEST)

cmd_gen:	$(ROOT)/$(COMPILER_COMMAND)

$(TEST):	build_tests
			$(V)printf "$(GREEN)Execute tests for $(NAME):$(WHITE)\n"
			$(V)./tests_run -f
			$(V)find . -maxdepth 1 -type f -name 'tmp*' -delete

debug:			 re

release:		 fclean echo_r $(NAME)

$(ROOT)/$(COMPILER_COMMAND): $(JSONS) += $(MAIN_JSONS)
$(ROOT)/$(COMPILER_COMMAND): $(JSONS) += $(TEST_JSONS)
$(ROOT)/$(COMPILER_COMMAND): $(JSONS)
	$(V)printf "$(WHITE)Creating $(BLUE)$(COMPILER_COMMAND)$(WHITE).\n"
	$(V)sed -e '2s/^/[$\n/' -e '$$s/,$$/$\n]/' $(JSONS) > $(ROOT)/$(COMPILER_COMMAND)
	$(V)rm *.o


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

$(BUILD)/%.o.json:		$(SRC_DIR)/%.c
						$(V)mkdir -p $(dir $@)
						$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
						$(V)$(CC) -MJ $@ -c $< $(CFLAGS)

$(BUILD)/%.o.json:		$(TEST_DIR)/%.c
						$(V)mkdir -p $(dir $@)
						$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
						$(V)$(CC) -MJ $@ -c $< $(TESTCFLAGS) $(WARN)


clean:
			$(V)rm -rf $(BUILD)
			$(V)find . -maxdepth 1 -type f -name 'tmp*' -delete
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:		clean
			$(V)rm -f $(NAME)
			$(V)rm -f $(TEST)
			$(V)rm -f $(COMPILER_COMMAND)
			$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:			fclean all

echo_build:
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_d:
			$(V)printf "$(RED)DEBUG MODE initialized.$(WHITE)\n";

echo_r:
			$(V)printf "$(RED)RELEASE MODE initialized.$(WHITE)\n";

.PHONY:		 clean fclean debug all re echo_debug buildrepo build_tests
