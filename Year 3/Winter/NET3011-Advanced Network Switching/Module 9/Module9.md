# Secure Network Access Control

## 802.1X and EAP

### 802.1X --> What is true?
- standard based protocol for port-based network access control (PNAC)
- Provides authentication mechanisms for wired local area networks and wireless local area networks.

Components:
- <b>Extensible Authentication Protocol (EAP)</b> - Provides an encapsulated transport for authentication process
- <b>EAP authentication method (EAP TYPE)</b> - Compatible with different authentication methods
- <b>EAP over LAN (EAPoL)</b> - Layer 2 encapsulation for the transport of EAP messages over wired and wireless LAN
- <b>RADIUS server with EAP extensions</b> - ONLY Radius servers with EAP extensions can be used with 802.1X

Roles:
Network devices have the following roles

1. <b>Supplicant</b> - software on the endpoint that communicates and provides identity credentials through EAPoL with the authenticator