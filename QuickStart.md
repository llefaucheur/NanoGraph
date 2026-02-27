# Quick start

NanoGraph separates responsibilities across three complementary domains:

- **System Integration**
   Connect the graph to application interfaces and data streams.
   Select and assemble computing nodes to implement DSP/ML processing.
- **Software Development**
   Develop nodes using a standardized interface for data and parameter exchange.
   Remain agnostic to platform capabilities and to the way computing nodes are assembled within the graph.
- **Platform Design**
   Define a formal manifest describing platform capabilities, including:
  - Guaranteed memory resources
  - I/O stream formats
  - Available computing nodes
  - Accelerated compute libraries

| Objective 1 = Enable system integrators to design graphs spanning multiple physical domains (e.g., “3V”: Vibration, Voice, Vision) |
| ------------------------------------------------------------ |
| ![](doc/NanoGraphMultidomains.png)                           |
| **Objective 2 = Allow the same graph to be mapped onto different architectures described through platform manifests** |
| ![img](doc/img_platforms_manifests.png)                      |



## From a system integrator angle

Launch `GUI.html` located in:

```
NanoGraph_Tools\NanoGraph_GUI
```

Use the platform-specific versions where applicable (e.g., `GUI_E84.html` for PSOC_E84, `GUI_RA8E1.html` for Renesas RA8E1, etc.).

The GUI exports a textual graph description.

This description is then **compiled** using `NanoGraph_Compiler`.
 A batch example (`NanoGraph_compiler.bat`) is available in:

```
NanoGraph_Compiler\NanoGraph_Platform\graphs
```

Alternatively, the graph can be provided directly to the compiler using the documented syntax:
 👉 [NanoGraph Design Specification](doc/NanoGraph-Design.md)

An example of a manually designed graph is available here:
 👉 [graph_computer_filter_detector.txt](doc/graph_computer_filter_detector.txt)

##### Compilation Output

The compilation process generates:

- Either a binary file embedded as a C source file
- Or a standalone binary format

On multiprocessor platforms, the compiled graph is typically placed in shared RAM accessible by all processors.

On simpler platforms, a dedicated Flash section can be reserved for the compiled graph. This enables application updates **without firmware recompilation**.

## From a software developer angle

Software developers must ensure that their nodes conform to the NanoGraph node interface specification:

👉 [NanoGraph Node Manifest Specification](doc/NanoGraph_Node_Manifest.md)

## From a platform designer angle

Platform designers must ensure that the platform description and I/O stream manifests conform to the NanoGraph specification:

👉 [NanoGraph Platform Manifest Specification](doc/NanoGraph_Platform_Manifest.md)
