from tvector import TVector
from math import sqrt


class TVector3D(TVector):
    def __init__(self, x, y, z):
        self.__x = x
        self.__y = y
        self.__z = z

    def getScalar(self, other):
        return self.__x * other.getCoordinate("x") + self.__y * other.getCoordinate("y") + self.__z * other.getCoordinate("z")

    def getLength(self):
        return sqrt(self.__x * self.__x + self.__y * self.__y + self.__z * self.__z)

    def getCoordinate(self, c):
        if c == "x":
            return self.__x
        elif c == "y":
            return self.__y
        elif c == "z":
            return self.__z
        else:
            return 0

    def print(self, header):
        print(f"{header} TVector3D: x = {self.__x:5} y = {self.__y:5} z = {self.__z:5}")
