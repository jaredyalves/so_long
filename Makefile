NAME		:= so_long

LIBDIR		:= lib
SRCDIR		:= src
OBJDIR		:= obj
INCDIR		:= include

LIBFT_DIR	:= $(LIBDIR)/libft
LIBFT_NAME	:= libft.a
LIBFT		:= $(LIBFT_DIR)/$(LIBFT_NAME)

GNL_DIR		:= $(LIBDIR)/get_next_line
GNL_NAME	:= libgnl.a
GNL			:= $(GNL_DIR)/$(GNL_NAME)

MLX_DIR		:= $(LIBDIR)/minilibx-linux
MLX_NAME	:= libmlx.a
MLX			:= $(MLX_DIR)/$(MLX_NAME)

SRCS		:= \
	$(SRCDIR)/main.c \
	$(SRCDIR)/check/check_args.c \
	$(SRCDIR)/parse/parse_file.c \
	$(SRCDIR)/parse/parse_line.c \
	$(SRCDIR)/utils/config.c \
	$(SRCDIR)/utils/exit.c \
	$(SRCDIR)/utils/extension.c \

OBJS		:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
INCS		:= \
	$(INCDIR)/so_long.h \

CC			:= cc
INCLUDES	:= -I$(INCDIR) -I$(LIBFT_DIR)/include -I$(GNL_DIR)/include -I$(MLX_DIR)
CFLAGS		:= -g -Wall -Werror -Wextra $(INCLUDES)
LDFLAGS		:= -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

RM			:= rm
RMFLAGS		:= -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJDIR)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all
