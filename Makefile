# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 22:51:59 by xlamiel-          #+#    #+#              #
#    Updated: 2025/08/03 18:05:08 by xlamiel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
# 🪄▶️ Command line
###############################################################################
#
# gcc ./src/push_swap.c \
#	-I./include \
#	-I/home/xlamiel-/gitroot/libft/include \
#	-L/home/xlamiel-/gitroot/libft \
#	-lft \
#	-oexec_push_swap
#
###############################################################################
# 📦 Project Configuration
###############################################################################

NAME		:= exec_push_swap
SRC_DIR		:= src
OBJ_DIR		:= obj
DEP_DIR		:= dep
INCLUDE_DIR	:= include
LIBFT_DIR	:= /home/xl/gitroot/libft
LIBFT		:= $(LIBFT_DIR)/libft.a

###############################################################################
# 🛠️ Tools & Commands
###############################################################################

CC			:= gcc
RM			:= rm -f
MKDIR		:= mkdir -p

###############################################################################
# ⚙️ Compilation Flags
###############################################################################

CFLAGS		:= -Wall -Wextra -Werror
DEPFLAGS	:= -MMD -MP
INCLUDES	:= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include
LDFLAGS		:= -L$(LIBFT_DIR)
LDLIBS		:= -lft

###############################################################################
# 🎨 Terminal Colors
###############################################################################

GREEN		:= \033[0;32m
RED			:= \033[0;31m
RESET		:= \033[0m

###############################################################################
# 📄 Source Files
###############################################################################
	#$(SRC_DIR)/ps_sorting.c 

SRC			:= \
	$(SRC_DIR)/ps_basic_mov.c \
	$(SRC_DIR)/ps_cost_calc.c \
	$(SRC_DIR)/ps_help_test.c \
	$(SRC_DIR)/ps_print_mov_p.c \
	$(SRC_DIR)/ps_print_mov_r.c \
	$(SRC_DIR)/ps_print_mov_rr.c \
	$(SRC_DIR)/ps_print_mov_s.c \
	$(SRC_DIR)/ps_sort_exec_mov.c \
	$(SRC_DIR)/ps_sort_large.c \
	$(SRC_DIR)/ps_sort_target.c \
	$(SRC_DIR)/ps_sort_three.c \
	$(SRC_DIR)/ps_sort_utils.c \
	$(SRC_DIR)/ps_stack_init.c \
	$(SRC_DIR)/ps_stack_ops1.c \
	$(SRC_DIR)/ps_stack_ops2.c \
	$(SRC_DIR)/push_swap.c

###############################################################################
# 🔧 Derived File Lists
###############################################################################

OBJ			:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEPS		:= $(patsubst $(SRC_DIR)/%.c,$(DEP_DIR)/%.d,$(SRC))

###############################################################################
# 🚀 Build Targets
###############################################################################

all: | $(OBJ_DIR) $(DEP_DIR)
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "$(GREEN)✅ Executable '$@' created$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

###############################################################################
# 🧱 Object Compilation
###############################################################################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@ -MF $(DEP_DIR)/$(notdir $*.d)

###############################################################################
# 📁 Directory Creation
###############################################################################

$(OBJ_DIR):
	@$(MKDIR) $@

$(DEP_DIR):
	@$(MKDIR) $@

###############################################################################
# 🧹 Cleaning Rules
###############################################################################

clean:
	@$(RM) -rf $(OBJ_DIR) $(DEP_DIR)
	@echo "$(RED)🧹 Object and dependency files removed$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🧹 Executable '$(NAME)' removed$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

###############################################################################
# 🐞 Debug Build
###############################################################################

debug:
	#@$(MAKE) -C $(LIBFT_DIR) debug
	@$(MAKE) CFLAGS="$(CFLAGS) -g3" DEPFLAGS="$(DEPFLAGS)" re

###############################################################################
# 📎 Dependency Inclusion
###############################################################################

-include $(wildcard $(DEPS))

###############################################################################
# 📌 Phony Targets
###############################################################################

.PHONY: all clean fclean re debug
