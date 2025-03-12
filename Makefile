##
## EPITECH PROJECT, 2024
## c_proj_template
## File description:
## Makefile
##

# Colors
BOLD=\033[1m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
NC=\033[0m # No Color

MAKEFLAGS += --no-print-directory

.PHONY: all clean fclean re debug

# Directories
LIB_DIR = lib
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Files
LIB	=	$(LIB_DIR)/libmy.a

SRC	=   $(SRC_DIR)/split_strtok.c \
		$(SRC_DIR)/read_csv.c

OBJ =	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME	=	libcuddle.a

# Compiler
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra -L$(LIB_DIR) -lmy

all: $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
	@ar rcT $(NAME) $(OBJ) $(LIB)
	@echo -e "$(GREEN)[PROJECT] $(BLUE)Project compiled$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo -e "$(GREEN)[PROJECT]$(NC)Compiling $<$(NC)"
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@echo -e "$(GREEN)[PROJECT] $(BLUE)Clean$(NC)"
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIB)
	@echo -e "$(YELLOW)[LIBRARY] $(BLUE)Full clean$(NC)"
	@rm -f $(NAME)
	@echo -e "$(GREEN)[PROJECT] $(BLUE)Full clean$(NC)"

re: fclean all

debug: CFLAGS += -g
debug: re
