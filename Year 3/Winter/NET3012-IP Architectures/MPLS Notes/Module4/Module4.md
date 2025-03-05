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

