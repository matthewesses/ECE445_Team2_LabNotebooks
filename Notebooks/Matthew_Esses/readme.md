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



## 1/17

### Sensor Selection and Additional Features
- **Design Feasibility:** After discussions with professors, it was determined that designing our own sensor was not feasible, leading us to opt for an off-the-shelf solution.
- **Incorporation of Doppler Radar:** To enhance functionality, a Doppler Radar was added to provide data below eye-level, particularly for emergency collision prevention purposes.

### Project Research and Documentation
- **Review of Previous Projects:** Studied projects from previous years to gain insights and inspiration.
- **Faculty Consultations:** Addressed questions from professors to ensure project alignment and feasibility.
- **Submission of RFA:** Submitted the Request for Approval (RFA) after completing a rough sketch of the physical design, which was shared with the team.

### Design Enhancement and Communication
- **Physical Design Sketch:** Shared a rough sketch of the physical design with the team, detailing key components and layout.
- **CAD Modeling:** Created a professional CAD model for the design, documented in the design document.

### Functional Enhancements
- **Motor Intensity Control:** Planned to implement motor intensity control using haptic feedback and Pulse Width Modulation (PWM) techniques for enhanced user interaction.

## 1/18

### Meeting with team for first time
- Met with team for the first time on 1/18, explained more of the ideas verbally, got feedback, planned roles and ways forward

## 1/24

### LiDAR Sensor Testing
- **Data Acquisition:** Focused on obtaining readings from the LiDAR sensor.
- **Datasheet Reference:** Utilized a datasheet for the LiDAR sensor available within the class resources.
- **Team Collaboration:** Tested the LiDAR sensor on an Arduino development board as a team, verifying its accuracy and performance against the datasheet specifications.

### Exploration of Hall Effect Sensors
- **Research and Learning:** Delved into understanding the functionality of Hall Effect sensors.
- **Initial Progress:** Began designing a Hall Effect sensor array to determine the orientation of the LiDAR sensor and synchronize it with the haptic feedback motors.

### Productivity Challenges
- **Personal Impact:** Experienced a period of decreased productivity for several weeks due to personal reasons.

### Ongoing Development
- **Hall Effect Sensor Array Design:** Continued work on designing the Hall Effect sensor array for angle detection of the LiDAR sensor and its integration with the haptic feedback motors.

### Next Steps
- **Resume Development:** Plan to resume full development activities and focus on completing the Hall Effect sensor array design and synchronization with motor control for the LiDAR system.


## February, Radio silence
No sufficient progress was made. Waited for partners to finish their portions of the project and then waited for updates

## STM32F401 Programming and PCB Routing - 3/6-3/13

### STM32F401 Programming
- **Learning Phase:** Acquired knowledge and skills in programming the STM32F401 microcontroller.
- **Circuit Enhancements:** Added an SWD header and Micro-USB connector to the circuit diagram for enhanced connectivity and programming capabilities.

### PCB Routing
- **Responsibility Assignment:** Took on the task of routing the PCB for the project.
- **Layer Consideration:** Ensured that reworking the microcontroller connections allowed for efficient routing on two layers.

### Team Collaboration and Quality Control
- **PCB Review:** Checked and verified the PCB design for any design violations, collaborating with team members Mitchell and Shreya.
- **Ordering Process:** Assisted in the order placement for the PCB board, handled by team member Shreya.

### Current Progress and Next Steps
- **Ongoing Work:** Waiting for completion of I2C integration with the STM32 dev board by Shreya to proceed with further physical design work.
- **Control Flow Mapping:** Mapped out the control flow for the control unit's programming, ensuring a clear understanding of the system's functionality.
- **Upcoming Tasks:** Deciding on off-board components for the half-wave rectifier and voltage divider for the Hall Effect sensors, focusing on low power consumption considerations.






