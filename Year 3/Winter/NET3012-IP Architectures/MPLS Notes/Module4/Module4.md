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

