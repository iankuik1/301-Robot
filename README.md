# 301-Robot
This was designed using Cypress PSOC 5 Kit, our custom PCB and designed on PSOC creator, written in C. 

Phototransistors are used as sensors. Signals are then cleaned up with a low pass filter set to 120Hz. They are then amplified and sent into a comparator to detect the presence of light. This is detailed in our LTSpice files.

Sensor data is inputted into our PSOC via GPIO pins and the PSOC will react accordingly.

[Demo Video.](https://drive.google.com/file/d/117MfSOEKXF8rv83AYyc8brWDtbxbpZWl/view?usp=sharing)
