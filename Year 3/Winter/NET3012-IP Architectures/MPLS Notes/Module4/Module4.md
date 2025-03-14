# Resource Reservation Protocol (RSVP)

## Introduction
- Initially used to signal traffic characteristics and IP traffic flow requirements 
- It is NOT a routing protocol, but works with routing protocols
- Requests resources for unidirectional flows.
  - Bidirectional flows require two RSVP sessions (one per direction)

----

## Extensions RSVP Traffic Engineering (RSVP-TE)
- Was extended to be used as a label distribution protocol
- RSVP-TE brings benefits such as:
  - The ability to administratively define LSP paths
  - Ability to make advanced path calculations that are not restricted to IGP cost values
  - Use of a rich set of traffic protection features
    - secondary paths, Fast Reroute
  - Ability to make resources reservations - Connection ADminssion Control (CAC) functionality.

### Characteristics

- LDPs are only signaled when explicitly requested
- Label distribution process starts at the egress router and progresses towards the ingress router
- Labels are cleared if not needed
- Path and Resevations messages are used to signal LSPs
- Session states are maintained on all routers along the path of an LSP


### PATH Message Flow

- Router sends a PATH message in the downstream direction and requests labels to be allocated along the path, in order to have an LSP to a tail-end router.
  - Head-end router is the ingress router of the tunnel and the egress router is called the Tail-end

### Reservation Message Flow

- RESV messages are sent in the upstream direction and labels are allocated at each hop.
- When the head-end router receives the RESV message from ts downstream neighbor, the LSP is brought up.

### Prerequisites for Configuring RSVP-TE LSP

- Ensure proper functioning of hardware 
- Configure network interfaces
- Configure IGP
- Enable MPLS context
- Configure the interfaces for MPLS
- Enable the RSVP content

Interfaces need to be enabled for both MPLS and RSVP on the main and every other router these messages will go through.

### Enabling and verifying MPLS and RSVP 

```
A:Admin@R1# configure router mpls
A:Admin@R1# configure > Router > mpls > no shutdown

A:Admin@R1# configure router rsvp
A:Admin@R1# configure > Router > rsvp > no shutdown
```

Done because both contexts are disabled by default.

### LSP and LSP-Path

![img](img/1.png)

- An RSVP-TE based LSP can have multiple associated LSP-Paths
- One primary and seven secondary paths can be defined for redundancy 
- One LSP-Path is active at any given time (referred to as the primary path)

An LSP can also have Fast Reroute detour or bypass tunnels to recover traffic in the fastest way possible. (Covered further in Module 6)

### LSP Path configuration options

- At least one path definition is needed for an LSP
- Path definition may contain a list of nodes that the path must traverse
  - Explicitly defined as "loose" or "strict" (Module 5)
  - Empty list with no explicit hops
- A path definintion can be used multiple times in different LSPs, but cannot be used more than once per LSP, whether primary or secondary.

### RSVP Path Messages

PATH messages uses end-to-end addressing with a "Router Alert" option to instruct each other along the path to process the RSVP content in the control plane

**If the RSVP message does not list any hops, the IGP forwaring table is used to forward the PATH message at each router.**

### Forwarding the PATH Message from router R1 to router R2

![img](img/2.png)

1. R1 creates the PATH message and a Path State Block (PSB)
2. R1 stores the PATH message in the PSB and forwards the mesage to the next hop
3. HOP contains R1's egress interface IP address
4. LABEL REQUEST object indicates that R1 expects a label

### From R2 to R4

![img](img/3.png)
![img](img/4.png)

R2:
1. Receives the PATH message
2. Creates the PSB
3. Stores the PATH message in the PSB
4. Looks up destination in FIB
5. Regenerates and forwards the PATH message

### End-to-end Forwarding of the PATH message

![img](img/5.png)

- PATH messages are forwarded downstream to R6
- A Path State Block is created at each hop, storing the PATH message sent by the upstream router
- R6 is the tunnel destination
- R6 needs to send a RESV message back to R4

### Forwarding the RESV message from R6 to R4

![img](img/6.png)

- R6 allocates a label (524287) and sends back a RESV message
- Destination IP address is the upstream router's egress interface IP address (advertised previously in the HOP object of the PATH message and stored in the PSB)

### Creating the RSVP session on R6