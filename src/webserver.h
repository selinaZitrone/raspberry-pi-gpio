#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <stdint.h>

/**
 * Konstanten für den Webserver
 */
#define HTTP_PORT 80               // Standard HTTP-Port
#define MAX_REQUEST_SIZE 1024      // Maximale Größe einer HTTP-Anfrage
#define MAX_RESPONSE_SIZE 2048     // Maximale Größe einer HTTP-Antwort

/**
 * HTTP-Anfrage-Struktur
 * Speichert die wichtigsten Informationen einer HTTP-Anfrage
 */
typedef struct {
    char method[8];                // HTTP-Methode (GET, POST, etc.)
    char path[64];                 // Angefragter Pfad
    char version[16];              // HTTP-Version
} http_request_t;

/**
 * HTTP-Antwort-Struktur
 * Enthält die Elemente einer HTTP-Antwort
 */
typedef struct {
    int status_code;               // HTTP-Statuscode (z.B. 200, 404)
    char content_type[32];         // Content-Type (z.B. "text/html")
    char body[MAX_RESPONSE_SIZE];  // Antwortinhalt
    uint16_t body_length;          // Länge des Antwortkörpers
} http_response_t;

/**
 * Initialisiert den Webserver
 * Setzt alle notwendigen Variablen und Zustände zurück
 */
void webserver_init(void);

/**
 * Verarbeitet eingehende Daten als HTTP-Anfrage
 * @param data Pointer auf die empfangenen Daten
 * @param length Länge der empfangenen Daten
 * @return 1 wenn die Anfrage vollständig verarbeitet wurde, sonst 0
 */
int webserver_process_request(uint8_t *data, uint16_t length);

/**
 * Parst eine HTTP-Anfrage und extrahiert die wichtigsten Informationen
 * @param raw_request Rohe HTTP-Anfragedaten
 * @param length Länge der Anfragedaten
 * @param request Pointer auf Struktur, um die geparste Anfrage zu speichern
 * @return 1 bei erfolgreicher Verarbeitung, 0 bei Fehler
 */
int webserver_parse_request(char *raw_request, uint16_t length, http_request_t *request);

/**
 * Generiert eine HTTP-Antwort basierend auf der Anfrage
 * @param request Die zu bearbeitende Anfrage
 * @param response Pointer auf die Antwortstruktur, die gefüllt werden soll
 */
void webserver_generate_response(http_request_t *request, http_response_t *response);

/**
 * Erstellt eine HTML-Seite mit dem aktuellen LED-Status
 * @param html_buffer Buffer für den HTML-Code
 * @param buffer_size Größe des Buffers
 * @return Länge des generierten HTML-Codes
 */
uint16_t webserver_generate_html(char *html_buffer, uint16_t buffer_size);

/**
 * Wandelt eine HTTP-Antwortstruktur in einen rohen HTTP-Response-String um
 * @param response Die Antwortstruktur
 * @param buffer Buffer für den HTTP-Response-String
 * @param buffer_size Größe des Buffers
 * @return Länge des generierten Response-Strings
 */
uint16_t webserver_format_response(http_response_t *response, char *buffer, uint16_t buffer_size);

/**
 * Sendet eine HTTP-Antwort über die Netzwerkschnittstelle
 * @param response_data Die zu sendenden Daten
 * @param length Länge der Daten
 * @return 1 bei erfolgreichem Senden, 0 bei Fehler
 */
int webserver_send_response(char *response_data, uint16_t length);

#endif /* WEBSERVER_H */