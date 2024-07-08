# C++ language project subset reference

- Everything should be const, constexpr or consteval if possible
- Every passed value should be const reference
- Every initialization should use { initializer } (copy-initialization only if necessary)
- () is reserved for function (or callable objects) calls and arithmetic operation
- Every constructor have to be explicit
- Every User-defined conversion have to be explicit
