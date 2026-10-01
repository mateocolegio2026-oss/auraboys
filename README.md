# 🐾 AuraBoys

## 👥 Integrantes

- Mateo Lopez
- Vittorio Rosso
- Juan Illuminati

---

## 📌 Descripción del proyecto

AuraBoys es un proyecto integrador de automatización desarrollado con Arduino. Consiste en un **dispensador automático de alimento para animales**, diseñado para entregar comida cuando detecta la presencia de un animal y controlar la frecuencia de dispensación para evitar el sobrealimentado y el desperdicio.

El sistema utiliza un sensor ultrasónico para detectar la presencia del animal y un servomotor para controlar la compuerta del dispensador.

---

## 🎯 Objetivo

Desarrollar un sistema automático capaz de dispensar alimento cuando un animal se encuentre a una distancia menor a 20 cm, controlando además el tiempo entre cada dispensación.

De esta manera, se busca que los animales puedan recibir alimento sin necesidad de que una persona esté presente constantemente y evitando el desperdicio de comida.

---

# ⚙️ Requerimientos del sistema

## Requerimientos Funcionales (RF)

### RF1 - Detección del animal

El sistema debe detectar la presencia de un animal a una distancia menor a **20 cm** mediante un **sensor ultrasónico**.

### RF2 - Dispensación automática

Al detectar al animal, el sistema debe activar un **servomotor** para abrir la compuerta de alimento durante **3 segundos** y luego cerrarla automáticamente.

### RF3 - Tiempo de espera

Después de cada dispensación, el sistema debe establecer un período de espera (**cooldown**) de **30 minutos** para evitar el sobrealimentado o el vaciado rápido del contenedor.

### RF4 - Indicadores LED

El sistema debe utilizar dos LEDs para indicar su estado:

- 🟢 **LED verde:** indica que el sistema está listo para dispensar.
- 🔴 **LED rojo:** indica que el sistema se encuentra en período de espera.

---

## Requerimientos No Funcionales (RNF)

### RNF1 - Usabilidad

El mecanismo de apertura debe funcionar de manera silenciosa para evitar asustar a los animales.

### RNF2 - Fiabilidad

La simulación realizada en **Wokwi** debe responder a la detección del sensor en un tiempo menor a **1 segundo**.

### RNF3 - Costo

El presupuesto total de los componentes físicos debe mantenerse dentro de un límite accesible para el equipo.

---

# 📖 Historia de Usuario

> **Como** cuidador o protector de animales,  
> **quiero** un dispensador automático que sirva alimento solo cuando un animal se acerque y controle la frecuencia de entrega,  
> **para** asegurar que los animales tengan comida disponible sin que se contamine ni se derroche mientras no hay personas presentes.

---

# 🔧 Componentes

Los principales componentes utilizados en el proyecto son:

- Arduino UNO
- Sensor ultrasónico
- Servomotor
- LED verde
- LED rojo
- Resistencias
- Protoboard
- Cables de conexión

---

# 🖥️ Simulación con Wokwi

El proyecto puede ser simulado mediante **Wokwi**, permitiendo comprobar el funcionamiento del circuito y del programa antes de realizar el montaje físico.

Durante la simulación se puede verificar:

1. La detección del animal mediante el sensor ultrasónico.
2. La activación del servomotor.
3. La apertura de la compuerta durante 3 segundos.
4. El cierre automático de la compuerta.
5. El funcionamiento del período de espera de 30 minutos.
6. El cambio entre el LED verde y el LED rojo según el estado del sistema.

---

# 🔄 Funcionamiento general

El sistema funciona de la siguiente manera:

```text
        ┌─────────────────────┐
        │     Arduino UNO     │
        └──────────┬──────────┘
                   │
                   ▼
        ┌─────────────────────┐
        │ Sensor ultrasónico  │
        └──────────┬──────────┘
                   │
             ¿Animal < 20 cm?
                   │
             ┌─────┴─────┐
             │           │
            NO          SÍ
             │           │
             │           ▼
             │    ┌─────────────┐
             │    │ Servomotor  │
             │    └──────┬──────┘
             │           │
             │           ▼
             │    Abre 3 segundos
             │           │
             │           ▼
             │      Cierra puerta
             │           │
             │           ▼
             │    Cooldown 30 min
             │           │
             │           ▼
             │       LED rojo
             │
             ▼
        Sistema esperando