#include "etherShield.h"
#include "ETHER_28J60.h"

static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};   //Endereço MAC - Camada de Enlace                                                        
static uint8_t ip[4] = {192, 168, 0, 0}; //Endereço IP - Camada de Rede - ajuste com um endereco na faixa da sua rede - separado com virgulas mesmo
static uint16_t port = 80; //Porta padrão protocolo HTTP

ETHER_28J60 ethernet;

int analog;
float milivolts;
float temperatura;

void setup()
{
  ethernet.setup(mac, ip, port); //inicializa a biblioteca com os valores setados anteriormente
}

void loop()
{
  if (ethernet.serviceRequest())
  {
    ethernet.print("<html><head><title>TempMeter ENC28J60</title></head><body>"); //isso aqui vai la na aba do teu navegador
    ethernet.print("<H1>Termometro web com ENC28J60</H1><br/>"); //titulo huehue
    ethernet.print("Temperatura em Celsius: "); //.
    analog = analogRead(0); //le temperatura no pino analogico 0 do UNO - sugiro usar um LM35 que eh baratinho e tem boa precisao
    milivolts = (analog * 0.00488);  // 5V / 1023 = 0.00488 (precisão do A/D)
    temperatura = milivolts * 100; //Converte milivolts para graus celsius. Cada 10mV = 1C
    ethernet.print(temperatura); //printa o valor da temperatura
    ethernet.print("<br><br><b><H1>FelipeOld</H1></b></body></html>"); //teu nome aqui pq vc merece
    ethernet.respond();
  }
  delay(100);
}
