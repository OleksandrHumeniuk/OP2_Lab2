from tvector2d import TVector2D
from tvector3d import TVector3D


def inputFloat(header):
    isValid = False
    while not isValid:
        try:
            num = float(input(header))
        except ValueError:
            print("You can only enter a number!")
        else:
            isValid = True
    return num


def inputTVector2D(header):
    print(header)
    x = inputFloat("Input x coordinate: ")
    y = inputFloat("Input y coordinate: ")

    return TVector2D(x, y)


def inputTVector3D(header):
    print(header)
    x = inputFloat("Input x coordinate: ")
    y = inputFloat("Input y coordinate: ")
    z = inputFloat("Input z coordinate: ")

    return TVector3D(x, y, z)
