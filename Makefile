name = ecsApplication
compile_flags = -Wall -Wextra -Werror -std=c++17
link_flags =
compiler = clang++
pwd = $(shell pwd)
header_directory = $(pwd)/headers
source_directory = $(pwd)/sources
object_directory = $(pwd)/objects
source_files = $(foreach file,$(shell find sources -type f -not -name "*.h"),$(pwd)/$(file))
object_files = $(subst $(source_directory),$(object_directory),$(source_files:.cpp=.o))
header_files = $(foreach file,$(shell find headers -type f),$(pwd)/$(file))

dependencies: $(name) | $(source_directory) $(header_directory) $(object_directory)

$(name): $(subst $(source_directory),$(object_directory),$(source_files:.cpp=.o)) | $(source_directory) $(header_directory) $(object_directory)
	$(compiler) $(link_flags) -o $@ $^

.SECONDEXPANSION:
$(object_directory)/main.o: $(source_directory)/main.cpp $(header_files) | $(object_directory)
	cd $(dir $@) && $(compiler) $(compile_flags) -I$(header_directory) -c $<

# each .hpp file needs to reside in the same directory structure as 'sources' except 'sources' replaced with 'headers'
.SECONDEXPANSION:
%.o: $$(subst $(object_directory),$(source_directory),$$(subst .o,.cpp,$$@)) $$(subst $(object_directory),$(header_directory),$$(subst .o,.hpp,$$@)) | $(object_directory)
	cd $(dir $@) && $(compiler) $(compile_flags) -I$(header_directory) -c $<

$(object_directory):
	mkdir $@ && cd $@ && touch .gitkeep
$(source_directory):
	mkdir $@ && cd $@ && touch .gitkeep
$(header_directory):
	mkdir $@ && cd $@ && touch .gitkeep

.PHONY: all clean re fclean
all:
	make $(name)
clean:
	find $(object_directory) -name "*.o" -delete
fclean: clean
	rm -f $(name)
re: fclean
	make $(name)
