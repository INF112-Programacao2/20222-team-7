TARGET=compfood
CC=g++
LD=g++
LDFLAGS= -l sqlite3
OBJS= maintrabfinal.cpp Dono/Dono.cpp Funcionario/Funcionario.cpp Cliente/Cliente.cpp Gerente/Gerente.cpp Garcom/Garcom.cpp Item/Item.cpp Pedido/Pedido.cpp Restaurante/Restaurante.cpp Validacao/validacao.cpp
compfood:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
install:
	@install sqlite3 /usr/local/bin/sqlite3

clean:
	rm -rf *.o
	rm -rf $(TARGET)

run:
	./$(TARGET)