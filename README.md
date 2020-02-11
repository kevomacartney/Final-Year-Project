# Final Year Project

This project iis a GPU implementation of MIIND using OpenGL API

This project **is under heavy development**.

Original Implementation

https://github.com/dekamps/miind

## MIIND: a population level simulator.
What is MIIND? It is a simulator that allows the creation, simulation and analysis of large-scale neural networks. It does not model individual neurons, but models populations directly, similarly to a neural mass models, except that we use population density techniques. Population density techniques are based on point model neurons, such as leaky-integrate-and-fire (LIF), quadratic-integrate-and-fire neurons (QIF), or more complex ones, such as adaptive-exponential-integrate-and-fire (AdExp), Izhikevich, Fitzhugh-Nagumo (FN). MIIND is able to model populations of 1D neural models (like LIF, QIF), or 2D models (AdExp, Izhikevich, FN, others). It does so by using statistical techniques to answer the question: "If I'd run a NEST or BRIAN simulation (to name some point model-based simulators), where in state space would my neurons be?" We calculate this distribution in terms of a density function, and from this density function we can infer many properties of the population, including its own firing rate. By modeling large-scale networks as homogeneous populations that exchange firing rate statistics, rather than spikes, remarkable efficiency can be achieved, whilst retaining a connection to spiking neurons that is not present in neural mass models.


## How to Build

Firsly we must create a new directory where we will place all the build files. We do using the following command.

```
$ mdir Build
```

You will then need to navigate into this folder, as this is where we will tell make to place all .obj and executable.
```
$ cd Build/
```

We then need to tell cmake where it can find all the source files. Since the files are in the directory before this, it's straight forward

```
$ cmake ..
```

Finally we can build, if you get any errors here, ensure you have C++14 installed and upto date.

```
$ make
```

The simulation will be made
