# llvm-tool
Create you own tool based on LLVM.

# Details
LLVM provides a great way to intreact with it due to the library based design approach.
The commit in this project tries to showcase how we can create an llvm based tool, inside llvm.

It's super simple to create such tool in LLVM with just regrestering the new tool in cmake.
This code is an isolated code, which doesn't work out of llvm tree, it needs llvm to work well.

You can pull this commit in your local fork of llvm and then try to build llvm in normal way, to see the tool present in your `bin/` folder.
Also llvm provides commandline library this repo. tries to showcase basic usage of the library.

# Steps
1. clone LLVM.
2. clone this commit and merge into the LLVM repo.
3. Resolve conflicts if any.
4. Build LLVM the normal way.
5. See `llvm-cli` in `bin/` folder.

# Output from the tool
```
root@628e70d1fb3b /h/b/build# ./bin/llvm-cli --help
OVERVIEW: llvm commandline playing tool

USAGE: llvm-cli [options] <input files>

OPTIONS:

Generic Options:

  --help      - Display available options (--help-hidden for more)
  --help-list - Display list of available options (--help-list-hidden for more)
  --version   - Display the version of this program

These are performance options:

  --opt1      - details
  --opt4      - details
  
```
```
root@628e70d1fb3b /h/b/build# ./bin/llvm-cli --help-hidden


OPTIONS:

Color Options:

  This option category has no options.

General options:

  This option category has no options.

Generic Options:

  -h                  - Alias for --help
  --help              - Display available options (--help-hidden for more)
  --help-hidden       - Display all available options
  --help-list         - Display list of available options (--help-list-hidden for more)
  --help-list-hidden  - Display list of all available options
  --print-all-options - Print all option values after command line parsing
  --print-options     - Print non-default options after command line parsing
  --version           - Display the version of this program

These are instrumnoption options:

  This option category has no options.

These are output options:

  This option category has no options.

These are performance options:

  --opt1              - details
  --opt4              - details
  ```
  
  # modified --version
  ```
  root@628e70d1fb3b /h/b/build# ./bin/llvm-cli --version
LLVM (http://llvm.org/):
  LLVM version 13.0.0git
  Optimized build with assertions.
  Default target: x86_64-unknown-linux-gnu
  Host CPU: znver1


Printing version: 2.0
Commit: f134bd33dd443aac3232
Date: 27/05/2021
```
