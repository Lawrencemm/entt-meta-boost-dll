#include <boost/dll.hpp>
#include <entt/meta/meta.hpp>
#include <iostream>

ENTT_NAMED_TYPE(uint32_t)

void ctx(entt::meta_ctx other) {
    std::cout << (entt::internal::meta_info<>::global) << std::endl;
    entt::meta_ctx::bind(other);
    std::cout << (entt::internal::meta_info<>::global) << std::endl;
}

entt::meta_any get_uint32_cpp()
{
    return entt::meta_any{uint32_t{5}};
}

BOOST_DLL_ALIAS(ctx, set_ctx);
BOOST_DLL_ALIAS(get_uint32_cpp, get_uint32_t);
