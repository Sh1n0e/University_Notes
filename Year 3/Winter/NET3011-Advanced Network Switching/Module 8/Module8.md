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

```
R1(config)# ip flow-export version 9 
R1(config)# ip flow-export destination <address>
R1(config)# configure interface <int>
R1(config-if)# ip flow ingress
R1(config-if)# ip flow egress
R1(config-if)# end 
```
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
```
!! Configuring Custom flow record

R1(config)# flow record CCNP8-CUSTOM-OUT
R1(config-flow-record)# description Custom Flow Record for outbound traffic
R1(config-flow-record)# match ipv4 destination address 
R1(config-flow-record)#match transport destination-port 
R1(config-flow-record)# collect counter bytes
R1(config-flow-record)# collect counter packets

R1# show flow record CCNP8-CUSTOM-OUT

!! Configuring custom flow EXPORTER

R1(config)# flow exporter CCNP8-COLLECTOR-HOST
R1(config-flow-exporter)# destination 182.168.1.50
R1(config-flow-exporter)# export-protocol netflow-v9
R1(config-flow-exporter)# transport UDP 9999
R1(config-flow-exporter)# end

R1# show flow exporter CCNP8-COLLECTOR-HOST

!! Cofngiuring Flow monitor
R1(config)# flwo monitor CCNP8-OUTBOUND-MONITOR 
R1(config-flow-monitor)# record CCNP8-CUSTOM-OUT
R1(config-flow-monitor)# cache timeout active 30 
R1(config-flow-monitor)# exporter CCNP8-COllector-HOST
R1(config-flow-monitor)# end

R1(config)# interface <int>
R1(config-if)# ip flow monitor CCNP8-OUTBOUND-MONITOR output
R1(config-if)# end

R1# show flow monitor CCNP8-OUTBOUND-MONITOR cache
```

### Key notes about flow exporter:
1. define flow exporter name
2. set useful description
3. specify destination of the flow exporter to be used 
4. specify version to export 
5. specify UDP port (Port 9999 is default)

### key notes for flow monitor:
1. define a flow monitor name 
2. descrition
3. specify record to be used 
4. specify ache timeout of 30 seconds for active connections
5. assign exporter to the monitor.

- Multiple flow monitors of different traffic types can be applied for a given interface and diretions
- Multiple flow monitors of the same traffic type cannot be applied for a given interface and direction.

---

## **IP SLA (Service Level Agreement)**
- IP SLA is a Cisco feature used to measure network performance.
- Provides proactive monitoring with synthetic traffic tests.

### **IP SLA Measurements**
- Network resource availability 
- Response time
- One-way delay
- Round trip delay 
- Jitter 
- Packet loss 
- Voice-quality scoring
- Application performance

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
