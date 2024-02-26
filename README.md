# Controle de Sensores e Atuadores em Arduino com C++ para Cozinha Inteligente

![Cozinha](https://github.com/EduardoDosSantosFerreira/cozinha-cpp/blob/main/cozinha.png)

O código fornecido implementa o controle de diversos sensores (ultrassônico, PIR, temperatura e gás) e atuadores (servo motor e LEDs) em um ambiente destinado a uma cozinha inteligente, controlado por um Arduino.

## Componentes Utilizados

- Arduino board
- Sensor ultrassônico
- Sensor de movimento PIR
- Sensor de temperatura
- Sensor de gás
- Servo motor
- LEDs

## Funcionalidades do Código

1. **Configuração Inicial**

   - Os pinos dos sensores e atuadores são configurados no método `setup`.
   - A comunicação serial é inicializada para depuração.

2. **Leitura do Sensor Ultrassônico**

   - A função `readUltrasonicDistance` é utilizada para medir a distância por meio do sensor ultrassônico.

3. **Controle do Servo Motor**

   - O servo motor é controlado com base na leitura do sensor ultrassônico. Quando a distância medida é inferior a 15, o servo motor é acionado para uma determinada posição, por exemplo, para abrir uma porta de armário.

4. **Leitura do Sensor de Movimento PIR**

   - O sensor PIR é lido e, se detectar movimento, aciona determinados pinos de saída, por exemplo, para acender as luzes da cozinha.

5. **Leitura do Sensor de Temperatura e Gás**

   - Os valores dos sensores de temperatura e gás são lidos e comparados a certos limites. Com base nas leituras, determinados LEDs são acionados para indicar condições como alta temperatura ou vazamento de gás.

## Considerações Finais

Esse código demonstra como controlar diversos sensores e atuadores em uma cozinha inteligente. A leitura e o processamento dos dados dos sensores resultam em ações específicas, como acionar um servo motor para abrir portas de armários, controlar a iluminação da cozinha com base no movimento e monitorar a temperatura e vazamento de gás, oferecendo um ambiente automatizado e seguro para uso na cozinha.
