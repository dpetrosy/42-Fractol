RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

NAME			= fractol
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined
OS				= $(shell uname)
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

LIBFT_DIR		= libft
LINKER  	    = -lft -L $(LIBFT_DIR)
FT_PRINTF_DIR	= ft_printf
LINKER			+= -lftprintf -L $(FT_PRINTF_DIR)

INCLUDES_DIR 	= includes
INCLUDES_FLAG 	= -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)/includes
INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) $(LIBFT_DIR)/libft.h \
				  			   $(FT_PRINTF_DIR)/includes/ft_printf.h

SRCS_DIR		= srcs
SRCS			= $(wildcard $(SRCS_DIR)/*.c)
OBJS_DIR		= objs
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))


ifeq ($(OS), Linux)
	MLX_DIR			= mlx_linux
	LINKER			+= -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
else
	MLX_DIR			= mlx_macos
	LINKER			+= -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
endif


all : $(OBJS_DIR) $(NAME)
	
$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

$(NAME) : $(OBJS)
	@echo $(CYAN) " - Making libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(YELLOW) " - Made libft!" $(RESET)
	@echo $(CYAN) " - Making printf..." $(RESET)
	@$(MAKE) $(FT_PRINTF_DIR)
	@echo $(YELLOW) " - Made printf!" $(RESET)
	@echo $(CYAN) " - Making mlx..." $(RESET)
	@$(MAKE) $(MLX_DIR)
	@echo $(YELLOW) " - Made mlx!" $(RESET)
	@echo $(GREEN) " - Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJS_DIR)
	@echo $(RED) " - Cleaned!" $(RESET)

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) $(MLX_DIR) clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(MAKE) $(FT_PRINTF_DIR) fclean
	@echo $(RED) " - Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re
