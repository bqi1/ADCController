
from time import sleep
import serial
class VoltageController():
    # This class can read and set voltage via a serial connection to an Arduino
    def __init__(self,serial_connection):
        self.ser = serial_connection
    def set_voltage(self,voltage):
        # This method sets the voltage supply connected to the Arduino towards the parameter, "voltage" 
        pass
    def read_voltage(self):
        # This method retrieves the current voltage the ADC is reading and prints the voltage result to the terminal
        keyword = str(1)
        self.ser.write(keyword.encode('ASCII')) # Convert the decimal number to ASCII then send it to the Arduino
        print("Voltage:",self.ser.readline().decode('ASCII')) # Read the newest output from the Arduino
        sleep(1)
def main():
    ser = serial.Serial('COM3', 9600) # Establish the connection on a specific port. As the connection may vary, check which port the Arduino is connected to on device manager 
    vc = VoltageController(ser)
    while True:
        vc.read_voltage()

if __name__ == "__main__":
    main()

