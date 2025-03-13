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

