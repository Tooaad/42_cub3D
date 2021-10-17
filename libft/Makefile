NAME			=	libft.a

LNAME			=	libft.a

SRCS			=	ft_memset.c			ft_bzero.c			ft_memcpy.c			ft_memccpy.c	\
					ft_memmove.c		ft_memchr.c			ft_memcmp.c			ft_strlen.c		\
					ft_strlcpy.c		ft_strlcat.c		ft_strchr.c			ft_strrchr.c	\
					ft_strnstr.c		ft_strncmp.c		ft_atoi.c			ft_isalpha.c	\
					ft_isdigit.c		ft_isalnum.c		ft_isascii.c		ft_isprint.c	\
					ft_toupper.c		ft_tolower.c		ft_calloc.c			ft_strdup.c		\
					ft_substr.c			ft_strjoin.c		ft_strtrim.c		ft_split.c		\
					ft_itoa.c			ft_strmapi.c		ft_putchar_fd.c		ft_strcpy.c		\
					ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c		base.c			\
					itoh.c				get_next_line.c		ft_newstr.c

OBJECTS			=	ft_memset.o			ft_bzero.o			ft_memcpy.o			ft_memccpy.o	\
					ft_memmove.o		ft_memchr.o			ft_memcmp.o			ft_strlen.o		\
					ft_strlcpy.o		ft_strlcat.o		ft_strchr.o			ft_strrchr.o	\
					ft_strnstr.o		ft_strncmp.o		ft_atoi.o			ft_isalpha.o	\
					ft_isdigit.o		ft_isalnum.o		ft_isascii.o		ft_isprint.o	\
					ft_toupper.o		ft_tolower.o		ft_calloc.o			ft_strdup.o		\
					ft_substr.o			ft_strjoin.o		ft_strtrim.o		ft_split.o		\
					ft_itoa.o			ft_strmapi.o		ft_putchar_fd.o		ft_strcpy.o		\
					ft_putstr_fd.o		ft_putendl_fd.o		ft_putnbr_fd.o		base.o			\
					itoh.o				get_next_line.o		ft_newstr.o

SRCS_BONUS		=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		ft_lstsize_bonus.c		\
					ft_lstlast_bonus.c		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c	\
					ft_lstclear_bonus.c		ft_lstiter_bonus.c			ft_lstmap_bonus.c

OBJECTS_BONUS	=	ft_lstnew_bonus.o		ft_lstadd_front_bonus.o		ft_lstsize_bonus.o		\
					ft_lstlast_bonus.o		ft_lstadd_back_bonus.o		ft_lstdelone_bonus.o	\
					ft_lstclear_bonus.o		ft_lstiter_bonus.o			ft_lstmap_bonus.o

INCLUDES		=	./libft.h

CFLAGS 			= 	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
bonus:
	@gcc $(CFLAGS) -I$(INCLUDES) -c $(SRCS) $(SRCS_BONUS)
	@ar rc $(NAME) $(OBJECTS) $(OBJECTS_BONUS)
	@ranlib $(NAME)
clean:
	@rm -f *.o
	@rm -f *.out
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all $(NAME) clear fclear re
