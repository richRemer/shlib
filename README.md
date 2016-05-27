Tools
=====
Function library for writing `bash` scripts.

```sh
opt.flag debug -X --debug
opt.flag -i verbosity -v --verbose
opt.flag -d verbosity -q --quiet
opt.value outfile -o --output
opt.required target_file
opt.optional source_file
opt.list include -I --include

opt.doc debug "debug mode"
opt.doc verbosity "amount of logging"
opt.doc outfile "output file to which log is written"
opt.doc target_file "target file for the operation"
opt.doc source_file "source file for the operation"
opt.doc include "search path for included modules"
```
