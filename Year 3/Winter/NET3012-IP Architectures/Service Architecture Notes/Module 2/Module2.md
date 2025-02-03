# Virtual Private Wire Services

----
# Section 1 - ePipe
----

## ePipe SAP Encapsulation

SAP encapsulation provides the router with a way of delineating services 

Ethernet encapsulation:
- Null - supports a single service on a port
- Dot1Q (802.1q) - supports multiple services for a single customer or multiple services for multiple customers
- Q-in-Q - provides a way to differentiate between customer services based on Q-tags

VLAN tag is used to determine which service the frame belongs to.

Multple SAPs can be defined on a single port for different services.

![img](img/1.png)

Null:
- Service is delimited by the port (SAP 1/1/1)
- The physical port belongs to a single service and a single customer
- VLAN tags are treated as customer data and are transparent on the network.

Dot1Q:
- Service is delimited by the VLAN tag (SAP 1/1/1:10)
- Allows more than one SAP to be configured on each physical port.

Q-in-Q:
- Service is delimited by 2 VLAN tags as port:outer.inter (SAP 1/1/1:10.100)
- Can specify a top and bottom VLAN ID to be matched.

----

## Ethernet Frame Encapsulation in an ePipe Service

Service delimiting VLAN tags are stripped at the SAP ingress along with the Frame Check Sequence (FCS) for the frame.

![img](img/2.png)
----

## Special SAP Values - dot1q

Default SAP (port:*)
- Receives all untagged frames and any frames with tag values that are not used as a service-delimiting value on another SAP
- VLAN tags are not stripped and are passed transparently
- e.g sap 1/1/3:*

Default SAP example: (Page 109 on pdf)



Null SAP (port:0)
- Receives all untagged frames and all frames with a VLAN tag of 0
- e.g sap 1/1/3:0

Null and defaulat SAP are mutually exlusive on a port.
