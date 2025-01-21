# Lecture 4

----

## Network Management Components

- Network devices
	- Managed devices/network elements
- Network management system (NMS)
	- An integrated set of tools for management 
- Management network 
	- Interconnecting managing and managed entities 
- Management support organization
	- Running the network using the management technologies


![img1](L4-img/L4-1.png)
	
---- 

## Key Concept - "Manager" & "Agent"

- Network management system (NMS) includes *management applications*
	- Each management application is a manager 
	- An NMS can involve multiple managers
		
- Network devices come with software component that implements a management interface.
	- These components would be knowwn as an *agent*
	- Network devices can have multiple agents for different management functions (i.e reading data, configuring, etc.)
- Manager - agent communication
	- Manager is in charge
	- Agent plays a support role

![img2](L4-img/L4-2.png)
	
---- 

## Network Devices 

- Also called network elements that includes the following:
	1. Switches
	2. Routers
	3. Gateways
	4. Can potentially include network operated servers.
		
- MUST HAVE a *management interface*
	- Allowing the management system to send messages to a device (request to configure, retrieve status data)
	- Allowing a device to send messages to the management system (response to request, unexpected event alarm, etc.)
		
----

## Components of Agent

### Agent

The software that implements the management interface for that device. This device *IS NOT* a network device, However, it represents the device when communicating with a management application (manager)

Conceptually an agent consists of three main parts:
	1. Management interface
	2. Management Information Base (MIB)
	3. Core agent logic.
	
![img3](L4-img/L4-3.png)

### Agent Part 1 - Management interface

The management interface handles management communications by *supporting a management protocol* (Rules of communication) for manager-agent communication.

With the management interface:
	- Management application (manager) can *open or terminate a management session* with the Agent
	- Manager can make *management requests* to the agent (requests for data, change configuration, etc.)
	- The *agent can send messages* to the manager (alert of loss of communication with another device for example.)
	
![img4](L4-img/L4-4.png)

----

## Management Information

An agent has a management information base (MIB)

Management information provides an *abstraction of real-world aspects of devices* for management purposes such as:
	1. Version of installed software
	2. Utilization of ports
	3. Device temperature, voltage
	4. Protocol timeout parameters
	5. Firewall rules
	
----

## Agent Part 2 - MIB

MIB is a *conceptual data store* that contains a management view of the device being managed.
	- Conceptual data stored in MIB - management information 
	- Agent MIB - information local to the device
	- Manager MIB - information of all managed devices
	
*THE MIB IS NOT A REAL DATABASE*
	- An agent MIB is a "virtual" database containing management infromation - just a way to view nad organize information.
	
EXAMPLE OF MIB:
	- Ports of a router represented as a table in an imaginary database
	- Each port having a corresponding entry in the table
	- Columns contain conceptual attributes corresponding to actual porperties of the port.

*If a device has multiple agents, each agent could have a different MIB - different views and abstraction of information*

MIB provides a foundation for network management operations
	- Management operations are based on management communications
	- Management communications are about exchaning information 

![img5](L4-img/L4-5.png)

----

## Agent Part 3 - Core Agent logic

The core agent logic *translates* between the operation of the management interface, the MIB, and the actual device.
	
EXAMPLE:
	1. Manager sends a request to "retrieve a counter" into an Agent
	2. The core agent logic *receives the request through the management interface*
	3. Core agent logic *checks MIB* for the referred counter.
	4. Core agent logic translates the request into an operation that reads out the corresponding hardware register of the device.
	
![img6](L4-img/L4-6.png)

---- 

## Managed Object vs. Real Resource

*A managed object (MO) is a chunk of management infromation* that represents one of the real-world aspects of a network device.

An MO could represent:
	1. Device fan along with its operational state
	2. Port along with a set of statistical data
	3. Firewall rule
	
The *real-world object* that an MO represents is generally referred to as the "real resource"
	- Same real resource can be abstracted in different ways corresponding to different and possibly coexisting MOs
	
> Q: can you give an analogy of different abstractions of the same object?
> 
> testing 

`

---- 