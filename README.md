# ENC28J60
Correção das bibliotecas ETHER_28J60.h e etherShield.h

Os arquivos a seguir permitem a compilação sem erros, ao utilizar um módulo enc28j60 da microchip juntamente com um arduino UNO (atmega328p).
Realizei testes com código simples, como webserver, getStaticIP e getDHCPandDNS, sendo estes dois últimos adaptados da biblioteca "ethercard". Talvez, pra códigos que utilizem mais das bibliotecas, seja necessário realizar mais alterações e/ou correções nos arquivos das bibliotecas, por hora, estas alterações me serviram bem.

Baixando as bibliotecas de seus repositórios oficiais e modificando as chamadas da constante "const prog_char *progmem_s" por "const char *progmem_s" em determinados arquivos, também é possível chegar ao mesmo resultado.

Os arquivos que modifiquei foram:
ip_arp_udp_tcp.h - linha 32, etherShield.h - linha 34, ip_arp_udp_tcp.c - linha 444 e etherShield.cpp - linha 14.

Não enviei a sugestão de alteração aos desenvolvedores da biblioteca pois a mesma não é mais mantida. Foi substituída pela biblioteca etherCard. Ainda assim, acredito que esta alteração seja válida pois estas bibliotecas são bastante simples de serem utilizadas e exigem poucos recursos do microcontrolador, deixando assim mais espaço para a execução do código implementado.

Não trata-se exatamente de uma descoberta, mas procurei por alguns dias a fio por uma solução e não encontrei nada explícito sobre tais erros, que até onde vi, são causados por uma das atualizações da IDE do Arduino.
