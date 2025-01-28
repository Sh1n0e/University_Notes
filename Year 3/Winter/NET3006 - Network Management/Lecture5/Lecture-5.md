
- [Management Information](#management-information)
- [MIB, MO, \& Management Protocol](#mib-mo--management-protocol)
	- [Management Infromation - Concept](#management-infromation---concept)
	- [Common Terminology](#common-terminology)
	- [Difference between MIB and Database](#difference-between-mib-and-database)

# Management Information

----

# MIB, MO, & Management Protocol

## Management Infromation - Concept

- Management applicaitons (managers) and managed devices (represented by agents) communicate

- Management Information
	- Anything managers need to know about managed devices
	- Carried in managemnet messages exchanged between managers and agesnt
	- Used by management functions.
	
- Important Questions:
	- *Define management information*
	- *establish common terminology* between manager and agent 
	
----

## Common Terminology 

A central aspect of management infromation which refers to a mutually understood way in which agents and managers can refer to various aspects of managed devices to prevent problems from arising.

Example Scenario:
- Manager queries an edge router for the incoming (direction A) traffic volume
- Agent has a different definition for "incoming" and returns the outgoing (direction B) traffic volume to manager
- Manager finds unusually high traffic --> Suspects an ongoing attack --> might switch off corresponding port to cut off the suspected attacker.

![img1](L5-img/L5-1.png)

>Q: Why would the manager find it unusual in such a case
>Download vs upload speed (Down will always be higher than upload)
>

Example Scenario 2:
- Manager queries agent for information about port 1
- Agent uses different indexes for ports and refers to port 4 as port 1
- Manager confused what and who connected to the two ports
- Subsequent management decisions building on wrong facts

![img2](L5-img/L5-2.png)

Misunderstandings:
- Type of information (incoming vs outgoing traffic in) scenario 1
- Particular instance of information (one of several ports) in scenario 2

----

## Difference between MIB and Database

Why would we be using MIB rather than a database and database management syste (DBMS)

A1: Footprint
- DBMS: heavier weight as it requires more processing resources
- MIB: Lighter weight which enables more focus on management interfaces
- Network devices have limited processing capabilities making it difficult to run a DBMS
- Much of the genera-purpose processing provided by DBMS aren't needed by a manager or an agent.

A2: Management Requirements
- A lot of management information that is hierarchical in nature
- Some management information maintained by the agent(monitoring data for example), others by managers (Configuration settings)

