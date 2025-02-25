Here's a well-structured Markdown version including relevant configurations:

```md
# **IPv4 Multicast - Module 6 (NET-3011)**  

## **1. Multicast Fundamentals**  
- Multicast **optimizes bandwidth** by sending a single stream to multiple receivers.  
- It operates using:  
  - **IGMP (Internet Group Management Protocol)** at Layer 2  
  - **PIM (Protocol Independent Multicast)** at Layer 3  
- **Use Cases:** IPTV, video conferencing, online gaming.  

---

## **2. Multicast Addressing**  
- Uses **IPv4 Class D addresses (224.0.0.0/4)**, assigned by IANA.  
- **Well-known Multicast Addresses:**  
  - `224.0.0/24` → Local network control  
  - `224.0.1.0/24` → Internetwork control  
- **Multicast MAC Addressing:**  
  - Mapped using a fixed prefix **`01:00:5E`**, with the last 23 bits derived from the IP address.  
  - Possible **address overlap** due to limited mapping bits.  

---

## **3. IGMP (Internet Group Management Protocol)**  
### **IGMPv2 Configuration**  
- **Enabling IGMP on an interface:**
  ```sh
  interface GigabitEthernet0/1
   ip igmp version 2
  ```
- **Joining a multicast group manually:**
  ```sh
  ip igmp join-group 239.1.1.1
  ```
- **Verifying IGMP group membership:**
  ```sh
  show ip igmp groups
  ```

### **IGMP Snooping (for switch configuration)**
```sh
ip igmp snooping
ip igmp snooping vlan 10
```

---

## **4. Protocol Independent Multicast (PIM)**  
- **Routes multicast traffic** using **unicast routing** for path discovery.  
- **Reverse Path Forwarding (RPF)** ensures packets arrive on the correct interface.  
- **PIM Modes:**  
  - **PIM Dense Mode (PIM-DM)** → **Flood & Prune** method (not recommended for large networks).  
  - **PIM Sparse Mode (PIM-SM)** → **Pull model**, requires an **RP (Rendezvous Point)**.  
  - **PIM Sparse-Dense Mode** → Hybrid of both modes.  

### **PIM Configuration (PIM Sparse Mode)**
```sh
interface GigabitEthernet0/1
 ip pim sparse-mode
```
- **Verifying PIM neighbors:**
  ```sh
  show ip pim neighbor
  ```
- **Checking multicast routes:**
  ```sh
  show ip mroute
  ```

---

## **5. Rendezvous Points (RP)**  
### **Static RP Configuration**  
```sh
ip pim rp-address 10.1.1.1
```
- **Checking RP mapping:**
  ```sh
  show ip pim rp mapping
  ```

### **Auto-RP Configuration (Cisco Proprietary)**  
- **Candidate RP (C-RP) Configuration:**  
  ```sh
  interface Loopback0
   ip pim sparse-mode
  ip pim send-rp-announce Loopback0 scope 10
  ```
- **Mapping Agent (MA) Configuration:**  
  ```sh
  ip pim send-rp-discovery Loopback0 scope 10
  ```
- **Auto-RP Listener for Sparse Mode:**  
  ```sh
  ip pim autorp listener
  ```

### **Bootstrap Router (BSR) Configuration (RFC 5059, Standard-Based)**
- **Candidate BSR (C-BSR) Configuration:**  
  ```sh
  interface Loopback0
   ip pim bsr-candidate Loopback0
  ```
- **Candidate RP (C-RP) Registration to BSR:**  
  ```sh
  ip pim rp-candidate Loopback0
  ```
- **Checking BSR RP Set:**  
  ```sh
  show ip pim bsr
  ```

---

## **6. PIM Optimization Techniques**  
### **PIM Designated Router (DR) Election**  
- By default, the router with the highest IP wins the election.
- To manually set DR priority:  
  ```sh
  interface GigabitEthernet0/1
   ip pim dr-priority 10
  ```
- **Verifying DR status:**  
  ```sh
  show ip pim interface
  ```

### **PIM Assert Mechanism (Prevents duplicate multicast streams)**  
- **PIM uses an Assert message** to elect a single **PIM forwarder** per LAN segment.
- Election process:  
  1. Lowest **Administrative Distance (AD)** to source wins.  
  2. If AD is the same, the lowest **unicast metric** wins.  
  3. If both are equal, the highest IP wins.  

- **Checking PIM Assert information:**  
  ```sh
  show ip pim assert
  ```

---
