#ifndef VARIANT_HASH_HPP
#define VARIANT_HASH_HPP

#include <utility>

#include <meta/meta.hpp>

#include <variant/detail/index_visitor.hpp>

#include <variant/visit.hpp>

namespace std {

//- 20.N.M hash support:

template <typename... Ts>
struct hash<experimental::variant<Ts...>> {
  using argument_type = experimental::variant<Ts...>;
  using result_type = size_t;

  result_type operator()(const argument_type &v) const {
    using namespace experimental;
    return visit(detail::make_index_visitor<hasher>(), v);
  }

  private:
  template <size_t I>
  struct hasher {
    template <typename Arg>
    result_type operator()(const Arg &arg) const {
      using T = meta::at_c<meta::list<Ts...>, I>;
      return hash<T>{}(arg);
    }
  };  // hasher
};  // hash<experimental::variant<Ts...>>

}  // namespace std

#endif  // VARIANT_HASH_HPP
