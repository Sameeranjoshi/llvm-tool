set(LLVM_LINK_COMPONENTS
  Object
  Support
  )

add_llvm_tool(llvm-cli
  llvm-cli.cpp
  )

if(LLVM_INSTALL_BINUTILS_SYMLINKS)
  add_llvm_tool_symlink(cli llvm-cli)
endif()
