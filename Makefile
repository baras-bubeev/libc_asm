SRCS	=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS	=	${SRCS:.s=.o}

NAME	=	libasm.a

TEST	=	test

ASM		=	nasm -felf64

RM		=	rm -f

.s.o:
			$(ASM) $<

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

test:		all
			gcc -o $(TEST) main.c libasm.a

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(TEST)

re:			fclean all

test_re:	fclean test

.PHONY:		all clean fclean re test test_re