CFLALGS 	= 	-g -Wall -Wextra -Werror -Imlx
NAME 		= 	so_long
NAME_BONUS 	= 	so_long_bonus
CC 			= 	cc
SRCLIB		= 	libft/libft.a
SRCPRI 		= 	ft_printf/libftprintf.a

SRC 		= 	mandatory/so_long.c mandatory/parsing.c mandatory/mlx.c mandatory/ft_msg.c mandatory/img_to_window.c \
				mandatory/check_ber.c mandatory/fillitems.c mandatory/move.c

BSRC 		= 	bonus/so_long_bonus.c bonus/parsing_bonus.c bonus/mlx_bonus.c bonus/ft_msg_bonus.c \
				bonus/img_to_window_bonus.c bonus/fillitems_bonus.c bonus/move_bonus.c bonus/check_ber_bonus.c \
				bonus/movenmy_bonus.c bonus/render_next_frame_bonus.c

OBJS 	= 	$(SRC:.c=.o)
BOBJS 	= 	$(BSRC:.c=.o)

MYLB	=	libft
MYHD	=	libft/libft.a

PRLB	=	ft_printf
PRHD	=	ft_printf/libftprintf.a

all	 : $(MYLB) $(PRLB) $(NAME)

bonus: $(MYLB) $(PRLB) $(NAME_BONUS)

$(MYLB):
	make -C $(MYLB)

$(PRLB):
	make -C $(PRLB)

%bonus.o: %bonus.c $(MYHD) $(PRHD) bonus/so_long_bonus.h
	$(CC) $(CFLALGS) -c -I $(MYLB) -I $(PRLB) $< -o $@

%.o: %.c $(MYHD) $(PRHD) mandatory/so_long.h
	$(CC) $(CFLALGS) -c -I $(MYLB) -I $(PRLB) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLALGS) $(OBJS) -L $(MYLB) -lft -L $(PRLB)  -lftprintf -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS): $(BOBJS)
	$(CC) $(CFLALGS) $(BOBJS) -L $(MYLB) -lft -L $(PRLB)  -lftprintf -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean:
	cd libft && make clean
	cd ft_printf && make clean
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	cd libft && make fclean
	cd ft_printf && make fclean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: $(MYLB) $(PRLB)