# NanoGraph Interpreter

How to start depends who you are :

| User               | Actions                                                      |
| ------------------ | ------------------------------------------------------------ |
| platform vendor    | deliver an abstraction layer and a manifest describing your platform capabilities: memory mapping, computing services, data-streaming interfaces |
| software developer | deliver your program together with a manifest describing its capabilities: I/O port descriptions (data formats), memory consumption |
| system integrator  | use the GUI or the graph description language to create arcs between nodes and  tune performance parameters if needed (memory overlays, FIFO sizes) |

## Overview of the interpreter processing

General presentation : [pdf](.doc/NanoGraph_presentation.pdf).

The integration for Computers (repository "NanoGraph_Computer") is a tutorial for the integration on other   platforms. The application declares the interpreter instances and calls `"nanograph_interpreter (NANOGRAPH_RESET)"`.  Next, the application calls `nanograph_interpreter (NANOGRAPH_RUN)`

[Graph-Interpreter Overview](./doc/Graph-Interpreter-Overview.md)

[Platform Manifest](./doc/Platform-Manifest.md)

[Node Manifest and Design](./doc/Node-Manifest.md)

[Scheduler](./doc/Scheduler.md)

[Graph Design](./doc/Graph-Design.md)