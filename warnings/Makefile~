WARN:=-Wall -Werror -Wconversion -Wpointer-arith

all: cast.minusequal.S cast.casting.S cast.minusequal.WARN.S cast.casting.WARN.S

cast.minusequal.S:
	arm-marvell-linux-gnueabi-gcc -c -g -Wa,-a,-ad cast.minusequal.c > cast.minusequal.S

cast.casting.S:
	arm-marvell-linux-gnueabi-gcc -c -g -Wa,-a,-ad cast.casting.c > cast.casting.S

cast.minusequal.WARN.S:
	-arm-marvell-linux-gnueabi-gcc -c -g -Wa,-a,-ad cast.minusequal.c $(WARN) > cast.minusequal.WARN.S

cast.casting.WARN.S:
	-arm-marvell-linux-gnueabi-gcc -c -g -Wa,-a,-ad cast.casting.c $(WARN) > cast.casting.WARN.S
