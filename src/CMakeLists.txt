add_library(alb Token.hpp tokens/BasicToken.hpp Lexer.hpp StringStore.hpp CompilerDirectiveChecks.hpp Resources.hpp CompilerDirectiveChecks.cpp Lexer.cpp StringStore.cpp Parser.cpp Parser.hpp Function.cpp Function.hpp ElfWriter.cpp ElfWriter.hpp)
target_link_libraries(alb absl::strings)
