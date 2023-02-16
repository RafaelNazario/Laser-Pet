# Projeto Laser Pet


>Projeto Desenvolvido durante a formação Microcontroladores e Eletrônica Aplicada da empresa Alura.

Funcionamento:

O Laser preso ao suporte pan tilt é ligado e os servos iniciam o movimento aleatório por 60 segundos 
ao receberem o sinal de presença do sensor PIR. O status do laser pet é publicado em um broker mqtt, podendo ser feito assinatura
para verificar se o mesmo está ativo ou não. 



Foram utilizados neste projeto:

```
1x NodeMCU-ESP8266
1x Sensor de Presença e Movimento PIR
1x Módulo Laser
1x Suporte Pan Tilt para Micro Servo
2x Micro Servo 9G
```


![lasercatcircuit](https://user-images.githubusercontent.com/101157817/219261947-e2947fa0-8099-4af1-b2c9-d88fcf30d6a6.png)
