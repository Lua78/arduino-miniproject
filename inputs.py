import serial
import keyboard
import time

try:
    # Conecta con el puerto serial donde está conectado el Arduino (ajusta el puerto según sea necesario)
    arduino = serial.Serial('COM1', 9600, timeout=1)  # Reemplaza 'COM3' con el puerto correcto en tu sistema
except:
    print("error al intentar conectar al puerto arduino..")
    exit()
time.sleep(2)

print("WASD para mover izquierda derecha arriba y abajo")
print("UJ para subir y bajar el antebrazo respectivamente")
print("IK para mover la muñeca del lado izquierdo")
print("OL para mover la muñeca del lado derecho")
print("T para sujetar")
print("G para soltar")
while True:
    try:
        if keyboard.is_pressed('a'):
            arduino.write(b'a')
        elif keyboard.is_pressed('d'):
            arduino.write(b'd')
        elif keyboard.is_pressed('w'):
            arduino.write(b'w')
        elif keyboard.is_pressed('s'):
            arduino.write(b's')
        elif keyboard.is_pressed('u'):
            arduino.write(b'u')
        elif keyboard.is_pressed('j'):
            arduino.write(b'j')
        elif keyboard.is_pressed('i'):
            arduino.write(b'i')
        elif keyboard.is_pressed('k'):
            arduino.write(b'k')
        elif keyboard.is_pressed('o'):
            arduino.write(b'o')
        elif keyboard.is_pressed('l'):
            arduino.write(b'l')
        elif keyboard.is_pressed('t'):
            arduino.write(b't')
        elif keyboard.is_pressed('g'):
            arduino.write(b'g')
        elif keyboard.is_pressed("z"):
            print("saliendo de la interfaz..")
            break
        time.sleep(0.1)
    except:
        break

# Cierra la conexión al puerto serial al salir
arduino.close()
