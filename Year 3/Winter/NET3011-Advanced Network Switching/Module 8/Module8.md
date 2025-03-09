# Network Assurance (NetFlow, Flexible NetFlow, IP SLA) - Study Notes

## **NetFlow Overview**
- NetFlow is a network monitoring protocol used to analyze traffic flows.
- Captures measurements on ingress (incoming) and egress (outgoing) traffic.
- Used for security, troubleshooting, and network performance analysis.

### **NetFlow Components**
1. **Flow Exporter** - Collects and exports flow data.
2. **Flow Collector** - Receives and stores exported flow data.
3. **Flow Analyzer** - Processes and visualizes collected data.

### **NetFlow Key vs. Non-Key Fields**
- **Key Fields** (define a flow): 
  - Source & Destination IPs
  - Source & Destination Ports
  - Layer 3 Protocol Type
  - Class of Service
  - Router/Switch Interface
- **Non-Key Fields** (additional data):
  - Packet & byte counts
  - Timestamps
  - Flow duration

### **NetFlow Configuration & Verification**
- Configuration involves enabling NetFlow on an interface and specifying a flow collector.
- Verification commands:
  - `show ip flow interface` (enabled interfaces)
  - `show ip flow` (export destination)
  - `show ip cache flow` (flow details)

---

## **Flexible NetFlow (FNF)**
- An enhanced version of NetFlow with improved flexibility & scalability.
- Customizable flow records allow for advanced traffic analysis.

### **Benefits of FNF**
- More detailed traffic identification.
- Supports Layer 2, IPv4, IPv6 flow tracking.
- Helps detect DoS attacks & network threats.

### **FNF Configuration Steps**
1. **Define a Flow Record** (customizable fields to capture).
2. **Create a Flow Exporter** (destination for collected data).
3. **Create a Flow Monitor** (associates a flow record with an exporter).
4. **Apply Flow Monitor to an Interface** (ingress, egress, or both).

### **Verification Commands**
- `show flow monitor <name>`
- `show flow exporter <name>`

---

## **IP SLA (Service Level Agreement)**
- IP SLA is a Cisco feature used to measure network performance.
- Provides proactive monitoring with synthetic traffic tests.

### **IP SLA Measurements**
- **Latency (one-way & round-trip delay)**
- **Jitter (packet delay variance)**
- **Packet Loss**
- **Network Availability**
- **Application Performance (VoIP, HTTP, DNS, etc.)**

### **IP SLA Components**
- **IP SLA Source**: Cisco router sending probes.
- **IP SLA Responder**: Cisco device configured to reply to probes.
- **Operations**: Defines what to measure (ICMP, UDP, HTTP, etc.).

### **Common IP SLA Operations**
- **ICMP Echo** (ping-based network reachability test).
- **UDP Jitter** (VoIP & real-time application suitability).
- **HTTP GET** (measures round-trip-time for web requests).

### **IP SLA Configuration**
1. Define the SLA operation (`ip sla <id>`)
2. Specify the type of test (`icmp-echo`, `udp-jitter`, etc.)
3. Set frequency & schedule (`ip sla schedule`)

### **Verification Commands**
- `show ip sla statistics`
- `show ip sla configuration`
- `show ip sla summary`

---

## **Key Notes**
- NetFlow provides traffic monitoring, while Flexible NetFlow enhances it with custom tracking.
- IP SLA helps measure and ensure network performance.
- Flow monitors must be applied to interfaces for NetFlow/FNF to work.
- IP SLA can be used for proactive troubleshooting and service assurance.

---
