template <typename T>
constexpr bool is_void_ptr = false;

template <>
constexpr bool is_void_ptr<void *> = true;
