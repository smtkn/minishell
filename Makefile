NAME = minishell
CFLAGS = -Wall -Werror -Wextra #-g -ggdb
LIBFT = libft
LIBFTM = libft/libft.a
INCLUDE = -L /usr/include -lreadline
USER 		:= $(shell whoami)
PCNAME		:= $(shell hostname | cut -d'.' -f1)
CC = gcc

 SRC = src/expander_utils.c src/lexer_utils.c src/run_builtin3.c src/run_builtin2.c \
       src/create_files.c src/expander_utils2.c src/main.c src/run_execve.c \
       src/create_files_utils.c src/expander_utils3.c src/run_execve1.c \
       src/dup2_fd.c src/expander_utils4.c src/parser.c src/signal.c \
       src/env.c src/ft_check.c src/single_or_multi_command.c \
       src/exec.c src/ft_check_utils.c src/parser_utils_others.c src/mini_parse.c\
       src/exec_free.c src/heredoc.c src/run_builtin.c \
       src/exec_free2.c src/heredoc_utils.c src/run_builtin1.c src/builtin.c \
 	  src/expander.c src/lexer.c src/utils.c src/exec_utils.c src/run_builtin4.c src/title.c


OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(BASE)))

BASE = $(basename $(notdir $(SRC)))

OBJDIR = builds

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

all: $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(NAME): uname $(OBJDIR) $(OBJ)
	@make -C $(LIBFT)
	@echo "$(CYAN)-- Building Minishell"
	@make bonus -C $(LIBFT)
	@echo "$(BLUE)-- Compiling Files..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFTM) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)-- Compiling Done!$(RESET)"

$(OBJDIR)/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJDIR)
	@echo "$(RED)-- Cleaning Objects...$(RESET)"
	@make -C $(LIBFT) clean

fclean: clean
	@$(RM) -f $(NAME)
	@echo "$(RED)-- Cleaning Program...$(RESET)"
	@make -C $(LIBFT) fclean

re: fclean all

# 	Bu komut minishell.h dosyasındaki T_NAME define'ını hangi kullanıcı ve hangi bilgisayarda çalıştığınızı gösteriyor.
uname:
	@sed -i '' 's/^# define T_NAME.*/# define T_NAME "\\033[0;31m$(USER)\\033[0;32m@\\033[0;36m$(PCNAME) \\033[m"/' src/minishell.h
	@sed -i '' 's/^# define C_NAME.*/# define C_NAME "$(USER)"/' src/minishell.h

# 	Bu komut minishell.h dosyasındaki T_NAME define'ını default olarak "user" olarak ayarlıyor.
unamecls:
	@sed -i '' 's/^# define T_NAME.*/# define T_NAME "user@pc"/' src/minishell.h

norm:
	@echo "$(GREEN)Checking Norminette..."
	@norminette $(SRC) $(HEADERS)
	@echo "$(RESET)"


.PHONY: all clean fclean re check
