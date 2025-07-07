#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>

// Netzwerk-Konfigurationskonstanten
#define MAC_ADDRESS           {0xB8, 0x27, 0xEB, 0x00, 0x00, 0x01}  // Beispiel-MAC für Raspberry Pi
#define IP_ADDRESS            {192, 168, 1, 100}                    // Beispiel-IP
#define IP_SUBNET_MASK        {255, 255, 255, 0}                    // Standard-Subnetzmaske
#define IP_GATEWAY            {192, 168, 1, 1}                      // Standard-Gateway

// Ethernet-Controller-Registerbasis
#define ETH_BASE              0x20000000  // Dies ist ein Beispielwert und muss angepasst werden

// Protokoll-Typen
#define ETHER_TYPE_IPV4       0x0800
#define ETHER_TYPE_ARP        0x0806

// Paket-Größen
#define ETH_HEADER_SIZE       14
#define IP_HEADER_SIZE        20
#define UDP_HEADER_SIZE       8
#define TCP_HEADER_SIZE       20
#define MAX_PACKET_SIZE       1500

// Funktions-Prototypen
void network_init(void);
void network_process(void);
int network_send_packet(uint8_t *data, uint16_t length);
int network_receive_packet(uint8_t *buffer, uint16_t *length);

#endif /* NETWORK_H */