CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRCS = server.c
CLIENT_SRCS = client.c
UTILS_SRCS = utils.c
COMMON_SRCS = minitalk.h

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
UTILS_OBJS = $(UTILS_SRCS:.c=.o)
FT_PRINTF_HEADER = ft_printf/ft_printf.h
FT_PRINTF_LIB = ft_printf/libftprintf.a

all: ft_printf $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(UTILS_OBJS) $(SERVER_OBJS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(UTILS_OBJS) $(SERVER_OBJS) $(FT_PRINTF_LIB) -o $(SERVER_NAME)

$(CLIENT_NAME): $(UTILS_OBJS) $(CLIENT_OBJS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(UTILS_OBJS) $(CLIENT_OBJS) $(FT_PRINTF_LIB) -o $(CLIENT_NAME)

%.o: %.c $(COMMON_SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf:
	$(MAKE) -C ft_printf

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(UTILS_OBJS)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re ft_printf
