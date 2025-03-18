# Common Management Protocols

## Part One - SNMP

### SNMPv1 Operations 
Three versions:
- SNMPv1 - original 
- SNMPv2 - builds on v1
- SNMPv3 - builds on v1 and v2

However, SNMPv1 is still widely used 


### SNMPv1
Pros:
- Designed to be simple
- Simple to implement for agents on managed devices with constrained resources

Cons:
- Functionality offered by SNMP agents aren't always powerful or elegant
- Not necessaril simple for management applications to use

The main tradeoff is functionality for simplicity.

Motivations for design choice:
- More types of agent implementations than manager applications
- More resources available to management applicaitons
- Analogy: accepting coins on busses (when norm is presto/tap)

### SNPv1 - Basic Operations 
SNMP defines **five operations** to access a MIB and interact with it.

1. Get request
2. Get-next request
3. Set request
4. Get response
5. Trap

### SNMPv1 - Variable Binding