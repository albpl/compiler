add_library(alb Token.hpp tokens/BasicToken.hpp Lexer.hpp StringStore.hpp CompilerDirectiveChecks.hpp Resources.hpp)
target_link_libraries(alb absl::strings)
