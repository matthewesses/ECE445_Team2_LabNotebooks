# Engineering notebook

## 1/14-1/15 Project Ideation and Concept Development

### Initial Discussion with Mitchell
Before the class officially began, Mitchell and I discussed the primary aim of our project. We considered various factors such as the project's usefulness, the problem space it addresses, and the need for it to be enjoyable to work on.

### Exploration of Project Ideas
- **Remote Sensing Systems:** We both shared an interest in working with remote sensing systems like RaDAR and LiDAR.
- **Nintendo Switch JoyCon IR Camera Sensors:** Initially, I considered reverse engineering the Nintendo Switch JoyCon IR Camera Sensors for a wearable LiDAR system. However, due to challenges such as poor documentation, legal and ethical concerns, and the non-traditional problem space, this idea was abandoned.
- **ECE 445 Documentation Review:** Upon reviewing the documentation on the ECE 445 page, I realized the importance of the project being useful to someone, which led to a shift in focus.

### Final Project Concept: Wearable LiDAR for the Blind
- **LiDAR Principle:** LiDAR technology requires radial movement to generate a point cloud.
- **Initial Design Concept:**
  - Utilized a ring gear driven by two stepper motors.
  - Integrated LiDAR sensors into the ring gear, communicating wirelessly with a main computing unit.
- **Challenges and Abandonment:**
  - Power consumption concerns.
  - Feasibility issues.
  - Potential user discomfort.
  - Lack of practical usefulness.

## Conceptual Diagram
![Wearable LiDAR Concept](https://cdn.discordapp.com/attachments/901495322310766633/1233264870749900892/image.png?ex=662c76ea&is=662b256a&hm=93154861a65bb14b6f8007802ecd6a6096c15eecfef7ae5cb52b7c3057570c84&)

## Engineering Notebook Entry - 1/16

### Inspiration from Natural Design
- **Radial Movement Concept:** Inspired by the arrangement of eyes on creatures' heads rather than their necks, I drew inspiration from propeller hats to achieve radial movement for the LiDAR system alongside a slip-ring.

### Sensor Range Consideration
- **NIR Range Selection:** Opted to develop a LiDAR sensor within the Near-Infrared (NIR) range instead of using an off-the-shelf solution. The choice was influenced by NIR's reduced vulnerability to solar noise due to the absorption properties of molecular oxygen and water vapor.

### Atmospheric Absorption Analysis
- **Reference [1]:** Explained the absorption of light by molecular oxygen and water vapor in the red, near-infrared, and mid-infrared regions.

![Figure 3: Light Absorption Via the Atmosphere](https://cdn.discordapp.com/attachments/901495322310766633/1233266273429884998/image.png?ex=662c7838&is=662b26b8&hm=bedc095843634cfde592979ec9894b942f79face59f694d0e6614c5d61b28a31&)

## Collaboration and Guidance
- **Office Hours with Jason (Head Lab TA):** Discussed the project requirements for building a LiDAR sensor using a time-of-flight ASIC.
- **Recommendations:**
  - Use of the STM32F401 microcontroller.
  - Integration of a Hall Effect sensor to determine motor orientation and track RPM of the sensor motor.
- **Concept Sketch:** Provided a rough sketch of the sensor concept.

![Concept Sketch](https://media.discordapp.net/attachments/901495322310766633/1233266387229872158/image.png?ex=662c7853&is=662b26d3&hm=c7fdbf1d82f06b36760c2e37b3eccbe251d574f67cad9de4b07a97b12dcc0adc&=&format=webp&quality=lossless)





