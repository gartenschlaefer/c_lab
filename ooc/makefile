# --
# makefile

# name of the build
build_name = test_ooc

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
#inc_flags = -I $(inc_paths) -D_REENTRANT
#lib_flags = -L $(lib_paths) -Wl,-rpath,$(lib_paths) -Wl,--enable-new-dtags -lSDL2
inc_flags = 
lib_flags = 

# build
build: infos obj
	$(cc) $(lib_flags) $(obj_files) -o $(build_target)

infos:
	@echo src files: $(src_files)
	@echo obj files - to be generated: $(obj_files)
	$(cc) --version

obj: $(obj_files)

# objects
$(obj_path)/%.o: %.c
	$(cc) $(inc_flags) -c $< -o $@

# run file
run:
	$(build_target)

# clean files
clean:
	rm -f $(obj_files)