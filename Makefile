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

.PHONY: all clean fclean re test run

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating $@"
	@ar crs $@ $^

$(ODIR):
	@mkdir -p $@

$(ODIR)/%.o: $(SDIR)/%.s $(ODIR)
	@echo "Compiling $<"
	@nasm -f elf64 -Werror -o $@ $<

clean:
	@rm -rf $(ODIR)

fclean : clean
	@rm -f $(NAME)

re: fclean all


TEST_NAME		:=	test_libasm
LIBASM_NAME		:=	libasm.a
LIBASM_PATH		:=	$(LIBASM_NAME)
CC				:=	gcc
CFLAGS			:=	-Wall -Werror -Wextra -fsanitize=address -z noexecstack
TEST_SRC_DIR	:=	tests
TEST_INC_DIR	:=	tests
TEST_OBJ_DIR	:=	test_objs
TEST_SRCS		:=	main.c \
					test_ft_read.c \
					test_ft_strcmp.c \
					test_ft_strcpy.c \
					test_ft_strdup.c \
					test_ft_strlen.c \
					test_ft_write.c
TEST_INCS		:=	$(TEST_INC_DIR)/libasm.h $(TEST_INC_DIR)/ft_test.h
TEST_OBJS		:=	$(addprefix $(TEST_OBJ_DIR)/, $(TEST_SRCS:.c=.o))
MD				:=	mkdir -p

test: re $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBASM_NAME) -lm -lsubunit -lcheck

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c $(TEST_INCS)
	@$(MD) $(TEST_OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(TEST_INC_DIR)

docker-test:
	@docker build --platform linux/amd64 -t libasm:latest -f ./tests/Dockerfile .
	@docker run --platform linux/amd64 -it --rm libasm:latest
