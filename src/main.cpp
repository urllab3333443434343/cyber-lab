#include <Arduino.h>
#include <WiFi.h>

void mostrarMenu();
void procesarOpcion(char opcion);

void setup() {
    Serial.begin(9600);

    delay(2000);

    Serial.println();
    Serial.println("================================");
    Serial.println("          CYBER LAB");
    Serial.println("================================");
    Serial.println("Sistema de laboratorio iniciado.");
    Serial.println();

    mostrarMenu();
}

void loop() {

    if (Serial.available() > 0) {

        char opcion = Serial.read();

        // Ignorar Enter
        if (opcion != '\n' && opcion != '\r') {
            procesarOpcion(opcion);
        }
    }
}

void mostrarMenu() {

    Serial.println();
    Serial.println("========== MENU ==========");
    Serial.println("[1] Escanear dispositivos");
    Serial.println("[2] Ver estado de seguridad");
    Serial.println("[3] Simular intento de acceso");
    Serial.println("[4] Activar proteccion");
    Serial.println("[5] Mostrar informacion del laboratorio");
    Serial.println("[0] Salir");
    Serial.println("==========================");
    Serial.print("Seleccione una opcion: ");
}

void procesarOpcion(char opcion) {

    Serial.println();
    Serial.print("Opcion seleccionada: ");
    Serial.println(opcion);

    switch (opcion) {

        case '1':
            Serial.println("Iniciando escaneo simulado...");
            delay(1000);

            Serial.println("[OK] Dispositivo 01 detectado");
            Serial.println("[OK] Dispositivo 02 detectado");
            Serial.println("[OK] Dispositivo 03 detectado");

            Serial.println("Escaneo finalizado.");
            break;

        case '2':
            Serial.println("===== ESTADO DE SEGURIDAD =====");
            Serial.println("Firewall: ACTIVO");
            Serial.println("Proteccion de datos: ACTIVA");
            Serial.println("Autenticacion: ACTIVADA");
            Serial.println("Estado general: SEGURO");
            break;

        case '3':
            Serial.println("===== SIMULACION DE ACCESO =====");
            Serial.println("Intento de acceso detectado...");
            delay(1000);
            Serial.println("Analizando credenciales...");
            delay(1000);
            Serial.println("ACCESO DENEGADO");
            Serial.println("Motivo: credenciales no autorizadas.");
            break;

        case '4':
            Serial.println("===== PROTECCION =====");
            Serial.println("Activando medidas de seguridad...");
            delay(1000);
            Serial.println("Firewall: ACTIVADO");
            Serial.println("Bloqueo de acceso: ACTIVADO");
            Serial.println("Proteccion: ACTIVA");
            break;

        case '5':
            Serial.println("===== CYBER LAB =====");
            Serial.println("Laboratorio educativo de ciberseguridad");
            Serial.println("Objetivo: aprender conceptos de");
            Serial.println("seguridad informatica mediante simulaciones.");
            break;

        case '0':
            Serial.println("Laboratorio finalizado.");
            break;

        default:
            Serial.println("Opcion no valida.");
            break;
    }

    mostrarMenu();
}