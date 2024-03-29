#include <boost/dll.hpp>
#include <entt/meta/meta.hpp>
#include <iostream>

int main() {
    auto library = boost::dll::shared_library{
            "shared_lib",
            boost::dll::load_mode::append_decorations,
    };
    typedef entt::meta_any (*get_uint32_fn)();
    auto the_any = library.get<get_uint32_fn>("get_uint32_t")();

    uint32_t expected_val{5};

    bool mem_eq = memcmp(the_any.data(), &expected_val, sizeof(uint32_t)) == 0;
    char const * mem_eq_msg = mem_eq? "True" : "False";

    std::cout << "Meta any value unchanged across boundary? " << mem_eq_msg << std::endl;

    auto the_uint = the_any.try_cast<uint32_t>();
    if (the_uint == nullptr)
        std::cout << "Could not cast meta_any to uint32_t" << std::endl;
    else
        std::cout << "Successfully cast meta_any to uint32_t" << std::endl;

    return 0;
}
