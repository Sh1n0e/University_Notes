# Secure Network Access Control

## 802.1X and EAP

### 802.1X --> What is true?
- standard based protocol for port-based network access control (PNAC)
- Provides authentication mechanisms for wired local area networks and wireless local area networks.

Components:
- **Extensible Authentication Protocol (EAP)** - Provides an encapsulated transport for authentication process
- **EAP authentication method (EAP TYPE)** - Compatible with different authentication methods
- **EAP over LAN (EAPoL)** - Layer 2 encapsulation for the transport of EAP messages over wired and wireless LAN
- **RADIUS server with EAP extensions** - ONLY Radius servers with EAP extensions can be used with 802.1X

Roles:
Network devices have the following roles

1. **Supplicant** - software on the endpoint that communicates and provides identity credentials through EAPoL with the authenticator
2. **Authenticator** - Network access deviceses controls access to teh network based on the authentication status of the user or endpoint.
3. **Autnetication Server** - RADIUS server with EAP extensions, it performs the authentication of the client

>Cisco Identity Services Engine (ISE) is a consolidated POLICY-BASED access control system
> 
>Performs the following functions:
>
>1. combines authentication, authroization, accounting (AAA) into one place.
>2. Provides for comprehensive guests access management
>3. Provides suppor for POLICY-BASED placement, and monitoring of endpoint devices in the network
>4. Defines and applies the enforcement policies including security group access (SGA) through the use of security group tag (SGT) and security group access control list (SGACL)

### 802.1X Authentication
1. when a port is up, EAP over Lan (EAPoL) messages are sent to being authentication
   - sends periodic EAP-request/identify frames
2. EAP messages are relayed between supplicant and RADIUS authentication server
3. if successful, authentication returns RADIUS access-accept message

Until fully authenticated 802.1X only allows EAPOL, Cisco Discovery Protocol (CDP), and Spanning-tree Protocol (STP). Aftgerwards, data traffic can pass through the port

802.1X relies on RADIUS with EAP extensions, meaning AAA parameters on Radius server must be configured correctly.

```
SW(config)# aaa new-model
SW(config)# aaa group server radius {grp-name}
SW(onfig-sg-radius)# server 10.1.1.1 auth-p 1812 acct-p 1813
```

Three steps to complete the setup:
1. enable 802.1X globally
2. configure an autehntication list
3. Apply to an access layer 2 port

### EAP Authentication Methods Comparison

![img](img/1.png)

### MAC Authentication Bypass (MAB)

MAB is an authentication and access control technique that enabled port-based access control using the MAC address of an endpoint if users and devices don't have an 802.1X suppplicant.

1. Switch initiates authentication by sending EAPoL identity request every 30 seconds (default)
2. Switch begins MAB by opening the port to accept a single packet to learn the MAC address of endpoint.
3. RADIUS server determines whether access is granted.

MAB authenticated endpoints should be given very restricted access and should only be allowed to communicate to networks and services the endpoints are required to speak to.

If authenticator is a Cisco switch, then many authroization options can be applied as part of the authorization result from the autehntication server, including the following:

1. Downloadable ACLs (dACLs)
2. Dynamic VLAN assignment (dVLAN)
3. Security Group Tags (SGT) tags

### Web Authentication 

Can be used by users that try to connect to the network without 802.1X supplicants AND might not know the MAC address to perform MAB.

**if both MAB and WebAuth are configured as fallbacks, when 802.1X times out, MAB is attempted first, then WebAuth**

<u>Unlike MAB. WebAuth is only for users and not devices since a web browser with manual username and password entry is required</u>

There are two types of WebAuth:
1. Local Web Authentication (LWA)
2. Centralized Web Authentication with Cisco Identity Services Engine (ISE)

#### Local Web Authentication (LWA)

- First form of web authentication
- Switch redirects web traffic to a locally hosted web portal running in the switch where an end user can enter a username and password.
- When switch sends login credentials on behalf of the user, it is considered to be LWA
- LWA web portals are not customizable
- Does not support Dynamic VLAN assignment, only ACL assignments
- LWA doesn't support the change of authroization (CoA) feature to apply new policies. Therefore, access policies cannot be changed based on posture or profiling state, and even administrative changes cannot be made as a result of malware to quarantine the endpoint.

#### Central Web Authentication (CWA) with Cisco ISE

Supports the following:
- CoA for profiling, as well as dACL and VLAN authroization options
- All the advances services: client provisioning, posture assessments, acceptable use policies, password changing, self-registration, and device registration

### Flexible Authentication (FlexAuth)

By default, cisco is configured with 802.1X, MAB, and WebAuth.

If an endpoint that does not support 802.1X tries to connect to the network, it needs to wait for a considerable amount of time before WebAuth is offered as an authentication option.

----

# Cisco TrustSec

