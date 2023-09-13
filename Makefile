# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakan <stakan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 10:51:52 by stakan            #+#    #+#              #
#    Updated: 2023/09/13 10:51:56 by stakan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

#	Flags for compile
CC			= gcc
FLAGS		= -Wall -Werror -Wextra

#	All process use for compiling.
UNAME		:= $(shell uname -s)
NUMPROC		:= 8
USER 		:= $(shell whoami)
PCNAME		:= $(shell hostname | cut -d'.' -f1)

OS			:= NULL
RL_INC_OS	:= /goinfre/$(USER)/brew/Cellar/readline/8.2.1/include
RL_LIB_OS	:= /goinfre/$(USER)/brew/Cellar/readline/8.2.1/lib

#	Libft Part --> OK
LIBFTDIR		= ./libraries/libft
# LIBFT		= $(LIBFTDIR)/libft.a

#	Locations Part --> OK
LIBRARIES	= \
	-L$(LIBFTDIR)/ -lft \
	-L$(RL_LIB_OS) -lreadline
#	-L/opt/homebrew/Cellar/readline/8.1.2/lib -lreadline
#	-L/goinfre/homebrew/opt/readline/lib -lreadline -fcommon

# -L.brew/opt/readline/lib -lreadline
INCLUDES	= \
	-I$(HEADERS_DIRECTORY) \
	-I$(LIBFTDIR)/includes \
	-I$(RL_INC_OS)
#	-I/opt/homebrew/Cellar/readline/8.1.2/include/
#	-I/goinfre/homebrew/opt/readline/include -fcommon
#	-I$(READLINE_DIR)/include

#	HEADERS Parts --> Kutuphane --> OK
HEADERS_DIRECTORY = ./includes/
# HEADERS_LIST = $(subst $(HEADERS_DIRECTORY),,$(wildcard $(HEADERS_DIRECTORY)*.h))
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

#	Source Files --> OK
SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = $(subst $(SOURCES_DIRECTORY),,$(wildcard $(SOURCES_DIRECTORY)*.c))
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

#	Object Files --> (Compiled files directory) -> OK
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

#	COLORS --> 🟥 🟩 🟦
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
END		= \033[m
RESET	= \033[0m
X		= \033[m

#	COLORS BOLD--> B🟥 B🟩 B🟦
B_CYAN		= \033[1;36m
B_BLUE		= \033[1;34m
B_YELLOW	= \033[1;33m
B_GREEN		= \033[1;32m
B_RED		= \033[1;31m
B_RESET		= \033[1m
#NOTE: \033[ ile derlenince calisiyor \e[ ile derlenince bozuk calisiyor.


#	Compiling with all threads.
ifeq ($(UNAME), Linux)
	NUMPROC	:= $(shell grep -c ^processor /proc/cpuinfo)
	OS = "You are connected from -$(CYAN)$(UNAME)$(X)- 🐧 Welcome -$(CYAN)$(USER)$(X)- 😄!"
	RL_INC_OS := /goinfre/brew/opt/readline/include -fcommon
	RL_LIB_OS := /goinfre/brew/opt/readline/lib -fcommon
else ifeq ($(UNAME), Darwin)
	NUMPROC	:= $(shell sysctl -n hw.ncpu)
	OS = "You are connected from $(PCNAME) iMac 🖥 ! Welcome $(CYAN)$(USER)$(X)"
endif
# You can use --> man sysctl -> shell: sysctl -a | grep "hw.ncpu"

all:
	@$(MAKE) $(NAME) -j $(NUMPROC) --no-print-directory
#	@$(MAKE) -s $(NAME) -j $(NUMPROC)

#	Compiling
$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-57b %b" "$(BLUE)COMPILED $(CYAN)$@" "$(GREEN)[✓]$(X)\n"

$(NAME): uname libft $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "[FINISHED]$(X)\n"
	@echo $(OS) $(NUMPROC) cekirdekle derlendi

#	Objects file creating
$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

#	My Library --> OK
libft:
ifneq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), $(NAME)))
	@make -C $(LIBFTDIR) $(MAKECMDGOALS) --silent
else
	@make -C $(LIBFTDIR) --silent
endif


clean: libft
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"

fclean: libft clean unamecls
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

# Use this command inside Ecole 42 schools iMac.
down_brew:
	git clone "https://github.com/Homebrew/brew" /goinfre/$(USER)/brew
	eval "$$(/goinfre/$(USER)/brew/bin/brew shellenv)"
	/goinfre/$(USER)/brew/bin/brew update --force --quiet
	chmod -R go-w "$$(/goinfre/$(USER)/brew/bin/brew --prefix)/share/zsh"
	@echo "Brew installed inside /goinfre/$(USER)/brew"
	/goinfre/$(USER)/brew/bin/brew install readline
	@echo "Brew readline installed."

norm:
	@echo "$(GREEN)Norminette Testi Yürütülüyor$(X)"
	@echo "Includes Norm Hata Sayısı: $(RED)$(shell norminette includes | grep "Error" | wc -l)$(X)"
	@echo "$(RED)$(shell norminette includes | grep "Error")$(X)"
	@echo "Libraries Norm Hata Sayısı: $(RED)$(shell norminette libraries | grep "Error" | wc -l)$(X)"
	@echo "$(RED)$(shell norminette libraries | grep "Error")$(X)"
	@echo "Sources Norm Hata Sayısı: $(RED)$(shell norminette sources | grep "Error" | wc -l)$(X)"
	@echo "$(RED)$(shell norminette sources | grep "Error")$(X)"

uname:
	@sed -i '' 's/^# define T_NAME.*/# define T_NAME 			"\\033[0;31m$(USER)\\033[0;32m@\\033[0;36m$(PCNAME) \\033[m"/' includes/minishell.h

unamecls:
	@sed -i '' 's/^# define T_NAME.*/# define T_NAME 			"user"/' includes/minishell.h

.PHONY: all clean fclean re libft down_brew uname