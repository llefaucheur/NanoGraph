# NanoGraph

This repository is a template for the use of NanoGraph. 

The content of the file "top_manifest.h" (conditional code compilation switches) is aligned with "top_manifest.txt" used by the the graph compiler. The file "top_manifest.c" creates the interface (subroutine "platform_init_specific()") between the generic graph interpreter and the specific details of the device. 

The software architecture of this repository is replicated for each platform.

The graphs are defined in "NanoGraph\NanoGraph_Platform\graphs" where a batch file is used for the graph compilation. The resulting binary graph can be either included and recompiled in the application, or placed at a predefined physical address to let the device execute a new scenario without recompilation. This is why NanoGraph is a real "no code" way of defining and tuning a system. 