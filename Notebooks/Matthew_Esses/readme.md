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

## 3/14-4/05 WAITING FOR THE PCB!!!

The PCB took a very long time to arrive. We decided on using either a stepper motor or the motor from ECE 110 at this time.

## 4/4 New scanning mechanism

### **Current Progress and Next Steps:** gave up on waiting and redesigned the drive train to be belt driven instead of purely gear driven to make the Hall-Effect module feasible. 3D printing first parts

# Engineering Notebook Entry - 4/7-4/10

## PCB Arrival and Troubleshooting

### PCB Delivery and Initial Issues
- **PCB Arrival:** Received the PCBs today.
- **Short Circuit Discovery:** Identified a short circuit between specific pins on the PCB.

### Troubleshooting and Resolution
- **Responsibility:** Tasked with locating and eliminating the short circuit to ensure proper board functionality.
- **Problem Areas:** Narrowed down potential locations of the short circuit to boot1 and boot0 pins, along with the 3V line connected to the buck converters.
- **Attempted non-destructive testing** Tried using a Nintendo switch joycon as an IR camera to read where the short was when I ran like 6W through the board, and it kinda went terribly and didnt show much due to the incident light was the only IR
- **Resolution Approach:** Drilled small holes into the PCB to pinpoint and eliminate the short circuit.
- **Success and Board Functionality:** After drilling, the board functioned as expected, allowing for continued progress and programming.

### Workload and Persistence
- **Time Investment:** Spent an entire night drilling into the boards to accurately identify and resolve the short circuit by myself.
- **Purpose of Drilling:** Ensured that the board could still be programmed and utilized for further iterations, even if similar issues were encountered in subsequent versions. I was also able to add destructive testing to my resume.

