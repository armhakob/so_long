NAME			= so_long
BUILD			= ./build
SRCDIR			= src
#BSRCDIR			= src_bonus
SRCS			= $(wildcard $(SRCDIR)/*.c)
#SRCS_BONUS		= $(wildcard $(BSRCDIR)/*.c)
OBJS			= $(patsubst $(SRCDIR)/%.c, $(BUILD)/%.o, $(SRCS))
#OBJS_BONUS		= $(patsubst $(BSRCDIR)/%.c, $(BUILD)/%.o, $(SRCS_BONUS))
INCS			= -Iincludes -ILibft
#INCS_BONUS		= $(INCS) -Iincludes_bonus
HEADER			= $(wildcard includes/*.h)
#HEADER_BONUS	= $(wildcard includes_bonus/*.h)
RM				= rm -rf
CC				= cc
FLAGS			= -Wall -Wextra -Werror -fsanitize=address -g
LINKERS			= -LLibft -lft -Imlx -lmlx -framework OpenGL -framework AppKit 


all:	$(BUILD) lib $(NAME)
#bonus:	$(BUILD) lib $(NAME_BONUS)

$(BUILD)/%.o:	$(SRCDIR)/%.c $(HEADER)
		$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(INCS) -o $(NAME) $(LINKERS)

# $(BUILD)/%.o:	$(BSRCDIR)/%.c $(HEADER_BONUS)
# $(CC) $(FLAGS) $(INCS_BONUS) -c $< -o $@

# $(NAME_BONUS):	$(OBJS_BONUS)
# $(CC) $(FLAGS) $(OBJS_BONUS) $(INCS_BONUS) -o $(NAME_BONUS) $(LINKERS) 

$(BUILD):	$(SRCDIR) $(BSRCDIR)
			@mkdir -p $@

lib:
		$(MAKE) -C Libft

clean:
		$(RM) $(BUILD)
		@make clean -C Libft

fclean:	clean
		$(RM) $(NAME)
# $(RM) $(NAME_BONUS)
		@make fclean -C Libft

re: fclean all #bonus


.PHONY : all clean fclean re lib #bonus
