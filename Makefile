NAMEC 		= client
NAMES 		= server
BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus

PRINTF = libftprintf.a

SRCC_FILES   =	srcs/client.c
SRCS_FILES   =	srcs/server.c
BONUSC_FILES =  srcs/client_bonus.c 
BONUSS_FILES =  srcs/server_bonus.c

OBJC  =  srcs/client.o
OBJS  =  srcs/server.o
OBJBC = srcs/client_bonus.o
OBJBS = srcs/server_bonus.o

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE 	= -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMES)

bonus : $(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC) : $(OBJBC)
				@make -C ft_printf
				$(CC) $(CFLAGS) $(OBJBC)  $(INCLUDE)  ft_printf/$(PRINTF) -o $(BONUS_NAMEC)

$(BONUS_NAMES) : $(OBJBS)
				@make -C ft_printf
				$(CC) $(CFLAGS) $(OBJBS)  $(INCLUDE)  ft_printf/$(PRINTF) -o $(BONUS_NAMES)

clean :
		@make clean -C ft_printf
		${RM} ${OBJC}
		${RM} ${OBJS}
		${RM} ${OBJBC}
		${RM} ${OBJBS}
		
fclean : clean
		@make fclean -C ft_printf
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(PRINTF)
		${RM} $(BONUS_NAMEC)
		${RM} $(BONUS_NAMES)

re : fclean all

.PHONY:		all bonus clean fclean re