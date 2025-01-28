## Object-oriented Model

- Managed system class
- Physical Equipment: superclass to "managed system"
- Managed system: contains objects of class "TCP connection"
- TCP Connection: maintains relationship to objects of class "endpoint"

----

## Table-based Model

Two tables
- Managed system table: one entry (for the one deivce)
- TCP connections table: multiple entries (for multiple connections)
- A bit more "coarse" than the object-oriented model

![img](img/1.png)

----

## Implicit Model based on Functions

Two groups of CLI functions
- 3 "system"-related functions: retreieve/set name, up time, contact, location
- 2 "connection"-related functions: retrieve connection information

Compared with object-oriented and table-based model
- The other two models: information itself instead of how to access infromation 
- CLI-based implicit model: specific about how to access information.

----

## MIB in SNMP

What does a MIB look like in practice?

Consider the specific metaschema and schema used in SNMP
- Metaschema: MOB specification language
- Schema: model 

Metaschema:
- Structure of Management Information (SMI)
- Table-based

Schema:
- MIB-2
- For devices implementing TCP/IP, widely implemented

SMI and MIB-2 defined by the Internet Engineering Task Force (IETF)
- Standards documents published by IETF: Requests For Comments (RFC)
- RFC 793 - Transmimssion Control Protocol (TCP)
- RFC 1155 - SMI
- RFC 1213 - MIB-II


Minimize details of SMI and MIB-2

Our focus: insight into
- The level of information that is specified
- What a specification can look like

----

## Structure of Managment Information (SMI)

SMI specifies MIB models in modules 

Each MIB module serves a purpose
- Related to a device's communication interfaces
- Related to a feature embedded on a device

MIB of any managed device instantiates multiple MIB modules
- Each represents one aspect of the device & provides a structured view of the resources to be managed.
----

## Object Identifier (OID) and OID Tree

Infomration in MIB organized into a conceptual tree
- Every model in the MIB --> a node in the tree

Each node named relative to a containing node:
- Node ID: the object identifier (OID)
- OID of iso: 1
- OID of org: 1.3
- OID of dod: 1.3.6
- OID of the internet: 1.3.6.1
- The tree - OID tree

![img](img/2.png)

----

## Scalar and Tabular Objects

Another way to categorize: instantiated how many times in an agent?

Scalars: instantiated only *once* in an agent
- Nodes containing the host name, or a serial number of a chassis, or some global settings for the device,e tc.
- Management operations apply exclusively to scalar objects in SNMP

Tabular objects: instantiated multiple times
- Nodes representing infromation about cards in a chassis, or communication resources that are dynamically created and torn down during run time.
- Conceptual table entries for deleopers of management application to organize information in SNMP.

----

## SMI-specified Data Types

No complex data types such as arrays or lists... There are only simple data types such as:
- Integer, octet strings, etc.
- Network addresses
- Counters - increasing only until reaching max value or resetting
- Gauges - increating or decreasing

A conceptual structure can be built by grouping objects together.

----

# A Closer Look at MIB-2

----

## Defining the MIB-2 Module

Based on IETF RFC1213.

Establishes mib-2 as a new node under "mgmnt" in OID tree 

![img](img/3.png)
