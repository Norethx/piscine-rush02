CC = cc
CFLAGS = -Wall -Wextra -Werror
MAIN = main.c
UTILS = string1.c string2.c
MODULES = get_from_params.c error.c print.c read_dict.c handle_number.c handle_blocks1.c handle_blocks2.c number.c validations.c
OUT = rush-02

# Alvo principal (o executável)
all: rush02

# Como gerar o executável final
rush02:
	$(CC) $(CFLAGS) $(MAIN) $(UTILS) $(MODULES) -o $(OUT)

leak:
	valgrind --leak-check=full --show-leak-kinds=all ./$(OUT)

# Limpeza dos arquivos objeto e do executável
fclean:
	rm -f rush-02