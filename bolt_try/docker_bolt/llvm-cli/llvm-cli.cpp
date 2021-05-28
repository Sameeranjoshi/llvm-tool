// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// Fun learning way to understand how we can integrate any tool in LLVM and make
// use of llvm based libraries, here specific interest is the commandline library.
// https://llvm.org/docs/CommandLine.html
//
// This integrated inside llvm, using out of tree is not in the scope of this repo.
//===----------------------------------------------------------------------===//
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>

using namespace llvm;
static cl::list<std::string>
    InputFilenames(cl::Positional, cl::desc("<input files>"), cl::ZeroOrMore);


cl::OptionCategory perfoption("These are performance options");
cl::OptionCategory outputoption("These are output options");
cl::OptionCategory instrumnoption("These are instrumnoption options");

cl::opt<bool> opt1("opt1", cl::desc("details"), cl::cat(perfoption));
cl::opt<bool> opt2("opt2", cl::desc("details"), cl::cat(outputoption));
cl::opt<bool> opt3("opt3", cl::desc("details"), cl::cat(instrumnoption));
cl::opt<bool> opt4("opt4", cl::desc("details"), cl::cat(perfoption));
cl::opt<bool> opt5("opt5", cl::desc("details"), cl::cat(instrumnoption));

cl::opt<std::string> somerandomoption("some-random-opt",
                cl::desc("This is a random option"),
                cl::init("This init value"));

static void printllvmcliversionprinterfunction(llvm::raw_ostream &OS) {
  OS << "Printing version: 2.0";
}

static void printllvmcliversionprinterfunctionExtra(llvm::raw_ostream &OS) {
  OS << "\nPrinting version: 2.0\n";
  OS << "Commit: f134bd33dd443aac3232\n";
  OS << "Date: 27/05/2021\n";
}

int main(int argc, char **argv) {
  cl::HideUnrelatedOptions(perfoption);
  cl::AddExtraVersionPrinter(printllvmcliversionprinterfunctionExtra);
  cl::ParseCommandLineOptions(argc, argv, "llvm commandline playing tool\n");
  if (InputFilenames.empty()){
          exit(1);
  }

}


