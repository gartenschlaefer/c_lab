# --
# makefile

# call similar to: // build: gcc sdl_game.c -o build/sdl_game -I /usr/local/include/SDL2 -D_REENTRANT -L /usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2

# name of the build
build_name = sdl_game

# compiler
cc = gcc

# paths
build_path = ./build
obj_path = ./obj
src_paths = ./
inc_paths = /usr/local/include/SDL2
lib_paths = /usr/local/lib

# create folder
$(shell mkdir $(obj_path) 2>/dev/null)
$(shell mkdir $(build_path) 2>/dev/null)

# files
build_target = $(build_path)/$(build_name)
src_files = ${wildcard *.c}
obj_files = $(src_files:%.c=$(obj_path)/%.o) 

# cc flags
inc_flags = -I $(inc_paths) -D_REENTRANT
lib_flags = -L $(lib_paths) -Wl,-rpath,$(lib_paths) -Wl,--enable-new-dtags -lSDL2

# build
build: infos obj
	$(cc) $(lib_flags) $(obj_files) -o $(build_target)
# build: infos sdl_game.o renderer.o
# 	$(cc) $(lib_flags) $(obj_path)/sdl_game.o $(obj_path)/renderer.o  -o $(build_target)

infos:
	@echo src files: $(src_files)
	@echo obj files - to be generated: $(obj_files)
	$(cc) --version

obj: $(obj_files)

# objects
$(obj_path)/%.o: %.c
	$(cc) $(inc_flags) -c $< -o $@
# sdl_game.o: sdl_game.c
# 	$(cc) $(inc_flags) -c sdl_game.c -o $(obj_path)/sdl_game.o
# renderer.o: renderer.c
# 	$(cc) $(inc_flags) -c renderer.c -o $(obj_path)/renderer.o

# run file
run:
	$(build_target)

# clean files
clean:
	rm -f $(obj_files)