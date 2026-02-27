# NanoGraph Repository

This repository provides a reference template for the integration and use of **NanoGraph**.

## Vision

NanoGraph aims to provide a modular, hardware-agnostic framework for deploying DSP and machine learning applications on embedded systems.

Its vision is to decouple **algorithm design**, **system integration**, and **hardware implementation**, enabling each stakeholder — node developer, system integrator, and silicon vendor — to innovate independently without tight coupling or disclosure of proprietary details.

By standardizing node interfaces, formalizing platform descriptions, and abstracting hardware acceleration, NanoGraph enables:

- Portable and reusable DSP/ML components
- Seamless hardware acceleration without code changes
- Flexible system reconfiguration
- Safe graph updates without firmware recompilation

NanoGraph ultimately establishes the foundation for a scalable ecosystem of interoperable software components across heterogeneous embedded platforms.

------

#### Quick start ([link](QuickStart.md))

------

## 1. Platform Description

A NanoGraph project typically begins with the definition of the target platform, located in:

```
.\NanoGraph_Platform
```

The platform description includes:

- The list of processors
- Associated memory banks
- Available data streams
- Possible interconnections for designing a computing graph

### I/O Manifests

The **I/O manifest** files define the characteristics of the data exchanged to and from the graphs, including:

- Raw sample format
- Interleaving scheme
- Physical domain
- Sampling rate
- Image or signal format
- Frame size
- Other relevant attributes

When multiple configuration options are available, the manifests specify the selectable parameters in order to optimize connections between computing nodes.

------

## 2. Software Components and Node Manifests

In most cases, the platform includes a predefined set of software components stored in flash memory. If not, the next step consists of creating a **node manifest** file for each software component.

The node manifest specifies:

- Input and output ports
- Data formats
- Memory requirements (static, scratch, or backup storage)
- Performance requirements
- Frame-size dependencies
- Initialization parameters
- Author and label information (used in the graphical interface)

### Service Abstraction

During initialization, each node is provided with access to a predefined list of **services**, which may include:

- Standard C library services
- Compute libraries (e.g., subsets of CMSIS such as FFT, filtering, or neural network functions)

This service abstraction enables silicon providers to integrate hardware accelerators transparently. Software nodes can therefore benefit from platform-specific acceleration without requiring code modification.

This mechanism also supports the delivery of **signed binary nodes**.

------

## 3. Graph Design and Compilation

Once the platform and nodes are defined, the computing graph is created using low-code or no-code graphical tools. These tools generate a compact binary representation of the graph, interpreted at runtime by NanoGraph.

### Available Tools

- `NanoGraph_Tools\NanoGraph_GUI`
   Generates a textual description of the links between nodes *(Work In Progress)*.
- `NanoGraph_Tools\NanoGraph_Compiler`
   Produces the binary graph file.
   See the `doc` folder for syntax documentation *(Work In Progress)*.

------

## 4. Dynamic Graph Capabilities

A NanoGraph graph is not limited to a static list of node connections.

It may also include **bytecode sequences** interpreted by a lightweight virtual machine. This enables:

- Dynamic parameter exchange
- Runtime use-case updates
- Flexible system reconfiguration without recompilation

------

## 5. Design Objectives

NanoGraph is designed for **low-cost and low-power embedded systems**.

It enables:

- Rapid tuning and short development cycles through graphical tools
- Avoidance of full code recompilation, reducing the risk of device bricking during OTA updates
- Delivery of scalable DSP/ML components that automatically adapt to platform capabilities (e.g., fast memory or hardware acceleration)
- A foundation for a future software component **store ecosystem**

------

NanoGraph provides a flexible and scalable framework for deploying signal processing and machine learning applications across heterogeneous embedded platforms.

