# Fundamentals of MPLS 

----

# Section 1 - Understanding the Dapa Plane Implementation 

----

## MPLS Label Stack Implementation 

![img](img/1.png)

- A single data packet or frame can carry multiple MPLS labels 
- When that happens, it is said that encapsulated data carries a label stack 
- MPLS labels are inserted between OSI Layer 2 and encapsulated data (Payload)
- Labels are used to differentiate different types of services and/or customers from each other.

----

![img](img/2.png)

----

![img](img/3.png)

----

![img](img/4.png)

----

![img](img/5.png)

----

![img](img/6.png)

----

## MPLS Label Range Allocation on Nokia OS

- MPLS Label Field is 20 bits 
- Possible values from 0 - 1,048,575

![img](img/7.png)

----

## MPLS Header: EXP Field 

- Consists of 3 bits 
- A.K.A Traffic Class field 
- Used solely to convey Quality of Service (QoS) information.
- Only the EXP field inside the top label is significant in processing
- Two approaches
  - Pipe mode
  - Uniform mode
- Nokia SR OS only implements pipe mode 

## Implementation

![img](img/8.png)

----

## MPLS Header - Bottom of Stack (S) Bit

![img](img/9.png)

----

## MPLS Header - Time to Live (TTL) Field 

- 8 bit MPLS TTL field functions similarly to IP TTL
- Prevents forwarding loops
- When TTL = 0, packet is not transmitted to next hop
- In *MOST* cases, only the TTL field inside the top label is significant in processing
- Two approaches:
  - Pipe mode
  - Uniform Mode
- Nokia only implementts Pipe mode

![img](img/10.png)
![img](img/11.png)

----

# Section 2 - Understanding the Control Plane implementation of MPLS

----

## Requirements for IP/MPLS Control Processes 

For tunnels to be estabilshed:
- Routers must know about each other's FECs (Essentially corresponds to an IP prefix)
- Label bindings for FECs mus tbe negotiated between routers.

![img](img/12.png)

----

## Requirements for MPLS Signaling Protocols

- FECs' IP prefixes are exchanged, and the other routers tunnel destinations are known due to IGP
- Signaling protocol is needed to negotiate MPLS labels and establish tunnels

There are two main signaling protocols:
1. Label Distribution Protocol (LDP)
2. Resource Reservation Protocol (RSVP)

----

## MPLS Transport Label Signaling Protocols

Label Distribution Protocol:
- IGP-based tunnels (only)
- Simple configuration
- No Traffic Engineering Support
- IGP dependednt convergence times
- Also called Link or Interface LDP
- Advertises labels for FECs automatically
- Keeps Labels in memory for all FECs received even if they are not used 

Resource Reservation protocol with Traffic Engineering (RSVP-TE):
- Fully customizable tunnel paths
- Ability to run more complex path calculations with additional adminsitrative constraints
- Superior traffic protection mechanisms
- Higher administrative overhead
- Only advertises labels for FECs that are requested by upstream routers
- Deletes Labels for FECs that are not used

----

![img](img/13.png)

## Upstream Label Distribution

- Routers advertise label bindings for their FECs, which are propogated to the upstream routers
- Each router selects the label value that it will advertise, associated with each FEC.

(Continue on Page 79 of MPLS)
