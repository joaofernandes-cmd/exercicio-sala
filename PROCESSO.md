# PROCESSO.md — Lab 1 · Pisca-LED

**Aluno:** João Glauco Fernandes Araújo de Freitas · joao.fernandes@sou.inteli.edu.br
**Turma / grupo:** T26 · Grupo 2

## 1. Contextualizar
- **Objetivo:** Quando o dispositivo estiver ligado o LED de status irá indicar isso .
- **Comportamento esperado:** De 2 em 2 segundos o pulso de 200 ms é aceso.
- **Critério de aceitação:** O ciclo de status cronometrado fica dentre 1,9 s e 2,1 s, e a corrente recomendada pelo datasheet deve estar abaixo de 20mA.
- **Delegação à IA × feito sozinho:** Pretendo pedir auxilio em alterações para disparar um som junto do LED de status, comigo sendo responsável pelo processo de revisão e questionamento da resposta da IA.

## 2. Consultar
- **Ferramenta:** Claude
- **Pergunta (exata):** De que forma e com qual tipo de calculo o resistor realiza a conversão da corrente de 8 v, para 5 v para o funcionamento correto do LED, e como de fato esse loop de 2 s é determinado?
- **Resposta resumida:** Não tem 8 V: o 8 é o número do pino (D8). Em HIGH, o pino entrega 5 V.
O resistor não converte tensão, ele limita a corrente. Sem ele, a corrente no LED dispara e queima o LED e/ou o pino.
Cálculo (Lei de Ohm): o LED vermelho “fica” com ~2 V e o resistor com o resto (~3 V). Então I = (5 − 2) / 220 ≈ 13,6 mA, que é seguro (até ~20 mA). Para dimensionar: R = (5 − 2) / 0,02 = 150 Ω mínimo, e 220 Ω dá margem.
Ciclo de 2 s: é a soma dos delays, delay(200) aceso + delay(1800) apagado = 2000 ms, repetido infinitamente pelo loop(). O tempo vem do cristal de 16 MHz. O ciclo real dá um pouquinho mais por causa dos microssegundos do digitalWrite.
Atenção: delay() trava o Arduino. Para fazer outras coisas ao mesmo tempo, use millis().

## 3. Confrontar
- **Afirmação conferida:** o datasheet do LED: corrente recomendada de 20 mA, com máximo absoluto um pouco acima, em geral entre 25 e 30 mA;
- **Fonte primária:** Datasheet do LED
- **Trecho / cálculo:** LEDs vermelhos de 5 mm típicos têm corrente direta recomendada de 20 mA e máximo absoluto em geral entre 25 e 30 mA (conferir o datasheet do componente real). No circuito do Lab 1, o resistor de 220 Ω limita a corrente a ≈ 13,6 mA (com V_f ≈ 2,0 V), dentro desses limites.
- **Veredito:** Precisou de ajuste
- **ADR:** —

## 4. Construir
- **Wokwi:** https://wokwi.com/projects/477972015771641857
- **Repositório / commit:** —
- **Ciclo medido:** 2 s
- **Corrente calculada com 220 Ω:** 13.6 mA
- **Projeto funcionando:** sim

## 5. Comprovar (sem IA)
1. **Corrente com 330 Ω:** — mA — cálculo: —
2. **Resistor de 0 Ω:** — — —
3. **LED no pino 12:** —
4. **TEMPO_APAGADO para 500 ms a cada 3 s:** — ms

Declaro que respondi a etapa Comprovar sem IA: não
