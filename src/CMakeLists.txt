add_library(alb Token.hpp tokens/BasicToken.hpp Lexer.hpp StringStore.hpp CompilerDirectiveChecks.hpp Resources.hpp CompilerDirectiveChecks.cpp Lexer.cpp StringStore.cpp)
target_link_libraries(alb absl::strings)
