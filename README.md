# 🐾 Los Auraboys

## Integrantes

* Mateo Lopez
* Vittorio Rosso
* Juan Illuminati

---

## 📌 Descripción del proyecto

**Los Auraboys** es un proyecto de automatización realizado con Arduino que consiste en un **dispensador automático de alimento para animales**.

El sistema detecta la presencia de un animal mediante un sensor ultrasónico. Cuando el animal se encuentra a una distancia menor a 20 cm, el sistema activa un servomotor que abre la compuerta del dispensador durante 3 segundos. Después de ese tiempo, la compuerta se cierra automáticamente.

Para evitar que el animal reciba alimento constantemente, el sistema cuenta con un período de espera de 30 minutos entre cada dispensación.

El proyecto también utiliza LEDs para indicar el estado del sistema:

* 🟢 LED verde: sistema listo para dispensar.
* 🔴 LED rojo: sistema en período de espera.

La simulación del proyecto se realiza mediante **Wokwi**.

---

# ⚙️ Requerimientos Funcionales

### RF1 - Detección del animal

El sistema debe detectar la presencia de un animal a una distancia menor a **20 cm** mediante un sensor ultrasónico.

### RF2 - Dispensación automática

Al detectar al animal, el sistema debe activar un servomotor para abrir la compuerta de alimento durante **3 segundos** y luego cerrarla automáticamente.

### RF3 - Tiempo de espera

El sistema debe incluir un tiempo de espera (**cooldown**) de **30 minutos** tras cada dispensación para evitar el sobrealimentado o el vaciado rápido del contenedor.

### RF4 - Indicadores LED

El sistema debe utilizar dos LEDs para indicar el estado:

* **LED verde:** indica que el sistema está listo para dispensar.
* **LED rojo:** se enciende mientras el sistema se encuentra en período de espera.

---

# 🛠️ Requerimientos No Funcionales

### RNF1 - Usabilidad

El mecanismo de apertura debe ser silencioso para no asustar a los animales.

### RNF2 - Fiabilidad

La simulación en Wokwi debe responder a la detección del sensor en un tiempo menor a **1 segundo**.

### RNF3 - Costo

El presupuesto total de los componentes físicos no debe superar un límite accesible para el equipo.

---

# 👤 Historia de Usuario

**Como** cuidador o protector de animales,

**Quiero** un dispensador automático que sirva alimento solo cuando un animal se acerque y controle la frecuencia de entrega,

**Para** asegurar que los animales tengan comida disponible sin que se contamine ni se derroche mientras no hay personas presentes.

---

# 🔌 Componentes

Los principales componentes utilizados en el proyecto son:

* Arduino Uno
* Sensor ultrasónico
* Servomotor
* LED verde
* LED rojo
* Resistencias
* Protoboard
* Cables de conexión

El circuito y su funcionamiento son simulados utilizando **Wokwi**.

---

# 🔄 Funcionamiento

El funcionamiento general del sistema es el siguiente:

1. El Arduino inicia el sistema.
2. El LED verde indica que está listo para dispensar.
3. El sensor ultrasónico mide constantemente la distancia.
4. Si detecta un animal a menos de **20 cm**, se activa el servomotor.
5. El servomotor abre la compuerta.
6. La compuerta permanece abierta durante **3 segundos**.
7. La compuerta vuelve a cerrarse.
8. El sistema inicia un período de espera de **30 minutos**.
9. Durante el período de espera se enciende el LED rojo.
10. Finalizado el tiempo de espera, el LED rojo se apaga y el LED verde vuelve a indicar que el sistema está listo.

---

# 🧠 Tecnologías utilizadas

* Arduino
* C/C++
* Wokwi
* Git
* GitHub
* Visual Studio Code

---

# 🎯 Objetivo

El objetivo del proyecto es desarrollar un sistema automático capaz de proporcionar alimento a los animales de manera controlada, reduciendo el desperdicio y evitando la necesidad de que una persona tenga que realizar manualmente cada dispensación.

---

# 👥 Equipo

### Los Auraboys

**Mateo Lopez**
**Vittorio Rosso**
**Juan Illuminati**

---

## 📚 Proyecto escolar

Proyecto de automatización con Arduino desarrollado como trabajo práctico escolar.