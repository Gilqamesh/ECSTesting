#ifndef TYPES_HPP
# define TYPES_HPP

# include <bitset>
# include <cstdint>

# define MAX_COMPONENTS UINT8_MAX
typedef uint8_t ComponentId;
typedef std::bitset<MAX_COMPONENTS> ComponentSignature;

#endif
