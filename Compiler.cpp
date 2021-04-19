#include <memory>

#include "Compiler.h"

namespace Compiler
{

Components::Components(std::string module_name) :
  builder(llvmCtx),
  llvmModule(std::make_unique<llvm::Module>(module_name, llvmCtx)) {}

}
