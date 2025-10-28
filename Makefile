# Nome do executável final
PROJETO = siglaw

# Diretórios
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Compilador e flags
CC = gcc
CFLAGS = -Wall -I$(INC_DIR)

# Lista de arquivos fonte (.c)
SRC = $(wildcard $(SRC_DIR)/*.c)

# Gera lista de objetos (.o) com base nos .c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

# Regra padrão: compilar tudo
all: $(BIN_DIR) $(PROJETO)

# Compila e gera o executável
$(PROJETO): $(OBJ)
	$(CC) $(OBJ) -o $(PROJETO)

# Regra para compilar cada .c individualmente
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cria pasta bin se não existir
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpar arquivos compilados
clean:
	rm -rf $(BIN_DIR) $(PROJETO)

# Limpar tudo, inclusive o executável
fclean: clean

# Recompilar do zero
re: fclean all

.PHONY: all clean fclean re