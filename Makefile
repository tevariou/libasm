NAME	:=	libasm.a
SDIR	:=	./srcs
ODIR	:=	./objs
SRCS	:=	ft_write.s \
			ft_read.s \
			ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_strdup.s
_OBJ	:= 	$(SRCS:.s=.o)
OBJ		:= 	$(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	@ar crs $@ $^

$(ODIR)/%.o: $(SDIR)/%.s
	@mkdir -p $(ODIR)
	@nasm -fmacho64 -o $@ $<

clean:
	@rm -rf $(ODIR)

fclean : clean
	@rm -f $(NAME)

re: fclean all

test: re
	@gcc -Wall -Werror -Wextra -fsanitize=address -o test -L. -lasm main.c -I.$
	@./test
	@rm test