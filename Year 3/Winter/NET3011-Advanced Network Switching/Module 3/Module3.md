# Multiple Spanning Tree Protocol

Known in short as MST or IEEE 802.1s which is a standards based protocol that maps one or multiple VLANs to a single STP instance.

MST instances run RSTP (IEEE 802.1w) convergence mechanisms by default.

---- 

## PVST Topologies

- Per-VLAN Spanning Tree (PVST) provides a separate spanning tree instance for each VLAN configured on the network
- Topologies below show how switches maintain a different STP topology for each of the four VLANs.
	- It is important to note that in environments with thousands of VLANs, maintaining STP state for all of them can burden the switch's processor.
	
![img1](img/M3-1.png)

> PVST is Cisco Proprietary and only operates on Inter-switch links (ISL) Trunks, whereas PVST+ can operate on either ISL or 802.1q Traunks, and that is the difference on whether it is PVST or PVST+ that is being ran.

----

## MST topology

- MST (IEEE 802.1s) is a standard based protocol open protocol derived from RSTP (Rapid Spanning Tree Protocol a.k.a 802.1w) sharing its rapid convergence properties.
- MST is the only standardized spanning-tree protocol for VLAN-based networks that are supported by multiple vendors.
- MST maps one or multiple VLANs into one STP tree, called an MST Instance (MSTI).

The figure below show how switches maintain STP topologies for VLANs. If more VLANs were added to the environemnt, the switches would maintain two STP topologies if the VLANs alligned to one of the existing 2 MSTIs.

![img2](img/M3-2.png)

----

## MST Region

- A group of MST switches with the same high-level configuration is known as an MST region.
- All devices MUST have the matching characteristics otherwise it will not work:
	1. MST protocol enabled
	2. Same region name
	4. Same VLAN-to-MST instance mapping configurations
	5. Physically linked together
	
- MST incorporates mechanisms that make an MST region appear as a single virtual switch to external switches that may not be running the MST protocol.

![img3](img/M3-3.png)

- MST protocol can generate multiple spanning trees in an MST region
- Each spanning tree is mapped to the specific VLANs
- Each spanning tree is referred to as a Multiple Spanning Tree Instance (MSTI)
- In MST region 3 contains three MSTIs:
	- MSTI 1
	- MSTI 2
	- MSTI 0 
	
When it comes to MSTI's... 1+2=4

----

## MST Region Boundary

- The exact VLANs-to-instance mapping is not propagated in the BPDU, because the switches may only need to know whether they are in the same region as a neighbor.
- Only a digest (or hash) of the VLAN-to-MST instance mapping table is sent, along with teh MST revision number and MST the region name.
- Once a switch receives a BPDU, the switch extracts the digest (or hash) and compares this digest with its own computed digest. If they differ, the port on which the BPDU was received is at the boundary of a region or in the same MST region.

----

## MST Instances (MSTI)

- The MANUALLY created MSTIs are spanning tree instances that onlyxist inside a region. These instances run RTSP (802.1w) for rapid convergence
- MST uses a special instance, instance 0 (MST0), called the Internal spannign tree (IST)
- IST is ALWAYS the first instance and runs on all switch portinterfaces in the MST region regardless of the VLANs associated with the ports. IST is enabled by default and CANNOT be deleted.
- Additional infromation about other MSTIs is nested in teh IST BPDU that is transmitted throughout the MST region. This allows MST to advertise only one set of BPDU's, minimizing STP traffic.
- MST manually configured interfaces do not send BPDUs outside an MST region, only the IST does. This means that *IST can send BPDUs inside and outside the MST region*

![img4](img/M3-4.png)

- Instance 0 (MST0) is the internal spanning tree (IST)
- MST does not send BPDUs for every active STP MST instance separately.
- A special instance is designed to carry STP-related infromation.

![img5](img/M3-5.png)