## Images of Drilled PCBs
- ![Drilled PCB 1](https://media.discordapp.net/attachments/962889307931164742/1227299514117914734/PXL_20240409_073322874.jpg?ex=662bdb3e&is=662a89be&hm=4556c0765e6730dd9536d161e3232559996ffff453093253ad5d42ad529e4812&=&format=webp&width=309&height=411)
- ![Drilled PCB 2](https://media.discordapp.net/attachments/962889307931164742/1227299514684280894/PXL_20240409_073321050.jpg?ex=662bdb3e&is=662a89be&hm=e3ad64fc59c6aeb5169fbe17af290db638b10798829fd66da2135fb5e6cb10d1&=&format=webp&width=309&height=411)
- ![Drilled PCB 3](https://media.discordapp.net/attachments/962889307931164742/1227299515246051328/PXL_20240409_073324853.jpg?ex=662bdb3e&is=662a89be&hm=cca35cebc9379e3499d69234f807f8d59afa1d76bd6ad8293f55e2a4c8691ac7&=&format=webp&width=309&height=411)

## Board Replacement and Progress - 4/11-4/13

### New Board Arrival
- **Replacement Boards:** Received the new set of boards, which did not have the short circuit issue found in the previous batch. Made final iteration of board and made sure they passed DRC.

### Personal Break and Decompression
- **Time Off:** Took a few days off to decompress and relax after the challenging experience of destructive testing being completely pointless. Did other coursework.

### Team Progress
- **Board Functionality:** The team successfully managed to get the new boards recognized by the development board and initiated programming tasks.

### Note on Progress
- **Alleged Programming Success:** While programming was reportedly successful, further verification and testing may be required to confirm full functionality and reliability.


## Drive Train and Scanning Mechanism Redesign -4/14-4/16

### Redesign Process
- **Drive Train and Scanning Mechanism:** Undertook another redesign iteration for improved functionality and performance. Group said part of it was too short.
- **3D Printing and Machining:** Utilized both 3D printing and manual machining through wood by hand drilling to create the redesigned components. Team lost access to MEB due to accidentally leaving a hot glue gun on.

### Hall Effect Module Holder Design
- **Design Task:** Created a holder specifically designed to accommodate the Hall Effect module, ensuring proper positioning and functionality within the system. 

### Progress Update
- **Completed Tasks:** Successfully completed the redesign of the drive train/scanning mechanism and the design of the Hall Effect module holder. completely assembled all parts.

### Next Steps
- **Integration:** Proceed with integrating the redesigned components into the overall system.
- **Testing:** Conduct initial testing to evaluate the performance and functionality of the redesigned drive train and scanning mechanism.

![Assembly 1 View 1](https://media.discordapp.net/attachments/1197376949950107669/1230377507568746538/rn_image_picker_lib_temp_8f6d4d88-b9f5-497e-8acd-89c2255088a6.jpg?ex=662c81d9&is=662b3059&hm=3b27238982f99c61448fd8ae020415bb1b65920da1fbcfe211f789f06767369b&=&format=webp&width=185&height=411)
![Assembly 1 View 2](https://media.discordapp.net/attachments/1197376949950107669/1230377508097097748/rn_image_picker_lib_temp_8e3244b8-3de0-4dd3-83dc-756b2b1d47fd.jpg?ex=662c81d9&is=662b3059&hm=f7d48a0da2173e5aa6a0a90f07470874b590f48619b0170418af0ef44ad04ee4&=&format=webp&width=185&height=411)

## Drive Train and Scanning Mechanism Redesign (again) -4/18-4/20

### Redesign Details
- **Drive Train and Scanning Mechanism:** Conducted another round of redesigning to enhance performance and functionality (group hated it to my dismay)
- **Integration of Ball Bearing:** Incorporated a ball bearing into the design to reduce friction during the turning of the LiDAR system.
- **Space Accommodation for Hall Effect Module:** Ensured sufficient space and compatibility for the Hall Effect module within the redesigned components.

### Progress Update
- **Redesign Completion:** Successfully completed the redesign of the drive train/scanning mechanism, incorporating the ball bearing and accommodating space for the Hall Effect module.

### Next Steps
- **Integration Testing:** 3-D print models and make full assembly. Find a different place to 3-D print parts.

![Cad Assembly 2 View 1](https://media.discordapp.net/attachments/1197377121027375245/1233282348263407686/image.png?ex=662c8731&is=662b35b1&hm=289482aa16ef47bd315dd31aad985573d35b32d1c0437f43e0a09015df9a32ce&=&format=webp&quality=lossless&width=444&height=411)
![Cad Assembly 2 View 2](https://media.discordapp.net/attachments/1197377121027375245/1233282811335675904/image.png?ex=662c879f&is=662b361f&hm=26965bdddc74ad049f282757a694c084bd48d647b30a0c44eb1de32b6074da1a&=&format=webp&quality=lossless&width=389&height=411)

## 3D Printing and Exam Day - 4/21-4/22

### 3D Printing Tasks
- **Part Production:** Utilized 3D printing technology to fabricate parts required for the project's assembly.

### Academic Commitment
- **ECE 434 Exam:** Had an exam for ECE 434, which required focus and preparation, leading to limited time available for completing the assembly.

### Progress Update
- **Part Production:** Successfully completed the 3D printing tasks, generating the necessary components for the project.

### Next Steps
- **Assembly Completion:** Plan to resume work and complete the assembly of the project once academic commitments, such as exams, are successfully addressed.

![Partial 3D prints](https://media.discordapp.net/attachments/1197377121027375245/1232113090431291402/20240422_151542.png?ex=662c3abc&is=662ae93c&hm=dcfb52f57cec7e2062b8405c81ef800bfbb4159c328976cef650e6a77c2c14ae&=&format=webp&quality=lossless)

## Physical Assembly Success and Role Reflection - 4/23

### Seeing-Eye-Hat Assembly
- **Completion:** Successfully finished the physical assembly for the seeing-eye-hat project.
- **First-Time Success:** The assembled project worked on the first try, indicating successful implementation.

### Role Reflection
- **Mechanical Engineering Contributions:** Recognized that my contributions to the project's physical assembly were more aligned with mechanical engineering principles rather than electrical engineering. Felt sad about it honestly.

### Group Challenges
- **PCB Issues:** The group encountered persistent challenges with the PCB, leading to difficulties in getting it to work.
- **Acceptance of Setbacks:** Accepted the reality of not achieving PCB-related milestones due to personal mistakes and challenges with supply chains.

![Complete Assembly 2 View 1](https://media.discordapp.net/attachments/1070112306823958610/1233118103425122385/20240424_221110.png?ex=662bee3a&is=662a9cba&hm=d693c4752a953440289babb8768e0dcaf08ad5186c3dbfdfa54f236d2c232f93&=&format=webp&quality=lossless&width=411&height=411)
![Comblete Assembly 2 View 2](https://media.discordapp.net/attachments/971438288512614480/1233118233054416957/20240424_220418.jpg?ex=662bee58&is=662a9cd8&hm=54d1b87562520b22ffa557f4ed81007f87df2ed5e3cb1f65d883c53819c6a090&=&format=webp&width=411&height=411)

## PCB Challenges and Acceptance of Setbacks - 4/24

### PCB Return and Non-Functionality
- **PCB Parts Returned:** The parts for the PCB were returned to the sender due to ongoing issues.
- **Lack of Success:** Despite efforts, none of the PCB attempts yielded functional results.
- **Acknowledgement of Challenges:** Accepted the situation where personal mistakes and external factors, such as supply chain issues, hindered progress.

### Adaptation and Resilience
- **Learning Experience:** Viewed the setbacks as learning opportunities to improve processes and mitigate future challenges.
- **Resilience:** Maintained a positive outlook despite the setbacks and continued to focus on other aspects of the project.

## Next Steps
- **Adaptation and Learning:** Plan to learn from the PCB challenges and adapt strategies for future projects.
- **Focus Shift:** Shift focus towards other project components and tasks to ensure overall progress and success.

![Bitter Defeat at the hands of USPS](https://media.discordapp.net/attachments/1197376949950107669/1233090498843902013/image.png?ex=662c7d44&is=662b2bc4&hm=f0a02b5e31e42e7688cf43e1eb8a5753b22415bd3f7502a491a5efa14c5e855c&=&format=webp&quality=lossless&width=866&height=411)
