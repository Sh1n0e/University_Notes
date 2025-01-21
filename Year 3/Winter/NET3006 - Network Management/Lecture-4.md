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

