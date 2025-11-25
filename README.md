# Arduino SCT-013 Current Monitor

This project implements a current monitoring system using an Arduino and the SCT-013 current transformer sensor.

## Hardware Components

- Arduino board (e.g., Arduino Uno)
- SCT-013 current transformer sensor (30A version)
- EmonLib library for energy monitoring

## Features

- Real-time current measurement
- Calibrated current readings
- Serial output for monitoring
- Automatic zero threshold for low current values

## Hardware Setup

1. Connect the SCT-013 sensor output to analog pin A0
2. The built-in LED on pin 13 is available for status indication
3. Ensure proper burden resistor is used with the SCT-013 sensor

## Software Configuration

The code uses the EmonLib library to interface with the SCT-013 sensor:

- Sensor pin: A0
- Calibration value: 30 (for 20A/1V sensor)
- Sample count: 1480 for RMS calculation
- Serial baud rate: 9600

## Calibration

The system includes a calibration formula:
```
I_calibrated = 0.936609 * I_raw - 0.115665
```

Current readings below 0.1A are automatically zeroed to filter noise.

### Calibration Data

The `creative.csv` and `creative.xlsx` files contain calibration data mapping digital readings to raw voltage values.

## Usage

1. Upload the `SCT_013_30A.ino` sketch to your Arduino
2. Open the Serial Monitor at 9600 baud
3. Clamp the SCT-013 sensor around the current-carrying wire
4. Observe both raw and calibrated current readings

## Output Format

The serial output displays:
- Raw current reading (in Amperes)
- Calibrated current reading (in Amperes)
- Update rate: approximately every 300ms

## Files

- `SCT_013_30A.ino` - Main Arduino sketch
- `creative.csv` - Calibration data in CSV format
- `creative.xlsx` - Calibration data in Excel format
- `Capture.JPG` - Hardware setup reference image

## Dependencies

- EmonLib - Energy monitoring library for Arduino

## License

Please refer to the repository license for usage terms.
