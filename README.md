# Projeto Laser Pet


>Projeto Desenvolvido durante a formação Microcontroladores e Eletrônica Aplicada da empresa Alura.

Funcionamento:

O Laser preso ao suporte pan tilt é ligado e os servos iniciam o movimento aleatório por 60 segundos 
ao receberem o sinal de presença do sensor PIR. O status do laser pet é publicado em um broker mqtt, podendo ser feito assinatura
para verificar se o mesmo está ativo ou não. 

![45aee7dd-79ce-4cf3-905e-3889947d83af_AdobeExpress_AdobeExpress](https://user-images.githubusercontent.com/101157817/219875100-61ee484a-3dbf-43af-9613-fc4d2b774b48.gif)


Foram utilizados neste projeto:

```
1x NodeMCU-ESP8266
1x Sensor de Presença e Movimento PIR
1x Módulo Laser
1x Suporte Pan Tilt para Micro Servo
2x Micro Servo 9G
```


![lasercatcircuit](https://user-images.githubusercontent.com/101157817/219261947-e2947fa0-8099-4af1-b2c9-d88fcf30d6a6.png)
