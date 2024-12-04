import pygame
import serial

def detectar_movimiento_control():
    # Inicializar pygame
    pygame.init()
    
    # Inicializar el joystick
    pygame.joystick.init()
    
    # Detectar joysticks conectados
    if pygame.joystick.get_count() == 0:
        print("No se detectó ningún control conectado.")
        return
    
    # Usar el primer joystick detectado
    joystick = pygame.joystick.Joystick(0)
    joystick.init()
    print(f"Control detectado: {joystick.get_name()}")
    try:
    # Conecta con el puerto serial donde está conectado el Arduino (ajusta el puerto según sea necesario)
        arduino = serial.Serial('COM1', 9600, timeout=1)  # Reemplaza 'COM3' con el puerto correcto en tu sistema
    except:
        print("error al intentar conectar al puerto arduino..")
        exit()
    time.sleep(2)
    
    # Loop para capturar eventos
    try:
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    return
                #print(event)
                if event.type == pygame.JOYAXISMOTION:
                    eje = event.axis
                    valor = event.value

                    # Stick izquierdo
                    if eje == 0:  # Horizontal del stick izquierdo
                        if valor < -0.5:
                            arduino.write(b'a')
                            print("Stick izquierdo: IZQUIERDA")
                        elif valor > 0.5:
                            arduino.write(b'd')
                            print("Stick izquierdo: DERECHA")
                    elif eje == 1:  # Vertical del stick izquierdo
                        if valor < -0.5:
                            arduino.write(b'w')
                            print("Stick izquierdo: ARRIBA")
                        elif valor > 0.5:
                            arduino.write(b's')
                            print("Stick izquierdo: ABAJO")

                    # Stick derecho
                    elif eje == 2:  # Horizontal del stick derecho
                        if valor < -0.5:
                            arduino.write(b'i')
                            print("Stick derecho: IZQUIERDA")
                        elif valor > 0.5:
                            arduino.write(b'o')
                            print("Stick derecho: DERECHA")
                    elif eje == 3:  # Vertical del stick derecho
                        if valor < -0.5:
                            arduino.write(b'k')
                            print("Stick derecho: ARRIBA")
                        elif valor > 0.5:
                            arduino.write(b'l')
                            print("Stick derecho: ABAJO")
                    elif eje == 4: # Gatillo derecho
                        if valor > 0.5:
                            arduino.write(b't')
                            print("Gatillo izquierdo presionado")
                    elif eje == 5: # Gatillo derecho
                        if valor > 0.5:
                            arduino.write(b'g')
                            print("Gatillo derecho presionado")  
                if event.type == pygame.JOYBUTTONDOWN:
                    boton = event.button
                    if boton == 3:
                        arduino.write(b'u')
                        print("y")
                    elif boton == 0:
                        arduino.write(b'j')
                        print("a")                          
    except KeyboardInterrupt:
        print("\nSaliendo...")
    finally:
        # Cerrar el joystick y salir de pygame
        joystick.quit()
        pygame.quit()

# Ejecutar la función
if __name__ == "__main__":
    detectar_movimiento_control()
