#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>
# define PRINT_HERE() (std::cerr << __FILE__ << ", " << __LINE__ << std::endl)
# define LOG(x) (std::cout << x << std::endl)

#endif
