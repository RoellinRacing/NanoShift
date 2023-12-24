# NanoShift

# **************************************************************************************
# developed by @carbon_gtv , support me on Instagram, sponsors and donators are welcome!
# **************************************************************************************

### Parts List
1. **Arduino Uno**: Control unit of the system.
2. **Pneumatic Cylinders**: For physically actuating the gearbox.
3. **3/2-Way Valves**: Two pieces, one for upshifting and one for downshifting.
4. **Compressed Air Source**: Compressor or compressed air tank.
5. **Hoses and Connectors**: For connecting valves, cylinders, and the compressed air source.
6. **Pushbuttons**: Two pieces, one for upshifting and one for downshifting.
7. **Relay Module**: For controlling the electropneumatic valves and additional functions.
8. **Additional Pins for Ignition Interruption and Throttle Blip**: Pins 6 and 7 on the Arduino.

### Connection Plan
- **Pneumatic Valves**:
  - Upshift valve to Pin 2 of the Arduino.
  - Downshift valve to Pin 3 of the Arduino.
- **Ignition Interruption**:
  - To Pin 6 of the Arduino.
- **Throttle Blip**:
  - To Pin 7 of the Arduino.
- **Pushbuttons**:
  - Upshift button to Pin 4 of the Arduino.
  - Downshift button to Pin 5 of the Arduino.
- **Relay Module**:
  - Connect to the respective pins on the Arduino and to the valves as well as the additional functions.

### Installing and Setting Up the Arduino IDE
1. **Download and Install Arduino IDE**: Visit the [official Arduino website](https://www.arduino.cc/en/software) and download the Arduino IDE for your operating system. Follow the installation instructions.

2. **Connect Arduino Uno**: Connect the Arduino Uno to your computer using a USB cable.

3. **Install Drivers**: Your operating system should automatically install the necessary drivers. If not, you can find the drivers on the Arduino website.

4. **Launch Arduino IDE**: Open the Arduino IDE.

5. **Select Board and Port**: Under `Tools` -> `Board`, select your Arduino Uno. Then, under `Tools` -> `Port`, choose the port to which your Arduino is connected.

6. **Upload Code**: Copy the provided code into the Arduino IDE. Click the Upload button to transfer the code to your Arduino Uno.

### Additional Notes
- **Safety**: Ensure that all components are correctly connected, and power supply is adequate.
- **Testing**: Thoroughly test the system before implementing it in a vehicle.
- **Calibration**: Adjust the delay times in the code to suit your specific needs. The default values are starting points and may need adjustment.

With this guide, you should be able to install and operate your pneumatic gearbox control system with the additional features of ignition interruption and throttle blip.
