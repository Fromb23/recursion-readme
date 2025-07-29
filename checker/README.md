# Compile the project
make

# Compile and immediately run the checker
make run

# Clean object files
make clean

# Clean everything (object files + executable)
make fclean

# Rebuild from scratch
make re

`Wall -Werror -Wextra -pedantic -std=gnu89`

## SON-C is required. Ensure it's installed:
```bash
    sudo apt install libjson-c-dev
```
