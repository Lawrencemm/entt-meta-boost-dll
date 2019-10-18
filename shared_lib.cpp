#include <boost/dll.hpp>
#include <entt/meta/meta.hpp>

entt::meta_any get_uint32_cpp()
{
    return entt::meta_any{uint32_t{5}};
}

BOOST_DLL_ALIAS(get_uint32_cpp, get_uint32_t);
